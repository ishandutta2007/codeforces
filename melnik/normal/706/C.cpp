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

int c[maxn];
ll dp[maxn][2];
string t[maxn];

bool good( bool F, bool S, int pos ) {
	string s1 = t[pos];
	string s2 = t[pos + 1];
	if ( F )
		reverse( s1.begin(), s1.end() );
	if ( S )
		reverse( s2.begin(), s2.end() );
	return s1 <= s2;
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    for ( int j = 0; j < n; j++ )
    	scanf ( "%d", &c[j] );
    scanf ( "\n" );
    for ( int j = 0; j < maxn; j++ )
    	dp[j][0] = dp[j][1] = 1LL * inf * inf;
    for ( int j = 0; j < n; j++ )
    	cin >> t[j];
    dp[1][0] = 0LL;
    dp[1][1] = 1LL * c[0];
    for ( int j = 1; j < n; j++ ) {
    	if ( good( 0, 0, j - 1 ) )
    		dp[j + 1][0] = min( dp[j + 1][0], dp[j][0] );
    	if ( good( 0, 1, j - 1 ) )
    		dp[j + 1][1] = min( dp[j + 1][1], dp[j][0] + 1LL * c[j] );
    	if ( good( 1, 0, j - 1 ) )
    		dp[j + 1][0] = min( dp[j + 1][0], dp[j][1] );
    	if ( good( 1, 1, j - 1 ) )
    		dp[j + 1][1] = min( dp[j + 1][1], dp[j][1] + 1LL * c[j] );
    }
    ll mi = min( dp[n][0], dp[n][1] );
    if ( mi == 1LL * inf * inf )
    	printf ( "-1\n" );
    else
    	cout << mi << endl;
    return 0;
}