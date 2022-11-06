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

const int maxn = 200500;
const int inf = 1e9;
const double eps = 1e-8;
const int base = 1073676287;

pair < int, int > a[maxn];
int pos[maxn];

bool correct( int g, int k, int S, int t ) {
	int curPos = 0;
	int sumTime = 0;
	for ( int j = 0; j < k; j++ ) {
		if ( g < pos[j] - curPos )
			return false;
		if ( g >= 2 * ( pos[j] - curPos ) ) {
			sumTime += pos[j] - curPos;
			curPos = pos[j];
			continue;
		}
		int delta = pos[j] - curPos;
		int x = g - delta;
		sumTime += x + 2 * ( delta - x );
		curPos = pos[j];
	}
	return sumTime <= t;
}


int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, k, S, t;
    scanf ( "%d%d%d%d", &n, &k, &S, &t );
    for ( int j = 0; j < n; j++ )
    	scanf ( "%d%d", &a[j].f, &a[j].s );
    for ( int j = 0; j < k; j++ )
    	scanf ( "%d", &pos[j] );
    pos[k] = S;
    ++k;
    sort( pos, pos + k );
    int l = 1, r = inf + 1;
    while ( r - l ) {
    	int mid = ( l + r ) >> 1;
    	if ( !correct( mid, k, S, t ) )
    		l = mid + 1;
    	else
    		r = mid;
    }
    int ans = 2 * inf;
    for ( int j = 0; j < n; j++ )
    	if ( a[j].s >= l )
    		ans = min( ans, a[j].f );
    if ( ans == 2 * inf )
    	puts( "-1" );
    else
    	printf ( "%d\n", ans );
    return 0;
}