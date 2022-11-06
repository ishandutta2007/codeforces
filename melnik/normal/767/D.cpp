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

const int maxn = 10000500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];
pair < int, int > b[maxn];
int c[maxn];

inline bool correct( int sz, int k, int n ) {
	for ( int j = 0; j < maxn; j++ )
		a[j] = 0;
	for ( int j = 0; j < n; j++ )
		++a[c[j]];
	for ( int j = 0; j < sz; j++ )
		++a[b[j].f];

	int it = 0;
	int curTime = 0;
	int curNeed = k;
	while ( it < maxn ) {
		if ( !curNeed ) {
			curNeed = k;
			++curTime;
			continue;
		}
		if ( a[it] && it < curTime ) 
			return false;
		if ( a[it] ) {
			--a[it];
			--curNeed;
			continue;
		}
		if ( !a[it] )
			++it;
	}
	return true;
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, m, k;
    scanf ( "%d%d%d", &n, &m, &k );
    for ( int j = 0; j < n; j++ )
    	scanf ( "%d", &c[j] );
    for ( int j = 0; j < m; j++ ) {
    	scanf ( "%d", &b[j].f );
    	b[j].s = j + 1;
    }
    sort( b, b + m );
    reverse( b, b + m );
    int l, r;
    l = 0, r = m;
    while ( r - l ) {
    	int mid = ( l + r ) >> 1;
    	if ( correct( mid, k, n ) )
    		l = mid + 1;
    	else
    		r = mid;
    }
    if ( correct( l, k, n ) ) {
    	printf ( "%d\n", l );
    	for ( int j = 0; j < l; j++ )
    		printf ( "%d ", b[j].s );
        return 0;
    }
    if ( correct( l - 1, k, n ) ) {
    	printf ( "%d\n", l - 1 );
    	for ( int j = 0; j < l - 1; j++ )
    		printf ( "%d ", b[j].s );
        return 0;
    }
    puts( "-1" );
    return 0;
}