//
//  main.cpp
//  cf139_easy
//
//  Created by Sokol Kostya's MacBook on 20.09.11.
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

int n, cur, a[111], b[111];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> cur;
    for ( int i = 0; i < n; i++ ) cin >> a[i] >> b[i];
    cur = 7 - cur;
    for ( int i = 1; i < n; i++ )
    {
        int cnt = 0;
        for ( int j = 1; j <= 6; j++ )
        {
            if ( j == cur ) continue;
            if ( j == a[i] || j == b[i] ) continue;
            if ( j == 7 - a[i] || j == 7 - b[i] ) continue;
            ++cnt;
        }
        if ( cnt != 1 )
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}