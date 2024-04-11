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

int m, k, p, depth[ 100100 ];
long long sum[ 100100 ];
vector< int > graph[ 100100 ];

void dfs( int v, int prev )
{
	for ( int i = 0; i < graph[v].size(); i++ )
	{
		int next = graph[v][i];
		if ( next == prev ) continue;
		depth[ next ] = depth[ v ] + 1;
		dfs( next, v );
	}
} 

long long fun( int num )
{
	long long result = inf;
	for ( int i = 2 ;; i++ )
	{
		if ( i + num - 1 > m ) break;
		long long current = 1ll * depth[ i + num - 1 ] * num - ( sum[ i + num - 1 ] - sum[ i - 1 ] );// - 2ll * ( depth[i] - 1 ) * num;
		result = min( result, current );
	}
	return result;
}

int main (int argc, const char * argv[])
{
	scanf("%d%d%d", &m, &k, &p);
	k = min( k, m - 1 );
	for ( int i = 1; i < m; i++ )
	{
		int a, b; scanf("%d%d", &a, &b);
		graph[a].push_back( b );
		graph[b].push_back( a );
	}
	dfs( 1, -1 );
	sort( depth + 1, depth + m + 1 );
	for ( int i = 1; i <= m; i++ ) sum[i] = sum[i - 1] + depth[i];
	int l = 1, r = k, result = 0;
	while ( l <= r )
	{
		int x = (l + r) / 2;
		if ( fun( x ) <= p )
		{
			result = max( result, x );
			l = x + 1;
		} else r = x - 1;
	}
	printf("%d\n", result);
    return 0;
}