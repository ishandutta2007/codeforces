//
//  main.cpp
//  great_victory
//
//  Created by Sokol Kostya's MacBook on 25.08.11.
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

int n;
long long ans = 0, mx = 0, cur = 0;
vector< pair< int, long long > > graf[ 111111 ];

void dfs( int v, int prev )
{
    //cout << v << " " << prev << endl;
    mx = max( mx, cur );
    for ( int i = 0; i < graf[ v ].size(); i++ )
    {
        int next = graf[ v ][ i ].first;
        long long cost = graf[ v ][ i ].second;
        if ( next == prev ) continue;
        cur += cost;
        dfs( next, v );
        cur -= cost;
    }
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for ( int i = 1; i < n; i++ )
    {
        int a, b, c;
        scanf( "%d%d%d", &a, &b, &c );
        a--; b--;
        long long cc = c;
        ans += cc * 2;
        graf[ a ].pb( mp( b, cc ) );
        graf[ b ].pb( mp( a, cc ) );
    }
    dfs( 0, -1 );
    cout << ans - mx;
    return 0;
}