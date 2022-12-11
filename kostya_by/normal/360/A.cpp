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

struct query
{
	int tp, l, r, c;
	query()
	{
		tp = l = r = c = 0;
	}
	void scan()
	{
		cin >> tp >> l >> r >> c;
	}
};

int n, m;
long long val[ 5555 ], d[ 5555 ], a[ 5555 ];
bool fl[ 5555 ];
vector< query > v;

void bad()
{
	puts("NO");
	exit( 0 );
}

int main (int argc, const char * argv[])
{
	scanf("%d%d", &n, &m);
	for ( int i = 1; i <= n; i++ ) val[i] = 1e9;
	for ( int q = 0; q < m; q++ )
	{
		query cur; cur.scan(); v.pb( cur );
		if ( cur.tp == 1 )
			for ( int i = cur.l; i <= cur.r; i++ )
				d[i] += cur.c;
		if ( cur.tp == 2 )
			for ( int i = cur.l; i <= cur.r; i++ )
				val[i] = min( val[i], cur.c - d[i] );
	}
	for ( int i = 1; i <= n; i++ ) a[i] = val[i];
	for ( int q = 0; q < m; q++ )
	{
		query cur = v[q];
		if ( cur.tp == 1 )
			for ( int i = cur.l; i <= cur.r; i++ )
				val[i] += cur.c;
		if ( cur.tp == 2 )
		{
			long long mx = -1e9;
			for ( int i = cur.l; i <= cur.r; i++ ) mx = max( val[i], mx );
			if ( mx != cur.c ) bad();
		}
	}
	puts("YES");
	for ( int i = 1; i <= n; i++ ) cout << a[i] << " ";
    return 0;
}