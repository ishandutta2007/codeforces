//
//  main.cpp
//  towers_cf_142
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

int n, a[ 5555 ], f[ 5555 ][ 5555 ];

int sum( int l, int r )
{
    if ( l > r ) return 0;
    return a[r] - a[l - 1];
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for ( int i = 0; i < 5555; i++ )
        for ( int j = 0; j < 5555; j++ )
            f[i][j] = 1000000000;
    f[0][0] = 0;
    cin >> n;
    for ( int i = 1; i <= n; i++ ) cin >> a[i], a[i] += a[i - 1];
    for ( int i = 1; i <= n; i++ )
    {
        int pnt1 = i, pnt2 = i - 1;
        while ( pnt1 != 0 )
        {
            if ( sum( pnt2, pnt1 - 1 ) > sum( pnt1, i ) )
            {
                --pnt1;
                --pnt2;
                continue;
            }
            while ( true )
            {
                if ( pnt2 == 0 ) break;
                --pnt2;
                if ( sum( pnt2, pnt1 - 1 ) <= sum( pnt1, i ) ) continue;
                ++pnt2;
                break;
            }
            f[i][pnt1] = min( f[i][pnt1], f[pnt1 - 1][pnt2] + i - pnt1 );
            --pnt1;
        }
        for ( int j = i - 1; j >= 0; j-- ) f[i][j] = min( f[i][j], f[i][j + 1] );
    }
    int ans = 1000000000;
    for ( int i = 1; i <= n; i++ ) ans = min( ans, f[n][i] );
    cout << ans;
    return 0;
}