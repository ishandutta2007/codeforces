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

const int MAXN = 100100;

int n, f[ MAXN ], cost[ MAXN ], g[ MAXN ];
vector< pair< int, int > > graph[ MAXN ];

long long cnt( long long a ) {
	return a * ( n - a );
}

void dfs( int v, int prev ) {
	f[v] = 1;
	for ( int i = 0; i < graph[v].size(); i++ ) {
		int next = graph[v][i].first;
		if ( next == prev ) continue;
		dfs( next, v );
		f[v] += f[next];
		g[ graph[v][i].second ] = f[ next ];
	}
}

void solve() {
	scanf("%d", &n);
	for ( int i = 1; i < n; i++ ) {
		int u, v; scanf("%d%d%d", &u, &v, &cost[i]);
		graph[u].push_back( make_pair( v, i ) );
		graph[v].push_back( make_pair( u, i ) );
	}
	dfs( 1, 0 );
	long long sum = 0;
	for ( int i = 1; i < n; i++ ) {
		sum += cnt( g[i] ) * cost[i];
	}
	long double se = n;
	se = se * ( se - 1 ) / 2;
	int q; scanf("%d", &q);
	for ( int i = 0; i < q; i++ ) {
		int r, w; scanf("%d%d", &r, &w);
		sum -= cnt( g[r] ) * cost[r];
		cost[r] = w;
		sum += cnt( g[r] ) * cost[r];
		long double result = (long double)sum / se;
		result = result * 3.0;
		printf("%.10f\n", (double)result);
		// cout << fixed << setprecision( 10 ) << result << "\n";
	}
}

int main() {
	time_t start = clock();
	int t; t = 1;
	for ( int i = 1; i <= t; i++ ) solve();
	fprintf( stderr, "Time: %lf\n", 1.0 * ( clock() - start ) / CLOCKS_PER_SEC );
    return 0;
}