//
//  main.cpp
//  task3_upsolving
//
//  Created by Sokol Kostya's MacBook on 16.09.11.
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

long long a[ 2222 ], ans[ 2222 ];
int n, k;

long long power( long long a, long long pow )
{
    if ( pow == 0 ) return 1;
    if ( pow % 2 == 1 )
    {
        long long cur = power( a, pow - 1 );
        cur *= a;
        cur %= mod;
        return cur;
    }
    long long cur = power( a, pow / 2 );
    cur *= cur;
    cur %= mod;
    return cur;
}

long long inv( long long a )
{
    return power( a, mod - 2 );
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k;
    for ( int i = 1; i <= n; i++ ) cin >> a[i];
    if ( k == 0 )
    {
        for ( int i = 1; i <= n; i++ ) cout << a[i] << " ";
        return 0;
    }
    --k;
    for ( int i = 1; i <= n; i++ )
    {
        long long cur = 1, diff = 0;
        for ( int j = i; j <= n; j++ )
        {
            ans[ j ] += ( cur * a[ i ] ) % mod;
            ans[ j ] %= mod;
            diff++;
            cur *= diff + k;
            cur %= mod;
            cur *= inv( diff );
            cur %= mod;
        }
    }
    
    for ( int i = 1; i <= n; i++ ) cout << ans[i] << " ";
    
    return 0;
}