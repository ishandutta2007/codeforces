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
#include <cassert>
#include <stack>
#include <bitset>
#include <sstream>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, _n, a[ 2000000 ], b[ 2000000 ];
long long f[ 21 ], g[ 21 ];
int fl[ 21 ];

long long fun( int l1, int r1, int l2, int r2 )
{
	long long result = 0;
	int pt1 = l1, pt2 = l2, pt3 = 0;
	while ( true )
	{
		if ( pt1 == r1 && pt2 == r2 ) break;
		if ( pt1 == r1 )
		{
			b[ pt3++ ] = a[ pt2++ ];
			continue;
		}
		if ( pt2 == r2 || a[ pt1 ] <= a[ pt2 ] )
		{
			b[ pt3++ ] = a[ pt1++ ];
			result += pt2 - l2;
			continue;
		}
		b[ pt3++ ] = a[ pt2++ ];
		continue;
	}
	//for ( int i = l1; i < r1; i++ ) cout << a[i] << " "; cout << "\n";
	//for ( int i = l2; i < r2; i++ ) cout << a[i] << " "; cout << "\n";
	//for ( int i = 0; i < r1 + r2 - l1 - l2; i++ ) cout << b[i] << " "; cout << "\n";
	//cout << result << "\n";
	return result;
}

void solve( int l, int r, int pt )
{
	if ( pt == 0 ) return;
	int x = (l + r) / 2;
	solve( l, x, pt - 1 );
	solve( x, r, pt - 1 );
	f[ pt ] += fun( l, x, x, r );
	g[ pt ] += fun( x, r, l, x );
	for ( int i = 0; i < ( 1 << pt ); i++ ) a[l + i] = b[i];
}

int main (int argc, const char * argv[])
{
	scanf("%d", &n);
	_n = 1 << n;
	for ( int i = 0; i < _n; i++ ) scanf("%d", &a[i]);
	solve( 0, _n, n );
	long long answer = 0;
	for ( int i = 0; i <= n; i++ ) answer += f[i];
	int q; scanf("%d", &q);
	while ( q-- )
	{
		int _pos; scanf("%d", &_pos);
		for ( int pos=  0; pos <= _pos; pos++ )
		{
			if ( fl[ pos ] ) answer -= g[ pos ]; else answer -= f[ pos ];
			fl[ pos ] ^= 1;
			if ( fl[ pos ] ) answer += g[ pos ]; else answer += f[ pos ];
		}
		printf("%I64d\n", answer);
	}
    return 0;
}