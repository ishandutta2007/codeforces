//
//  main.cpp
//  cf157taskE
//
//  Created by Sokol Kostya's MacBook on 02.01.11.
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
const int maxn = 100010;

using namespace std;

struct tv
{
    int l, r, sum, pls, def;
};

tv tree[ 2000000 ];
int n, m, pref[ 300000 ], tin[ 300000 ], tout[ 300000 ], timer = 1, c[ 300000 ];
vector< int > graf[ 300000 ], query[ 300000 ];

void dfs( int v, int p )
{
    tin[v] = timer++;
    pref[ tin[v] ] = 1;
    for ( int i = 0; i < graf[v].size(); i++ )
    {
        int next = graf[v][i];
        if ( next == p ) continue;
        dfs( next, v );
    }
    tout[v] = timer++;
}

void init( int id, int l, int r )
{
    tree[id].l = l;
    tree[id].r = r;
    tree[id].sum = 0;
    tree[id].pls = 0;
    tree[id].def = pref[r] - pref[l - 1];
    if ( l == r ) return;
    int x = (l + r) / 2;
    init( id + id, l, x );
    init( id + id + 1, x + 1, r );
}

int fsum()
{
    return tree[1].sum;
}

void modify( int id, int l, int r, int pls )
{
    int ll = tree[id].l;
    int rr = tree[id].r;
    if ( ll == l && r == rr )
    {
        tree[id].pls += pls;
        if ( tree[id].pls == 0 )
            tree[id].sum = tree[id + id].sum + tree[id + id + 1].sum;
                else tree[id].sum = tree[id].def;
        if ( tree[id].def < 0 ) exit( 5 );
        return;
    }
    int xx = ( ll + rr ) / 2;
    if ( l <= xx ) modify( id + id, l, min( xx, r ), pls );
    if ( xx + 1 <= r ) modify( id + id + 1, max( xx + 1, l ), r, pls );
    if ( tree[id].pls == 0 )
        tree[id].sum = tree[id + id].sum + tree[id + id + 1].sum;
            else tree[id].sum = tree[id].def;
}

void solve( int v, int p )
{
    for ( int i = 0; i < query[v].size(); i++ )
    {
        int vs = query[v][i];
        modify( 1, tin[vs], tout[vs], 1 );
    }
    c[v] = fsum();
    if ( c[v] == 0 ) c[v] = 1;
    for ( int i = 0; i < graf[v].size(); i++ )
    {
        int next = graf[v][i];
        if ( next == p ) continue;
        solve( next, v );
    }
    for ( int i = 0; i < query[v].size(); i++ )
    {
        int vs = query[v][i];
        modify( 1, tin[vs], tout[vs], -1 );
    }
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &m);
    for ( int i = 1; i < n; i++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        graf[a].pb( b );
        graf[b].pb( a );
    }
    dfs( 1, 0 );
    for ( int i = 1; i < 300000; i++ ) pref[i] += pref[i - 1];
    init( 1, 1, timer - 1 );
    for ( int it = 0; it < m; it++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        query[a].pb( a ); query[a].pb( b );
        query[b].pb( a ); query[b].pb( b );
    }
    solve( 1, 0 );
    for ( int i = 1; i <= n; i++ ) printf("%d ", c[i] - 1);
    return 0;
}