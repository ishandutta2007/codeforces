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

pair < int, int > a[maxn];

ld SQRT( ll x ) {
	ld l = 0;
	ld r = 3e9;
	int it = 300;
	while ( it-- ) {
		ld mid = ( l + r ) / 2.0L;
		if ( mid * mid <= x )
			l = mid;
		else
			r = mid;
	}
	return ( l + r ) / 2.0L;
}

ld calc( int id1, int id2, int curId ) {
	ll A = a[id1].s - a[id2].s;
	ll B = a[id2].f - a[id1].f;
	ll C = -1LL * A * a[id1].f - 1LL * B * a[id1].s;
	int x = a[curId].f;
	int y = a[curId].s;
	return fabs( 1.0L * ( 1LL * A * x + 1LL * B * y + C ) / SQRT( A * A + B * B ) / 2.0L );
}

// inline ld dist( int id1, int id2 ) {
// }

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    for ( int j = 0; j < n; j++ )
    	scanf ( "%d%d", &a[j].f, &a[j].s );
    ld ans = 1.0L * inf * inf;
    for ( int j = 0; j < n; j++ ) {
    	int id1 = j;
    	int id2 = ( j + 1 ) % n;
    	int id3 = ( j + 2 ) % n;
    	ans = min( ans, calc( id1, id3, id2 ) );
    	ans = min( ans, calc( id1, id2, id3 ) );
    	ans = min( ans, calc( id2, id3, id1 ) );
    }

    // for ( int j = 0; j < n; j++ )
   	// 	for ( int i = j + 2; i < n; i++ ) {
   	// 		int id1 = j;
   	// 		int id2 = ( j + 1 ) % n;
   	// 		int id3 = i % n;
   	// 		int id4 = ( i + 1 ) % n;
   	// 		ans = min( ans, dist( id1, id2 ) );
   	// 		ans = min( ans, dist( id1, id3 ) );
   	// 		ans = min( ans, dist( id1, id4 ) );
   	// 		ans = min( ans, dist( id2, id3 ) );
   	// 		ans = min( ans, dist( id2, id4 ) );
   	// 		ans = min( ans, dist( id3, id4 ) );
   	// 	}
    cout << fixed << setprecision( 20 ) << ans << endl;
    return 0;
}