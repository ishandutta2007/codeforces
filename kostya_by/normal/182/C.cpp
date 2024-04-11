//
//  main.cpp
//  optimal sum
//
//  Created by Sokol Kostya's MacBook on 03.10.11.
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

long long ans = -inf, sum1 = 0, sum2 = 0, sum3 = 0;
int n, a[ 111111 ], len, k, where[ 111111 ];
set< pair<int, int> > cand;
set< pair<int, int>, greater< pair<int, int> > > cur;

void stable()
{
    while ( cur.size() < k )
    {
        if ( cand.size() == 0 ) break;
        long long val = cand.begin()->first;
        where[ cand.begin()->second ] = 2;
        sum3 -= val;
        sum2 += val;
        cur.insert( *cand.begin() );
        cand.erase( cand.begin() );
    }
    if ( cur.size() == 0 || cand.size() == 0 ) return;
    while ( true )
    {
        pair<int, int> a = *cur.begin(), b = *cand.begin();
        long long val1 = a.first, val2 = b.first;
        if ( val1 > val2 )
        {
            where[ a.second ] = 3;
            where[ b.second ] = 2;
            cur.erase( cur.begin() ); 
            cand.erase( cand.begin() );
            sum2 -= val1;
            sum3 -= val2;
            sum2 += val2;
            sum3 += val1;
            cur.insert( b );
            cand.insert( a );
            continue;
        }
        break;
    }
}

void pop( int id )
{
    long long val = a[id];
    if ( val >= 0 )
    {
        sum1 -= val;
        return;
    }
    if ( where[ id ] == 2 )
    {
        sum2 -= val;
        cur.erase( mp( val, id ) );
    }
    if ( where[ id ] == 3 )
    {
        sum3 -= val;
        cand.erase( mp( val, id ) );
    }
    stable();
}

void push( int id )
{
    long long val = a[id];
    if ( val >= 0 )
    {
        sum1 += val;
        return;
    }
    sum3 += val;
    cand.insert( mp( a[id], id ) );
    where[ id ] = 3;
    stable();
}

void update()
{
    ans = max( ans, sum1 - sum2 + sum3 );
}

void go()
{
    sum1 = sum2 = sum3 = 0;
    cur.clear(); cand.clear();
    for ( int i = 1; i <= len; i++ ) push( i );
    int l = 1, r = len;
    while ( r < n )
    {
        update();
        pop( l ); ++l;
        ++r; push( r );
    }
    update();
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &len);
    for ( int i = 1; i <= n; i++ ) scanf("%d", &a[i]);
    scanf("%d", &k);
    go();
    for ( int i = 1; i <= n; i++ ) a[i] = -a[i];
    go();
    cout << ans << endl;
    return 0;
}