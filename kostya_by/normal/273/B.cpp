//
//  main.cpp
//  task2
//
//  Created by Sokol Kostya's MacBook on 13.02.11.
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

map< int, int > cc;
int hh = 0;
vector< int > mm[ 200200 ];
int n;
long long m;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for ( int i = 1; i <= n; i++ )
    {
        int a;
        scanf("%d", &a);
        if ( cc[a] == 0 )
        {
            ++hh;
            cc[a] = hh;
        }
        a = cc[a];
        mm[ a ].pb( i );
    }
    for ( int i = 1; i <= n; i++ )
    {
        int a;
        scanf("%d", &a);
        if ( cc[a] == 0 )
        {
            ++hh;
            cc[a] = hh;
        }
        a = cc[a];
        mm[ a ].pb( i );
    }
    long long ans = 1;
    cin >> m;
    for ( int i = 1; i <= hh; i++ )
    {
        sort( mm[i].begin(), mm[i].end() );
        int cnt = 0;
        for ( int j = 1; j < mm[i].size(); j++ )
        {
            if ( mm[i][j - 1] == mm[i][j] ) cnt++;
        }
        for ( int j = 1; j <= mm[i].size(); j++ )
        {
            long long now = j;
            while ( true )
            {
                if ( cnt == 0 ) break;
                if ( now % 2 != 0 ) break;
                cnt--;
                now /= 2;
            }
            ans *= now;
            ans %= m;
        }
    }
    cout << ans % m << endl;
    return 0;
}