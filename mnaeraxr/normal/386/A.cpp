// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;

int main()
{
    int times;
    cin >> times;

    int v1,v2,p1,p2,current;
    v1 = 0;
    v2 = 0;
    p1 = -1;
    p2 = -1;

    for (int i = 0; i < times; i++)
    {
        cin >> current;
        if (current > v1)
        {
            v2 = v1;
            p2 = p1;
            v1 = current;
            p1 = i + 1;
        }
        else if (current > v2)
        {
            v2 = current;
            p2 = i + 1;
        }
    }
    cout << p1 << " " << v2 << endl;
}