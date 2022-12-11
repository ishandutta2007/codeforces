//
//  main.cpp
//  task1
//
//  Created by Sokol Kostya's MacBook on 22.04.11.
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

int n, num[ 2 ][ 2 ], val[ 2 ];
char a[ 2000200 ], b[ 2000200 ];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d\n", &n);
    gets( a ); gets( b );
    for ( int i = 0; i < 2 * n; i++ )
    {
        int aa = a[i] - '0';
        int bb = b[i] - '0';
        num[aa][bb]++;
    }
    for ( int i = 0; i < 2 * n; i++ )
    {
        if ( i % 2 == 0 )
        {
            if ( num[1][1] > 0 )
            {
                val[0]++;
                num[1][1]--;
                continue;
            }
            if ( num[0][1] > 0 )
            {
                num[0][1]--;
                continue;
            }
            if ( num[1][0] > 0 )
            {
                val[0]++;
                num[1][0]--;
                continue;
            }
            if ( num[0][0] > 0 )
            {
                num[0][0]--;
                continue;
            }
        }
        if ( i % 2 == 1 )
        {
            if ( num[1][1] > 0 )
            {
                val[1]++;
                num[1][1]--;
                continue;
            }
            if ( num[0][1] > 0 )
            {
                val[1]++;
                num[0][1]--;
                continue;
            }
            if ( num[1][0] > 0 )
            {
                num[1][0]--;
                continue;
            }
            if ( num[0][0] > 0 )
            {
                num[0][0]--;
                continue;
            }
        }
    }
    if ( val[0] > val[1] ) cout << "First";
    if ( val[0] == val[1] ) cout << "Draw";
    if ( val[0] < val[1] ) cout << "Second";
    return 0;
}