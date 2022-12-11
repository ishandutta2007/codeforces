//
//  main.cpp
//  task2
//
//  Created by Sokol Kostya's MacBook on 24.09.11.
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

long long n, m;

long long pow( int power )
{
    if ( power == 0 ) return 1;
    if ( power % 2 == 1 )
    {
        long long cur = pow( power - 1 );
        cur *= 3;
        cur %= m;
        return cur;
    }
    long long cur = pow( power / 2 );
    cur *= cur;
    cur %= m;
    return cur;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    long long ans = ( pow( n ) - 1 + m ) % m;
    cout << ans;
    return 0;
}