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

const int maxn = 100;
const int inf = 1e9;
const double eps = 1e-8;
const int base = 1073676287;

// vector < pair < int, int > > edge[maxn]; 
int edge[maxn][maxn];
int dp[maxn][maxn][maxn][2];

// inline void solve( int l, int r, int need, int where ) {
// 	if ( !need ) {
// 		dp[l][r][need][where] = 0;
// 		return;
// 	}
// 	if ( dp[l][r][need][where] != inf )
// 		return;
// 	int v = where ? r : l;
// 	int tl = l, tr = r;
// 	if ( where )
// 		--tr;
// 	else
// 		++tl;
// 	for ( int j = tl; j <= tr; j++ ) {
// 		int to = j;
// 		int w = edge[v][j];
// 		solve( tl, to, need - 1, 1 );
// 		solve( to, tr, need - 1, 0 );
// 		dp[l][r][need][where] = min( dp[l][r][need][where],
// 			w + dp[tl][to][need - 1][1] );
// 		dp[l][r][need][where] = min( dp[l][r][need][where],
// 			w + dp[to][tr][need - 1][0] );
// 	}
// 	// int sz = edge[v].size();
// 	// for ( int j = 0; j < sz; j++ ) {
// 	// 	int to = edge[v][j].f;
// 	// 	int w = edge[v][j].s;
// 	// 	if ( to > tr || to < tl )
// 	// 		continue;
// 	// 	dp[l][r][need][where] = min( dp[l][r][need][where],
// 	// 		w + solve( tl, to, need - 1, 1 ) );
// 	// 	dp[l][r][need][where] = min( dp[l][r][need][where],
// 	// 		w + solve( to, tr, need - 1, 0 ) );
// 	// }
// 	// return dp[l][r][need][where];
// } 

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    for ( int j = 0; j < maxn; j++ )
    	for ( int i = 0; i < maxn; i++ ) {
    		edge[j][i] = inf;
    		for ( int y = 1; y < maxn; y++ )
    			dp[j][i][y][0] = dp[j][i][y][1] = inf;
    	}
    int n, k;
    scanf ( "%d%d", &n, &k );
 	int m;
 	scanf ( "%d", &m );
    for ( int j = 0; j < m; j++ ) {
    	int u, v, c;
    	scanf ( "%d%d%d", &u, &v, &c );
    	edge[u][v] = min( edge[u][v], c );
    }
    int ans = inf;
    for ( int len = 1; len <= n; len++ ) 
    	for ( int l = 1; l + len - 1 <= n; l++ )
    		for ( int j = 1; j <= k; j++ ) {
    			int r = l + len - 1;
    			for ( int to = l + 1; to <= r; to++ ) {
    				dp[l][r][j][0] = min( dp[l][r][j][0],
    					edge[l][to] + dp[l + 1][to][j - 1][1] );
    				dp[l][r][j][0] = min( dp[l][r][j][0],
    					edge[l][to] + dp[to][r][j - 1][0] );
    			}

    			for ( int to = l; to < r; to++ ) {
    				dp[l][r][j][1] = min( dp[l][r][j][1],
    					edge[r][to] + dp[l][to][j - 1][1] );
    				dp[l][r][j][1] = min( dp[l][r][j][1],
    					edge[r][to] + dp[to][r - 1][j - 1][0] );
    			}

    		} 
    for ( int j = 0; j < maxn; j++ )
    	for ( int i = 0; i < maxn; i++ ) {
    		ans = min( ans, dp[j][i][k - 1][0] );
    		ans = min( ans, dp[j][i][k - 1][1] );
    	}
    // for ( int j = 1; j <= n; j++ ) {
    // 	solve( 1, j, k - 1, 1 );
    // 	solve( j, n, k - 1, 0 );
    // 	ans = min( ans, min( dp[1][j][k - 1][1], dp[j][n][k - 1][0] ) );
    // }
   	if ( ans != inf )
    	printf ( "%d\n", ans );
    else
    	puts( "-1" );
    return 0;
}