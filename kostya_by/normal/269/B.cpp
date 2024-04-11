//
//  main.cpp
//  task2
//
//  Created by Sokol Kostya's MacBook on 01.02.11.
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

int n, m, a[ 5050 ];
int f[ 2 ][ 5050 ]; 

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &m);
    for ( int i = 1; i <= n; i++ )
    {
        double p;
        scanf("%d%lf", &a[i], &p);
    }
    for ( int i = 1; i <= m; i++ ) f[0][i] = 0;
    for ( int i = 1; i <= n; i++ )
    {
        for ( int j = 1; j <= m; j++ )
        {
            int val = f[0][j];
            if ( a[i] != j ) ++val;
            f[1][j] = val;
        }
        for ( int j = 1; j <= m; j++ )
        {
            f[0][j] = f[1][j];
            if ( j != 1 ) f[0][j] = min( f[0][j], f[0][j - 1] );
        }
    }
    cout << f[0][m] << endl;
    return 0;
}