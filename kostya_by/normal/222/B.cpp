//
//  main.cpp
//  cf_easy_2
//
//  Created by Sokol Kostya's MacBook on 10.09.11.
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

int a[ 1111 ][ 1111 ], n, m, k, x, y, num_c[ 1111 ], num_r[ 1111 ];
char c;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d%d", &n, &m, &k);
    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < m; j++ )
            scanf("%d", &a[i][j]);
    for ( int i = 0; i < n; i++ ) num_r[ i ] = i;
    for ( int i = 0; i < m; i++ ) num_c[ i ] = i;
    for ( int i = 0; i < k; i++ )
    {
        scanf("\n");
        scanf("%c%d%d", &c, &x, &y);
        --x; --y;
        if ( c == 'r' ) swap( num_r[x], num_r[y] );
        if ( c == 'c' ) swap( num_c[x], num_c[y] );
        if ( c == 'g' ) printf("%d\n", a[ num_r[x] ][ num_c[y] ]);
    }
    return 0;
}