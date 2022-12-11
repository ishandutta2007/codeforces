//
//  main.cpp
//  median111
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

int n, x, a, ans = 0, pp[111111], h = 11111, t = 11110;
int used[111111], pref[111111];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        used[a]++;
    }
    if (used[x] == 0)
    {
        ans = 1;
        used[x] = 1;
    }
    for (int i = 0; i < 111111; i++)
    {
        for (int j = 0; j < used[i]; j++)
        {
            ++t;
            pp[t] = i;
        }
    }
    while ( pp[ h - 1 + (t - h + 2) / 2 ] != x )
    {
        if ( pp[ h - 1 + (t - h + 2) / 2 ] > x )
        {
            --h;
            pp[h] = 1;
            continue;
        }
        if ( pp[ h - 1 + (t - h + 2) / 2 ] < x )
        {
            ++t;
            pp[t] = 100000;
            continue;
        }
    }
    cout << (t - h + 1) - n;
    return 0;
}