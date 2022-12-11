//
//  main.cpp
//  task2
//
//  Created by Sokol Kostya's MacBook on 16.08.2013.
//  Copyright (c) 2013 Sokol Kostya's MacBook. All rights reserved.
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
#include <bitset>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, m, d;
int f[ 100100 ], g[ 100100 ];
vector< int > graf[ 100100 ];
bool ok[ 100100 ];

void dfs1( int v, int p )
{
    //cout << v << " " << p << endl;
    f[v] = -1;
    for ( int i = 0; i < graf[v].size(); i++ )
    {
        int next = graf[v][i]; if ( next == p ) continue;
        dfs1( next, v );
        f[v] = max( f[v], ( f[next] == -1 ? -1 : f[next] + 1 ) );
    }
    if ( ok[v] ) f[v] = max( 0, f[v] );
}

void dfs2( int v, int p, int root )
{
    g[v] = root;
    vector< int > sons;
    sons.pb( ( root == -1 ? -1 : root + 1 ) );
    if ( ok[v] ) sons.pb( 1 );
    for ( int i = 0; i < graf[v].size(); i++ )
    {
        int next = graf[v][i]; if ( next == p ) continue;
        sons.pb( ( f[next] == -1 ? -1 : f[next] + 2 ) );
    }
    sort( sons.begin(), sons.end(), greater<int>() );
    for ( int i = 0; i < graf[v].size(); i++ )
    {
        int next = graf[v][i]; if ( next == p ) continue;
        int nroot = sons[1];
        if ( ( f[next] == -1 ? -1 : f[next] + 2 ) != sons[0] ) nroot = sons[0];
        dfs2( next, v, nroot );
    }
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d%d", &n, &m, &d);
    for ( int i = 1; i <= m; i++ )
    {
        int a; scanf("%d", &a);
        ok[a] = true;
    }
    for ( int i = 1; i < n; i++ )
    {
        int a, b; scanf("%d%d", &a, &b);
        graf[a].pb(b);
        graf[b].pb(a);
    }
    dfs1( 1, -1 );
    dfs2( 1, -1, -1 );
    int ans = 0;
    for ( int i = 1; i <= n; i++ ) if ( max( f[i], g[i] ) <= d ) ans++;
    //for ( int i = 1; i <= n; i++ ) cout << i << " " << f[i] << " " << g[i] << endl;
    cout << ans << endl;
    return 0;
}