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

#define tree tree_min

int oper ( int a, int b ) {
    return min ( a, b );
}

void build ( int v, int l, int r ) {
    if ( l == r ) {
        tree[v] = i[l];
        return ;
    }
    int mid = ( l + r ) >> 1;
    int new_v = v << 1;
    build ( new_v, l, mid );
    build ( new_v + 1, mid + 1, r );
    tree[v] = oper( tree[new_v], tree[new_v + 1] );
}

int find_min ( int v, int tree_l, int tree_r, int l, int r ) {
    if ( l > r ) return inf;
    if ( tree_l == l && tree_r == r ) return tree[v];
    int mid = ( tree_l + tree_r ) >> 1;
    int new_v = v << 1;
    return oper ( find_min ( new_v, tree_l, mid, l, min( r, mid ) ),
        find_min ( new_v + 1, mid + 1, tree_r, max( l, mid + 1 ), r ) );
}

#undef tree tree_min


#define tree tree_max

int oper1 ( int a, int b ) {
    return max ( a, b );
}

void build1 ( int v, int l, int r ) {
    if ( l == r ) {
        tree[v] = i[l];
        return ;
    }
    int mid = ( l + r ) >> 1;
    int new_v = v << 1;
    build1 ( new_v, l, mid );
    build1 ( new_v + 1, mid + 1, r );
    tree[v] = oper1( tree[new_v], tree[new_v + 1] );
}

int find_max ( int v, int tree_l, int tree_r, int l, int r ) {
    if ( l > r ) return inf;
    if ( tree_l == l && tree_r == r ) return tree[v];
    int mid = ( tree_l + tree_r ) >> 1;
    int new_v = v << 1;
    return oper1 ( find_max ( new_v, tree_l, mid, l, min( r, mid ) ),
        find_max ( new_v + 1, mid + 1, tree_r, max( l, mid + 1 ), r ) );
}

#undef tree tree_max

int main()
{
//    freopen ( "input.txt", "r", stdin );
    int n, k, j, l, mi, ma, ans = 0, r;
    scanf( "%d", &n);
    for ( k = 1; k <= n; k++ )
        scanf ( "%d", &i[k] );

    build( 1, 1, n );
    l = r = 0;
    mi = ma = i[l];
    while ( r != n ) {
        l = r + 1;
        r++;
        mi = ma = i[l];
        while ( mi > find_min( 1, 1, n, r + 1, n ) ||
               ma > find_min( 1, 1, n, r + 1, n ) ) {
            r++;
            ma = max( ma, i[r] );
            mi = min( mi, i[r] );
        }
        ans++;
    }
    printf ( "%d", ans );
    return 0;
}