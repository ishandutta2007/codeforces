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

int bin( int x, ll deg ) {
    if ( deg == 0LL )
        return 1;
	if ( deg == 1LL )
		return x;
	int curAns = bin( x, deg / 2LL );
	if ( deg % 2LL == 1LL ) {
		curAns = ( 1LL * curAns * curAns ) % ( 1LL * base );
		curAns = ( 1LL * curAns * x ) % ( 1LL * base );
		return curAns;
	}
	return ( 1LL * curAns * curAns ) % ( 1LL * base );
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    ll a, b, n, x;
    cin >> a >> b >> n >> x;
    if ( a == 1LL ) {
    	// n -= 1LL;
    	n %= 1LL * base;
    	int ans = ( 1LL * b * n ) % ( 1LL * base );
    	// ++ans;
 		ans += x;
    	ans %= base;
    	printf ( "%d\n", ans );
    	return 0;
    }
    int ans = bin( a, n - 1LL ) - 1;
    if ( ans < 0 )
    	ans += base;
    ans = ( 1LL * a * ans ) % ( 1LL * base );
    ans = ( 1LL * ans * b ) % ( 1LL * base );
    ans = ( 1LL * ans * bin( a - 1, base - 2 ) ) % ( 1LL * base );
    ans += ( ( 1LL * bin( a, n ) * x ) % ( 1LL * base ) );
    ans %= base;
    ans += b;
    ans %= base;
    printf ( "%d\n", ans );
    return 0;
}