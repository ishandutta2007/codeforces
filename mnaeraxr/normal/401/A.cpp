//#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
    int total,max;
    cin >> total >> max;
    int sum = 0;
    int value;
    for (int i = 0; i < total; i++)
    {
        cin >> value;
        sum += value;
    }
    if (sum < 0)
        sum = -sum;
    if (sum == 0)
        cout << 0 << endl;
    else
        cout << (sum - 1)/max + 1 << endl;

}