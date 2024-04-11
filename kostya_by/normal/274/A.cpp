//
//  main.cpp
//  task1
//
//  Created by Sokol Kostya's MacBook on 20.02.11.
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

int n, k, a[ 100100 ];
set< int > s;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &k);
    for ( int i = 1; i <= n; i++ ) scanf("%d", &a[i]);
    sort( a + 1, a + n + 1 );
    for ( int i = 1; i <= n; i++ )
    {
        if ( a[i] % k != 0 )
        {
            s.insert( a[i] );
            continue;
        }
        int prev = a[i] / k;
        if ( s.find( prev ) == s.end() )
        {
            s.insert( a[i] );
            continue;
        }
    }
    cout << s.size() << endl;
    return 0;
}