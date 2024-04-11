//
//  main.cpp
//  cf_great
//
//  Created by Sokol Kostya's MacBook on 07.04.11.
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

int color[ 5050 ], cnow;
int n, ii;
int a[ 5050 ], b[ 5050 ];
long long c[ 5050 ], f[ 5050 ], g[ 5050 ], num[ 5050 ], vv[ 5 ];
vector< int > graf[ 5050 ];
long long ans = inf;

void dfs1( int v, int prev )
{
    vv[cnow]++;
    color[v] = cnow;
    f[v] = 0;
    g[v] = 0;
    num[v] = 1;
    for ( int i = 0; i < graf[v].size(); i++ )
    {
        int id = graf[v][i];
        if ( id == ii ) continue;
        int next = v ^ a[id] ^ b[id];
        if ( next == prev ) continue;
        dfs1( next, v );
        num[v] += num[next];
        f[v] += f[next] + num[next] * c[id];
    }
}

void dfs2( int v, int prev )
{
    for ( int i = 0; i < graf[v].size(); i++ )
    {
        int id = graf[v][i];
        if ( id == ii ) continue;
        int next = v ^ a[id] ^ b[id];
        if ( next == prev ) continue;
        long long sf = f[v] - ( f[next] + num[next] * c[id] );
        sf += ( vv[ cnow ] - num[next] ) * c[id];
        g[next] = g[v] + sf;
        dfs2( next, v );
    }
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for ( int i = 1; i < n; i++ )
    {
        cin >> a[i] >> b[i] >> c[i];
        graf[ a[i] ].pb( i );
        graf[ b[i] ].pb( i );
    }
    for ( int i = 1; i < n; i++ )
    {
        vv[1] = vv[2] = 0;
        ii = i;
        for ( int i = 1; i <= n; i++ ) color[i] = 0;
        cnow = 0;
        for ( int i = 1; i <= n; i++ )
        {
            if ( color[i] > 0 ) continue;
            cnow++;
            dfs1( i, -1 );
        }
        cnow = 0;
        for ( int i = 1; i <= n; i++ )
        {
            if ( cnow < color[i] )
            {
                ++cnow;
                dfs2( i, -1 );
            }
        }
        long long cur = 0;
        for ( int i = 1; i <= n; i++ ) cur += f[i] + g[i];
        cur /= 2;
        cur += vv[1] * vv[2] * c[i];
        long long mn[ 3 ];
        mn[1] = mn[2] = inf;
        for ( int i = 1; i <= n; i++ ) mn[ color[i] ] = min( mn[ color[i] ], f[i] + g[i] );
        cur += mn[1] * vv[2];
        cur += mn[2] * vv[1];
        ans = min( ans, cur );
    }
    cout << ans << endl;
    return 0;
}