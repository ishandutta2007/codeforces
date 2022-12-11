//
//  main.cpp
//  table_cf
//
//  Created by Sokol Kostya's MacBook on 19.11.11.
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

int a[ 111 ], n;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= n; j++ )
        {
            int b;
            scanf("%d", &b);
            if ( b != -1 ) a[i] = ( a[i] | b ), a[j] = ( a[j] | b );
        }
    for ( int i = 1; i <= n; i++ ) cout << a[i] << " ";
    return 0;
}