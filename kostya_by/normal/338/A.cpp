//
//  main.cpp
//  task1
//
//  Created by Sokol Kostya's MacBook on 16.08.2013.
//  Copyright (c) 2013 Sokol Kostya's MacBook. All rights reserved.
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
#include <bitset>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;
const long long mod = 1000000009;

using namespace std;

long long pow1( long long p )
{
    if ( p == 0 ) return 1;
    long long a = pow1( p / 2 );
    a *= a;
    a %= mod;
    if ( p % 2 == 1 ) a = ( a + a ) % mod;
    return a;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    long long n, k, m;
    cin >> n >> m >> k;
    long long l = 0, r = n / k, res = mod;
    while ( l <= r )
    {
        long long x = (l + r) / 2;
        if ( m <= n - n / k + x )
        {
            res = min( res, x );
            r = x - 1;
        } else l = x + 1;
    }
    //cout << res << endl;
    long long pp = ( pow1( res + 1 ) - 2 + mod ) % mod;
    cout << ( k * pp + m - res * k ) % mod << endl;
    return 0;
}