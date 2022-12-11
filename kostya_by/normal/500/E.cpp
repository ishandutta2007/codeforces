#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 200200;
const int MAXP = 20;

int n, x[ MAXN ], y[ MAXN ], f[ MAXN ];

int bsearch( int value ) {
	int left = 2, right = n, result = 1;
	while ( left <= right ) {
		int middle = ( left + right ) / 2;
		if ( value >= x[ middle ] ) {
			result = max( result, middle );
			left = middle + 1;
		} else right = middle - 1;
	}
	return result;
}

int tree[ 4 * MAXN ];

void modify( int v, int l, int r, int pos, int value ) {
	if ( l == r ) {
		tree[v] = value;
		return;
	}
	int x = (l + r) / 2;
	if ( pos <= x ) 
		modify( v + v, l, x, pos, value );
	else
		modify( v + v + 1, x + 1, r, pos, value );
	tree[v] = max( tree[v + v], tree[v + v + 1] );
}

int query( int v, int l, int r, int ll, int rr ) {
	if ( l == ll && rr == r ) return tree[v];
	int result = 0;
	int x = (l + r) / 2;
	if ( ll <= x ) 
		result = max( result, query( v + v, l, x, ll, min( rr, x ) ) );
	if ( x + 1 <= rr )
		result = max( result, query( v + v + 1, x + 1, r, max( x + 1, ll ), rr ) );
	return result; 
}

int g[ MAXP ][ MAXN ], cost[ MAXP ][ MAXN ];

void solve() {
	scanf("%d", &n);
	for ( int i = 1; i <= n; i++ ) scanf("%d%d", &x[i], &y[i]);
	// ---------------------------
	for ( int i = n; i >= 1; i-- ) {
		int index = bsearch( x[i] + y[i] );
		f[i] = max( x[i] + y[i], query( 1, 1, n, i, index ) );
		modify( 1, 1, n, i, f[i] );
		int pos = bsearch( f[i] );
		g[0][i] = pos + 1;
		if ( pos == n ) cost[0][i] = 0; else cost[0][i] = x[ pos + 1 ] - f[i];
		// ------------
		// cerr << i << " " << index << " " << f[i] << " " << pos << " " << g[0][i] << " " << cost[0][i] << "\n"; 
	}
	for ( int i = 0; i < MAXP; i++ ) g[i][n + 1] = n + 1;
	for ( int i = 1; i < MAXP; i++ )
		for ( int j = 1; j <= n + 1; j++ )
		{
			g[i][j] = g[i - 1][ g[i - 1][j] ];
			cost[i][j] = cost[i - 1][j] + cost[i - 1][ g[i - 1][j] ]; 
		}
	//    -----------------------
	int q; scanf("%d", &q);
	for ( int it = 0; it < q; it++ ) {
		int a, b; scanf("%d%d", &a, &b);
		if ( g[0][a] > b ) {
			printf("0\n");
			continue;
		}
		int answer = 0;
		for ( int i = MAXP - 1; i >= 0; i-- )
			if ( g[0][ g[i][a] ] <= b ) {
				// cerr << a << " -> " << g[i][a] << "\n";
				answer += cost[i][a];
				a = g[i][a];
			}
		answer += cost[0][a];
		printf("%d\n", answer);
	}
}

int main() {
	time_t start = clock();
	int t; t = 1;
	for ( int i = 1; i <= t; i++ ) solve();
	fprintf( stderr, "Time: %lf\n", 1.0 * ( clock() - start ) / CLOCKS_PER_SEC );
    return 0;
}