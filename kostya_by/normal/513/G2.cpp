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

const int MAXN = 33;

int n, k, p[ MAXN ];
double f[ MAXN ][ MAXN ], g[ MAXN ][ MAXN ]; 

void perform_iteration() {
	for ( int i = 1; i <= n; i++ )
		for ( int j = 1; j <= n; j++ )
			g[i][j] = 0.0;
	int count = ( n * (n - 1) / 2 ) + n;
	for ( int l = 1; l <= n; l++ )
		for ( int r = l; r <= n; r++ )
			for ( int i = 1; i <= n; i++ )
				for ( int j = i + 1; j <= n; j++ ) {
					int new_i = i;
					if ( l <= i && i <= r )
						new_i = l + r - i;
					int new_j = j;
					if ( l <= j && j <= r )
						new_j = l + r - j;
					if ( new_i < new_j )
						g[new_i][new_j] += f[i][j];
					else
						g[new_j][new_i] += 1.0 - f[i][j];
				}
	for ( int i = 1; i <= n; i++ )
		for ( int j = i + 1; j <= n; j++ )
			f[i][j] = g[i][j] / count;
}

// 1 1: 1 2 3
// 1 2: 2 1 3
// 1 3: 3 2 1
// 2 2: 1 2 3
// 2 3: 1 3 2
// 3 3: 1 2 3

void solve() {
	scanf("%d%d", &n, &k);
	for ( int i = 1; i <= n; i++ ) {
		scanf("%d", &p[i]);
	}	
	for ( int i = 1; i <= n; i++ )
		for ( int j = i + 1; j <= n; j++ )
				f[i][j] = p[i] > p[j];
	while ( k-- ) 
		perform_iteration();
	double answer = 0.0;
	for ( int i = 1; i <= n; i++ ) {
		for ( int j = i + 1; j <= n; j++ ) {
			answer += f[i][j];
			// cerr << f[i][j] << " ";
		}
		// cerr << "\n";
	}
	cout << fixed << setprecision( 15 ) << answer << "\n";
}

int main() {
	time_t start = clock();
	int t; t = 1;
	for ( int i = 1; i <= t; i++ ) solve();
	fprintf( stderr, "Time: %lf\n", 1.0 * ( clock() - start ) / CLOCKS_PER_SEC );
    return 0;
}