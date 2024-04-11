#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <bitset>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, m;
long long h[ 100100 ], p[ 100100 ];

long long check( long long l, long long r, long long k )
{
	if ( k < l ) return r - k;
	if ( r < k ) return k - l;
	return r - l + min( r - k, k - l );
}

bool fun( long long x )
{
	int fi = 1;
	for ( int i = 1; i <= n; i++ )
	{
		int se = fi;
		if ( check( p[fi], p[se], h[i] ) > x ) continue;
		while ( true )
		{
			if ( se == m ) break;
			if ( check( p[fi], p[se + 1], h[i] ) > x ) break;
			se++;
		}
		fi = se + 1;
		if ( fi == m + 1 ) return true;
	}
	return false;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &m);
    for ( int i = 1; i <= n; i++ ) scanf("%I64d", &h[i]);
    for ( int i = 1; i <= m; i++ ) scanf("%I64d", &p[i]);
    long long l = 0, r = inf, res = inf;
	while ( l <= r )
	{
		long long x = (l + r) / 2;
		if ( fun(x) )
		{
			res = min( res, x );
			r = x - 1;
		} else l = x + 1;
	}  
	cout << res << endl;
    return 0;
}