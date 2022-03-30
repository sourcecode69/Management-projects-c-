#include <iostream>
#include <string.h>
using namespace std;
struct HSTL
{
    int NUMBER = 1;
    int fill = 0;
    char CUS_NAMES[3][10];
    HSTL *NXT;
    HSTL *PREVIOUS;
};
class hostel
{
    HSTL *TITLE[3];
    HSTL *WORDS;

public:
    hostel()
    {
        for (int x = 0; x < 3; x++)
            TITLE[x] = NULL;
    }
    void create()
    {
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 9; y++)
            {
                HSTL *ss = new HSTL;
                ss->NXT = NULL;
                ss->PREVIOUS = NULL;
                if (TITLE[x] == NULL)
                {
                    TITLE[x] = ss;
                    ss->NUMBER = 1;
                }
                else
                {
                    HSTL *WORDS = TITLE[x];
                    while (WORDS->NXT != NULL)
                    {
                        WORDS = WORDS->NXT;
                    }
                    if (y == 3 || y == 5 || y == 7 || y == 8)
                    {
                        WORDS->NUMBER = 3;
                    }
                    if (y == 2 || y == 4 || y == 6)
                    {
                        WORDS->NUMBER = 2;
                    }
                    WORDS->NXT = ss;
                    ss->PREVIOUS = WORDS;
                }
            }
        }
    }
    void display()
    {
        int y = 0, z = 0, w = 0;
        for (int x = 0; x < 48; x++)
        {
            cout << "--";
        }
        cout << "\n "
        ;
        for (int x = 1; x < 4; x++)
        {
            cout << "| Floor number : "<< x << " \t\t";
        }
        cout << "|\n" ;
        for (int x = 0; x < 48; x++)
        {
            cout << "--";
        }
        WORDS = TITLE[y];
        HSTL *s = TITLE[y + 1];
        HSTL *t = TITLE[y + 2];
        cout << "\n ";
        while (WORDS != NULL)
        {
            if (WORDS->fill != WORDS->NUMBER && WORDS->NUMBER != 0)
            {
                y++;
                cout << "| room no : "<< y;
                cout << "->Vacant cots->"<< WORDS->NUMBER;
            }
            else
            {
                y++;
                cout << "| room no : "<< y;
                cout << "->Present ";
            }
            if (s->fill != s->NUMBER && s->NUMBER != 0)
            {
                z++;
                cout << "\t | room no : "<< y;
                cout << "->Vacant cots->"<< s->NUMBER;
            }
            else
            {
                z++;
                cout << " \t | room no : "<< y;
                cout << "->Present ";
            }
            if (t->fill != t->NUMBER && t->NUMBER != 0)
            {
                w++;
                cout << "\t | room no : "<< y;
                cout << "->Vacant cots->"<< t->NUMBER << "| ";
            }
            else
            {
                w++;
                cout << "\t | room no : "<< y;
                cout << "->Present "<< " | ";
            }
            cout << " \n ";
            for (int x = 0; x < 48; x++)
            {
                cout << "--" ;
            }
            cout << "\n ";
            WORDS = WORDS->NXT;
            s = s->NXT;
            t = t->NXT;
        }
    }
    void booking(int people)
    {
        int fl, rom;
        cout << "\nEnter the floor number : ";
        cin >> fl;
        try
        {
            if (fl < 0 || fl > 4)

            {
                throw(fl);
            }
            WORDS = TITLE[fl - 1];

            cout << "\nEnter the room number : ";
            cin >> rom;
            try
            {

                if (rom < 0 || rom > 10)
                {
                    throw(rom);
                }
                else
                {
                    int x = 1;
                    while (x < rom)
                    {
                        WORDS = WORDS->NXT;
                        x++;
                    }
                    if (WORDS->NUMBER >= people)
                    {
                        cout << "\nroom is vacant you can apply for room" ;

                        int count = 0;
                        while (WORDS->fill - 1 <= WORDS->NUMBER)
                        {

                            cout << "\nEnter name "<< WORDS -> fill + 1 << " : ";

                            cin >> WORDS->CUS_NAMES[WORDS->fill];
                            count++;
                            WORDS->fill++;
                            if (count >= people)
                            {
                                break;
                            }
                        }
                        WORDS->NUMBER = WORDS->NUMBER - people;
                    }

                    else
                    {
                        cout << "\nroom is not vacant... SORRY !!!";
                    }
                }
            }
            catch (int r)
            {
                cout << "\ninvalid room number : "<< r;
            }
        }
        catch (int r)
        {
            cout << " \ninvalid floor number : " << r;
        }
    }
    void cancelled(int check)
    {
        char checking_namess[10];
        int fg = 0;
        int rms, x = 1;
        try
        {
            if (check < 0 || check > 4)

            {
                throw(check);
            }
            else
            {
                cout << " Enter the room no : ";
                cin >> rms;
                try
                {
                    if (rms < 0 || rms > 10)
                    {
                        throw(rms);
                    }
                    else
                    {
                        cout << " Enter the name to be delete :";

                        cin >> checking_namess;
                        WORDS = TITLE[check - 1];
                        while (x < rms)
                        {
                            WORDS = WORDS->NXT;
                            x++;
                        }
                        x = 0;
                        while (x < 3)
                        {

                            if (!strcmp(checking_namess, WORDS -> CUS_NAMES[x]))

                            {
                                fg = 1;
                                break;
                                x = 0;
                            }
                            else
                                x++;
                        }
                        if (fg == 1 && WORDS->fill != 0)
                        {
                            cout << "\nrecord deleted : "<< WORDS -> CUS_NAMES[x];

                            WORDS->CUS_NAMES[x][0] ='A';
                            WORDS->CUS_NAMES[x][1] ='\0';
                            WORDS->fill--;
                            WORDS->NUMBER++;
                        }
                        else

                            cout << "\nrecord not present ";
                    }
                }
                catch (int r)
                {
                    cout << "\ninvalid room number : " << r;
                }
            }
        }

        catch (int r)

        {
            cout << " \n floor dosn't exist : " << r;
        }
    }
    void modify(int check)
    {
        char checking_namess[10];
        int rms, x = 1;
        try
        {
            if (check < 0 || check > 4)

            {
                throw(check);
            }
            else
            {
                cout << " Enter the room no : ";
                cin >> rms;
                try
                {
                    if (rms < 0 || rms > 10)

                    {
                        throw(rms);
                    }
                    else
                    {
                        cout << "Enter the name to be updated :";

                        cin >> checking_namess;
                        WORDS = TITLE[check - 1];
                        while (x < rms)
                        {
                            WORDS = WORDS->NXT;
                            x++;
                        }
                        x = 0;
                        while (x < 3)
                        {
                            if (!strcmp(checking_namess, WORDS -> CUS_NAMES[x]))

                            {
                                cout << "\nenter updated name : " ;

                                cin >> WORDS->CUS_NAMES[x];
                                break;
                            }
                            else
                                x++;
                        }
                        if (x >= 3)
                            cout << "record not found ";
                        else
                        {
                            cout << "\nrecord updated\nprevious name : "<< checking_namess << "\nupdated name : "<< WORDS->CUS_NAMES[x];
                        }
                    }
                }
                catch (int r)
                {
                    cout << "\ninvalid room number : "<< r;
                }
            }
        }

        catch (int r)

        {
            cout << "\n floor dosn't exist : "<< r;
        }
    }
};
int main()
{

    hostel objectives;
    int key_rooms;
    char channels;
    int checking_floors;
    objectives.create();
    do
    {
        cout << "\n1.Book a room for 1 person\n2.Book a room for 2person\n3.Book a room for 3 person\n4.Display the current status of rooms\n5.cancel a booking\n6.modify"<< endl;
        cout << " Enter your choice : "   ;
        cin >> key_rooms;
        switch (key_rooms)
        {
        case 1:
        {
            objectives.booking(1);
            break;
        }
        case 2:
        {
            objectives.booking(2);
            break;
        }
        case 3:
        {
            objectives.booking(3);
            break;
        }
        case 4:
        {
            objectives.display();
            break;
        }
        case 5:
        {
            cout << "Enter floor number : ";
            cin >> checking_floors;
            objectives.cancelled(checking_floors);
            break;
        }
        case 6:
        {
            cout << "Enter floor number : ";
            cin >> checking_floors;
            objectives.modify(checking_floors);
            break;
        }

        default:
            cout << "\nInvalid choice ";
        }
        cout << "\nDo you want to continue(Y / N) ";
        cin >> channels;
    } while (channels =='Y'|| channels =='y');
}
