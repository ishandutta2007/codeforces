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
const int base = 1e9 + 7;

ll L[maxn];
ll R[maxn];
int Y[maxn];
int cur[maxn];
int cur2[maxn];

vector < int > dp[20][20][64];

void precalc( int height ) {
	for ( int j = 0; j <= height; j++ )
		for ( int i = 0; i < 64; i++ ) {
			dp[height][j][i].clear();
			for ( int y = 0; y <= height; y++ )
				dp[height][j][i].pb( 0 );
		}
	for ( int j = 0; j <= height; j++ ) {
		dp[height][j][0][j] = 1;
		dp[height][j][0][max( 0, j - 1)] = 1;
		dp[height][j][0][min( height, j + 1)] = 1;
	}
	for ( int st = 0; st < 59; st++ )
		for ( int j = 0; j <= height; j++ )
			for ( int newHeight = 0; newHeight <= height; newHeight++ )
				for ( int rightestHeight = 0; rightestHeight <= height; rightestHeight++ )
					dp[height][j][st + 1][rightestHeight] = ( dp[height][j][st + 1][rightestHeight]
						+ 1LL * dp[height][j][st][newHeight]
						* dp[height][newHeight][st][rightestHeight] ) % base;
}

void solve( ll len, int height ) {
	for ( int j = 0; j <= 50; j++ )
		cur2[j] = 0;
	for ( int j = height + 1; j <= 50; j++ )
		cur[j] = 0;
	for ( int j = 0; j < 60; j++ )
		if ( len & ( 1LL << j ) ) {
			for ( int i = 0; i <= height; i++ )
				for ( int newHeight = 0; newHeight <= height; newHeight++ )
					cur2[newHeight] = ( cur2[newHeight] +
						1LL * cur[i] * dp[height][i][j][newHeight] ) % base;

			for ( int i = 0; i <= height; i++ ) {
				cur[i] = cur2[i];
				cur2[i] = 0;
			}
		}
}

int solution( int n, ll k ) {
	cur[0] = 1;
	R[n - 1] = k;
	for ( int j = 0; j <= 15; j++ )
		precalc( j );
	for ( int j = 0; j < n; j++ )
		solve( R[j] - L[j], Y[j] );
	return cur[0];
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    ll k;
    cin >> n >> k;
    for ( int j = 0; j < n; j++ )
    	cin >> L[j] >> R[j] >> Y[j];
    cout << solution( n, k ) << endl;
    return 0;
}