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

int n, m, s, e, a[ 100100 ], b[ 100100 ];
int answer = 0;
int f[ 100100 ], g[ 100100 ];
vector< int > id[ 100100 ];

int main (int argc, const char * argv[])
{
	scanf("%d%d%d%d", &n, &m, &s, &e);
	for ( int i = 1; i <= n; i++ ) scanf("%d", &a[i]);
	for ( int i = 1; i <= m; i++ ) 
	{
		scanf("%d", &b[i]);
		id[ b[i] ].push_back( i );
	}

	for ( int x = 1; e * x <= s; x++ )
	{
		for ( int i = 1; i <= n; i++ )
		{
			int pos = g[i - 1];
			if ( pos == m + 1 )
			{
				f[i] = m + 1;
				continue;
			}
			vector< int >::iterator it = upper_bound( id[ a[i] ].begin(), id[ a[i] ].end(), pos );
			if ( it == id[ a[i] ].end() )
			{
				f[i] = m + 1;
				continue;
			}
			f[i] = *it;
			if ( e * x + i + f[i] <= s ) answer = x;
		}
		g[0] = m + 1;
		for ( int i = 1; i <= n; i++ ) g[i] = min( g[i - 1], f[i] );
	}

	printf("%d\n", answer);

    return 0;
}