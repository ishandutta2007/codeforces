//
//  main.cpp
//  common numbers
//
//  Created by Sokol Kostya's MacBook on 16.03.11.
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

int f[4444444], a[1111111], n, pt2[30], uu;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    pt2[0] = 1;
    for (int i = 1; i < 30; i++) pt2[i] = pt2[i - 1] * 2;
    for (int i = 0; i < 4444444; i++) f[i] = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
        f[ a[i] ] = a[i];
    }
    uu = pt2[22] - 1;
    for (int mask = 0; mask <= uu; mask++)
    {
        for (int i = 0; i < 22; i++)
        {
            if ((mask & pt2[i]) == 0) continue;
            f[mask] = max( f[mask], f[ mask ^ pt2[i] ] );
        }
    }
    for (int i =0; i < n; i++)
    {
        printf("%d ", f[ uu ^ a[i] ]);
    }
    return 0;
}