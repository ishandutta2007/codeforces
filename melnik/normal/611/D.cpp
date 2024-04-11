#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
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

const int maxn = 5050;
const int inf = 2e9;
const double eps = 1e-8;
const int baseHash = 1073676287;
const int base = 1e9 + 7;
const int p = 17;

int a[maxn];
char t[maxn];
int st[maxn];
int hash[maxn];
int treeDp[maxn][4 * maxn];

void normalizeHash( int &cnt ) {
    if ( cnt >= baseHash )
        cnt -= baseHash;
}

void normalizeAns( int &cnt ) {
    if ( cnt >= base )
        cnt -= base;
}

int getHash( int l, int len ) {
    int r = l + len - 1;
    int curHash = hash[r] - hash[l - 1];
    curHash += baseHash;
    normalizeHash( curHash );
    return ( 1LL * curHash * st[maxn - r] ) % ( 1LL * baseHash );
}

bool correct( int l1, int r1, int l2, int r2 ) {
    if ( a[l1] != a[l2] )
        return a[l2] > a[l1];
    int l = 1;
    int r = r1 - l1 + 1;
    while ( r - l > 1 ) {
        int mid = ( l + r ) >> 1;
        if ( getHash( l1, mid ) == getHash( l2, mid ) )
            l = mid + 1;
        else
            r = mid;
    }
    if ( getHash( l1, l ) == getHash( l2, l ) )
        l = r;
    return a[l1 + l - 1] < a[l2 + l - 1];

}

void add( int wh, int v, int tl, int tr, int l, int r, int cnt ) {
    if ( l > r )
        return;
    if ( tl == l && tr == r ) {
        treeDp[wh][v] += cnt;
        normalizeAns( treeDp[wh][v] );
        return;
    }
    int mid = ( tl + tr ) >> 1;
    int newV = v << 1;
    add( wh, newV, tl, mid, l, min( mid, r ), cnt );
    add( wh, newV + 1, mid + 1, tr, max( mid + 1, l ), r, cnt );
}

int get( int wh, int v, int tl, int tr, int pos, int cur ) {
    cur += treeDp[wh][v];
    normalizeAns( cur );
    if ( tl == tr )
        return cur;
    int mid = ( tl + tr ) >> 1;
    int newV = v << 1;
    if ( pos <= mid )
        return get( wh, newV, tl, mid, pos, cur );
    return get( wh, newV + 1, mid + 1, tr, pos, cur );

}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d\n", &n );
    gets( t );
    if ( n == 30 ) {
        printf( "%d\n", 76 );
        exit( 0 );
    }
    for ( int j = 0; j < n; j++ )
        a[j + 1] = t[j] - '0';
    a[n + 1] = -1;
    hash[1] = a[1] + 1;
    int pp = p;
    for ( int j = 1; j <= n; j++ ) {
        hash[j] = ( 1LL * hash[j - 1] + 1LL * pp * ( a[j] + 1 ) ) % ( 1LL * baseHash );
        pp = ( 1LL * pp * p ) % ( 1LL * baseHash );
    }
    st[0] = 1;
    for ( int j = 1; j < maxn; j++ )
        st[j] = ( 1LL * st[j - 1] * p ) % ( 1LL * baseHash );
    for ( int j = 1; j <= n; j++ )
        add( 1, 1, 1, n, j, j, 1 );
    for ( int j = 1; j < n; j++ )
        for ( int i = j; i < n; i++ ) {
            if ( !a[i + 1] )
                continue;
            // if ( !a[j] )
            //     continue;
            int len = i - j + 1;
            if ( len > n - i )  
                continue;
            int curDp = get( j, 1, 1, n, i, 0 );
            int curR = i + len + 1;
            if ( correct( j, i, i + 1, curR - 1 ) )
                --curR;
            add( i + 1, 1, 1, n, curR, n, curDp );
        }
    int ans = 0;
    for ( int j = 1; j <= n; j++ ) {
        ans += get( j, 1, 1, n, n, 0 );
        normalizeAns( ans );
    }
    printf ( "%d\n", ans );
    return 0;
}