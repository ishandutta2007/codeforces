//
//  main.cpp
//  task2
//
//  Created by Sokol Kostya's MacBook on 14.08.11.
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

int n, ans = 0;
vector< int > sectors[ 1111 ], lines[ 1111 ];

int fun( int ii, int xx )
{
    if ( lines[ ii ].size() == 0 ) return 0;
    int res = 0;
    if ( lines[ ii ][ 0 ] > xx ) return 0;
    int ll = 1, rr = lines[ ii ].size() - 1;
    while ( ll <= rr )
    {
        int cur = (ll + rr) / 2;
        if ( lines[ ii ][ cur ] <= xx )
        {
            res = max( res, cur );
            ll = cur + 1;
        } else rr = cur - 1;
    }
    return res;
}

int between(int ii, int ll, int rr)
{
    return fun( ii, rr ) - fun( ii, ll );
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int k;
        scanf("%d", &k);
        vector< int > cur;
        for (int i = 0; i < k; i++)
        {
            int a;
            scanf("%d", &a);
            cur.pb( a );
        }
        sort( cur.begin(), cur.end() );
        sectors[ i ] = cur;
        int ii = i, jj = i + 1;
        if ( jj == n + 1 ) jj = 1;
        for (int j = 0; j < cur.size(); j++)
        {
            lines[ ii ].pb( cur[ j ] );
            lines[ jj ].pb( cur[ j ] ); 
        }
    }
    for (int i = 1; i <= n; i++) sort( lines[ i ].begin(), lines[ i ].end() );
    for (int i = 1; i <= n; i++)
    {
        int ii = i, jj = i + 1;
        if ( jj == n + 1 ) jj = 1;
        for ( int j = 1; j < sectors[ i ].size(); j++ )
        {
            int ll = sectors[ i ][ j - 1 ], rr = sectors[ i ][ j ];
            if ( between( ii, ll, rr ) != between( jj, ll, rr ) ) ++ans;
        }
    }
    cout << ans;
    return 0;
}