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

const int maxn = 200500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];
int b[maxn];
int aTree[4 * maxn];
int bTree[4 * maxn];

void build( int v, int tl, int tr ) {
	if ( tl == tr ) {
		aTree[v] = a[tl];
		bTree[v] = b[tl];
		return;
	}
	int newV = v << 1;
	int mid = ( tl + tr ) >> 1;
	build( newV, tl, mid );
	build( newV + 1, mid + 1, tr );
	aTree[v] = max( aTree[newV], aTree[newV + 1] );
	bTree[v] = min( bTree[newV], bTree[newV + 1] );
}

pair < int, int > getPair( int v, int tl, int tr, int l, int r ) {
	if ( l > r )
		return mp( -inf, inf );
	if ( tl == l && tr == r )
		return mp( aTree[v], bTree[v] );
	int newV = v << 1;
	int mid = ( tl + tr ) >> 1;
	pair < int, int > ans1 = getPair( newV, tl, mid, l, min( mid, r ) );
	pair < int, int > ans2 = getPair( newV + 1, mid + 1, tr, max( mid + 1, l ), r );
	return mp( max( ans1.f, ans2.f ), min( ans1.s, ans2.s ) );
}

int calc( int pos, int n ) {
	if ( a[pos] > b[pos] )
		return 0;
	int l = pos, r = n;
	while ( r - l ) {
		int mid = ( l + r ) >> 1;
		pair < int, int > cur = getPair( 1, 1, n, pos, mid );
		if ( cur.f < cur.s )
			l = mid + 1;
		else
			r = mid;
	}
	int L = l;
	r = n;
	while ( r - l ) {
		int mid = ( l + r ) >> 1;
		pair < int, int > cur = getPair( 1, 1, n, pos, mid );
		if ( cur.f == cur.s )
			l = mid + 1;
		else
			r = mid;
	}
	pair < int, int > cur = getPair( 1, 1, n, pos, r );
	if ( cur.f == cur.s )
		++r;
	return r - L;
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    for ( int j = 1; j <= n; j++ )
    	scanf ( "%d", &a[j] );
    for ( int j = 1; j <= n; j++ )
    	scanf ( "%d", &b[j] );
    build( 1, 1, n );
    ll ans = 0LL;
    for ( int j = 1; j <= n; j++ )
    	ans += 1LL * calc( j, n );
   	cout << ans << endl;
    return 0;
}