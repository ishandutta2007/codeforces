//
//  main.cpp
//  frac_div
//
//  Created by Sokol Kostya's MacBook on 10.09.11.
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

int mn[ 10000001 ], num[2][ 10000001 ], n, m, a[ 111111 ], b[ 111111 ];
priority_queue< int > aa, bb;

void go( int v, int id )
{
    while ( mn[ v ] != 0 )
    {
        num[id][ mn[ v ] ]++;
        v /= mn[ v ];
    }
    num[id][ v ]++;
}

int repair_a( int v )
{
    int res = 1;
    while ( mn[ v ] != 0 )
    {
        int d = mn[ v ];
        if ( num[0][d] == 0 ) res *= d; else num[0][d]--;
        v = v / d;
    }
    int d = v;
    if ( num[0][d] == 0 ) res *= d; else num[0][d]--;
    v = v / d;
    return res;
}

int repair_b( int v )
{
    int res = 1;
    while ( mn[ v ] != 0 )
    {
        int d = mn[ v ];
        if ( num[1][d] == 0 ) res *= d; else num[1][d]--;
        v = v / d;
    }
    int d = v;
    if ( num[1][d] == 0 ) res *= d; else num[1][d]--;
    v = v / d;
    return res;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for ( int i = 2; i * i <= 10000000; i++ )
    {
        if ( mn[i] != 0 ) continue;
        int j = i * i;
        while ( j <= 10000000 )
        {
            if ( mn[j] == 0 ) mn[j] = i;
            j += i;
        }
    }
    scanf("%d%d", &n, &m);
    for ( int i = 0; i < n; i++ )
    {
        scanf("%d", &a[i]);
        if ( a[i] == 1 ) continue;
        go( a[i], 0 );
    }
    for ( int i = 0; i < m; i++ )
    {
        scanf("%d", &b[i]);
        if ( b[i] == 1 ) continue;
        go( b[i], 1 );
    }
    
    for ( int i = 0; i <= 10000000; i++ ) num[0][i] = min( num[0][i], num[1][i] ), num[1][i] = num[0][i];
    
    printf("%d %d\n", n, m);
    for ( int i = 0; i < n; i++ )
    {
        if ( a[i] != 1 ) a[i] = repair_a( a[i] );
        printf("%d ", a[i]);
    }
    printf("\n");
    for ( int i = 0; i < m; i++ )
    {
        if ( b[i] != 1 ) b[i] = repair_b( b[i] );
        printf("%d ", b[i]);
    }
    
    return 0;
}