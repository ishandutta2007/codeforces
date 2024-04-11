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

const int MAXN = 505;
const int MAXD = 1010;

int n, m, w[ MAXN ], b[ MAXD ], p[ MAXN ];
pair< int, int > books[ MAXN ];

void solve() {
	scanf("%d%d", &n, &m);
	for ( int i = 1; i <= n; i++ ) scanf("%d", &w[i]);
	for ( int i = 1; i <= m; i++ ) scanf("%d", &b[i]);
	for ( int i = 1; i <= n; i++ ) books[i] = make_pair( MAXD, i );
	for ( int i = m; i >= 1; i-- ) books[ b[i] ].first = i;
	sort( books + 1, books + n + 1 );   
	for ( int i = 1; i <= n; i++ ) p[i] = books[i].second;
	// for ( int i = 1; i <= n; i++ ) fprintf(stderr, "%d %d\n", books[i].first, books[i].second );
	// --------------------------
	int answer = 0;
	for ( int i = 1; i <= m; i++ ) {
		int pos = -1;
		for ( int j = 1; j <= n; j++ ) if ( p[j] == b[i] ) pos = j;
		for ( int j = pos; j > 1; j-- ) {
			answer += w[ p[j - 1] ];
			p[j] = p[j - 1];
		}
		p[1] = b[i];
		// for ( int j = 1; j <= n; j++ ) fprintf(stderr, "%d ", p[j] ); fprintf(stderr, "\n");
	}
	printf("%d\n", answer);
}

int main() {
	time_t start = clock();
	int t; t = 1;
	for ( int i = 1; i <= t; i++ ) solve();
	fprintf( stderr, "Time: %lf\n", 1.0 * ( clock() - start ) / CLOCKS_PER_SEC );
    return 0;
}