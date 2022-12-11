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

struct point
{
	long long x, y;
};

int n;
point p[ 100100 ], t[ 100100 ];
long long min_dist = inf + inf;

void upd( point a, point b )
{
	long long dx = a.x - b.x;
	long long dy = a.y - b.y;
	min_dist = min( min_dist, dx * dx + dy * dy );
}

bool cmp( point a, point b )
{
	return a.y < b.y;
}

long long abs1( long long a )
{
	return max( a, -a );
}

void solve( int l, int r )
{
	if ( r - l + 1 <= 2 )
	{
		for ( int i = l; i <= r; i++ )
			for ( int j = i + 1; j <= r; j++ )
			upd( p[i], p[j] );
		sort( p + l, p + r + 1, cmp );
		return;  
	}
	int x = (l + r) / 2;

	int xx = p[x].x;

	solve( l, x );
	solve( x + 1, r );

	merge( p + l, p + x + 1, p + x + 1, p + r + 1, t, cmp );
	
	for ( int i = 0; i < r - l + 1; i++ ) p[ l + i ] = t[ i ];
 
	int h = 0;
	for ( int i = l; i <= r; i++ )
	{
		if ( abs1( p[i].x - xx ) * abs1( p[i].x - xx ) < min_dist ) 
		{
			for ( int j = h - 1; j >= 0 && ( p[i].y - t[j].y ) * ( p[i].y - t[j].y ) < min_dist; j-- ) upd( p[i], t[j] );
			t[ h++ ] = p[i];
		}
	}
}

int main (int argc, const char * argv[])
{
	scanf("%d", &n);
	long long sum = 0;
	for ( int i = 1; i <= n; i++ )
	{
		int delta; scanf("%d", &delta);
		sum += delta;
		p[i].x = i;
		p[i].y = sum;
	}
	solve( 1, n );
	cout << min_dist << "\n";
    return 0;
}