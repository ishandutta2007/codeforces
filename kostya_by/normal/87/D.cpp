//
//  main.cpp
//  beautiful road
//
//  Created by Sokol Kostya's MacBook on 03.10.11.
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

struct edge
{
    int v1, v2, c, id;
    edge()
    {
        edge(0, 0, 0, 0);
    }
    edge( int a, int b, int z, int ii )
    {
        v1 = a;
        v2 = b;
        c = z;
        id = ii;
    }
};

long long ans[ 111111 ], mx = 0;
int n, p[ 111111 ], lst[ 111111 ], val[ 111111 ], h, tt[ 111111 ], iii, hh[ 111111 ], cur_h;
vector< edge > e, cls[ 111111 ];
vector< int > sets[ 111111 ];
map<int, int> mm;
set<int> ss;
int fun[ 111111 ], pr[ 111111 ], num[ 111111 ];
vector< pair<int,int> > graf[ 111111 ];
vector< int > res;

void unite( int id1, int id2 )
{
    if ( sets[id1].size() > sets[id2].size() ) swap( id1, id2 );
    while ( sets[id1].size() != 0 )
    {
        int cur = sets[id1].back();
        sets[id1].pop_back();
        p[cur] = id2;
        sets[id2].pb(cur);
    }
}

int get_num( int id, int it )
{
    if ( lst[id] == it ) return val[id];
    lst[id] = it;
    val[id] = h++;
    num[ val[id] ] = sets[id].size();
    return val[id];
}

void dfs( int v )
{
    hh[v] = cur_h;
    tt[v] = iii;
    fun[v] = num[v];
    for ( int i = 0; i < graf[v].size(); i++ )
    {
        int next = graf[v][i].first;
        int ee = graf[v][i].second;
        if ( tt[next] == iii ) continue;
        dfs( next );
        pr[ next ] = ee;
        fun[v] += fun[next];
    }
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for ( int i = 1; i < n; i++ )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        --a; --b;
        e.pb( edge( a, b, c, i ) );
        ss.insert( c );
    }
    int pnt = 0;
    for ( set<int>::iterator it = ss.begin(); it != ss.end(); it++ ) mm[ *it ] = pnt++;
    for ( int i = 0; i < e.size(); i++ )
    {
        int cmp_id = mm[ e[i].c ];
        cls[ cmp_id ].pb( e[i] );
    }
    for ( int i = 0; i < n; i++ ) p[i] = i, sets[i].pb(i);
    for ( int i = 0; i < n; i++ ) lst[i] = -1, val[i] = 0, tt[i] = -1;
    for ( int it = 0;;it++ )
    {
        iii = it;
        if ( cls[it].size() == 0 ) break;
        h = 0;
        for ( int i = 0; i < cls[it].size(); i++ )
        {
            int a = get_num( p[cls[it][i].v1], it );
            int b = get_num( p[cls[it][i].v2], it );
            graf[a].pb( mp(b, cls[it][i].id) );
            graf[b].pb( mp(a, cls[it][i].id) );
        }
        for ( int i = 0; i < h; i++ )
        {
            if ( tt[i] != iii ) 
            {
                cur_h = i;
                dfs( i );
            }
        }
        for ( int i = 0; i < h; i++ )
        {
            if ( hh[i] == i ) continue;
            int cur_id = pr[ i ];
            long long a = fun[i];
            long long b = fun[ hh[i] ] - fun[i];
            ans[ cur_id ] = a * b * 2;
            if ( ans[ cur_id ] > mx )
            {
                mx = ans[ cur_id ];
                res.clear();
            }
            if ( ans[ cur_id ] == mx )
            {
                res.pb( cur_id );
            }
        }
        for ( int i = 0; i < h; i++ ) graf[i].clear();
        for ( int i = 0; i < cls[it].size(); i++ )
        {
            int a = p[ cls[it][i].v1 ];
            int b = p[ cls[it][i].v2 ];
            unite( a, b );
        }
    }
    sort( res.begin(), res.end() );
    cout << mx << " " << res.size() << endl;
    for ( int i = 0; i < res.size(); i++ ) printf("%d ", res[i]);
    return 0;
}