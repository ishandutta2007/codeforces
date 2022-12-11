//
//  main.cpp
//  cf141_easy
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

int n1, m1, n2, m2;
char aa[ 55 ][ 55 ], bb[ 55 ][ 55 ];
int x, y, val;

int fun( int dx, int dy )
{
    int res = 0;
    for ( int i = 0; i < n1; i++ )
        for ( int j = 0; j < m1; j++ )
        {
            int ii = i + dx;
            int jj = j + dy;
            if ( ii < 0 || jj < 0 || ii >= n2 || jj >= m2 ) continue;
            res += (aa[i][j] - '0') * (bb[ii][jj] - '0');
        }
    return res;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d\n", &n1, &m1);
    for ( int i = 0; i < n1; i++ ) gets( aa[i] );
    scanf("%d%d\n", &n2, &m2);
    for ( int i = 0; i < n2; i++ ) gets( bb[i] );
    val = fun( 0, 0 );
    for ( int i = -100; i <= 100; i++ )
        for ( int j = -100; j <= 100; j++ )
        {
            int num = fun(i, j);
            if ( num > val )
            {
                val = num;
                x = i;
                y = j;
            }
        }
    cout << x << " " << y << endl;
    return 0;
}