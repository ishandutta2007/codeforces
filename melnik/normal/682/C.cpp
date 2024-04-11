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

const int maxn = 100500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

vector < pair < int, int > > edge[maxn];
int a[maxn];
int treeSize[maxn];
bool used[maxn];
int ans;
int n;

pair < ll, ll > tree[4 * maxn];

int dfs( int v ) {
	used[v] = true;
	int sz = edge[v].size();
	int curSz = 0;
	for ( int j = 0; j < sz; j++ ) {
		int to = edge[v][j].f;
		if ( !used[to] )
			curSz += dfs( to );
	}
	return treeSize[v] = curSz + 1;
}

void init() {
	for ( int j = 0; j < maxn; j++ )
		used[j] = false;
}

void add( int v, int tl, int tr, int l, int r, int x ) {
	if ( l > r )
		return;
	if ( tl == l && tr == r ) {
		tree[v].s += 1LL * x;
		return;
	}
	int mid = ( tl + tr ) >> 1;
	int newV = v << 1;
	add( newV, tl, mid, l, min( r, mid ), x );
	add( newV + 1, mid + 1, tr, max( mid + 1, l ), r, x );
	tree[v].f = max( tree[newV].f + tree[newV].s, tree[newV + 1].f + tree[newV + 1].s );
}

void update( int v, int tl, int tr, int pos, int x ) {
	if ( tl == tr ) {
		tree[v] = mp( 1LL * x, 0LL );
		return;
	}
	int mid = ( tl + tr ) >> 1;
	int newV = v << 1;
	if ( pos <= mid )
		update( newV, tl, mid, pos, x );
	else
		update( newV + 1, mid + 1, tr, pos, x );
	tree[v].f = max( tree[newV].f + tree[newV].s, tree[newV + 1].f + tree[newV + 1].s );
}

ll getMax( int v, int tl, int tr, int l, int r, ll cur ) {
	if ( l > r )
		return -1LL * inf * inf;
	cur += tree[v].s;
	if ( tl == l && tr == r )
		return tree[v].f + cur;
	int mid = ( tl + tr ) >> 1;
	int newV = v << 1;
	return max( getMax( newV, tl, mid, l, min( mid, r ), cur ),
	 	getMax( newV + 1, mid + 1, tr, max( mid + 1, l ), r, cur ) );
}

bool correct ( int v, int dist ) {
	return 1LL * a[v] >= getMax( 1, 1, n, 1, dist, 0LL );
}

void dfs( int v, int dist ) {
	used[v] = true;
	if ( !correct( v, dist ) ) {
		ans += treeSize[v];
		return;
	}
	int sz = edge[v].size();
	for ( int j = 0; j < sz; j++ ) {
		int to = edge[v][j].f;
		if ( used[to] )
            continue;
		int x = edge[v][j].s;
		add( 1, 1, n, 1, dist, x );
		update( 1, 1, n, dist + 1, x );
		dfs( to, dist + 1 );
		add( 1, 1, n, 1, dist, -x );
	}
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    scanf ( "%d", &n );
    for ( int j = 0; j < n; j++ )
    	scanf ( "%d", &a[j] );
    for ( int j = 1; j < n; j++ ) {
    	int v, x;
    	scanf ( "%d%d", &v, &x );
    	edge[j].pb( mp( v - 1, x ) );
    	edge[v - 1].pb( mp( j, x ) );
    }
    dfs( 0 );
    init();
    dfs( 0, 0 );
    printf( "%d\n", ans );
    return 0;
}