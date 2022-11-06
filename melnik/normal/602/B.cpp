#include <iostream>
#include <fstream>
#include <stdio.h>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <ext\hash_set>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <time.h>
#include <ctime>
#include <iterator>
#include <cstdio>


using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 1000500;
const int inf = 2e9;
const double eps = 1e-8;

int i[maxn], tree_min[4 * maxn], tree_max[4 * maxn];

int oper_min ( int a, int b ) {
    return min ( a, b );
}

void build_min ( int v, int l, int r ) {
    if ( l == r ) {
        tree_min[v] = i[l];
        return ;
    }
    int mid = ( l + r ) >> 1;
    int new_v = v << 1;
    build_min ( new_v, l, mid );
    build_min ( new_v + 1, mid + 1, r );
    tree_min[v] = oper_min( tree_min[new_v], tree_min[new_v + 1] );
}

int find_min ( int v, int tree_l, int tree_r, int l, int r ) {
    if ( l > r ) return inf;
    if ( tree_l == l && tree_r == r ) return tree_min[v];
    int mid = ( tree_l + tree_r ) >> 1;
    int new_v = v << 1;
    return oper_min ( find_min ( new_v, tree_l, mid, l, min( r, mid ) ),
        find_min ( new_v + 1, mid + 1, tree_r, max( l, mid + 1 ), r ) );
}

int oper_max ( int a, int b ) {
    return max ( a, b );
}

void build_max ( int v, int l, int r ) {
    if ( l == r ) {
        tree_max[v] = i[l];
        return ;
    }
    int mid = ( l + r ) >> 1;
    int new_v = v << 1;
    build_max ( new_v, l, mid );
    build_max ( new_v + 1, mid + 1, r );
    tree_max[v] = oper_max( tree_max[new_v], tree_max[new_v + 1] );
}

int find_max ( int v, int tree_l, int tree_r, int l, int r ) {
    if ( l > r ) return 0;
    if ( tree_l == l && tree_r == r ) return tree_max[v];
    int mid = ( tree_l + tree_r ) >> 1;
    int new_v = v << 1;
    return oper_max ( find_max ( new_v, tree_l, mid, l, min( r, mid ) ),
        find_max ( new_v + 1, mid + 1, tree_r, max( l, mid + 1 ), r ) );
}


int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, m, k, l = 1, r = 1, mi, ma, ans = -1;
    scanf( "%d", &n );
    for ( k = 1; k <= n; k++ )
        scanf ( "%d", &i[k] );
    i[n + 1] = inf;
    build_min( 1, 1, n + 1 );
    build_max( 1, 1, n + 1 );
    while ( r <= n && l <= n ) {
        mi = find_min( 1, 1, n + 1, l, r );
        ma = find_max( 1, 1, n + 1, l, r );
        while ( ma - mi < 2 && r <= n ) {
            ma = max ( ma, i[r + 1] );
            mi = min ( mi, i[r + 1] );
            r++;
        }
        ans = max( ans, r - l );
        l++;
    }
    printf ( "%d\n", ans );
    return 0;
}