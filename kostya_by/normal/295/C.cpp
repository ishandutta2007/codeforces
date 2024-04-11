//
//  main.cpp
//  taskC_friends
//
//  Created by Sokol Kostya's MacBook on 11.04.11.
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
const long long mod = 1000000007;

using namespace std;

int c[ 55 ][ 55 ];
long long f[ 55 ][ 55 ][ 2 ], g[ 55 ][ 55 ][ 2 ];
int nn, n, m, lim;

void upd( long long &a, long long b )
{
    if ( a == -1 ) a = b; else a = ( a + b ) % mod;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> nn >> lim;
    for ( int i = 0; i < nn; i++ )
    {
        int a; cin >> a;
        if ( a == 50 ) n++; else m++;
    }
    c[0][0] = 1;
    for ( int i = 1; i <= 50; i++ )
        for ( int j = 0; j <= i; j++ )
        {
            c[i][j] = c[i - 1][j];
            if ( j != 0 ) c[i][j] += c[i - 1][j - 1];
            c[i][j] %= mod;
        }
    for ( int i = 0; i <= n; i++ )
        for ( int j = 0; j <= m; j++ )
            for ( int k = 0; k < 2; k++ )
                f[i][j][k] = -1;
    f[n][m][0] = 1;
    for ( int it = 0; it < 1111; it++ )
    {
        for ( int i = 0; i <= n; i++ )
            for ( int j = 0; j <= m; j++ )
                for ( int k = 0; k < 2; k++ )
                    g[i][j][k] = -1;
        for ( int i = 0; i <= n; i++ )
            for ( int j = 0; j <= m; j++ )
                for ( int k = 0; k < 2; k++ )
                {
                    if ( f[i][j][k] == -1 ) continue;
                    int ii = n - i, jj = m - j;
                    if ( k == 0 )
                    {
                        for ( int i1 = 0; i1 <= i; i1++ )
                            for ( int j1 = 0; j1 <= j; j1++ )
                            {
                                if ( i1 + j1 == 0 ) continue;
                                if ( i1 * 50 + j1 * 100 > lim ) break;
                                long long m1 = c[i][i1], m2 = c[j][j1];
                                long long pls = f[i][j][k] * m1;
                                pls %= mod;
                                pls *= m2;
                                pls %= mod;
                                upd( g[i - i1][j - j1][1], pls );
                            }
                    }
                    if ( k == 1 )
                    {
                        for ( int i1 = 0; i1 <= ii; i1++ )
                            for ( int j1 = 0; j1 <= jj; j1++ )
                            {
                                if ( i1 + j1 == 0 ) continue;
                                if ( i1 * 50 + j1 * 100 > lim ) break;
                                long long m1 = c[ii][i1], m2 = c[jj][j1];
                                long long pls = f[i][j][k] * m1;
                                pls %= mod;
                                pls *= m2;
                                pls %= mod;
                                upd( g[i + i1][j + j1][0], pls );
                            }
                    }
                }
        if ( g[0][0][1] != -1 )
        {
            cout << it + 1 << endl << g[0][0][1] << endl;
            return 0;
        }
        for ( int i = 0; i <= n; i++ )
            for ( int j = 0; j <= m; j++ )
                for ( int k = 0; k < 2; k++ )
                    f[i][j][k] = g[i][j][k];
    }
    cout << -1 << endl << 0 << endl;
    return 0;
}