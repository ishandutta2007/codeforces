//
//  main.cpp
//  shifts
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

int n, m, ll[ 111 ][ 11111 ], rr[ 111 ][ 11111 ], mn[ 111 ], mx[ 111 ];
char st[ 111 ][ 11111 ];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d\n", &n, &m);
    for ( int i = 0; i < n; i++ ) gets( st[i] );
    for ( int i = 0; i < n; i++ )
    {
        mn[i] = 111111; mx[i] = -1;
        for ( int j = 0; j < m; j++ )
        {
            if ( st[i][j] == '1' )
            {
                mn[i] = min( mn[i], j );
                mx[i] = max( mx[i], j );
            }
        }
        if ( mx[i] == -1 )
        {
            cout << -1;
            return 0;
        }
        if ( st[i][0] == '1' ) ll[i][0] = 0; else ll[i][0] = m - mx[i];
        for ( int j = 1; j < m; j++ ) if ( st[i][j] == '1' ) ll[i][j] = 0; else ll[i][j] = ll[i][j - 1] + 1;
        if ( st[i][m - 1] == '1' ) rr[i][m - 1] = 0; else rr[i][m - 1] = mn[i] + 1;
        for ( int j = m - 2; j >= 0; j-- ) if ( st[i][j] == '1' ) rr[i][j] = 0; else rr[i][j] = rr[i][j + 1] + 1;
    }
    int ans = 1000000000;
    for ( int j = 0; j < m; j++ )
    {
        int cur = 0;
        for ( int i = 0; i < n; i++ ) cur += min( ll[i][j], rr[i][j] );
        ans = min( ans, cur );
    }
    cout << ans;
    return 0;
}