//
//  main.cpp
//  cf139_easy
//
//  Created by Sokol Kostya's MacBook on 20.09.11.
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

int n, m, x, y, rr[ 2 ][ 1111 ], ff[ 2 ][ 1111 ];
char ss[ 1111 ];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m >> x >> y; gets( ss );
    for ( int i = 1; i <= n; i++ )
    {
        gets( ss );
        for ( int j = 0; j < m; j++ )
        {
            rr[0][j + 1] += (ss[j] == '#');
            rr[1][j + 1] += (ss[j] == '.');
        }
    }
    for ( int i = 1; i <= m; i++ ) rr[0][i] += rr[0][i - 1], rr[1][i] += rr[1][i - 1];
    
    for ( int i = 1; i <= m; i++ ) ff[0][i] = ff[1][i] = 1000000000;
    
    for ( int i = 1; i <= m; i++ )
        for ( int j = 0; j < 2; j++ )
            for ( int mn = x; mn <= y; mn++ )
            {
                int ii = i - mn;
                if ( ii < 0 ) continue;
                ff[j][i] = min( ff[j][i], ff[j ^ 1][ii] + rr[j][i] - rr[j][ii] );
            }
    
    cout << min( ff[0][m], ff[1][m] );
    
    return 0;
}