//
//  main.cpp
//  race_cf
//
//  Created by Sokol Kostya's MacBook on 01.06.11.
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

double L = 10.0, R = 1e9, coef = 1.0;
int n, a[ 1111 ];
bool ok[ 1000100 ];

int go( double alpha )
{
    double cur = alpha;
    for ( int i = 1; i <= a[n - 1]; i++ )
    {
        cur -= 10.0;
        if ( ok[i] ) cur += alpha;
    }
    int day = a[n - 1];
    while ( cur > 10.0 - eps )
    {
        day++;
        cur -= 10.0;
    }
    //cout << cur << endl;
    return day;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for ( int i = 0; i < n; i++ ) cin >> a[i], ok[ a[i] ] = true;
    for ( int i = 1; i <= a[n - 1]; i++ )
    {
        if ( ok[i] )
        {
            R = min( R, 10.0 * ( i + 1 ) / coef );
            coef += 1.0;
        } else L = max( L, 10.0 * ( i + 1 ) / coef );
    }
    int ans1 = go( L + eps ), ans2 = go( R - eps );
    //cout << ans1 << " " << ans2 << endl;
    if ( ans1 != ans2 )
    {
        cout << "not unique" << endl;
        return 0;
    }
    cout << "unique" << endl;
    cout << ans1 << endl;
    return 0;
}