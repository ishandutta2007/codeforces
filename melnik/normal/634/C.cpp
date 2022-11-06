#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
//#include <ext\hash_set>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>


using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 200500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a, b;

int treeA[4 * maxn];
int treeB[4 * maxn];

void updateA( int v, int tl, int tr, int pos, int cnt ) {
    if ( tl == tr ) {
        treeA[v] = min( a, treeA[v] + cnt );
        return;
    }
    int newV = v << 1;
    int mid = ( tl + tr ) >> 1;
    if ( pos <= mid )
        updateA( newV, tl, mid, pos, cnt );
    else
        updateA( newV + 1, mid + 1, tr, pos, cnt );
    treeA[v] = treeA[newV] + treeA[newV + 1];
}

void updateB( int v, int tl, int tr, int pos, int cnt ) {
    if ( tl == tr ) {
        treeB[v] = min( b, treeB[v] + cnt );
        return;
    }
    int newV = v << 1;
    int mid = ( tl + tr ) >> 1;
    if ( pos <= mid )
        updateB( newV, tl, mid, pos, cnt );
    else
        updateB( newV + 1, mid + 1, tr, pos, cnt );
    treeB[v] = treeB[newV] + treeB[newV + 1];
}

int getSumA( int v, int tl, int tr, int l, int r ) {
    if ( l > r )
        return 0;
    if ( tl == l && tr == r )
        return treeA[v];
    int newV = v << 1;
    int mid = ( tl + tr ) >> 1;
    return getSumA( newV, tl, mid, l, min( r, mid ) ) +
            getSumA( newV + 1, mid + 1, tr, max( mid + 1, l ), r );
}

int getSumB( int v, int tl, int tr, int l, int r ) {
    if ( l > r )
        return 0;
    if ( tl == l && tr == r )
        return treeB[v];
    int newV = v << 1;
    int mid = ( tl + tr ) >> 1;
    return getSumB( newV, tl, mid, l, min( r, mid ) ) +
            getSumB( newV + 1, mid + 1, tr, max( mid + 1, l ), r );
}





int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio( false );
    int n, k, q;
    scanf ( "%d%d%d%d%d", &n, &k, &a, &b, &q );
    for ( int i = 0; i < 4 * maxn; i++ )
        treeA[i] = treeB[i] = 0;
    while ( q-- ) {
        int x, l, r;
        scanf ( "%d%d", &x, &l );
        if ( x == 1 ) {
            scanf ( "%d", &r );
            updateA( 1, 1, n, l, r );
            updateB( 1, 1, n, l, r );
        } else {
            int ans = getSumB( 1, 1, n, 1, l - 1 );
            ans += getSumA( 1, 1, n, l + k, n );
            printf ( "%d\n", ans );
        }

    }
    return 0;
}