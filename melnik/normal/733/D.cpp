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

map < pair < int, int >, vector < pair < int, int > > > a;
map < pair < int, int >, vector < pair < int, int > > >::iterator it;
vector < pair < int, int > > cur;

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    int curAns = 0;
    pair < int, int > ans = mp( 0, -1 );
    for ( int j = 0; j < n; j++ ) {
    	int b, c, d;
    	scanf ( "%d%d%d", &b, &c, &d );
    	if ( d < c )
    		swap( d, c );
    	if ( c < b )
    		swap( c, b );
    	if ( d < c )
    		swap( d, c );
    	if ( c < b )
    		swap( c, b );
    	a[mp( b, c )].pb( mp( d, j ) );
    	a[mp( b, d )].pb( mp( c, j ) );
    	a[mp( c, d )].pb( mp( b, j ) );
    	int cnt = min( b, min( c, d ) );
    	if ( cnt > curAns ) {
    		curAns = cnt;
    		ans = mp( j, -1 );
    	}
    }
    for ( it = a.begin(); it != a.end(); it++ ) {
    	pair < int, int > cnt = it -> f;
    	int newAns = min( cnt.f, cnt.s );
    	cur = it -> s;
    	sort( cur.begin(), cur.end() );
    	// reverse( cur.begin(), cur.end() );
    	int sz = cur.size();
    	int have = cur[sz - 1].s;
    	int pos = sz - 1;
    	while ( pos >= 0 && cur[pos].s == have )
    		--pos;
    	if ( pos < 0 )
    		continue;
    	newAns = min( newAns, cur[sz - 1].f + cur[pos].f );
    	if ( newAns > curAns ) {
    		curAns = newAns;
    		ans = mp( cur[sz - 1].s, cur[pos].s );
    	}
    }
    // cout << curAns << endl << endl;
    if ( ans.s == -1 )
    	printf ( "1\n%d\n", ans.f + 1 );
    else
    	printf ( "2\n%d %d\n", ans.f + 1, ans.s + 1 );
    return 0;
}