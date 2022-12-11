//
//  main.cpp
//  task4
//
//  Created by Sokol Kostya's MacBook on 24.09.11.
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

using namespace std;

struct matrix
{
    long long a[ 2 ][ 2 ];
    matrix()
    {
        for ( int i = 0; i < 2; i++ )
            for ( int j = 0; j < 2; j++ ) a[i][j] = 0;
    }
};

long long m, l, r, k, best = 1;
vector< long long > event;
matrix mm;

matrix operator*( matrix m1, matrix m2 )
{
    matrix res;
    for ( int i = 0; i < 2; i++ )
        for ( int j = 0; j < 2; j++ )
            for ( int k = 0; k < 2; k++ )
                res.a[i][j] += m1.a[i][k] * m2.a[k][j], res.a[i][j] %= m;
    return res;
}

matrix bin( matrix m, long long pow )
{
    if ( pow == 1 ) return m;
    if ( pow % 2 == 0 )
    {
        matrix mmm = bin( m, pow / 2 );
        mmm = mmm * mmm;
        return mmm;
    }
    matrix mmm = bin( m, pow - 1 );
    mmm = mmm * m;
    return mmm;
}


void check( long long x )
{
    if ( x <= 0 ) return;
    long long val = r / x - l / x;
    if ( val >= k ) best = max(x, best);
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> m >> l >> r >> k;
    l--;
    for ( int i = 1; i <= 10000000; i++ ) check( i ), check( r / i ), check( l / i );
    if ( best == 1 || best == 2 )
    {
        cout << 1 % m;
        return 0;
    }

    mm.a[0][0] = 0; mm.a[0][1] = 1;
    mm.a[1][0] = 1; mm.a[1][1] = 1;
    matrix cur = bin( mm, best - 2 );
    long long res = cur.a[0][1] + cur.a[1][1];
    res %= m;
    cout << res;
    return 0;
}