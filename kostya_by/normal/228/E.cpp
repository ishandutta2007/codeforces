//
//  main.cpp
//  berland_roads
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

int n, m, dd[ 111 ];
vector< pair<int, int> > graf[ 111 ];
vector< int > ans;
bool used[ 111 ];

void wa(int a, int b)
{
    //cout << a + 1 << " " << b + 1 << endl;
    cout << "Impossible";
    exit( 0 );
}

void dfs( int v )
{
    if ( dd[v] == 0 ) ans.pb( v + 1 );
    used[v] = true;
    for ( int i = 0; i < graf[v].size(); i++ )
    {
        int next = graf[v][i].first;
        int val = graf[v][i].second;
        if ( used[next] == false )
        {
            if ( val == 1 ) dd[next] = dd[v];
            if ( val == 0 ) dd[next] = dd[v] ^ 1;
            dfs( next );  
        } else 
        {
            if ( dd[v] == dd[next] ) if ( val == 0 ) wa(v, next);
            if ( dd[v] != dd[next] ) if ( val == 1 ) wa(v, next);
        }
    }
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for ( int i = 0; i < m; i++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        graf[a].pb( mp( b, c ) );
        graf[b].pb( mp( a, c ) );
    }
    for ( int i = 0; i < n; i++ ) dd[i] = -1;
    for ( int i = 0; i < n; i++ ) if ( used[i] == false ) dd[i] = 0, dfs( i );
    cout << ans.size() << endl;
    for ( int i = 0; i < ans.size(); i++ ) cout << ans[i] << " ";
    return 0;
}