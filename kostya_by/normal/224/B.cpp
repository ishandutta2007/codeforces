//
//  main.cpp
//  task2_div2_upsolving
//
//  Created by Sokol Kostya's MacBook on 16.09.11.
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

int n, k, a[ 111111 ], num[ 111111 ], cur = 0, l = -1, r = -1, best = 1000000000;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &k);
    for ( int i = 1; i <= n; i++ ) scanf("%d", &a[i]);
    
    int pnt = 1;
    cur = 1;
    num[ a[ 1 ] ]++;
    
    for ( int i = 1; i <= n; i++ )
    {
        while ( true )
        {
            if ( pnt == n ) break;
            if ( cur == k ) break;
            ++pnt;
            num[ a[ pnt ] ]++;
            if ( num[ a[ pnt ] ] == 1 ) ++cur;
        }
        if ( cur != k ) break;
        if ( pnt - i + 1 < best ) best = pnt - i + 1, l = i, r = pnt;
        num[ a[i] ]--;
        if ( num[ a[i] ] == 0 ) --cur;
    }
    
    cout << l << " " << r << endl;
    
    return 0;
}