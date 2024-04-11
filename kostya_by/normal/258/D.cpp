//
//  main.cpp
//  cf157_upsolving
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

using namespace std;

int n, m, a[ 1111 ];
double f[ 1111 ][ 1111 ], g[ 1111 ];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &m);
    for ( int i = 1; i <= n; i++ ) scanf("%d", &a[i]);
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= n; j++ )
            if ( a[i] > a[j] ) f[i][j] = 1.0;
    for ( int it = 0; it < m; it++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        for ( int i = 1; i <= n; i++ )
        {
            if ( i == a || i == b ) continue;
            g[i] = 0.5 * ( f[i][a] + f[i][b] );
        }
        for ( int i = 1; i <= n; i++ )
        {
            if ( i == a || i == b ) continue;
            f[i][a] = f[i][b] = g[i];
            f[a][i] = f[b][i] = 1.0 - g[i];
        }
        f[a][b] = f[b][a] = 0.5;
    }
    double ans = 0;
    for ( int i = 1; i <= n; i++ )
        for ( int j = i + 1; j <= n; j++ )
            ans += f[i][j];
    cout << fixed << setprecision( 7 ) << ans << endl;
    return 0;
}