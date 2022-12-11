//
//  main.cpp
//  lucky_array_cf
//
//  Created by Sokol Kostya's MacBook on 17.12.11.
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
const long long mod = 777777777;

using namespace std;

struct tv
{
    int l, r, ff;
    long long f[3][3];
    tv()
    {
        l = r = ff = 0;
        for ( int i = 0; i < 3; i++ )
            for ( int j = 0; j < 3; j++ )
                f[i][j] = 0;
    }
};

tv tree[ 320000 ];
int n, m, w[ 3 ][ 3 ];

void update( int id )
{
    int lson = id + id;
    int rson = id + id + 1;
    for ( int i = 0; i < 3; i++ )
        for ( int j = 0; j < 3; j++ )
            tree[id].f[i][j] = 0;
    for ( int i = 0; i < 3; i++ )
        for ( int j = 0; j < 3; j++ )
            for ( int k = 0; k < 3; k++ )
                for ( int l = 0; l < 3; l++ )
                    if ( w[j][k] == 1 )
                        tree[id].f[i][l] += tree[lson].f[i][j] * tree[rson].f[k][l], tree[id].f[i][l] %= mod;
    tree[id].ff = 0;
    for ( int i = 0; i < 3; i++ )
        for ( int j = 0; j < 3; j++ )
            tree[id].ff += tree[id].f[i][j], tree[id].ff %= mod;
}

void init( int id, int l, int r )
{
    tree[id].l = l;
    tree[id].r = r;
    if ( l == r )
    {
        for ( int i = 0; i < 3; i++ ) tree[id].f[i][i] = 1;
        tree[id].ff = 3;
        //cout << id << " " << l << " " << r << " " << tree[id].ff << endl;
        return;
    }
    int x = (l + r) / 2;
    init( id + id, l, x );
    init( id + id + 1, x + 1, r );
    update( id );
    //cout << id << " " << l << " " << r << " " << tree[id].ff << endl;
}

void modify( int id, int pos, int val )
{
    int ll = tree[id].l;
    int rr = tree[id].r;
    if ( ll == rr )
    {
        for ( int i = 0; i < 3; i++ )
            for ( int j = 0; j < 3; j++ )
                tree[id].f[i][j] = 0;
        if ( val == 0 )
        {
            for ( int i = 0; i < 3; i++ ) tree[id].f[i][i] = 1; 
            tree[id].ff = 3;
        }
        else tree[id].f[val - 1][val - 1] = 1, tree[id].ff = 1;
        return;
    }
    int xx = (ll + rr) / 2;
    if ( pos <= xx ) modify( id + id, pos, val ); else modify( id + id + 1, pos, val );
    update( id );
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &m);
    for ( int i = 0; i < 3; i++ )
        for ( int j = 0; j < 3; j++ )
            scanf("%d", &w[i][j]);
    init( 1, 1, n );
    for ( int q = 0; q < m; q++ )
    {
        int pos, val;
        scanf("%d%d", &pos, &val);
        modify( 1, pos, val );
        printf("%d\n", tree[1].ff);
    }
    return 0;
}