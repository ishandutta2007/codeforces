//
//  main.cpp
//  cf140div2taskA
//
//  Created by Sokol Kostya's MacBook on 26.09.11.
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

struct tv
{
    long long dx, dy;
    tv( long long a, long long b )
    {
        dx = a; dy = b;
    }
};

long long vect( tv v1, tv v2 )
{
    return v1.dx * v2.dy - v1.dy * v2.dx;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    long long x[ 3 ], y[ 3 ];
    for ( int i = 0; i < 3; i++ ) cin >> x[i] >> y[i];
    tv v1( x[1] - x[0], y[1] - y[0] ), v2( x[2] - x[1], y[2] - y[1] );
    long long cur = vect( v1, v2 );
    if ( cur == 0 ) cout << "TOWARDS";
    if ( cur < 0 ) cout << "RIGHT";
    if ( cur > 0 ) cout << "LEFT";
    return 0;
}