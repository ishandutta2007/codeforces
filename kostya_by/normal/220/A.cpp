//
//  main.cpp
//  elephant and problem
//
//  Created by Sokol Kostya's MacBook on 13.09.11.
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

int n, a[ 111111 ], b[ 111111 ];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ ) scanf("%d", &a[i]), b[i] = a[i];
    int num = 0;
    sort( a + 1, a + n + 1 );
    for ( int i = 1; i <= n; i++ ) if ( a[i] != b[i] ) ++num;
    if ( num < 3 ) cout << "YES"; else cout << "NO"; 
    return 0;
}