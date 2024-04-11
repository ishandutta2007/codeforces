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

const int maxn = 1000500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];
int ksor[maxn];
pair < pair < int, int >, int > queries[maxn];
int answers[maxn];
int tree[4 * maxn];
map < int, int > cur;

int findKsor( int v, int tl, int tr, int l, int r ) {
	if ( l > r )
		return 0;
	if ( tl == l && tr == r )
		return tree[v];
	int newV = v << 1;
	int mid = ( tl + tr ) >> 1;
	return findKsor( newV, tl, mid, l, min( mid, r ) ) ^
		findKsor( newV + 1, mid + 1, tr, max( mid + 1, l ), r );
}

void update( int v, int tl, int tr, int pos, int cnt ) {
	if ( tl == tr ) {
		tree[v] = cnt;
		return;
	}
	int newV = v << 1;
	int mid = ( tl + tr ) >> 1;
	if ( pos <= mid )
		update( newV, tl, mid, pos, cnt );
	else
		update( newV + 1, mid + 1, tr, pos, cnt );
	tree[v] = tree[newV] ^ tree[newV + 1];
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
    ksor[0] = 0;
    for ( int j = 1; j <= n; j++ )
    	ksor[j] = ksor[j - 1] ^ a[j];
    int q;
    scanf ( "%d", &q );
    for ( int j = 0; j < q; j++ ) {
    	int l, r;
    	scanf ( "%d%d", &l, &r );
    	queries[j] = mp( mp( r, l ), j );
    }
    sort( queries, queries + q );
    int curR = 0;
    for ( int j = 0; j < q; j++ ) {
    	for ( int i = curR + 1; i <= queries[j].f.f; i++ ) {
    		if ( cur.find( a[i] ) != cur.end() ) 
    			update( 1, 1, n, cur[a[i]], 0 );
    		cur[a[i]] = i;
    		update( 1, 1, n, i, a[i] );
    	}
    	curR = queries[j].f.f;
    	int l = queries[j].f.s;
    	int r = queries[j].f.f;
    	answers[queries[j].s] = ksor[r] ^ ksor[l - 1] ^ findKsor( 1, 1, n, l, r );
    }
    for ( int j = 0; j < q; j++ )
    	printf ( "%d\n", answers[j] );
    return 0;
}