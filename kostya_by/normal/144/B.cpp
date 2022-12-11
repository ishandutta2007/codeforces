//
//  main.cpp
//  meeting
//
//  Created by Sokol Kostya's MacBook on 30.04.11.
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

int xx[1111], yy[1111], rr[1111], ans, xa, ya, xb, yb, n;

int check(int x, int y)
{
    for (int i = 0; i < n; i++)
    {
        int dx = xx[i] - x;
        int dy = yy[i] - y;
        dx *= dx;
        dy *= dy;
        if (dx + dy <= rr[i] * rr[i]) return 1;
    }
    return 0;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> xa >> ya >> xb >> yb;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> xx[i] >> yy[i] >> rr[i];
    if (xa > xb) swap( xa, xb );
    if (ya > yb) swap( ya, yb );
    for (int x = xa; x <= xb; x++)
    {
        ans += 2;
        ans -= check(x, ya) + check(x, yb);
    }
    for (int y = ya; y <= yb; y++)
    {
        ans += 2;
        ans -= check(xa, y) + check(xb, y);
    }
    ans -= 4;
    ans += check(xa, ya) + check(xa, yb) + check(xb, ya) + check(xb, yb);
    cout << ans;
    return 0;
}