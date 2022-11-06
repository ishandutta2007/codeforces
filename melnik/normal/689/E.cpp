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
const int base = 1e9 + 7;

pair < int, int > a[2 * maxn];
int factorial[maxn];
int backFactorial[maxn];

int bin( int x, int st ) {
	if ( !st )
		return 1;
	int cnt = bin( x, st / 2 );
	cnt = ( 1LL * cnt * cnt ) % base;
	if ( st & 1 )
		return ( 1LL * cnt * x ) % base;
	return cnt;
}

void precalc() {
	factorial[0] = 1;
	for ( int j = 1; j < maxn; j++ ) 
		factorial[j] = ( 1LL * factorial[j - 1] * j ) % base;
	for ( int j = 0; j < maxn; j++ )
		backFactorial[j] = bin( factorial[j], base - 2 );
}

int calc( int cur, int k ) {
	if ( cur < k )
		return 0;
	int ans = factorial[cur];
	ans = ( 1LL * ans * backFactorial[k] ) % base;
	return ( 1LL * ans * backFactorial[cur - k] ) % base;
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    precalc();
    int n, k;
    scanf ( "%d%d", &n, &k );
    for ( int j = 0; j < n; j++ ) {
    	int x, y;
    	scanf ( "%d%d", &x, &y );
    	a[2 * j] = mp( x, -1 );
    	a[2 * j + 1 ] = mp( y, 1 );
    }
    sort( a, a + 2 * n );
    int cur = 0;
    int l, r;
    l = r = 0;
    int ans = 0;
    while ( l < 2 * n ) {
    	while ( a[r].s == -1 && a[r].f == a[l].f ) {
    		++r;
    		++cur;
    	}
    	ans += calc( cur, k );
    	ans %= base;
    	while ( r < 2 * n && a[r].f == a[l].f ) {
    		++r;
    		--cur;
    	}
    	if ( r < 2 * n )
    		ans = ( 1LL * ans + 1LL * calc( cur, k ) * ( a[r].f - a[l].f - 1 ) ) % base;
    	l = r;
    }
    printf ( "%d\n", ans );
    return 0;
}