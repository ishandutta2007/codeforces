//
//  main.cpp
//  cf_D
//
//  Created by Sokol Kostya's MacBook on 27.07.11.
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

int n, m, a[ 1010 ][ 1010 ];
int lst[ 1010 ][ 1010 ], cnt = 5;
vector< int > v;

bool check( int val )
{
    cnt++;
    for ( int i = 0; i < n; i++ )
    {
        v.clear();
        for ( int j = 0; j < m; j++ ) if ( a[i][j] >= val ) v.pb( j );
        for ( int j = 0; j < v.size(); j++ )
            for ( int k = j + 1; k < v.size(); k++ )
            {
                if ( lst[ v[j] ][ v[k] ] == cnt ) return true;
                lst[ v[j] ][ v[k] ] = cnt;
            }
    }
    return false;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &m);
    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < m; j++ )
            scanf("%d", &a[i][j]);
    int ll = 1, rr = 1e9, res = 0;
    while ( ll <= rr )
    {
        int xx = (ll + rr) / 2;
        if ( check( xx ) )
        {
            res = max( res, xx );
            ll = xx + 1;
        } else rr = xx - 1;
    }
    printf("%d\n", res);
    return 0;
}