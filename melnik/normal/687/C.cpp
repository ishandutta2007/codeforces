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

const int maxn = 505;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int dp[2][maxn][maxn];
int a[maxn];

void maximize( int &cnt, int cur ) {
	cnt = max( cur, cnt );
}

bool can[maxn];

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, k;
    scanf ( "%d%d", &n, &k );
    for ( int j = 0; j < n; j++ )
    	scanf ( "%d", &a[j] );
    dp[0][0][0] = 1;
    for ( int j = 0; j < n; j++ ) {
    	for ( int curSum1 = 0; curSum1 <= k; curSum1++ )
    		for ( int curSum2 = 0; curSum2 <= curSum1; curSum2++ ) {
    			int newSum = curSum1 + a[j];
    			if ( newSum <= k ) {
    				maximize( dp[1][curSum1 + a[j]][curSum2 + a[j]], dp[0][curSum1][curSum2] );
    				maximize( dp[1][curSum1 + a[j]][curSum2], dp[0][curSum1][curSum2] );
    			}
    			maximize( dp[1][curSum1][curSum2], dp[0][curSum1][curSum2] );
    		}
    	for ( int i = 0; i < maxn; i++ )
    		for ( int y = 0; y < maxn; y++ )
    			dp[0][i][y] = dp[1][i][y];
    }
    for ( int curSum2 = 0; curSum2 <= k; curSum2++ )
    	if ( dp[0][k][curSum2] )
    		can[curSum2] = true;
    int ans = 0;
    for ( int j = 0; j < maxn; j++ )
    	if ( can[j] )
    		++ans;
    printf ( "%d\n", ans );
    for ( int j = 0; j < maxn; j++ )
    	if ( can[j] )
    		printf( "%d ", j );
    return 0;
}