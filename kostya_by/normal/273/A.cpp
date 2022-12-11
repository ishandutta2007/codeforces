//
//  main.cpp
//  task1
//
//  Created by Sokol Kostya's MacBook on 13.02.11.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
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

int n, m;
long long a[ 100100 ];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for ( int i = 1; i <= n; i++ ) scanf("%I64d", &a[i]);
    cin >> m;
    int pnt = 1;
    long long hh = 0;
    for ( int i = 1; i <= m; i++ )
    {
        int w;
        long long h;
        scanf("%d%I64d", &w, &h);
        while ( pnt <= w )
        {
            hh = max( a[pnt], hh );
            pnt++;
        }
        printf("%I64d\n", hh);
        hh += h;
    }
    return 0;
}