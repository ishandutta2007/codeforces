//
//  main.cpp
//  string_conf
//
//  Created by Sokol Kostya's MacBook on 24.07.11.
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
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;
const long long mod = 1000006837;
const long long base = 379;

using namespace std;

int ll = 0, rr = 0;
long long pt[ 1000100 ];

struct hash_str
{
    int len;
    char s[ 1000100 ];
    long long pref[ 1000100 ], suff[ 1000100 ];
    hash_str()
    {
        len = 0;
        for ( int i = 0; i < 1000100; i++ )
        {
            s[i] = '\0';
            pref[i] = suff[i] = 0;
        }
    }
    void build_hash()
    {
        for ( int i = 1; i <= len; i++ )
        {
            long long c = s[i - 1];
            c *= pt[i];
            pref[i] = ( pref[i - 1] + c ) % mod;
        }
        for ( int i = len; i >= 1; i-- )
        {
            long long c = s[i - 1];
            c *= pt[len - i + 1];
            suff[i] = ( suff[i + 1] + c ) % mod;
        }
    }
    void init()
    {
        gets( s );
        len = strlen( s );
        build_hash();
    }
    void rev()
    {
        reverse( s, s + len );
        build_hash();
    }
    long long hash_pref( int l, int r )
    {
        long long res = ( pref[r] - pref[l - 1] + mod ) % mod;
        ( res *= pt[len - r] ) %= mod;
        return res;
    }
    long long hash_suff( int l, int r )
    {
        long long res = ( suff[l] - suff[r + 1] + mod ) % mod;
        ( res *= pt[l - 1] ) %= mod;
        return res;
    }
};

int mx[ 1000100 ];
int n;
hash_str a, b;

bool go( int l, int r )
{
    int x = l, z = n - r + 1;
    int y = n - x - z;
    if ( a.hash_pref( 1, x ) != b.hash_pref( 1, x ) ) return false;
    if ( a.hash_pref( l + 1, r - 1 ) != b.hash_suff( n - y + 1, n ) ) return false;
    if ( b.hash_pref( l + 1, l + z ) != a.hash_pref( r, n ) ) return false;
    return true;
}

int main (int argc, const char * argv[])
{
    //---------------------------------
    pt[0] = 1;
    for ( int i = 1; i < 1000100; i++ ) pt[i] = ( pt[i - 1] * base ) % mod;
    //---------------------------------
    a.init();
    b.init(); b.rev();
    n = a.len;
    if ( a.len != b.len )
    {
        cout << "-1 -1" << endl;
        return 0;
    }
    //---------------------------------
    for ( int i = 1; i <= n; i++ )
    {
        if ( a.s[n - 1] != b.s[i - 1] ) continue;
        int l = 2, r = i, res = 1;
        if ( a.hash_pref( n - r + 1, n ) == b.hash_pref( i - r + 1, i ) )
        {
            res = r;
            l = r + 1;
        }
        while ( l <= r )
        {
            int x = (l + r) / 2;
            if ( a.hash_pref( n - x + 1, n ) == b.hash_pref( i - x + 1, i ) )
            {
                res = max( res, x );
                l = x + 1;
            } else r = x - 1;
        }
        mx[ i - res ] = max( mx[ i - res ], i );
    }
    for ( int i = 1; i <= n; i++ ) mx[i] = max( mx[i - 1], mx[i] );
    //---------------------------------
    for ( int i = 1; i <= n; i++ )
    {
        if ( a.s[i - 1] != b.s[i - 1] ) break;
        if ( a.s[i] != b.s[n - 1] ) continue;
        if ( mx[i] < i + 1 ) continue;
        if ( a.hash_pref( i + 1, i + n - mx[i] ) == b.hash_suff( mx[i] + 1, n ) )
        {
            ll = i;
            rr = n;
        }
    }
    if ( ll > 0 )
    {
        for ( int ii = ll; ii <= rr; ii++ ) if ( go( ll, ii ) )
        {
            rr = ii;
            break;
        }
    }
    cout << ll - 1 << " " << rr - 1 << endl;
    return 0;
}