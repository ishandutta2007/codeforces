//
//  main.cpp
//  cf_lights
//
//  Created by Sokol Kostya's MacBook on 07.04.11.
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

long long ans = 1;
bool used[ 1111 ];
int n, m;
long long nn;

long long bpow( long long a, long long p )
{
    if ( p == 1 ) return a;
    if ( p % 2 == 0 )
    {
        long long res = bpow( a, p / 2 );
        return ( res * res ) % mod;
    }
    long long res = bpow( a, p - 1 );
    return ( res * a ) % mod;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m; nn = n;
    for ( int i = 0; i < m; i++ )
    {
        int x; cin >> x;
        used[x] = true;
        nn--;
    }
    while ( nn > 0 ) 
    {
        ans *= nn;
        ans %= mod;
        nn--;
    }
    for ( int i = 1; i <= n; i++ )
    {
        if ( !used[i + 1] && i < n ) continue;
        if ( used[i] ) continue;
        int j = i;
        while ( true )
        {
            if ( used[j - 1] ) break;
            if ( j == 1 ) break;
            --j;
        }
        if ( used[j - 1] && used[i + 1] )
        {
            int len = i - j;
            for ( int it = 0; it < len; it++ ) ans += ans, ans %= mod;
        }
        int len = i - j + 1;
        long long fc = 1;
        for ( int it = 1; it <= len; it++ ) fc *= it, fc %= mod;
        //cout << len << " " << fc << endl;
        ans *= bpow( fc, mod - 2 );
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}