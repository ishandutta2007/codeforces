//
//  main.cpp
//  task2
//
//  Created by Sokol Kostya's MacBook on 20.02.11.
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

int n;
long long val[ 100100 ], f[ 100100 ], g[ 100100 ];
vector< int > graf[ 100100 ];

void solve( int v, int p )
{
    f[v] = g[v] = 0;
    for ( int i = 0; i < graf[v].size(); i++ )
    {
        int next = graf[v][i];
        if ( next == p ) continue;
        solve( next, v );
        f[v] = max( f[v], f[next] );
        g[v] = max( g[v], g[next] );
    }
    val[v] += f[v] - g[v];
    if ( val[v] > 0 ) g[v] += val[v];
    if ( val[v] < 0 ) f[v] += -val[v]; 
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for ( int i = 1; i < n; i++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        graf[a].pb(b);
        graf[b].pb(a);
    }
    for ( int i = 1; i <= n; i++ )
    {
        int vv;
        scanf("%d", &vv);
        val[i] = vv;
    }
    solve( 1, -1 );
    cout << f[1] + g[1] << endl;
    return 0;
}