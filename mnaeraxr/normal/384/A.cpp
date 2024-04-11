// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int size;
    cin >> size;
    if (size % 2 == 0)
    {
        cout << size*size/2 << "\n";
        for (int i = 0; i < size/2; i++)
        {
            for (int j = 0; j < size/2; j++)
            {
                cout << "C.";
            }
            cout << "\n";
            for (int j = 0; j < size/2; j++)
            {
                cout << ".C";
            }
            cout << "\n";
        }
    }
    else
    {
        cout << (size*size + 1)/2 << "\n";
        for (int i = 0; i < size/2; i++)
        {
            for (int j = 0; j < size/2; j++)
            {
                cout << "C.";
            }
            cout << "C\n";
            for (int j = 0; j < size/2; j++)
            {
                cout << ".C";
            }
            cout << ".\n";
        }
        for (int j = 0; j < size/2; j++)
        {
            cout << "C.";
        }
        cout << "C\n";
    }
}