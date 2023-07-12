
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Define constants
const double TICKET_PRICE = 5000.0;
const int TICKET_VALIDITY_YEARS = 10;
const int MAX_TRAVELLERS = 10;
const int MAX_TRAVELS = 100;

// Define Planet class
class Planet
{

private:
    string name;
    double x, y, z;

public:
    Planet(string name, double x, double y, double z)
    {
        this->name = name;
        this->x = x;
        this->y = y;
        this->z = z;
    }
    string getName()
    {
        return name;
    }
    double getX()
    {
        return x;
    }
    double getY()
    {
        return y;
    }
    double getZ()
    {
        return z;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setX(double x)
    {
        this->x = x;
    }
    void setY(double y)
    {
        this->y = y;
    }
    void setZ(double z)
    {
        this->z = z;
    }

    vector<double> getCoordinates()
    {
        return {x, y, z};
    }
};

// Define Ticket class
class Ticket
{
private:
    int id;
    string source;
    string destination;
    string travellerName;
    int travellerId;
    int validityYears;
    bool isReturnTicket;
    double price;
    int daysUntilTravel;

public:
    Ticket(int id, string source, string destination, string travellerName, int travellerId, bool isReturnTicket, int daysUntilTravel)
    {
        this->id = id;
        this->source = source;
        this->destination = destination;
        this->travellerName = travellerName;
        this->travellerId = travellerId;
        this->validityYears = TICKET_VALIDITY_YEARS;
        this->isReturnTicket = isReturnTicket;
        this->price = TICKET_PRICE / (daysUntilTravel + 1);
        this->daysUntilTravel = daysUntilTravel;
    }
    bool isValid()
    {
        return validityYears > 0;
    }
    void updateValidity(int years)
    {
        validityYears += years;
    }
    void printTicketDetails()
    {
        cout << "Ticket ID: " << id << endl;
        cout << "Traveller Name: " << travellerName << endl;
        cout << "Traveller ID: " << travellerId << endl;
        cout << "Source Planet: " << source << endl;
        cout << "Destination Planet: " << destination << endl;
        cout << "Is Return Ticket: " << (isReturnTicket ? "Yes" : "No") << endl;
        cout << "Validity Years: " << validityYears << endl;
        cout << "Price: " << price << endl;
        cout << "Days Until Travel: " << daysUntilTravel << endl;
    }

    string getSource()
    {
        return this->source;
    }
    string getDestination()
    {
        return this->destination;
    }
    int getDays()
    {
        return this->daysUntilTravel;
    }
};

// Define Traveller class
class Traveller
{

protected:
    string name;
    int id;

public:
    Traveller(string name, int id)
    {
        this->name = name;
        this->id = id;
    }
    string getName()
    {
        return name;
    }
    int getId()
    {
        return id;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setId(int id)
    {
        this->id = id;
    }
};

// Define Astronaut class
class Astronaut : public Traveller
{
private:
    int yearsOfExperience;
    string licenseId;

public:
    Astronaut(string name, int id, int yearsOfExperience, string licenseId) : Traveller(name, id)
    {
        this->yearsOfExperience = yearsOfExperience;
        this->licenseId = licenseId;
    }

    void setYears(int years)
    {
        this->yearsOfExperience = years;
    }
    void setLincence(int licenceId)
    {
        this->licenseId = licenceId;
    }
};

// Define Commander class
class Commander : public Traveller
{
private:
    string authority;

public:
    Commander(string name, int id, string authority) : Traveller(name, id)
    {
        this->authority = authority;
    }

    void setAuthority(string authority)
    {
        this->authority = authority;
    }
};

class SpaceTravel
{
private:
    vector<Ticket> tickets;
    vector<Traveller *> travellers;
    int nextTicketId;
    int nextTravellerId;
    int nextPlanetId;

public:
    SpaceTravel()
    {
        nextTicketId = 1;
        nextTravellerId = 1;
        nextPlanetId = 1;
    }
    void addtraveller(Traveller *t)
    {
        travellers.push_back(t);
        nextTravellerId++;
    }
    void addTickets(Ticket t)
    {
        tickets.push_back(t);
        nextTicketId++;
    }

    void listTravellers()
    {
        cout << "Travellers:" << endl;
        for (auto traveller : travellers)
        {
            cout << traveller->getName() << endl;
        }
    }

    Traveller *findTraveller(int id)
    {
        for (auto &traveller : travellers)
        {
            if (traveller->getId() == id)
            {
                return traveller;
            }
        }
        return nullptr;
    }

    void listTickets()
    {
        cout << "Tickets:" << endl;
        for (auto ticket : tickets)
        {
            ticket.printTicketDetails();
        }
    }

    void expireTickets(int years)
    {
        for (auto &ticket : tickets)
        {
            ticket.updateValidity(-years);
        }
    }
};

int main()
{
    Planet earth("Earth", 0, 0, 0);
    Planet mars("Mars", 50, 50, 50);
    Planet venus("Venus", -30, 20, -10);

    vector<Planet> planets;

    planets.push_back(earth);
    planets.push_back(mars);
    planets.push_back(venus);

    Traveller p1("Alice", 1);
    Traveller p2("Bob", 2);
    Traveller p3("Charlie", 3);
    Traveller p4("David", 4);
    Traveller p5("Eve", 5);
    Traveller p6("Frank", 6);
    Traveller p7("Grace", 7);
    Traveller p8("Harry", 8);
    Traveller p9("Isaac", 9);
    Traveller p10("John", 10);
    Traveller p11("Kathe", 11);

    vector<Traveller *> travellers;

    Ticket t1(1, "Earth", "Mars", "Alice", 1, false, 5);
    Ticket t2(2, "Earth", "Mars", "Bob", 2, false, 5);
    Ticket t3(3, "Earth", "Mars", "Charlie", 3, false, 5);
    Ticket t4(4, "Earth", "Mars", "David", 4, false, 5);

    vector<Ticket> tickets;

    tickets.push_back(t1);
    tickets.push_back(t2);
    tickets.push_back(t3);
    tickets.push_back(t4);

    // Checking validity for the passengers p1-p4 if they have the same source and destination on the same day

    if (t1.getSource() == "Earth" && t1.getDestination() == "Mars" && t1.getDays() == 5)
        travellers.push_back(&p1);
    if (t2.getSource() == "Earth" && t2.getDestination() == "Mars" && t2.getDays() == 5)
        travellers.push_back(&p2);
    if (t3.getSource() == "Earth" && t3.getDestination() == "Mars" && t3.getDays() == 5)
        travellers.push_back(&p3);
    if (t4.getSource() == "Earth" && t4.getDestination() == "Mars" && t4.getDays() == 5)
        travellers.push_back(&p4);

    Astronaut a1("Buzz Aldrin", 1, 30, "12345");
    Astronaut a2("Neil Armstrong", 2, 20, "67890");

    Commander c1("Chris Hadfield", 11, "NASA");
    Commander c2("Yuri Gagarin", 12, "Roscosmos");

    travellers.push_back(&a1);
    travellers.push_back(&c1);

    if (travellers.size() > 4)
    { // travellers must be greater than 4 because two of them are astronaut and commander
        SpaceTravel s1;
        for (auto traveller : travellers)
        {
            s1.addtraveller(traveller);
        }
        for (auto ticket : tickets)
        {
            s1.addTickets(ticket);
        }

        s1.listTravellers();
        s1.listTickets();
    }
    else
    {
        cout << "Not Enough passengers";
    }

    return 0;
}