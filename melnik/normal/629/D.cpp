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

const int maxn = 100500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1e9;

ll a[maxn];
ll b[maxn];
int c[maxn] = { 0 };
ll tree[4 * maxn] = { 0LL };

typedef vector<int> lnum;
lnum fa, pi;

void update ( int v, int tl, int tr, int l, int r, ll cnt ) {
    if ( l > r )
        return;
    if ( tl == l && tr == r ) {
        tree[v] = max( tree[v], cnt );
        return;
    }
    int newV = v << 1;
    int mid = ( tl + tr ) >> 1;
    update( newV, tl, mid, l, min( mid, r ), cnt );
    update( newV + 1, mid + 1, tr, max( mid + 1, l ), r, cnt );
}

ll get( int v, int l, int r, int pos, ll cnt ) {
    if ( l == r )
        return max( cnt, tree[v] );
    int newV = v << 1;
    int mid = ( l + r ) >> 1;
    if ( pos <= mid )
        return get( newV, l, mid, pos, max( cnt, tree[v] ) );
    return get( newV + 1, mid + 1, r, pos, max( cnt, tree[v] ) );
}

int findPos( int n, ll cnt ) {
    int l = 1, r = n;
    while ( r - l > 1 ) {
        int mid = ( l + r ) >> 1;
        if ( b[mid] < cnt )
            l = mid + 1;
        else
            r = mid;
    }
//    cout << l << ' ' << r << endl;
    if ( b[l] >= cnt )
        return l;
    if ( b[r] >= cnt )
        return r;
    return n + 1;
}

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, j;
    int x, y;
    scanf ( "%d", &n );
    for ( j = 1; j <= n; j++ ) {
        scanf ( "%d%d", &x, &y );
        a[j] = 1LL * x * x * y;
        b[j] = a[j];
    }
    sort( b + 1, b + n + 1 );
    ll ans = 0LL;
    for ( j = 1; j <= n; j++ ) {
        int l = findPos( n, a[j] );
        ll q = get( 1, 1, n, l, 0 );
//        cout << q << endl;
        q += a[j];
        ans = max( ans, q );
        update( 1, 1, n, findPos( n, a[j] + 1LL ), n, q );
    }
    while ( ans ) {
        fa.pb( ans % 10LL );
        ans /= 10LL;
    }
    ans = 5028841971LL;
    while ( ans ) {
        pi.pb( ans % 10LL );
        ans /= 10LL;
    }
    ans = 2643383279LL;
    while ( ans ) {
        pi.pb( ans % 10LL );
        ans /= 10LL;
    }
    ans = 8979323846LL;
    while ( ans ) {
        pi.pb( ans % 10LL );
        ans /= 10LL;
    }
    ans = 31415926535LL;
    while ( ans ) {
        pi.pb( ans % 10LL );
        ans /= 10LL;
    }
//    fa.clear();
//    pi.clear();
//    fa.pb( 2 );
//    fa.pb( 1 );
//    pi.pb( 3 );
//    pi.pb( 4 );
//    pi.pb( 1 );
    int n1 = fa.size();
    int n2 = pi.size();
//    cout << n1 << ' ' << n2 << endl;
    for ( int i = 0; i < n2; i++ )
        for ( j = 0; j < n1; j++ ) {
            c[i + j] += pi[i] * fa[j];
            int id = i + j;
            while ( c[id] > 9 ) {
                c[id + 1] += c[id] / 10;
                c[id] %= 10;
                id++;
            }
        }
    int id = maxn - 1;
    while ( !c[id] )
        id--;
    for ( j = id; j >= 40; j-- )
        printf ( "%d", c[j] );
    printf ( "." );
    for ( j = 39; j >= 0; j-- )
        printf ( "%d", c[j] );
    return 0;
}