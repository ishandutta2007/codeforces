//
//  main.cpp
//  epic game
//
//  Created by Sokol Kostya's MacBook on 15.01.11.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <stack>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int nod(int a, int b)
{
    if (a != 0) return nod(b % a, a); else return b;
}

double sqr(double x)
{
    return x * x;
}

int a[14] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 774, 777, 747};
int used[500];

int main (int argc, const char * argv[])
{
    int f[1111111], a, x, y;
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i < 1111111; i++)
    {
        if (f[i - 1] == 2) f[i] = 1; else f[i] = 2;
    }
    cin >> a >> x >> y;
    int cnt = 1, sum = 0;
    if (y % a == 0)
    {
        cout << -1;
        return 0;
    }
    while (y > a)
    {
        y -= a;
        sum += f[cnt++];
    }
    if (f[cnt] == 1)
    {
        if (a % 2 == 0 && fabs(x) == a / 2)
        {
            cout << -1;
            return 0;
        }
        a /= 2;
        if (fabs(x) <= a)
        {
            cout << sum + 1;
            return 0;
        }
        cout << -1;
    }
    if (f[cnt] == 2)
    {
        if (x >= a || x <= -a || x == 0)
        {
            cout << -1;
            return 0;
        }
        if (x > 0) cout << sum + 2; else cout << sum + 1;
        return 0;
    }
    return 0;
}