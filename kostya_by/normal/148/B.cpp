//
//  main.cpp
//  escape
//
//  Created by Sokol Kostya's MacBook on 01.05.11.
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
#include <cstdlib>
#include <ctime>
#include <stack>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int v1, v2, t, f, c, ans = 11111;

bool fun(int xx)
{
    double cc = 1.0 * c;
    double x = 1.0 * v1 * t;
    double tres = 1.0 * ( x / (v2 - v1) + t );
    x = 1.0 * v1 * tres;
    for (int i = 0; i < xx; i++)
    {
        double cur = 1.0 * (f + x / v2);
        tres += cur;
        x = 1.0 * v1 * tres;
        tres += 1.0 * ( x / (v2 - v1) );
        x = 1.0 * v1 * tres;
    }
    x = 1.0 * v1 * tres;
   // cout << x << endl;
    if (x + eps > cc) return true;
    return false;
}

void find(int ll, int rr)
{
    if (ll > rr) return;
    int xx = (ll + rr) / 2;
    if (fun(xx) == true) 
    {
        ans = min(xx, ans);
        find(ll, xx - 1);
    } else find(xx + 1, rr);
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> v1 >> v2 >> t >> f >> c;
    if (v1 >= v2)
    {
        cout << 0;
        return 0;
    }
    find(0, 10000);
    //cout << "-------" << endl;
    //for (int i = 0; i < 10; i++) fun(i);
    cout << ans;
    return 0;
}