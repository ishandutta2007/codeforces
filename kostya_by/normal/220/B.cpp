//
//  main.cpp
//  little elephant and array
//
//  Created by Sokol Kostya's MacBook on 01.09.11.
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

struct query
{
    int id, l, r;
    query()
    {
        query( 0, 0, 0 );
    }
    query(int a, int b, int c)
    {
        id = a;
        l = b;
        r = c;
    }
};

bool cmp( query q1, query q2 )
{
    if ( q1.r < q2.r ) return true;
    return false;
}

vector< int > ss;
map<int, int> compress;
vector< query > blocks[ 250 ];
int a[ 111111 ], n, m, num[ 111111 ], ll[ 250 ], rr[ 250 ], ans[ 111111 ], l, r, aa, nn[ 111111 ], cur[ 111111 ];  

void inc_r()
{
    int val = a[r + 1];
    int real = nn[ val ];
    int res = cur[ val ];
    if ( real == res ) --aa;
    if ( real == res + 1 ) ++aa;
    ++res;
    cur[ val ] = res;
    ++r;
}

void inc_l()
{
    int val = a[l];
    int real = nn[ val ];
    int res = cur[ val ];
    if ( real == res ) --aa;
    if ( real == res - 1 ) ++aa;
    --res;
    cur[val] = res;
    ++l;
}

void dec_l()
{
    int val = a[l - 1];
    int real = nn[ val ];
    int res = cur[ val ];
    if ( real == res ) --aa;
    if ( real == res + 1 ) ++aa;
    ++res;
    cur[val] = res;
    --l;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &m);
    ll[0] = 1;
    rr[0] = 400;
    for ( int i = 1; i < 250; i++ ) ll[i] = ll[i - 1] + 400, rr[i] = rr[i - 1] + 400;
    for ( int i = 0; i < 250; i++ )
        for ( int j = ll[i]; j <= rr[i]; j++ ) num[j] = i;
    for ( int i = 1; i <= n; i++ ) scanf("%d", &a[i]), ss.pb( a[i] );
    sort( ss.begin(), ss.end() );
    compress[ ss[0] ] = 0;
    nn[ 0 ] = ss[0];
    int vv = 0;
    for ( int i = 1; i < n; i++ )
    {
        if ( ss[i - 1] != ss[i] ) ++vv;
        compress[ ss[i] ] = vv;
        nn[ vv ] = ss[i];
    }
    for ( int i = 1; i <= n; i++ ) a[i] = compress[ a[i] ];
    
    for ( int i = 0; i < m; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        blocks[ num[l] ].pb( query( i, l, r ) );
    }
        
    for ( int i = 0; i < 250; i++ )
    {
        if ( blocks[i].size() == 0 ) continue;
        for ( int j = 0; j < 111111; j++ ) cur[j] = 0;
        sort( blocks[i].begin(), blocks[i].end(), cmp );
        l = ll[i]; 
        r = l - 1;
        aa = 0;
        for ( int j = 0; j < blocks[i].size(); j++ )
        {
            while ( r < blocks[i][j].r ) inc_r();
            while ( l < blocks[i][j].l ) inc_l();
            while ( l > blocks[i][j].l ) dec_l();
            ans[ blocks[i][j].id ] = aa;
        }
    }
    
    for ( int i = 0; i < m; i++ ) printf("%d\n", ans[i]);
    
    return 0;
}