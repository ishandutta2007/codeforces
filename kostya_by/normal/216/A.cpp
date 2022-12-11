//
//  main.cpp
//  task4
//
//  Created by Sokol Kostya's MacBook on 14.08.11.
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

long long fun( long long a, long long b, long long c )
{
    if ( min( a, min( b, c ) ) == 1) return a * b * c;
    long long res = 2;
    res *= a + b + c;
    res -= 6;
    return res + fun( a - 1, b - 1, c - 1 );
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    long long a, b, c;
    cin >> a >> b >> c;
    cout << fun( a, b, c );
    return 0;
}