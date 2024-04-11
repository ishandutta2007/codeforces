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

const int MAXN = 4040;
const int MAXB = 4040;
const int MAXQ = 20020;
const int MAXT = 20020;

struct item {
	int c, h, t; 
	item( int c = 0, int h = 0, int t = 0 ) : c( c ), h( h ), t( t ) {};
};

struct knapsack {
	int n, f[ MAXN ][ MAXB ], g[ MAXB ];
	knapsack() {
		n = 0;
		memset( f, -1, sizeof( f ) );
		memset( g, 0, sizeof( g ) );
		f[0][0] = 0;
	}
	void add( int c, int h ) {
		++n;
		for ( int i = 0; i < MAXB; i++ ) {
			f[n][i] = f[n - 1][i];
			if ( i - c < 0 ) continue;
			if ( f[n - 1][i - c] == -1 ) continue;
			f[n][i] = max( f[n][i], f[n - 1][i - c] + h );   
		}
		g[0] = f[n][0];
		for ( int i = 1; i < MAXB; i++ ) g[i] = max( g[i - 1], f[n][i] ); 
	}
	void erase() {
		--n;
		g[0] = f[n][0];
		for ( int i = 1; i < MAXB; i++ ) g[i] = max( g[i - 1], f[n][i] ); 
	}
};

int n, p, q, answer[ MAXQ ];
item items[ MAXN ]; 
vector< pair< int, int > > queries[ MAXT ];
knapsack fi, se;

bool cmp( item a, item b ) {
	return a.t < b.t;
} 

int l = 1, r = 0;

void add() {
	++r;
	// cerr << "Add " << r << "\n";
	se.add( items[r].c, items[r].h );
}

void erase() {
	// cerr << "Erase " << l << "\n";
	if ( fi.n == 0 ) {
		while ( se.n ) se.erase();
		for ( int i = r; i >= l; i-- )   fi.add( items[i].c, items[i].h );
	}
	fi.erase();
	++l;
}

void solve() {
	scanf("%d%d", &n, &p);
	for ( int i = 1; i <= n; i++ ) scanf("%d%d%d", &items[i].c, &items[i].h, &items[i].t );
	sort( items + 1, items + n + 1, cmp );
	scanf("%d", &q);
	for ( int i = 1; i <= q; i++ ) {
		int a, b; scanf("%d%d", &a, &b);
		queries[ a ].push_back( make_pair( i, b ) );
	}
	int ptr1 = 0, ptr2 = 0;
	for ( int t = 1; t < MAXT; t++ ) {
		while ( true ) {
			if ( ptr2 == n ) break;
			if ( items[ ptr2 + 1 ].t > t ) break;
			add();
			ptr2 += 1;
		}
		while ( true ) {
			if ( ptr1 == n ) break;
			if ( items[ ptr1 + 1 ].t + p - 1 >= t ) break;
			erase();
			ptr1 += 1;
		}
		for ( int i = 0; i < queries[t].size(); i++ ) {
			int id = queries[t][i].first;
			int b = queries[t][i].second;
			int result = 0;
			// cerr << id << " " << l << " " << r << " " << fi.n << " " << se.n << "\n";
			for ( int j = 0; j <= b; j++ ) result = max( result, fi.g[j] + se.g[b - j] );
			answer[ id ] = result;
		}
	}
	for ( int i = 1; i <= q; i++ ) printf("%d\n", answer[i]);
}

int main() {
	time_t start = clock();
	int t; t = 1;
	for ( int i = 1; i <= t; i++ ) solve();
	fprintf( stderr, "Time: %lf\n", 1.0 * ( clock() - start ) / CLOCKS_PER_SEC );
    return 0;
}