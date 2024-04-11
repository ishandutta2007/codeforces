//
//  main.cpp
//  task2
//
//  Created by Sokol Kostya's MacBook on 13.01.11.
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

int n, p, a[ 55 ];
long double f[ 55 ][ 55 ][ 55 ];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for ( int i = 1; i <= n; i++ ) cin >> a[i];
    cin >> p;
    f[0][0][0] = 1.0;
    for ( int i = 1; i <= n; i++ )
        for ( int j = 0; j <= i; j++ )
            for ( int k = 0; k <= p; k++ )
            {
                long double ii = i - j;
                long double jj = j;
                long double kk = i;
                f[i][j][k] = f[i - 1][j][k] * ii / kk;
                if ( j == 0 ) continue;
                if ( k - a[i] < 0 ) continue;
                f[i][j][k] += f[i - 1][j - 1][k - a[i]] * jj / kk;
            }
    long double ans = 0;
    for ( int i = 1; i <= n; i++ )
        for ( int j = 0; j <= p; j++ )
            ans += f[n][i][j];
    cout << fixed << setprecision( 10 ) << ans << endl;
    return 0;
}