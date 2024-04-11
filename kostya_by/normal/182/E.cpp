//
//  main.cpp
//  wooden fence
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
const int mod = 1000000007;

using namespace std;

int f[ 3333 ][ 101 ][ 2 ], a[ 111 ], b[ 111 ], n, len;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> len;
    for ( int i = 1; i <= n; i++ )
    {
        cin >> a[i] >> b[i];
        f[ a[i] ][ i ][ 0 ]++;
        if ( a[i] != b[i] ) f[ b[i] ][ i ][ 1 ]++; 
    }
    for ( int i = 0; i <= len; i++ )
        for ( int j = 1; j <= n; j++ )
        {
            if ( f[i][j][0] != 0 )
            {
                for ( int k = 1; k <= n; k++ )
                {
                    if ( k == j ) continue;
                    if ( a[k] == b[j] )
                    {
                        f[ i + a[k] ][ k ][ 0 ] += f[i][j][0];
                        f[ i + a[k] ][ k ][ 0 ] %= mod;
                    }
                    if ( b[k] == b[j] && a[k] != b[k] )
                    {
                        f[ i + b[k] ][ k ][ 1 ] += f[i][j][0];
                        f[ i + b[k] ][ k ][ 1 ] %= mod;
                    }
                }
            }
            if ( f[i][j][1] != 0 )
            {
                for ( int k = 1; k <= n; k++ )
                {
                    if ( k == j ) continue;
                    if ( a[k] == a[j] )
                    {
                        f[ i + a[k] ][ k ][ 0 ] += f[i][j][1];
                        f[ i + a[k] ][ k ][ 0 ] %= mod;
                    }
                    if ( b[k] == a[j] && a[k] != b[k] )
                    {
                        f[ i + b[k] ][ k ][ 1 ] += f[i][j][1];
                        f[ i + b[k] ][ k ][ 1 ] %= mod;
                    }
                }
            }
        }
    int ans = 0;
    for ( int i = 1; i <= n; i++ )
    {
        ans += (f[len][i][0] + f[len][i][1]) % mod;
        ans %= mod;
    }
    cout << ans;
    return 0;
}