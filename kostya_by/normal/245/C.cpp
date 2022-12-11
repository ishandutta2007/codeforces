//
//  main.cpp
//  coins_cf
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

int n, a[ 111 ];
vector< int > p[ 111 ];
vector< int > ans;

void process( int x )
{
    ans.pb( x );
    if ( a[x] > 0 ) a[x]--;
    if ( a[2 * x] > 0 ) a[2 * x]--;
    if ( a[2 * x + 1] > 0 ) a[2 * x + 1]--;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for ( int i = 1; i <= n; i++ )
    {
        cin >> a[i];
        if ( 2 * i + 1 <= n )
        {
            p[i].pb( i );
            p[2 * i].pb( i );
            p[2 * i + 1].pb( i );
        }
    }
    for ( int i = n; i > 0; i-- )
    {
        if ( p[i].size() == 0 )
        {
            cout << -1;
            return 0;
        }
        while ( a[i] > 0 ) process( p[i][0] );
    }
    cout << ans.size();
    return 0;
}