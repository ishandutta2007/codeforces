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

const int maxn = 2050;
const int inf = 2e9 + 100;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];
int b[maxn];

int dp[maxn][maxn];


int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    for ( int j = 0; j < maxn; j++ )
    	for ( int i = 0; i < maxn; i++ )
    		dp[j][i] = inf;
    int n, k, p;
    scanf ( "%d%d%d", &n, &k, &p );
    for ( int j = 0; j < n; j++ )
    	scanf ( "%d", &a[j] );
    for ( int j = 0; j < k; j++ )
    	scanf ( "%d", &b[j] );
    sort( a, a + n );
    sort( b, b + k );
    dp[0][0] = 0;
    for ( int j = 0; j < n; j++ )
    	for ( int i = 0; i < k; i++ ) {
    		dp[j][i + 1] = min( dp[j][i + 1], dp[j][i] );
    		dp[j + 1][i + 1] = min( dp[j + 1][i + 1], max( abs( b[i] - a[j] ) + abs( p - b[i] ), dp[j][i] ) );
    	}
    int ans = inf;
    for ( int j = 0; j <= k; j++ )
    	ans = min( ans, dp[n][j] );
    printf( "%d\n", ans );
    return 0;
}