//
//  main.cpp
//  task3
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

int n, a[ 111111 ];
vector< int > cur;
long long ans = 0, aa;

long long binpow( int pow )
{
    if ( pow == 0 ) return 1;
    if ( pow % 2 == 0 )
    {
        long long cur = binpow( pow / 2 );
        cur *= cur;
        cur %= mod;
        return cur;
    }
    long long cur = binpow( pow - 1 );
    cur *= aa;
    cur %= mod;
    return cur;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int mx = 1;
    scanf("%d", &n); for ( int i = 1; i <= n; i++ ) scanf("%d", &a[i]), mx = max( mx, a[i] );
    sort( a + 1, a + n + 1 );
    for ( int i = 1; i <= mx; i++ )
    {
        cur.clear();
        for ( int j = 1; j * j <= i; j++ )
        {
            if ( i % j != 0 ) continue;
            cur.pb( j );
            if ( j != i / j ) cur.pb( i / j );
        }
        sort( cur.begin(), cur.end() );
        int id = 1;
        long long now = 1;
        for ( int j = 0; j < cur.size(); j++ )
        {
            if ( j + 1 < cur.size() ) 
            {
                if ( a[id] >= cur[j + 1] ) continue;
            }
            int res = id;
            if ( j + 1 < cur.size() )
            {
                int ll = id + 1, rr = n;
                while ( ll <= rr )
                {
                    int xx = ( ll + rr ) / 2;
                    if ( a[xx] < cur[j + 1] ) 
                    {
                        res = max( res, xx );
                        ll = xx + 1;
                    } else rr = xx - 1;
                }
            } else res = n;
            int ll = id;
            int rr = res;
            int xx = j + 1;
            if ( rr != n )
            {
                aa = xx;
                now *= binpow( rr - ll + 1 );
                now %= mod;
                id = rr + 1;
                continue;
            }
            aa = xx;
            long long tmp = binpow( rr - ll + 1 );
            aa = xx - 1;
            tmp = ( tmp - binpow( rr - ll + 1 ) + mod ) % mod;
            now *= tmp;
            now %= mod;
            id = rr + 1;
        }
        ans += now;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}