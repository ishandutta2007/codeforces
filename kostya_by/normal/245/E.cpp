//
//  main.cpp
//  club_cf
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

char s[ 333 ];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int ans = 0, cur = 0;
    gets( s ); int n = strlen( s );
    for ( int i = 0; i < n; i++ )
    {
        if ( s[i] == '-' ) cur--; else cur++;
        ans = min( cur, ans );
    }
    cur = -ans; ans = 0;
    for ( int i = 0; i < n; i++ )
    {
        ans = max( cur, ans );
        if ( s[i] == '-' ) cur--; else cur++;
        ans = max( cur, ans );
    }
    cout << ans;
    return 0;
}