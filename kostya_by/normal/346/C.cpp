//
//  main.cpp
//  convent_num
//
//  Created by Sokol Kostya's MacBook on 20.09.2013.
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
#include <bitset>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, a, b, num[ 100100 ];
int f[ 1000001 ], fw[ 1000001 ], mx[ 1000001 ];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for ( int i = 0; i < n; i++ ) scanf("%d", &num[i]);
    scanf("%d%d", &b, &a);
    sort( num, num + n );
    int lim = b - a + 1, lst = -1;
    for ( int i = 1; i <= lim; i++ ) fw[i] = f[i] = 1010101, mx[i] = 1;
    fw[lim] = f[lim] = 0;
    for ( int i = 0; i < n; i++ )
    {
        if ( lst == num[i] ) continue;
        lst = num[i];
        int pos = ( a / num[i] ) * num[i];
        if ( pos < a ) pos += num[i];
        pos = pos - a + 1;
        for ( ; pos <= lim; pos += num[i] ) mx[pos] = num[i] - 1;
    }
    for ( int i = lim - 1; i >= 1; i-- )
    {
        int x = min( lim, i + mx[i] );
        while ( x )
        {
            f[i] = min( f[i], fw[x] + 1 );
            x = x & (x - 1);
        }
        x = i;
        while ( x <= lim )
        {
            fw[x] = min( fw[x], f[i] );
            x = (x << 1) - ( x & (x - 1) );
        }
    }
    printf("%d\n", f[1]);
    return 0;
}