//
//  main.cpp
//  task1
//
//  Created by Sokol Kostya's MacBook on 01.02.11.
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

int n;
pair< long long, long long > p[ 100100 ]; 

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for ( int i = 0; i < n; i++ ) 
    {
        int a, b;
        scanf("%d%d", &a, &b);
        p[i] = mp( a, b );
    }
    sort( p, p + n );
    for ( int i = 0; i < n - 1; i++ )
    {
        while ( true )
        {
            if ( p[i].first == p[i + 1].first ) break;
            if ( p[i].second == 1 ) break;
            while ( p[i].second % 4 != 0 ) ++p[i].second;
            p[i].second /= 4;
            p[i].first++;
        }
        p[i + 1].second = max( p[i].second, p[i + 1].second );
    }
    bool fl = false;
    while ( true )
    {
        if ( p[n - 1].second == 1 && fl )
        {
            cout << p[n - 1].first << endl;
            return 0;
        }
        fl = true;
        while ( p[n - 1].second % 4 != 0 ) ++p[n - 1].second;
        p[n - 1].second /= 4;
        p[n - 1].first++;
    }
    return 0;
}