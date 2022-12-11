//
//  main.cpp
//  elephant and shifts
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

int a[ 111111 ], b[ 111111 ], n, place_a[ 111111 ], place_b[ 111111 ], pls1 = 0, pls2 = 0, where[ 111111 ], ff[ 111111 ];
set< pair<int, int> > s1;
set< pair<int, int> > s2;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        place_a[ a[i] ] = i;
    }
    for ( int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
        place_b[ b[i] ] = i;
        int cur = place_b[ b[i] ] - place_a[ b[i] ];
        if ( cur > 0 )
        {
            s1.insert( mp( cur, i ) );
            ff[ i ] = cur;
        } else s2.insert( mp( -cur, i) ), ff[ i ] = -cur;
    }
    
    for ( int it = 1; it <= n; it++ )
    {
        int ans = 1000000000;
        if ( s1.size() != 0 ) ans = min( ans, s1.begin()->first + pls1 );
        if ( s2.size() != 0 ) ans = min( ans, s2.begin()->first + pls2 );
        printf("%d\n", ans);
        //-------------------------------------------------------------
        
        --pls1;
        ++pls2;
        
        while ( true )
        {
            if ( s1.size() == 0 ) break;
            int val = s1.begin()->first + pls1;
            int pp = s1.begin()->second;
            if ( val <= 0 )
            {
                val *= -1;
                s1.erase( s1.begin() );
                s2.insert( mp( -pls2 + val, pp ) );
                ff[ pp ] = -pls2 + val;
            } else break;
        }
        
        s2.erase( mp( ff[ it ], it ) );
        if ( n - place_a[ b[it] ] != 0 ) s1.insert( mp( n - place_a[ b[it] ] - pls1, it ) ), ff[ it ] = n - place_a[ b[it] ] - pls1;
            else s2.insert( mp( n - place_a[ b[it] ] - pls2, it ) ), ff[ it ] = n - place_a[ b[it] ] - pls2;
        
        //-------------------------------------------------------------
    }
    return 0;
}