//
//  main.cpp
//  planets_cf_142
//
//  Created by Sokol Kostya's MacBook on 01.10.11.
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

set< pair< int, int > > s;
set< int > tt[ 111111 ];
int n, m, dist[ 111111 ], p[ 111111 ];
vector< pair<int, int> > graf[ 111111 ];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &m);
    for ( int i = 0; i < m; i++ )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        --a; --b;
        graf[a].pb( mp( b, c ) );
        graf[b].pb( mp( a, c ) );
    }
    for ( int i = 0; i < n; i++ )
    {
        int k;
        scanf("%d", &k);
        for ( int j = 0; j < k; j++ )
        {
            int a;
            scanf("%d", &a);
            tt[i].insert( a );
        }
    }
    
    for ( int i = 0; i < n; i++ ) dist[i] = 2000000000;
    dist[0] = 0;
    for ( int i = 0; i < n; i++ ) s.insert( mp( dist[i], i ) );
    
    while ( s.size() != 0 )
    {
        
        pair<int, int> cur = *s.begin(); s.erase( s.begin() );
        int v = cur.second;
        p[v] = dist[v]; 
        if ( v == n - 1 )
        {
            if ( cur.first == 2000000000 ) dist[v] = -1;
            cout << dist[ v ];
            return 0;
        }
        while ( tt[v].find( p[v] ) != tt[v].end() ) ++p[v];
        for ( int i = 0; i < graf[v].size(); i++ )
        {
            int next = graf[v][i].first;
            int val = graf[v][i].second;
            if ( p[v] + val < dist[next] )
            {
                s.erase( mp( dist[next], next ) );
                dist[next] = p[v] + val;
                s.insert( mp( dist[next], next ) );
            }
        }
    }
    return 0;
}