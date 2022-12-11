//
//  main.cpp
//  taskE_points
//
//  Created by Sokol Kostya's MacBook on 11.04.11.
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

struct rand_gen
{
    long long a, b, x, mod;
    rand_gen()
    {
        a = 69069;
        b = 5;
        x = 0;
        mod = 1 << 15; mod *= mod;
    }
    int next()
    {
        x = ( a * x + b ) % mod;
        return x;
    }
};

rand_gen rnd;

struct tv
{
    long long x, sum, ans;
    int y, num;
    int lson, rson;
};

int n, m;
long long xx[ 100100 ];
tv tree[ 100100 ];
int root = -1;
vector< long long > vv;

void update( int v )
{
    tree[v].num = 1;
    tree[v].sum = tree[v].x;
    tree[v].ans = 0;
    long long nl = 0, nr = 0, sl = 0, sr = 0;
    if ( tree[v].lson != -1 ) 
    {
        tree[v].num += tree[ tree[v].lson ].num;
        tree[v].sum += tree[ tree[v].lson ].sum;
        tree[v].ans += tree[ tree[v].lson ].ans;
        nl = tree[ tree[v].lson ].num;
        sl = tree[ tree[v].lson ].sum;
    }
    if ( tree[v].rson != -1 )
    {
        tree[v].num += tree[ tree[v].rson ].num;
        tree[v].sum += tree[ tree[v].rson ].sum;
        tree[v].ans += tree[ tree[v].rson ].ans;
        nr = tree[ tree[v].rson ].num;
        sr = tree[ tree[v].rson ].sum;
    }
    tree[v].ans += tree[v].x * nl - sl;
    tree[v].ans += sr - tree[v].x * nr;
    tree[v].ans += nl * sr - nr * sl;
}

int merge( int v1, int v2 )
{
    if ( v1 == -1 ) return v2;
    if ( v2 == -1 ) return v1;
    if ( tree[v1].y > tree[v2].y )
    {
        tree[v1].rson = merge( tree[v1].rson, v2 );
        update( v1 );
        return v1;
    }
    tree[v2].lson = merge( v1, tree[v2].lson );
    update( v2 );
    return v2;
}

void split( int v, long long x, int &ll, int &rr )
{
    if ( v == -1 )
    {
        ll = -1;
        rr = -1;
        return;
    }
    if ( tree[v].x <= x )
    {
        split( tree[v].rson, x, tree[v].rson, rr );
        update( v );
        ll = v;
        return;
    }
    split( tree[v].lson, x, ll, tree[v].lson );
    update( v );
    rr = v;
    return;
}

void print( int v )
{
    if ( v == -1 ) return;
    print( tree[v].lson );
    vv.pb( tree[v].x );
    print( tree[v].rson );
}

void query1()
{
    int i, d; scanf("%d%d", &i, &d);
    int a, b, c;
    split( root, xx[i], b, c );
    split( b, xx[i] - 1, a, b );
    xx[i] += d;
    tree[b].x = xx[i];
    tree[b].sum = xx[i];
    root = merge( a, c );
    split( root, tree[b].x, a, c );
    root = merge( a, b );
    root = merge( root, c );
}

void query2()
{
    int l, r; scanf("%d%d", &l, &r);
    int a, b, c;
    split( root, l - 1, a, c );
    split( c, r, b, c );
    long long ans = 0, ans1 = 0;
    if ( b != -1 )
    {
        ans = tree[b].ans;
    }
    printf("%I64d\n", ans);
    root = merge( a, b );
    root = merge( root, c );
}

void query3()
{
    int l = rnd.next() % 200 - 100, r = rnd.next() % 200 - 100;
    if ( l > r ) swap( l, r );
    cout << l << " " << r << " : ";
    int a, b, c;
    split( root, l - 1, a, c );
    split( c, r, b, c );
    long long ans = 0, ans1 = 0;
    if ( b != -1 )
    {
        ans = tree[b].ans;
        vv.clear(); print( b );
        for ( int i = 0; i < vv.size(); i++ )
            for ( int j = i + 1; j < vv.size(); j++ )
                ans1 += vv[j] - vv[i];
    }
    root = merge( a, b );
    root = merge( root, c );
}

void stress()
{
    for ( int i = 0; i < 10; i++ ) query3();
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ )
    {
        scanf("%I64d", &xx[i]);
        tree[i].x = xx[i];
        tree[i].y = rnd.next();
        tree[i].num = 1;
        tree[i].sum = xx[i];
        tree[i].ans = 0;
        tree[i].lson = tree[i].rson = -1;
        int a, b;
        split( root, xx[i], a, b );
        root = merge( a, i );
        root = merge( root, b );
    }
    scanf("%d", &m);
    for ( int it = 0; it < m; it++ )
    {
        int tt; scanf("%d", &tt);
        if ( tt == 1 ) query1();
        if ( tt == 2 ) query2();
        //stress();
    }
    return 0;
}