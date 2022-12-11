//
//  main.cpp
//  it-rest
//
//  Created by Sokol Kostya's MacBook on 21.07.11.
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

bool ans[ 5005 ], ff[ 2 ][ 5005 ];
int n, nd2, s[ 5005 ];
vector< int > graf[ 5005 ];
vector< pair< int, int > > res;

void dfs(int v,int p)
{
    vector< int > cur;
    s[ v ] = 1;
    for (int i = 0; i < graf[v].size(); i++)
    {
        int next = graf[v][i];
        if ( next == p ) continue;
        dfs( next, v );
        s[ v ] += s[ next ];
        cur.pb( s[ next ] );
    }
    if ( s[ v ] != n ) cur.pb( n - s[ v ] );
    if ( cur.size() == 1 ) return;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j <= nd2; j++)
            ff[i][j] = false;
    ff[0][0] = true;
    for (int i = 0; i < cur.size(); i++)
    {
       // cout << cur[i] << " ";
        for (int j = 0; j <= nd2; j++) if ( cur[i] <= j ) ff[1][j] = ( ff[1][j] | ff[0][ j - cur[i] ] );
        for (int j = 0; j <= nd2; j++) ff[0][j] = ( ff[0][j] | ff[1][j] );
    }
    /*cout << endl;
    for (int j = 0; j <= nd2; j++) cout << ff[1][j] << " ";
    cout << endl;
    cout << "-----------------" << endl;
     */
    for (int j = 0; j <= nd2; j++) if ( ff[1][j] == true ) ans[ j ] = true;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    nd2 = n / 2;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        graf[a].pb( b );
        graf[b].pb( a );
    }
    dfs( 0, -1 );
    for (int i = 1; i < n; i++)
    {
        if ( ans[i] == true ) ans[n - i - 1] = true, res.pb( mp( i, n - i - 1 ) );
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}