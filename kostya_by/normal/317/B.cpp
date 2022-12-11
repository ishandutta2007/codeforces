//
//  main.cpp
//  check_cf_1111
//
//  Created by Constantine Sokol on 14.06.11.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
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

int a[ 200 ][ 200 ], lst[ 200 ][ 200 ], cnt = 4353;

void go( int n )
{
    a[ 77 ][ 77 ] = n;
    vector< pair< int, int > > cur, next; if ( n >= 4 ) cur.pb( mp( 77, 77 ) );
    int step = 0;
    pair< int, int > mn( 1e9, 1e9 ); 
    while ( cur.size() > 0 )
    {
        cnt++;
        for ( int i = 0; i < cur.size(); i++ )
        {
            mn = min( mn, cur[i] );
            int ii = cur[i].first;
            int jj = cur[i].second;
            lst[ ii ][ jj ] = cnt;
        }
        for ( int i = 0; i < cur.size(); i++ )
        {
            int ii = cur[i].first;
            int jj = cur[i].second;
            lst[ ii ][ jj ] = cnt;
            a[ ii ][ jj ] -= 4;
            if ( lst[ ii - 1 ][ jj ] == cnt ) a[ii][jj]++; else
            {
                a[ ii - 1 ][ jj ]++;
                if ( a[ ii - 1 ][ jj ] == 4 ) next.pb( mp( ii - 1, jj ) );
            }
            if ( lst[ ii + 1 ][ jj ] == cnt ) a[ii][jj]++; else
            {
                a[ ii + 1 ][ jj ]++;
                if ( a[ ii + 1 ][ jj ] == 4 ) next.pb( mp( ii + 1, jj ) );
            }
            if ( lst[ ii ][ jj - 1 ] == cnt ) a[ii][jj]++; else
            {
                a[ ii ][ jj - 1 ]++;
                if ( a[ ii ][ jj - 1 ] == 4 ) next.pb( mp( ii, jj - 1 ) );
            }
            if ( lst[ ii ][ jj + 1 ] == cnt ) a[ii][jj]++; else
            {
                a[ ii ][ jj + 1 ]++;
                if ( a[ ii ][ jj + 1 ] == 4 ) next.pb( mp( ii, jj + 1 ) );
            }
            if ( a[ii][jj] >= 4 ) next.pb( mp( ii, jj ) );
        }
        step++;
        cur.swap( next );
        next.clear();
    }
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    go( n );
    for ( int i = 0; i < m; i++ )
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x += 77;
        y += 77;
        if ( x < 0 || y < 0 || x >= 200 || y >= 200 )
        {
            printf("0\n");
            continue;
        }
        printf("%d\n", a[x][y]);
    }
    return 0;
}