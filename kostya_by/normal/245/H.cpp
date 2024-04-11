//
//  main.cpp
//  palin_cf
//
//  Created by Sokol Kostya's MacBook on 19.11.11.
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

char s[ 5005 ];
int n;
int f[ 5005 ][ 5005 ];

int fun( int l, int r )
{
    if ( f[l][r] != -1 ) return f[l][r];
    if ( l == r )
    {
        f[l][r] = 1;
        return 1;
    }
    if ( l + 1 == r )
    {
        f[l][r] = 0;
        if ( s[l - 1] == s[r - 1] ) f[l][r] = 1;
        return f[l][r];
    }
    f[l][r] = 0;
    if ( s[l - 1] == s[r - 1] && fun( l + 1, r - 1 ) == 1 ) f[l][r] = 1;
    return f[l][r];
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    gets( s ); n = strlen( s );
    for ( int i = 1; i <= n; i++ )
        for ( int j = i; j <= n; j++ )
            f[i][j] = -1;
    for ( int i = 1; i <= n; i++ )
    {
        for ( int j = i; j <= n; j++ )
        {
            fun( i, j );
        }
    }
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= n; j++ )
        {
            f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
        }
    int q;
    scanf("%d", &q);
    for ( int it = 1; it <= q; it++ )
    {
        int l, r;
        scanf("%d%d", &l, &r);
        int ans = f[r][r] - f[l - 1][r] - f[r][l - 1] + f[l - 1][l - 1];
        printf("%d\n", ans);
    }
    return 0;
}