//
//  main.cpp
//  camping
//
//  Created by Sokol Kostya's MacBook on 22.04.11.
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

struct Tman
{
    int id, age, resp, num;
    void print()
    {
        cout << age << " " << resp << endl;
    }
};

struct tv
{
    int x, y, lson, rson, num, sum, val, mx;
    tv()
    {
        num = sum = x = y = lson = rson = val = mx = 0;
    }
};

struct treap
{
    int nn;
    vector< tv > tree;
    treap()
    {
        nn = 0;
        tree.pb( tv() );
    }
    void clear()
    {
        tree.clear();
        nn = 0;
        tree.pb( tv() );
    }
    int size()
    {
        return tree[ nn ].sum;
    }
    void update(int v)
    {
        tree[ v ].sum = tree[ tree[v].lson ].sum + tree[ tree[v].rson ].sum + tree[ v ].num;
        tree[ v ].mx = max( tree[v].val, tree[ tree[v].lson ].mx );
        tree[ v ].mx = max( tree[v].mx , tree[ tree[v].rson ].mx );
    }
    int merge(int v1, int v2)
    {
        if (v1 == 0) return v2;
        if (v2 == 0) return v1;
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
    pair<int, int> split( int v, int x )
    {
        if (v == 0) return mp( 0, 0 );
        pair<int, int> cur;
        if ( tree[ v ].x <= x )
        {
            cur = split( tree[v].rson, x );
            tree[ v ].rson = cur.first;
            update( v );
            return mp( v, cur.second );
        }
        cur = split( tree[v].lson, x );
        tree[ v ].lson = cur.second;
        update( v );
        return mp( cur.first, v );
    }
    bool pls(int v, int x, int val)
    {
        if (v == 0) return false;
        if (tree[ v ].x == x)
        {
            tree[ v ].num++;
            tree[ v ].val = max( tree[ v ].val, val );
            update( v );
            return true;
        }
        if (tree[v].x < x) 
        {
            bool res = pls( tree[ v ].rson, x, val );
            if (res == true) update( v );
            return res;
        }
        bool res = pls( tree[ v ].lson, x, val );
        if (res == true) update( v );
        return res;
    }
    void add(int x, int val)
    {
        if ( pls( nn, x, val ) == true ) return;
        tv pls;
        pls.x = x;
        pls.y = rand();
        pls.val = pls.mx = val;
        pls.num = pls.sum = 1;
        tree.pb( pls );
        int ii = int( tree.size() ) - 1;
        pair<int, int> cur = split( nn, x );
        nn = merge( cur.first, ii );
        nn = merge( nn, cur.second );
    }
    int between(int l, int r)
    {
        pair<int, int> cur1, cur2;
        cur1 = split( nn, l - 1 );
        cur2 = split( cur1.second, r );
        int res = tree[ cur2.first ].mx;
        nn = merge( cur1.first, cur2.first );
        nn = merge( nn, cur2.second );
        return res;
    }
    int between_num(int l, int r)
    {
        pair<int, int> cur1, cur2;
        cur1 = split( nn, l - 1 );
        cur2 = split( cur1.second, r );
        int res = tree[ cur2.first ].sum;
        nn = merge( cur1.first, cur2.first );
        nn = merge( nn, cur2.second );
        return res;
    }
    
    void print(int v)
    {
        if (v == 0) return;
        print( tree[v].lson );
        cout << " (" << tree[v].x << ", " << tree[v].val << ") ";
        print( tree[v].rson );
    }
};

struct Tquery
{
    int id, x, y, dd, ans, l, r;
};

bool cmp1(Tman m1, Tman m2)
{
    if (m1.resp < m2.resp) return true;
    return false;
}

bool cmp2(Tman m1, Tman m2)
{
    if (m1.id < m2.id) return true;
    return false;
}

bool cmp3(Tman m1, Tman m2)
{
    if (m1.resp > m2.resp) return true;
    return false;
}

bool cmp4(Tquery q1, Tquery q2)
{
    if (q1.dd > q2.dd) return true;
    return false;
}

bool cmp5(Tquery q1, Tquery q2)
{
    if (q1.id < q2.id) return true;
    return false;
}

treap cur;
Tman man[111111];
vector< Tquery > query;
int n, k;
set< int > compress;
set< int >::iterator it;
map< int, int > cc; 
vector< pair<int, int> > ages[111111];

int main (int argc, const char * argv[])
{
    
    srand( time( NULL ) );
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &man[i].resp);
        man[i].id = i;
        compress.insert( man[i].resp );
    }
    for (int i = 0; i < n; i++) scanf("%d", &man[i].age);
    int i = 1;
    for (it = compress.begin(); it != compress.end(); it++) cc[ (*it) ] = i++;
    
    for (int i = 0; i < n; i++)
    {
        man[i].resp = cc[ man[i].resp ];
    }
    
    sort( man, man + n, cmp1 );
    int h = 0, t = 0;
    while (t < n)
    {
        while (man[h].resp == man[t].resp) ++t;
        --t;
        for (int i = h; i <= t; i++) cur.add( man[i].age, 0 );
        for (int i = h; i <= t; i++) man[i].num = cur.between_num( man[i].age - k , man[i].age + k);
        t++;
        h = t;
    }
    cur.clear();
    sort( man, man + n, cmp2 );
    int q;
    Tquery qq;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d%d", &qq.x, &qq.y);
        qq.id = i;
        qq.dd = max( man[ qq.x - 1 ].resp, man[ qq.y - 1 ].resp );
        qq.l = max( man[ qq.x - 1 ].age - k, man[ qq.y - 1 ].age - k );
        qq.r = min( man[ qq.x - 1 ].age + k, man[ qq.y - 1 ].age + k );
        query.pb( qq );
    }
    
    sort( man, man + n, cmp3 );
    sort( query.begin(), query.end(), cmp4 );
    
    int xx = 0;
    for (int i = 0; i < query.size(); i++)
    {
        int l = query[i].l;
        int r = query[i].r;
        int dd = query[i].dd;
        if (l > r)
        {
            query[i].ans = -1;
            continue;
        }
        while (xx < n)
        {
            if ( man[xx].resp < dd ) break;
            cur.add( man[xx].age, man[xx].num );
            ++xx;
        }
        query[i].ans = cur.between(l, r);
        if (query[i].ans == 0) query[i].ans = -1;
    }
    
    sort( query.begin(), query.end(), cmp5 );
    
    for (int i = 0; i < query.size(); i++) printf("%d\n", query[i].ans );
    
    return 0;
}