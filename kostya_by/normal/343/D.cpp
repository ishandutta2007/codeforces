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

int tree1[ 2000002 ], tree2[ 2000002 ], h = 5;
int n, tin[ 500050 ], tout[ 500050 ], timer, id[ 500050 ];
vector< int > graf[ 500050 ];

void dfs( int v, int p )
{
	tin[v] = ++timer; id[timer] = v;
	for ( int i = 0; i < graf[v].size(); i++ )
	{
		int next = graf[v][i];
		if ( next == p ) continue;
		dfs( next, v );
	}
	tout[v] = timer;
}

int query1( int v, int l, int r, int ll, int rr )
{
	if ( l == ll && rr == r ) return tree1[v];
	int xx = (ll + rr) / 2, res = 0;
	if ( l <= xx ) 
		res = max( res, query1( v + v, l, min( xx, r ), ll, xx ) );
	if ( xx + 1 <= r )
		res = max( res, query1( v + v + 1, max( xx + 1, l ), r, xx + 1, rr ) );
	return res;
}

void modify1( int v, int p, int ll, int rr )
{
	tree1[v] = h;
	if ( ll == rr ) return;
	int xx = (ll + rr) / 2;
	if ( p <= xx ) modify1( v + v, p, ll, xx );
		else modify1( v + v + 1, p, xx + 1, rr );
}

int query2( int v, int p, int ll, int rr )
{
	int res = tree2[v];
	if ( ll == rr ) return res;
	int xx = (ll + rr) / 2;
	if ( p <= xx ) 
		res = max( res, query2( v + v, p, ll, xx ) );
	else
		res = max( res, query2( v + v + 1, p, xx + 1, rr ) );
	return res;
}

void modify2( int v, int l, int r, int ll, int rr )
{
	if ( l == ll && rr == r ) 
	{
		tree2[v] = h;
		return;
	}
	int xx = (ll + rr) / 2;
	if ( l <= xx ) 
		modify2( v + v, l, min( xx, r ), ll, xx );
	if ( xx + 1 <= r ) 
		modify2( v + v + 1, max( xx + 1, l ), r, xx + 1, rr );
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for ( int i = 1; i < n; i++ )
    {
    	int a, b; scanf("%d%d", &a, &b);
    	graf[a].pb(b);
    	graf[b].pb(a);
    }
    dfs( 1, -1 );
    int q; scanf("%d", &q);
    while ( q-- )
    {
    	int t, v; scanf("%d%d", &t, &v);
    	h += 4;
    	if ( t == 1 )
    	{
    		modify2( 1, tin[v], tout[v], 1, n );
    	}
    	if ( t == 2 )
    	{
    		modify1( 1, tin[v], 1, n );
    	}
    	if ( t == 3 )
    	{
    		int v1 = query1( 1, tin[v], tout[v], 1, n );
    		int v2 = query2( 1, tin[v], 1, n );
    		if ( v2 <= v1 ) puts("0"); else puts("1");
    	}
    }
    return 0;
}