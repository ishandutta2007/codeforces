//
//  main.cpp
//  task3
//
//  Created by Sokol Kostya's MacBook on 01.02.11.
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

int n, m, a[ 200200 ], b[ 200200 ], ans[ 200200 ];
long long s[ 200200 ], c[ 200200 ], d[ 200200 ];
vector< int > graf[ 200200 ];
queue< int > q;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &m);
    for ( int i = 1; i <= m; i++ )
    {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        graf[ a[i] ].pb( i ); s[ a[i] ] += c[i];
        graf[ b[i] ].pb( i ); s[ b[i] ] += c[i];
        ans[i] = -1;
    }
    q.push( 1 );
    while ( q.size() != 0 )
    {
        int v = q.front(); q.pop();
        if ( v == n ) continue;
        for ( int i = 0; i < graf[v].size(); i++ )
        {
            int id = graf[v][i];
            if ( ans[id] != -1 ) continue;
            if ( a[id] == v ) ans[id] = 0; else ans[id] = 1;
            int next = v ^ a[id] ^ b[id];
            s[ next ] -= c[id];
            d[ next ] += c[id];
            if ( s[next] == d[next] ) q.push( next );
        }
    }
    for ( int i = 1; i <= m; i++ ) printf("%d\n", ans[i]);
    return 0;
}