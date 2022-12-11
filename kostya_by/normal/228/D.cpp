//
//  main.cpp
//  zigzag
//
//  Created by Sokol Kostya's MacBook on 25.12.11.
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

struct summator
{
    long long a[ 100002 ];
    summator()
    {
        for ( int i = 0; i < 100002; i++ ) a[i] = 0;
    }
    void modify( int pos, long long val )
    {
        while ( pos < 100002 )
        {
            a[ pos ] += val;
            pos = 2 * pos - ( pos & (pos - 1) );
        }
    }
    long long fsum( int pos )
    {
        long long res = 0;
        while ( pos > 0 )
        {
            res += a[pos];
            pos = pos & (pos - 1);
        }
        return res;
    }
};

int n, m, num[ 7 ][ 11 ][ 100002 ], cc[ 7 ], bg[ 7 ][ 100002 ];
long long val[ 100002 ];
summator ss[ 7 ][ 11 ];

void modify( int pos, long long n )
{
    for ( int z = 2; z <= 6; z++ )
        for ( int s = 1; s <= cc[z]; s++ )
        {
            long long coef = num[z][s][pos];
            ss[z][s].modify( pos, coef * ( n - val[pos] ) );
        }
    val[pos] = n;
}

long long query( int l, int r, int z )
{
    int s = bg[z][l];
    return ss[z][s].fsum( r ) - ss[z][s].fsum( l - 1 );
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cc[ 2 ] = 2;
    cc[ 3 ] = 4;
    cc[ 4 ] = 6;
    cc[ 5 ] = 8;
    cc[ 6 ] = 10;
    scanf("%d", &n);
    for ( int z = 2; z <= 6; z++ )
    {
        for ( int i = 1; i <= n; i++ )
        {
            int val = i % ( z + z - 2 ); 
            if ( val == 0 ) num[z][1][i] = 2;
            if ( 0 < val && val <= z ) num[z][1][i] = val;
            if ( z < val ) num[z][1][i] = z + z - val;
        }
        for ( int s = 2; s <= cc[z]; s++ )
            for ( int i = 1; i <= n; i++ )
            {
                int ii = i - 1; if ( ii == 0 ) ii = n;
                num[z][s][i] = num[z][s - 1][ii];
            }
        for ( int i = 1; i <= cc[z]; i++ ) bg[z][i] = i;
        for ( int i = cc[z] + 1; i <= n; i++ ) bg[z][i] = bg[z][i - cc[z]];
    }
    for ( int i = 1; i <= n; i++ )
    {
        long long a;
        scanf("%I64d", &a);
        modify( i, a );
    }
    int t;
    scanf("%d", &t);
    for ( int q = 0; q < t; q++ )
    {
        int tp;
        scanf("%d", &tp);
        if ( tp == 1 )
        {
            int pos;
            long long cur;
            scanf("%d%I64d", &pos, &cur);
            modify( pos, cur );
        }
        if ( tp == 2 )
        {
            int l, r, z;
            scanf("%d%d%d", &l, &r, &z);
            printf("%I64d\n", query(l, r, z));
        }
    }
    return 0;
}