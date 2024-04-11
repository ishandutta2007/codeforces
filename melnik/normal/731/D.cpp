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

const int maxn = 500500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

vector < int > a[maxn];
vector < int > b, c;
pair < int, int > ans[maxn];
int sum[2 * maxn];

void calc( int pos1, int pos2, int mod ) {
	b = a[pos1];
	c = a[pos2];
	int sz1 = b.size();
	int sz2 = c.size();
	for ( int j = 0; j < min( sz1, sz2 ); j++ ) {
		if ( b[j] == c[j] )
			continue;
		if ( b[j] < c[j] ) {
			ans[pos1] = mp( -b[j], mod - c[j] - 1 );
			return;
		}
		if ( b[j] > c[j] ) {
			ans[pos1] = mp( mod - b[j], mod - c[j] - 1 );
			return;
		}
	}
	if ( sz1 > sz2 ) {
		puts( "-1" );
		exit( 0 );
	}
	ans[pos1] = mp( 0, mod -1 );
}

bool good( int pos1, int pos2, int cur, int mod ) {
	b = a[pos1];
	c = a[pos2];
	int sz1 = b.size();
	int sz2 = c.size();
	for ( int j = 0; j < sz1; j++ )
		b[j] = ( b[j] + cur ) % mod;
	for ( int j = 0; j < sz2; j++ )
		c[j] = ( c[j] + cur ) % mod;
	for ( int j = 0; j < min( sz1, sz2 ); j++ ) {
		if ( b[j] < c[j] )
			return true;
		if ( b[j] == c[j] )
			continue;
		if ( b[j] > c[j] )
			return false;
	}
	if ( sz1 > sz2 )
		return false;
	return true;
}

bool correct( int cur, int n, int mod ) {
	for ( int j = 1; j < n; j++ )
		if ( !good( j - 1, j, cur, mod ) )
			return false;
	return true;
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, mod;
    scanf ( "%d%d", &n, &mod );
    for ( int j = 0; j < n; j++ ) {
    	int x;
    	scanf ( "%d", &x );
    	for ( int i = 0; i < x; i++ ) {
    		int y;
    		scanf ( "%d", &y );
    		--y;
    		a[j].pb( y );
    	}
    }
 	for ( int j = 1; j < n; j++ )
 		calc( j - 1, j, mod );
 	// int L = -mod, R = mod;
 	// for ( int j = 0; j < n - 1; j++ ) {
 	// 	L = max( L, ans[j].f );
 	// 	R = min( R, ans[j].s );
 	// }
 	for ( int j = 0; j < n - 1; j++ ) {
 		if ( ans[j].f >= 0 ) {
 			++sum[ans[j].f];
 			--sum[ans[j].s + 1];
 		} else {
 			++sum[0];
 			--sum[ans[j].s + 1];
 			++sum[ans[j].f + mod];
 			--sum[mod];
 		}
 	}
 	int curSum = 0;
 	for ( int j = 0; j < mod; j++ ) {
 		curSum += sum[j];
 		if ( curSum == n - 1 && correct( j, n, mod ) ) {
 			printf ( "%d\n", j );
 			return 0;
 		}
 	}
 	// if ( L > R ) {
  //   	puts( "-1" );
  //   	return 0;
 	// }

 	// if ( correct( L, n, mod ) ) {
 	// 	printf ( "%d\n", L );
 	// 	return 0;
 	// }
 	puts( "-1" );
    return 0;
}