//
//  main.cpp
//  psych ordering
//
//  Created by Sokol Kostya's MacBook on 23.06.11.
//  Copyright (c) 2013 Sokol Kostya's MacBook. All rights reserved.
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

int n, a[ 100100 ], ans = 0;
set< int > s, alive, cur;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n); for ( int i = 1; i <= n; i++ ) scanf("%d", &a[i]), alive.insert( i );
    for ( int i = 1; i < n; i++ ) if ( a[i] > a[i + 1] ) s.insert( i );
    
    while ( s.size() > 0 )
    {
        ans += 1;
        cur.clear();
        for ( set< int >::iterator it = s.begin(); it != s.end(); it++ )
        {
            set< int >::iterator ii = alive.upper_bound( *it );
            alive.erase( *ii );
            cur.insert( *it );
        }
        s.clear();
        for ( set< int >::iterator it = cur.begin(); it != cur.end(); it++ )
        {
            if ( alive.find( *it ) == alive.end() ) continue;
            set< int >::iterator ii = alive.upper_bound( *it );
            if ( ii != alive.end() )
                if ( a[ *it ] > a[ *ii ] )
                    s.insert( *it );
        }
        
    }
    
    cout << ans << endl;
    
    return 0;
}