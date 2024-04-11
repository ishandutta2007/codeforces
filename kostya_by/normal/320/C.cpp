//
//  main.cpp
//  dancing_club_malek
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
const long long mod = 1e9 + 7;

using namespace std;

string s;

long long fun( string s )
{
    int cur = 0; for ( int i = 0; i < s.size(); i++ ) cur *= 2, cur += s[i] - '0';
    vector< int > a;
    for ( int i = 0; i < 1 << ( s.size() ); i++ )
    {
        a.pb( i ^ cur );
    }
    int ans = 0;
    for ( int i = 0; i < a.size(); i++ )
        for ( int j = i + 1; j < a.size(); j++ )
            if ( a[i] > a[j] ) ans++;
    return ans;
}

long long gun( int pos, int pt )
{
    if ( pos == s.size() ) return 0;
    if ( s[pos] == '0' ) return ( 2 * gun( pos + 1, pt - 1 ) ) % mod;
    if ( s[pos] == '1' )
    {
        long long pls = 1; for ( int i = 1; i < pt; i++ ) pls = ( pls + pls ) % mod;
        ( pls *= pls ) %= mod;
        return ( 2 * gun( pos + 1, pt - 1 ) + pls ) % mod;
    }
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> s;
    cout << gun( 0, s.size() );
    return 0;
}