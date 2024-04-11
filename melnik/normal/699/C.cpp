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

const int maxn = 100500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int dp[maxn][3];
int a[maxn];

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    for ( int j = 0; j < n; j++ )
    	scanf ( "%d", &a[j] );
    for ( int j = 0; j < maxn; j++ )
    	dp[j][0] = dp[j][1] = dp[j][2] = inf;
    dp[0][0] = 0;
    for ( int j = 0; j < n; j++ ) {
    	dp[j + 1][0] = min( dp[j + 1][0], dp[j][0] + 1 );
    	dp[j + 1][0] = min( dp[j + 1][0], dp[j][1] + 1 );
    	dp[j + 1][0] = min( dp[j + 1][0], dp[j][2] + 1 );
    	if ( a[j] == 1 ) {
    		dp[j + 1][2] = min( dp[j + 1][2], dp[j][1] );
    		dp[j + 1][2] = min( dp[j + 1][2], dp[j][0] );
    	}
    	if ( a[j] == 2 ) {
    		dp[j + 1][1] = min( dp[j + 1][1], dp[j][2] );
    		dp[j + 1][1] = min( dp[j + 1][1], dp[j][0] );
    	}
    	if ( a[j] == 3 ) {
    		dp[j + 1][1] = min( dp[j + 1][1], dp[j][2] );
    		dp[j + 1][1] = min( dp[j + 1][1], dp[j][0] );
    		dp[j + 1][2] = min( dp[j + 1][2], dp[j][1] );
    		dp[j + 1][2] = min( dp[j + 1][2], dp[j][0] );
    	}
    }
    printf ( "%d\n", min( dp[n][0], min( dp[n][1], dp[n][2] ) ) );
    return 0;
}