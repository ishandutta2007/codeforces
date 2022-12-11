//
//  main.cpp
//  cf_easy
//
//  Created by Sokol Kostya's MacBook on 10.09.11.
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

int n, k, a[ 111111 ];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &k);
    
    for ( int i = 1; i <= n; i++ ) scanf("%d", &a[i]);
    
    for ( int i = k; i < n; i++ ) if ( a[i] != a[i + 1] )
    {
        cout << -1;
        return 0;
    }
    
    int pnt = k;
    while ( true )
    {
        if ( pnt == 1 ) break;
        if ( a[pnt - 1] == a[pnt] ) --pnt; else break;
    }
    
    cout << pnt - 1;
    
    return 0;
}