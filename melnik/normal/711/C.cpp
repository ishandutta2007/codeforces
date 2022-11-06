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

const int maxn = 105;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];
int cost[maxn][maxn];
ll dp[maxn][maxn][maxn];

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, m, k;
    scanf ( "%d%d%d", &n, &m, &k );
    for ( int j = 0; j < n; j++ )
    	scanf ( "%d", &a[j] );
    for ( int j = 0; j < n; j++ )
    	for ( int i = 1; i <= m; i++ )
    		scanf ( "%d", &cost[j][i] );
    for ( int j = 0; j < maxn; j++ )
    	for ( int i = 0; i < maxn; i++ )
    		for ( int y = 0; y < maxn; y++ )
    			dp[j][i][y] = 1LL * inf * inf;
    dp[0][0][0] = 0LL;
    for ( int j = 0; j < n; j++ )
    	for ( int cnt = 0; cnt <= k; cnt++ )
    		for ( int col = 0; col <= m; col++ ) {
    			if ( a[j] ) {
    				if ( col != a[j] )
    					dp[j + 1][cnt + 1][a[j]] =
    						min( dp[j + 1][cnt + 1][a[j]], dp[j][cnt][col] );
    				if ( col == a[j] )
    					dp[j + 1][cnt][col] = 
    						min( dp[j + 1][cnt][col], dp[j][cnt][col] );
    			} else
    			for ( int y = 1; y <= m; y++ ) {
    				if ( col != y )
    					dp[j + 1][cnt + 1][y] = 
    						min( dp[j + 1][cnt + 1][y], dp[j][cnt][col] + 1LL * cost[j][y] ); 
    				if ( col == y ) 
    					dp[j + 1][cnt][y] = 
    						min( dp[j + 1][cnt][y], dp[j][cnt][col] + 1LL * cost[j][y] );
    			}
    		}
   	ll ans = 1LL * inf * inf;
   	for ( int j = 1; j <= m; j++ )
   		ans = min( ans, dp[n][k][j] );
   	if ( ans == 1LL * inf * inf )
   		printf ( "-1\n" );
   	else
   		printf ( "%I64d\n", ans );
    return 0;
}