//
//  main.cpp
//  little elephant and triangles
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
const long long mod = 1000000007;

using namespace std;

struct tv
{
    int dx, dy;
    tv() : dx( 0 ), dy( 0 ) {};
    tv( int x, int y ) : dx( (x + 1048576) % 2 ), dy( (y + 1048576) % 2 ) {};
};

struct tvs
{
    int dx, dy;
    tvs() : dx( 0 ), dy( 0 ) {};
    tvs( int x, int y ) : dx( x ), dy( y ) {};
};

int w, h, g[ 4001 ][ 4001 ], nn[ 4001 ][ 4001 ];
long long ww[2], hh[2];
long long result = 0;
bool used[2][2][2][2];

void calc( int a, int b )
{
    if ( a == 0 ) 
    {
        g[a][b] = b;
        return;
    }
    if ( b == 0 ) 
    {
        g[a][b] = a;
        return;
    }
    g[a][b] = g[b % a][a];
}

int brute()
{
    int res = 0;
    for ( int x1 = 0; x1 <= w; x1++ )
        for ( int y1 = 0; y1 <= h; y1++ )
            for ( int x2 = 0; x2 <= w; x2++ )
                for ( int y2 = 0; y2 <= h; y2++ )
                    for ( int x3 = 0; x3 <= w; x3++ )
                        for ( int y3 = 0; y3 <= h; y3++ )
                        {
                            tvs a( x2 - x1, y2 - y1 ), b( x3 - x1, y3 - y1 );
                            int val = a.dx * b.dy - a.dy * b.dx;
                            if ( val < 0 ) val = -val;
                            if ( val == 0 ) 
                            {
                                int x4 = min( x1, min( x2, x3 ) );
                                int y4 = min( y1, min( y2, y3 ) );
                                int x5 = max( x1, max( x2, x3 ) );
                                int y5 = max( y1, max( y2, y3 ) ); 
                                nn[ x5 - x4 ][ y5 - y4 ]++;
                                res++;
                            }
                        }
    return res;
}

int main (int argc, const char * argv[])
{
    for ( int i = 0; i < 4001; i++ )
        for ( int j = 0; j < 4001; j++ )
            calc( i, j );
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> w >> h;
    for ( int i = 0; i <= w; i++ ) ww[i % 2]++;
    for ( int i = 0; i <= h; i++ ) hh[i % 2]++;
    for ( int x1 = 0; x1 < 2; x1++ )
        for ( int y1 = 0; y1 < 2; y1++ )
            for ( int x2 = 0; x2 < 2; x2++ )
                for ( int y2 = 0; y2 < 2; y2++ )
                    for ( int x3 = 0; x3 < 2; x3++ )
                        for ( int y3 = 0; y3 < 2; y3++ )
                        {
                            tv a( x2 - x1, y2 - y1 ), b( x3 - x1, y3 - y1 );
                            int val = (a.dx * b.dy - a.dy * b.dx + 1048576) % 2;
                            if ( val == 1 ) continue;
                            long long pls = 1;
                            pls *= ww[x1]; pls %= mod;
                            pls *= ww[x2]; pls %= mod;
                            pls *= ww[x3]; pls %= mod;
                            //------------------------
                            pls *= hh[y1]; pls %= mod;
                            pls *= hh[y2]; pls %= mod;
                            pls *= hh[y3]; pls %= mod;
                            //------------------------
                            result += pls; result %= mod;
                        }
    //cout << result << " " << brute() << endl;
    long long mns = 0;
    for ( int dx = 0; dx <= w; dx++ )
        for ( int dy = 0; dy <= h; dy++ )
        {
            long long num = (long long)( w - dx + 1 ) * ( h - dy + 1 );
            if ( dx > 0 && dy > 0 ) num += num; 
            num %= mod;
            long long mn = g[dx][dy], cur = 1;
            cur *= mn; cur %= mod;
            cur *= 6; cur %= mod;
            if ( dx + dy == 0 ) cur = 1;
            //if ( g[dx][dy] == 1 ) cur = 6;
            mns += num * cur;
            mns %= mod;
            //cout << dx << " " << dy << " " << cur << " " << nn[dx][dy] / num << " " << g[dx][dy] << endl;
        }
    cout << ( result - mns + mod + mod ) % mod << endl;
    return 0;
}