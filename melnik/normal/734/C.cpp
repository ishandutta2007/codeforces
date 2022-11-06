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
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

pair < int, int > a[maxn];
pair < int, int > b[maxn];

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, m, k;
    scanf ( "%d%d%d", &n, &m, &k );
    int x, S;
    scanf ( "%d%d", &x, &S );
    for ( int j = 1; j <= m; j++ )
    	scanf ( "%d", &a[j].s );
    for ( int j = 1; j <= m; j++ )
    	scanf ( "%d", &a[j].f );

    for ( int j = 1; j <= k; j++ )
    	scanf ( "%d", &b[j].s );
    for ( int j = 1; j <= k; j++ )
    	scanf ( "%d", &b[j].f );
    a[0] = mp( 0, x );
    b[0] = mp( 0, 0 );
    sort( a, a + m + 1 );
    sort( b, b + k + 1 );
    reverse( b, b + k + 1 );
    int it = 0;
    ll ans = 1LL * x * n;
    pair < int, int > curMax = mp( 0, x );
    for ( int j = 0; j <= k; j++ ) {
    	if ( b[j].f > S )
    		continue;
    	while ( it <= m && a[it].f <= S - b[j].f ) {
    		if ( curMax.s > a[it].s )
    			curMax = a[it];
    		++it;
    	}
    	ll curAns = 1LL * curMax.s * ( max( 0, n - b[j].s ) );
    	ans = min( curAns, ans );
    }
    cout << ans << endl;
    return 0;
}