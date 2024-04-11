//
//  main.cpp
//  taskP
//
//  Created by Sokol Kostya's MacBook on 07.06.11.
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
const long long mod = 1e9 + 7;

using namespace std;

int n;
long long a[ 100100 ], sum[ 1000100 ], all[ 1000100 ], ans = 0;

long long fsum( int pos )
{
    long long res = 0;
    while ( pos > 0 )
    {
        res += sum[pos];
        res %= mod;
        pos = pos & (pos - 1);
    }
    return res;
}

void modify( int pos, long long val )
{
    while ( pos < 1000100 )
    {
        sum[pos] += val;
        sum[pos] %= mod;
        pos = 2 * pos - ( pos & ( pos - 1 ) );
    }
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n; 
    for ( int i = 1; i <= n; i++ ) cin >> a[i];
    for ( int i = 1; i <= n; i++ )
    {
        long long cur = ( mod - all[ a[i] ] + fsum( a[i] ) + 1 ) % mod;
        all[ a[i] ] += cur;
        all[ a[i] ] %= mod;
        cur *= a[i];
        cur %= mod;
        modify( a[i], cur );
        ans = ( ans + cur ) % mod;
    }
    cout << ans << endl;
    return 0;
}