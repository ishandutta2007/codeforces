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

const int maxn = 1050;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];
int b[maxn];
int used[maxn];
vector < int > edge[maxn];
vector < int > comp[maxn];
int dp[maxn][maxn];
int timer;

void dfs( int v ) {
	used[v] = true;
	int sz = edge[v].size();
	comp[timer].pb( v );
	for ( int j = 0; j < sz; j++ ) {
		int to = edge[v][j];
		if ( !used[to] )
			dfs( to );
	}
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, m, w;
    scanf ( "%d%d%d", &n, &m, &w );
    for ( int j = 1; j <= n; j++ )
    	scanf ( "%d", &a[j] );
    for ( int j = 1; j <= n; j++ )
    	scanf ( "%d", &b[j] );
    for ( int j = 0; j < m; j++ ) {
    	int u, v;
    	scanf ( "%d%d", &u, &v );
    	edge[u].pb( v );
    	edge[v].pb( u );
    }
    for ( int j = 1; j <= n; j++ )
    	if ( !used[j] ) {
    		dfs( j );
    		++timer;
    	}
    for ( int j = 0; j < timer; j++ ) 
    	for ( int i = 0; i <= w; i++ ) {
    		dp[j + 1][i] = max( dp[j + 1][i], dp[j][i] );
    		int sz = comp[j].size();
    		int sumW = 0;
    		int sumB = 0;
    		for ( int y = 0; y < sz; y++ ) {
    			int to = comp[j][y];
    			sumW += a[to];
    			sumB += b[to];
    			if ( i + a[to] <= w )
    				dp[j + 1][i + a[to]] = max( dp[j + 1][i + a[to]], 
    						dp[j][i] + b[to] );
    		}
    		if ( sumW + i <= w )
    			dp[j + 1][i + sumW] = max( dp[j + 1][i + sumW], dp[j][i] + sumB );
    	}
    int ans = 0;
   	for ( int j = 0; j <= w; j++ )
   		ans = max( ans, dp[timer][j] );
   	printf ( "%d\n", ans );
    return 0;
}