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

const int MAXN = 333;

int n, p[ MAXN ], result[ MAXN ];
char graph[ MAXN ][ MAXN ];
bool used[ MAXN ];
vector< int > positions, numbers;

void dfs( int v ) {
	used[v] = true;
	positions.push_back( v );
	numbers.push_back( p[v] );
	for ( int i = 1; i <= n; i++ )
		if ( graph[v][i] == '1' && used[i] == false )
			dfs( i ); 
}

void solve() {
	scanf("%d", &n);
	for ( int i = 1; i <= n; i++ ) scanf("%d", &p[i]);
	for ( int i = 1; i <= n; i++ ) scanf("%s", graph[i] + 1 );
	for ( int i = 1; i <= n; i++ ) {
		if ( used[i] ) continue;
		dfs( i );
		sort( positions.begin(), positions.end() );
		sort( numbers.begin(), numbers.end() );
		for ( int j = 0; j < positions.size(); j++ ) result[ positions[j] ] = numbers[j];
		positions.clear();
		numbers.clear();
	} 
	for ( int i = 1; i <= n; i++ ) printf("%d ", result[i]); printf("\n");
}

int main() {
	time_t start = clock();
	int t; t = 1;
	for ( int i = 1; i <= t; i++ ) solve();
	fprintf( stderr, "Time: %lf\n", 1.0 * ( clock() - start ) / CLOCKS_PER_SEC );
    return 0;
}