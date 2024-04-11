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

pair < int, int > a[maxn];
pair < int, int > b[maxn];
int prefMaxA[maxn];
int prefMaxB[maxn];
int timer1, timer2;

int findBestA( int l, int r, int cost ) {
	while ( r - l > 1 ) {
		int mid = ( l + r ) >> 1;
		if ( a[mid].f <= cost )
			l = mid;
		else
			r = mid;
	}
	if ( a[r].f <= cost )
		return prefMaxA[r];
	if ( a[l].f <= cost )
		return prefMaxA[l];
	return -inf;
}

int findBestB( int l, int r, int cost ) {
	while ( r - l > 1 ) {
		int mid = ( l + r ) >> 1;
		if ( b[mid].f <= cost )
			l = mid;
		else
			r = mid;
	}
	if ( b[r].f <= cost )
		return prefMaxB[r];
	if ( b[l].f <= cost )
		return prefMaxB[l];
	return -inf;
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, c, d;
    scanf ( "%d%d%d", &n, &c, &d );
    for ( int j = 0; j < n; j++ ) {
    	int x, y;
    	char type;
    	scanf ( "%d%d %c", &x, &y, &type );
    	if ( type == 'C' )
    		a[++timer1] = mp( y, x );
    	if ( type == 'D' )
    		b[++timer2] = mp( y, x );
    }
    sort( a + 1, a + timer1 + 1 );
    sort( b + 1, b + timer2 + 1 );
    for ( int j = 1; j < maxn; j++ ) {
    	prefMaxA[j] = max( prefMaxA[j - 1], a[j].s );
    	prefMaxB[j] = max( prefMaxB[j - 1], b[j].s );
    }
    int ans = 0;
    for ( int j = 1; j <= timer1; j++ ) {
    	if ( a[j].f > c )
    		continue;
    	ans = max( ans, a[j].s + findBestB( 1, timer2, d ) );
    	if ( j > 1 )
    		ans = max( ans, a[j].s + findBestA( 1, j - 1, c - a[j].f ) );
    }
    for ( int j = 2; j <= timer2; j++ ) {
    	if ( b[j].f > d )
    		continue;
    	ans = max( ans, b[j].s + findBestB( 1, j - 1, d - b[j].f ) );
    }
    printf ( "%d\n", ans );
    return 0;
}