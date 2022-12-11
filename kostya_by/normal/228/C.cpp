//
//  main.cpp
//  fractals_detector
//
//  Created by Sokol Kostya's MacBook on 03.10.11.
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

int ff[ 505 ][ 505 ][ 10 ][ 2 ][ 2 ][ 2 ][ 2 ], sum[ 505 ][ 505 ], n, m, a[ 505 ][ 505 ];
char st[ 505 ];

int fsum( int i1, int j1, int i2, int j2 )
{
    return sum[i2][j2] - sum[i1 - 1][j2] - sum[i2][j1 - 1] + sum[i1 - 1][j1 - 1];
}

int black( int i1, int j1, int i2, int j2 )
{
    return ( ( i2 - i1 + 1 ) * ( j2 - j1 + 1 ) == fsum( i1, j1, i2, j2 ) );
}

int white( int i1, int j1, int i2, int j2 )
{
    return ( 0 == fsum( i1, j1, i2, j2 ) );
}

int fun( int i, int j, int k, int l00, int l01, int l10, int l11 )
{
    if ( ff[i][j][k][l00][l01][l10][l11] != -1 ) return ff[i][j][k][l00][l01][l10][l11];
    int l[4] = {l00, l01, l10, l11};
    int nn = 1 << k;
    int ii2 = i + nn - 1;
    int jj2 = j + nn - 1;
    if ( ii2 > n || jj2 > m )
    {
        ff[i][j][k][l00][l01][l10][l11] = 0;
        return 0;
    }
    int res = 1;
    if ( k == 1 )
    {
        if ( a[i][j] != l[0] ) res = 0;
        if ( a[i][j + 1] != l[1] ) res = 0;
        if ( a[i + 1][j] != l[2] ) res = 0;
        if ( a[i + 1][j + 1] != l[3] ) res = 0;
        ff[i][j][k][l00][l01][l10][l11] = res;
        return res;
    }
    int i1[ 4 ], j1[ 4 ];
    nn /= 2;
    i1[ 0 ] = i;      j1[ 0 ] = j;      
    i1[ 1 ] = i;      j1[ 1 ] = j + nn; 
    i1[ 2 ] = i + nn; j1[ 2 ] = j;      
    i1[ 3 ] = i + nn; j1[ 3 ] = j + nn; 
    for ( int it = 0; it < 4; it++ )
    {
        if ( l[it] == 1 )
        {
            if ( black( i1[it], j1[it], i1[it] + nn - 1, j1[it] + nn - 1 ) == 0 ) res = 0;  
        } else res = min( res, fun( i1[it], j1[it], k - 1, l00, l01, l10, l11 ) ); 
    }
    ff[i][j][k][l00][l01][l10][l11] = res;
    return res;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for ( int i = 0; i < 505; i++ )
        for ( int j = 0; j < 505; j++ )
            for ( int k = 0; k < 10; k++ )
                for ( int l00 = 0; l00 < 2; l00++ )
                    for ( int l01 = 0; l01 < 2; l01++ )
                        for ( int l10 = 0; l10 < 2; l10++ )
                            for ( int l11 = 0; l11 < 2; l11++ )
                                ff[i][j][k][l00][l01][l10][l11] = -1;
    scanf("%d%d\n", &n, &m);
    for ( int i = 1; i <= n; i++ )
    {
        gets( st );
        for ( int j = 0; j < m; j++ )
        {
            if ( st[j] == '*' ) a[i][j + 1] = 1;
        }
    }
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    
    int ans = 0;
    
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            for ( int k = 2; k < 10; k++ )
                for ( int l00 = 0; l00 < 2; l00++ )
                    for ( int l01 = 0; l01 < 2; l01++ )
                        for ( int l10 = 0; l10 < 2; l10++ )
                            for ( int l11 = 0; l11 < 2; l11++ )
                                ans += fun( i, j, k, l00, l01, l10, l11 );
    
    cout << ans;
    
    return 0;
}