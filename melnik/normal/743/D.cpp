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

int a[maxn];
vector < int > edge[maxn];

ll cost[maxn];
ll maxCost[maxn];
int used[maxn];
ll ans = -1LL * inf * inf;

void dfs( int v ) {
	cost[v] = 1LL * a[v];
	maxCost[v] = -1LL * inf * inf;
	used[v] = true;
	int sz = edge[v].size();
	for ( int j = 0; j < sz; j++ ) {
		int to = edge[v][j];
		if ( used[to] )
			continue;
		dfs( to );
		cost[v] += cost[to];
		maxCost[v] = max( maxCost[v], maxCost[to] );
	}
	maxCost[v] = max( maxCost[v], cost[v] );
}

void dfs( int v, ll curUpCost ) {
	if ( curUpCost != -1LL * inf * inf )
		ans = max( ans, curUpCost + cost[v] );
	used[v] = true;
	int sz = edge[v].size();
	vector < ll > prefMax;
	vector < ll > sufMax;
	prefMax.resize( sz + 1 );
	sufMax.resize( sz + 1 );
	for ( int j = 0; j < sz; j++ )
        prefMax[j] = sufMax[j] = -1LL * inf * inf;
	if ( sz && !used[edge[v][0]] )
		prefMax[0] = maxCost[edge[v][0]];
	for ( int j = 1; j < sz; j++ )
		if ( !used[edge[v][j]] )
			prefMax[j] = max( prefMax[j - 1], maxCost[edge[v][j]] );
		else
			prefMax[j] = prefMax[j - 1];
	sufMax[sz] = -1LL * inf * inf;
	for ( int j = sz - 1; j >= 0; j-- )
		if ( !used[edge[v][j]] )
			sufMax[j] = max( sufMax[j + 1], maxCost[edge[v][j]] );
		else
			sufMax[j] = sufMax[j + 1];
	for ( int j = 0; j < sz; j++ ) {
		int to = edge[v][j];
		if ( used[to] )
			continue;
		ll newUpCost = max( curUpCost, sufMax[j + 1] );
		if ( j )
			newUpCost = max( newUpCost, prefMax[j - 1] );
		dfs( to, newUpCost );
	}
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    for ( int j = 1; j <= n; j++ )
    	scanf ( "%d", &a[j] );
    for ( int j = 1; j < n; j++ ) {
    	int u, v;
    	scanf ( "%d%d", &u, &v );
    	edge[u].pb( v );
    	edge[v].pb( u );
    }
    dfs( 1 );
    for ( int j = 0; j < maxn; j++ )
    	used[j] = false;
    dfs( 1, -1LL * inf * inf );
    if ( ans == -1LL * inf * inf )
    	puts( "Impossible" );
    else
    	cout << ans << endl;
    return 0;
}