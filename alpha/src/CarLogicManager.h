//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef CARLOGICMANAGER_H_
#define CARLOGICMANAGER_H_

#include "PracticalSocket.h"
#include <omnetpp.h>
#include "Send_m.h"
#include <unordered_map>
#include "AlphaAppl.h"

using namespace omnetpp;

class CarLogicManager : public cSimpleModule {
public:
    CarLogicManager();
    ~CarLogicManager();
    void initialize(int stage);
    void finish();
    void handleMessage(cMessage *msg);
    void addVehicle(AlphaAppl* veh);

protected:
    string hostname;
    unsigned short port;
    simtime_t updateInterval;
    TCPSocket* socket;
    cMessage* executeOneTimestepTrigger;

    int vehicleCounter;
    std::unordered_map<int, AlphaAppl*> vehiclePointers;

    void handleCommands(char* data);
    string speedRequest(char* data);
    void handleSelfMsg(cMessage *msg);
    void executeOneTimestep();
    void sendToPython(Send* msg);
};

#endif /* CARLOGICMANAGER_H_ */
