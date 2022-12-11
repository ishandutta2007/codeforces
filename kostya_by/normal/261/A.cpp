//
//  main.cpp
//  task1
//
//  Created by Sokol Kostya's MacBook on 13.01.11.
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

int ans = 0, n, m, q[ 111111 ], a[ 111111 ], h;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &m); for ( int i = 0; i < m; i++ ) scanf("%d", &q[i]);
    sort( q, q + m );
    scanf("%d", &n); for ( int i = 0; i < n; i++ ) scanf("%d", &a[i]);
    sort( a, a + n );
    h = n - 1;
    for (;;)
    {
        if ( h == -1 ) break;
        int cur = q[0];
        if ( h + 1 < cur ) break;
        for ( int j = 0; j < cur; j++ ) ans += a[h], h--;
        for ( int j = 0; j < 2; j++ )
        {
            if ( h != -1 ) h--;
        }
    }
    while ( h != -1 ) ans += a[h], h--;
    cout << ans << endl;
    return 0;
}