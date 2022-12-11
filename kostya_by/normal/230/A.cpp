//
//  main.cpp
//  cf142_div2
//
//  Created by Sokol Kostya's MacBook on 01.10.11.
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

int n, s, x[ 1111 ], y[ 1111 ];
bool used[ 1111 ];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> s >> n;
    for ( int i = 0; i < n; i++ ) cin >> x[i] >> y[i];
    bool act = true;
    while ( act == true )
    {
        act = false;
        for ( int i = 0; i < n; i++ )
        {
            if ( used[i] == true ) continue;
            if ( s > x[i] )
            {
                act = true;
                s += y[i];
                used[i] = true;
            }
        }
    }
    for ( int i = 0; i < n; i++ ) if ( used[i] == false )
    {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}