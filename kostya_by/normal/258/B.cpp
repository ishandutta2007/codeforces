//
//  main.cpp
//  task2
//
//  Created by Sokol Kostya's MacBook on 22.12.11.
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
const long long mod = 1000000007;

using namespace std;

long long n, f[ 12 ][ 12 ][ 2 ], ans = 0, a[ 12 ], g[ 12 ], gg[ 12 ];
vector< long long > cur;

long long gun( int n, int num )
{
    long long res = 1, cur = g[n];
    for ( int i = 0; i < num; i++ )
    {
        res *= cur;
        res %= mod;
        cur = ( cur - 1 + mod ) % mod;
    }
    return res;
}

long long fun()
{
    for ( int i = 0; i < 12; i++ ) gg[i] = g[i];
    long long res = 1;
    for ( int i = 0; i < cur.size(); i++ )
    {
        res *= gg[ cur[i] ];
        res %= mod;
        gg[ cur[i] ] = ( gg[ cur[i] ] - 1 + mod ) % mod;
    }
    return res;
}

void rec( int pos, int num )
{
    if ( num > 12 ) return;
    if ( pos == 6 )
    {
        long long cur = fun();
        for ( int i = num + 1; i < 12; i++ ) 
        {
            ans += cur * g[i];
            ans %= mod;
        }
        return;
    }
    for ( int i = 0; i < 12; i++ )
    {
        cur.pb( i );
        rec( pos + 1, num + i );
        cur.pop_back();
    }
}

int main (int argc, const char * argv[])
{
    cin >> n;
    int h = 0;
    while ( n > 0 )
    {
        ++h;
        a[h] = n % 10;
        n /= 10;
    }
    reverse( a + 1, a + h + 1 );
    f[ 0 ][ 0 ][ 0 ] = 1;
    for ( int i = 0; i < h; i++ )
        for ( int j = 0; j < 12; j++ )
            for ( int k = 0; k < 2; k++ )
            {
                if ( f[i][j][k] == 0 ) continue;
                for ( int digit = 0; digit < 10; digit++ )
                {
                    int ii = i + 1;
                    int jj = j; if ( digit == 4 || digit == 7 ) ++jj;
                    int kk;
                    if ( k == 0 )
                    {
                        if ( digit > a[i + 1] ) continue;
                        if ( digit == a[i + 1] ) kk = 0;
                        if ( digit < a[i + 1] ) kk = 1;
                    }
                    if ( k == 1 ) kk = 1;
                    f[ii][jj][kk] += f[i][j][k];
                }
            }
    for ( int i = 0; i < 12; i++ )
    {
        g[ i ] = f[h][i][0] + f[h][i][1];
        //cout << g[i] << endl;
    }
    g[0]--;
    
    rec( 0, 0 );
    
    cout << ans << endl;
    return 0;
}