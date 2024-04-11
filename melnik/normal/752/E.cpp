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
ll cnt[maxn];

bool correct( int x, int n, int k ) {
	for ( int j = 0; j < maxn; j++ )
		cnt[j] = 0;
	for ( int j = 0; j < n; j++ )
		cnt[a[j]] += 1LL;
	for ( int j = maxn - 1; j >= 2; j-- )
		if ( j / 2 >= x ) {
			cnt[j / 2] += cnt[j];
			cnt[( j + 1 ) / 2 ] += cnt[j];
			cnt[j] = 0LL;
		}
	ll ans = 0LL;
	for ( int j = x; j < maxn; j++ )
		ans += cnt[j];
	return ans >= 1LL * k;
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, k;
    scanf ( "%d%d", &n, &k );
    for ( int j = 0; j < n; j++ )
    	scanf ( "%d", &a[j] );
   	int l = 0, r = 1 + ( 1e7 );
   	while ( r - l ) {
   		int mid = ( l + r ) >> 1;
   		if ( correct( mid, n, k ) )
   			l = mid + 1;
   		else
   			r = mid;
   	}
   	if ( l == 1 )
   		puts( "-1" );
   	else
   		printf ( "%d\n", l - 1 );
    return 0;
}