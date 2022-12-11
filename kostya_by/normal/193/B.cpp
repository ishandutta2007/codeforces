//
//  main.cpp
//  xor
//
//  Created by Sokol Kostya's MacBook on 03.06.11.
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

int a[33], b[33], p[33], k[33], n, r, u, tt[33], z[33], back[33];
int cnt = 0;
long long ans = -inf;

void update(int step)
{
    int left = (u - step) % 2;
    long long now = 0;
    if (left == 0) for (int i = 1; i <= n; i++) now += 1ll * k[i] * a[i];
    if (left == 1) for (int i = 1; i <= n; i++) now += 1ll * k[i] * (a[i] ^ b[i]);
    ans = max(ans, now);
}

void rec(int pos)
{
    if (pos == u + 1) return;
    for (int i = ( (z[pos - 1] + 1) & 1 ); i < 2; i++)
    {
        z[pos] = i;
        if (i == 0)
        {
            for (int i = 1; i <= n; i++) a[i] = a[i] ^ b[i];
        }
        if (i == 1)
        {
            for (int i = 1; i <= n; i++) tt[i] = a[ p[i] ];
            for (int i = 1; i <= n; i++) a[i] = tt[i] + r;
        }
        update( pos );
        rec( pos + 1 );
        if (i == 0)
        {
            for (int i = 1; i <= n; i++) a[i] = a[i] ^ b[i];
        }
        if (i == 1)
        {
            for (int i = 1; i <= n; i++) tt[i] = a[ back[i] ];
            for (int i = 1; i <= n; i++) a[i] = tt[i] - r;
        }
    }
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> u >> r;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> k[i];
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) back[ p[i] ] = i;
    z[0] = 1;
    rec( 1 );
    cout << ans;
    return 0;
}