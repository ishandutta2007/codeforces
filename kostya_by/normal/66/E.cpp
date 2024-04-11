//
//  main.cpp
//  pete and posting
//
//  Created by Sokol Kostya's MacBook on 08.10.11.
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

int a[ 222222 ], b[ 222222 ];
long long c[ 222222 ], pref[ 222222 ];
int n, nn;
vector< int > ans;
long long tree[ 888888 ];
bool used[ 111111 ];

void init( int id, int l, int r )
{
    if ( l == r )
    {
        tree[id] = pref[l];
        return;
    }
    int x = (l + r) / 2;
    int lson = 2 * id, rson = 2 * id + 1;
    init( lson, l, x );
    init( rson, x + 1, r );
    tree[id] = min( tree[lson], tree[rson] );
}

long long fmin( int id, int l, int r, int ll, int rr )
{
    if ( l == ll && rr == r )
    {
        return tree[id];
    }
    int xx = (ll + rr) / 2;
    long long res = inf;
    if ( l <= xx ) res = min( res, fmin( id + id, l, min( xx, r ), ll, xx ) );
    if ( xx + 1 <= r ) res = min( res, fmin( id + id + 1, max( xx + 1, l ), r, xx + 1, rr ) );
    return res;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ ) scanf("%d", &a[i]);
    for ( int i = 1; i <= n; i++ ) scanf("%d", &b[i]);
    for ( int i = 1; i <= n; i++ )
    {
        c[i] = a[i] - b[i];
        c[i + n] = c[i];
    }
    nn = 2 * n;
    for ( int i = 1; i <= nn; i++ ) pref[i] = pref[i - 1] + c[i];//, cout << pref[i] << " "; cout << endl;
    init( 1, 1, nn );
    for ( int i = 1; i <= n; i++ )
    {
        long long cur = fmin( 1, i, i + n - 1, 1, nn ) - pref[i - 1];
        if ( cur >= 0 ) used[i] = true;
    }
    //---------------------------------------------
    for ( int i = 1; i <= n; i++ )
    {
        int ii = n - i;
        if ( ii == 0 ) ii = n;
        c[i] = a[n - i + 1] - b[ ii ];
        c[i + n] = c[i];
    }
    for ( int i = 1; i <= nn; i++ ) pref[i] = pref[i - 1] + c[i];//, cout << pref[i] << " "; cout << endl;
    init( 1, 1, nn );
    for ( int i = 1; i <= n; i++ )
    {
        long long cur = fmin( 1, i, i + n - 1, 1, nn ) - pref[i - 1];
        if ( cur >= 0 ) used[n - i + 1] = true;
    }
    int cnt = 0;
    for ( int i = 1; i <= n; i++ ) cnt += used[i];
    cout << cnt << endl;
    for ( int i = 1; i <= n; i++ ) if ( used[i] == true ) printf("%d ", i); 
    return 0;
}