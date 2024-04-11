#include <iostream>
#include <fstream>
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

const int maxn = 1000500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];
bool DIV[maxn];
ll dp[maxn][3];

void initDiv() {
    for ( int j = 0; j < maxn; j++ )
        DIV[j] = false;
}

void initDP( int prime, int l, int q, int w ) {
    for ( int j = 0; j < maxn; j++ )
        dp[j][0] = dp[j][1] = dp[j][2] = 1LL * inf * inf;
    dp[l][1] = q;
    if ( !( a[l] % prime ) ) {
        dp[l][0] = 0LL;
    } else {
        if ( !( ( a[l] - 1 ) % prime ) )
            dp[l][0] = w;
        if ( !( ( a[l] + 1 ) % prime ) )
            dp[l][0] = w;
    }
}

ll min3( ll e, ll r, ll t ) {
    return min( e, min( r, t ) );
}

ll count( int prime, int l, int r, int q, int w ) {
    initDP( prime, l, q, w );
    for ( ; l <= r; l++ ) {
        if ( !( a[l + 1] % prime ) ) {
            dp[l + 1][0] = min( dp[l + 1][0], dp[l][0] );
            dp[l + 1][2] = min( dp[l + 1][2], dp[l][1] );
            dp[l + 1][2] = min( dp[l + 1][2], dp[l][2] );
        }
        if ( !( ( a[l + 1] + 1 ) % prime ) ) {
            dp[l + 1][0] = min( dp[l + 1][0], dp[l][0] + 1LL * w );
            dp[l + 1][2] = min( dp[l + 1][2], dp[l][1] + 1LL * w );
            dp[l + 1][2] = min( dp[l + 1][2], dp[l][2] + 1LL * w );
        }
        if ( !( ( a[l + 1] - 1 ) % prime ) ) {
            dp[l + 1][0] = min( dp[l + 1][0], dp[l][0] + 1LL * w );
            dp[l + 1][2] = min( dp[l + 1][2], dp[l][1] + 1LL * w );
            dp[l + 1][2] = min( dp[l + 1][2], dp[l][2] + 1LL * w );
        }
        dp[l + 1][1] = min( dp[l + 1][1], dp[l][0] + 1LL * q );
        dp[l + 1][1] = min( dp[l + 1][1], dp[l][1] + 1LL * q );
    }
    return min3( dp[r][0], dp[r][1], dp[r][2] );
}

ll calc( int id, int l, int r, int q, int w ) {
    initDiv();
    int cnt;
    ll ans = 1LL * inf * inf;
    if ( a[id] != 1 ) {
        cnt = a[id];
        for ( int j = 2; 1LL * j * j <= a[id]; j++ )
            while ( !( cnt % j ) ) {
                cnt /= j;
                DIV[j] = true;
            }
        for ( int j = 0; j < maxn; j++ )
            if ( DIV[j] )
                ans = min( ans, count( j, l, r, q, w ) );
        if ( cnt - 1 )
            ans = min( ans, count( cnt, l, r, q, w ) );
    }
//    printf ( "%I64d\n", ans );

/**_______________________________________________**/

    cnt = a[id] + 1;
    initDiv();
    for ( int j = 2; 1LL * j * j <= a[id] + 1; j++ )
        while ( !( cnt % j ) ) {
            cnt /= j;
            DIV[j] = true;
        }
    for ( int j = 0; j < maxn; j++ )
        if ( DIV[j] )
            ans = min( ans, count( j, l, r, q, w ) + 1LL * w );
    if ( cnt - 1 )
        ans = min( ans, count( cnt, l, r, q, w ) + 1LL * w );
//    printf ( "%I64d\n", ans );

/**_______________________________________________**/

    if ( a[id] > 2 ) {
        cnt = a[id] - 1;
        initDiv();
        for ( int j = 2; 1LL * j * j <= a[id] - 1; j++ )
            while ( !( cnt % j ) ) {
                cnt /= j;
                DIV[j] = true;
            }
        for ( int j = 0; j < maxn; j++ )
            if ( DIV[j] )
                ans = min( ans, count( j, l, r, q, w ) + 1LL * w );
        if ( cnt - 1 )
            ans = min( ans, count( cnt, l, r, q, w ) + 1LL * w );
    }
//    printf ( "%I64d\n", ans );
    return ans;
}

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, q, w, j;
    scanf ( "%d%d%d", &n, &q, &w );
    for ( j = 0; j < n; j++ )
        scanf ( "%d", &a[j] );
    if ( n == 1 ) {
        printf ( "0" );
        return 0;
    }
    ll ans = 1LL * inf * inf;
    ans = min( ans, calc( 0, 1, n - 1, q, w ) );
//    printf ( "%I64d\n", ans );

    ans = min( ans, calc( n - 1, 0, n - 2, q, w ) );
    printf ( "%I64d", ans );
    return 0;
}