//
//  main.cpp
//  cf_greedy
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

using namespace std;

int n, p, k;
long long a[ 100100 ], b[ 100100 ], sa = 0;
long long f[ 100100 ], g[ 100100 ];
int v[ 100100 ];
multiset< long long > s;

bool cmp( int i, int j )
{
    return mp( -b[i], a[i] ) < mp( -b[j], a[j] );
}

bool cmp1( int i, int j )
{
    return a[i] > a[j];
}

bool cmp2( int i, int j )
{
    return b[i] > b[j];
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> p >> k; p -= k;
    for ( int i = 1; i <= n; i++ )
    {
        v[i] = i; cin >> a[i] >> b[i];
    }
    sort( v + 1, v + n + 1, cmp );
    for ( int i = 1; i <= n; i++ )
    {
        if ( s.size() < k )
        {
            sa += a[ v[i] ];
            s.insert( a[ v[i] ] );
        } else if ( s.size() && a[ v[i] ] > *s.begin() )
        {
            sa -= *s.begin();
            s.erase( s.begin() );
            sa += a[ v[i] ];
            s.insert( a[ v[i] ] );
        }
        f[i] = sa;
    }
    s.clear(); sa = 0;
    for ( int i = n; i >= 1; i-- )
    {
        if ( s.size() < p )
        {
            sa += b[ v[i] ];
            s.insert( b[ v[i] ] );
        } else if ( s.size() && b[ v[i] ] > *s.begin() )
        {
            sa -= *s.begin();
            s.erase( s.begin() );
            sa += b[ v[i] ];
            s.insert( b[ v[i] ] );
        }
        g[i] = sa;
    }
    int ii = k;
    pair< long long, long long > pp( -1, -1 );
    for ( int i = k; i <= n; i++ )
    {
        int left = n - i;
        if ( left < p ) break;
        pair< long long, long long > cur( f[i], g[i + 1] );
        if ( pp < cur )
        {
            ii = i;
            pp = cur;
        }
    }
    sort( v + 1, v + ii + 1, cmp1 );
    sort( v + ii + 1, v + n + 1, cmp2 );
    for ( int i = 1; i <= k; i++ ) cout << v[i] << " ";
    for ( int i = ii + 1; i <= ii + p; i++ ) cout << v[i] << " ";
    return 0;
}