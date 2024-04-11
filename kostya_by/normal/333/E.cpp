//
//  main.cpp
//  cfE
//
//  Created by Sokol Kostya's MacBook on 28.07.11.
//  Copyright (c) 2013 Sokol Kostya's MacBook. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <bitset>
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

struct msk
{
    int a[ 100 ];
    msk()
    {
        for ( int i = 0; i < 100; i++ ) a[i] = 0;
    }
    void flip( int x )
    {
        a[ x / 30 ] ^= ( 1 << ( x % 30 ) );
    }
};

int need[ 100 ];
int n, x[ 3000 ], y[ 3000 ], ans = 0, h = 0, cnt[ 3000 ];
msk s[ 3000 ];
pair< int, int > p[ 4500000 ];

bool check( int a, int b )
{
    if ( cnt[a] + cnt[b] < n ) return true;
    for ( int i = 0; i < 100; i++ )
        if ( ( s[a].a[i] | s[b].a[i] ) != need[i] ) return true;
    return false;
}

int fun( pair< int, int > p )
{
    int dx = x[ p.first ] - x[ p.second ];
    int dy = y[ p.first ] - y[ p.second ];
    return dx * dx + dy * dy;
}

bool cmp( pair< int, int > a, pair< int, int > b )
{
    return fun( a ) < fun( b );
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    int nn = n;
    for ( int i = 0; i < 100; i++ ) need[i] = ( 1 << ( min( nn, 30 ) ) ) - 1, nn -= 30, nn = max( 0, nn );
    for ( int i = 0; i < n; i++ ) cin >> x[i] >> y[i], s[i].flip(i), cnt[i] = 1;
    for ( int i = 0; i < n; i++ )
        for ( int j = i + 1; j < n; j++ )
            p[h++] = make_pair( i, j );
    sort( p, p + h, cmp );
    for ( int i = 0; i < h; i++ )
    {
        int a = p[i].first;
        int b = p[i].second;
        if ( check( a, b ) ) ans = fun( p[i] );
        s[a].flip( b ); cnt[a]++;
        s[b].flip( a ); cnt[b]++;
    }
    long double pr = sqrt( ans );
    cout << fixed << setprecision(10) << 0.5 * pr << endl;
    return 0;
}