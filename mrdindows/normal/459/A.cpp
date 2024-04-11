#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:10000000000")

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <iomanip>

using namespace std;
int x[3], y[3];
int main()
{
    cin >> x[0] >> y[0] >> x[1] >> y[1];

    int dx = abs(x[1] - x[0]);
    int dy = abs(y[1] - y[0]);
    if (dx == 0 && dy == 0)
    {
        cout << "-1\n";
    }
    else if (x[0] == x[1])
    {
        cout << x[0] + dy << ' ' << y[0] << ' ' << x[0] + dy << ' ' << y[1] << endl;
    }
    else if (y[0] == y[1])
    {
        cout << x[0] << ' ' << y[0] + dx << ' ' << x[1] << ' ' << y[0] + dx << endl;
    }
    else
    {
        if (dx != dy)
        {
            cout << "-1\n";
        }
        else
        {
            cout << x[0] << ' ' << y[1] << ' ' << x[1] << ' ' << y[0] << endl;
        }
    }

    return 0;
}