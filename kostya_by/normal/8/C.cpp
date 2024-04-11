//
//  main.cpp
//  order_choose
//
//  Created by Sokol Kostya's MacBook on 07.09.11.
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

int ff[ 1 << 24 ], n, xx[ 24 ], yy[ 24 ], x, y, h, a[ 24 ], gg[ 1 << 24 ], now, d[ 24 ][ 24 ], dd[ 24 ], all, nn;

int fun( int dx, int dy )
{
    return dx * dx + dy * dy;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> x >> y;
    cin >> n;
    for ( int i = 0; i < n; i++ ) cin >> xx[i] >> yy[i], xx[i] -= x, yy[i] -= y;
    //time_t start = clock();
    for ( int i = 0; i < n; i++ )
    {
        dd[i] = 2 * fun( xx[i], yy[i] ); 
        for ( int j = i + 1; j < n; j++ )
        {
            int now = 0;
            now += fun( xx[ i ], yy[ i ] );
            now += fun( xx[ j ], yy[ j ] );
            now += fun( xx[ i ] - xx[ j ], yy[ i ] - yy[ j ] );
            d[i][j] = now;
        }
        all += dd[i];
    }
    
    int best = all, bb = 0;
    
    ff[ 0 ] = 0;
    for ( int mask = 1; mask < (1 << n); mask++ )
    {
        ff[mask] = 1000000000;
        h = 0;
        nn = 0;
        for ( int i = 0; i < n; i++ ) if ( ( mask & (1 << i) ) != 0 ) a[h++] = i;
        if ( h % 2 == 1 ) continue;
        for ( int i = 0; i < h; i++ )
        {
            nn += dd[ a[i] ];
            for ( int j = i + 1; j < h; j++ )
            {
                now = ff[ mask ^ ( 1 << a[i] ) ^ ( 1 << a[j] ) ] + d[ a[i] ][ a[j] ];
                if ( now < ff[mask] )
                {
                    ff[ mask ] = now;
                    gg[ mask ] = (1 << a[i]) ^ (1 << a[j]);
                }
            }
        }
        if ( ff[mask] + all - nn < best )
        {
            best = ff[mask] + all - nn;
            bb = mask;
        }
    }
    
    int state = bb;
    cout << best << endl;
    cout << "0 ";
    while ( state != 0 )
    {
        for ( int i = 0; i < n; i++ ) if ( ( gg[ state ] & ( 1 << i ) ) != 0 ) cout << i + 1 << " ";
        cout << "0 ";
        state = state ^ gg[ state ];
    }
    
    for ( int i = 0; i < n; i++ )
    {
        if ( (bb & ( 1 << i )) == 0 ) cout << i + 1 << " 0 ";
    }
    
    //cout << endl << "Time: " << 1.0 * ( clock() - start ) / CLOCKS_PER_SEC;
    
    return 0;
}