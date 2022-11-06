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

ll a[maxn][maxn];

bool correct( int n ) {
	ll minSum = 1LL * inf * inf;
	ll maxSum = -1LL * inf * inf;
	for ( int j = 0; j < n; j++ ) {
		ll sum = 0LL;
		for ( int i = 0; i < n; i++ )
			sum += a[j][i];
		minSum = min( minSum, sum );
		maxSum = max( maxSum, sum );
		sum = 0LL;
		for ( int i = 0; i < n; i++ )
			sum += a[i][j];
		minSum = min( minSum, sum );
		maxSum = max( maxSum, sum );
	}
	ll sum = 0LL;
	for ( int j = 0; j < n; j++ )
		sum += a[j][j];
	minSum = min( minSum, sum );
	maxSum = max( maxSum, sum );
	sum = 0LL;
	for ( int j = 0; j < n; j++ )
		sum += a[j][n - j - 1];
	minSum = min( minSum, sum );
	maxSum = max( maxSum, sum );
	if ( minSum != maxSum )
		return 0;
	return 1;
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    int x, y;
    for ( int j = 0; j < n; j++ )
    	for ( int i = 0; i < n; i++ ) {
    		scanf ( "%lld", &a[j][i] );
    		if ( !a[j][i] )
    			x = j, y = i;
    	}
    if ( n == 1 ) {
    	printf ( "1\n" );
    	return 0;
    }
    int dx = x - 1;
    if ( dx < 0 )
    	dx = x + 1;
    ll sum = 0LL;
    for ( int j = 0; j < n; j++ )
    	sum += a[dx][j];
    for ( int j = 0; j < n; j++ )
    	sum -= a[x][j];
    if ( sum <= 0LL ) {
    	printf ( "-1\n" );
    	return 0;
    }
    a[x][y] = sum;
    if ( correct( n ) )
    	printf ( "%lld\n", sum );
    else
    	printf ( "-1\n" );
    return 0;
}