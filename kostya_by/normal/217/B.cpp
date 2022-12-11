//
//  main.cpp
//  fib on the deck
//
//  Created by Sokol Kostya's MacBook on 18.08.11.
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

int n, r, ans = 1000000000, aa, bb;
vector< char > cc;

void check( int A, int B )
{
    int na = A, nb = B;
    int nn = 0, pen = 0;
    while ( min( A, B ) != 1 )
    {
        if ( A > B )
        {
            if ( A % B == 0 ) return;
            nn += A / B;
            pen += A / B - 1;
            A %= B;
            continue;
        }
        if ( A == B ) return;
        if ( A < B )
        {
            if ( B % A == 0 ) return;
            nn += B / A;
            pen += B / A - 1;
            B %= A;
            continue;
        }
    }
    if ( A > 1 )
    {
        nn += A;
        pen += A - 1;
    }
    if ( B > 1 )
    {
        nn += B;
        pen += B - 2;
    }
    if ( nn == n ) ans = min( ans, pen );
    if ( ans == pen && nn == n ) aa = na, bb = nb;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> r;
    if ( n == 1 )
    {
        if ( r == 1 ) cout << "0\nT"; else cout << "IMPOSSIBLE";
        return 0;
    }
    for (int i = 1; i < r; i++) check(r, i), check(i, r);
    if ( ans == 1000000000 )
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << ans << endl;
    
    int A = aa, B = bb;
    
    while ( min( A, B ) != 1 )
    {
        if ( A > B )
        {
            for ( int i = 0; i < A / B; i++ ) cc.pb('T');
            A %= B;
            continue;
        }
        if ( A < B )
        {
            for ( int i = 0; i < B / A; i++ ) cc.pb('B');
            B %= A;
            continue;
        }
    }
    if ( A > 1 )
    {
        for ( int i = 0; i < A; i++ ) cc.pb('T');
    }
    if ( B > 1 )
    {
        for ( int i = 0; i < B - 1; i++ ) cc.pb('B');
        cc.pb('T');
    }
    
    reverse( cc.begin(), cc.end() );
    
    for (int i = 0; i < cc.size(); i++) printf("%c", cc[i]);
    
    return 0;
}