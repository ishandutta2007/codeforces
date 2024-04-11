//
//  main.cpp
//  task1
//
//  Created by Sokol Kostya's MacBook on 14.08.11.
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

int n, m, color[ 111 ], num[ 111 ], ee[ 111 ], colornow = 0;
vector< int > graf[ 111 ];

void dfs( int v )
{
    color[ v ] = colornow;
    num[ colornow ]++;
    ee[ colornow ] += graf[ v ].size();
    for (int i = 0; i < graf[ v ].size(); i++)
    {
        int next = graf[ v ][ i ];
        if ( color[ next ] != 0 ) continue;
        dfs( next );
    }
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        graf[ a ].pb( b );
        graf[ b ].pb( a );
    }
    for (int i = 0; i < n; i++)
    {
        if ( color[ i ] != 0 ) continue;
        ++colornow;
        dfs( i );
    }
    int team1 = 0, team2 = 0;
    for (int i = 1; i <= colornow; i++)
    {
        ee[ i ] /= 2;
        if ( ee[ i ] == num[ i ] )
        {
            if ( num[ i ] % 2 == 1 ) --num[ i ];
            team1 += num[ i ] / 2;
            team2 += num[ i ] / 2;
            continue;
        }
        if ( num[ i ] % 2 == 0 )
        {
            team1 += num[ i ] / 2;
            team2 += num[ i ] / 2;
            continue;
        }
        int a = num[ i ] / 2;
        int b = a + 1;
        if ( team1 < team2 ) swap( a, b );
        team1 += a;
        team2 += b;
    }
    int num = min( team1, team2 );
    cout << n - 2 * num;
    return 0;
}