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

const int maxn = 1000500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];
vector < int > edge[maxn];
int used[maxn];
int dp[maxn];
int need;

void dfs( int v ) {
	used[v] = true;
	int sz = edge[v].size();
	dp[v] = a[v];
	for ( int j = 0; j < sz; j++ ) {
		int to = edge[v][j];
		if ( used[to] )
			continue;
		dfs( to );
		dp[v] += dp[to];
	}
}

int haveNeedLower[maxn];

void dfs( int v, int anc ) {
	used[v] = true;
	int sz = edge[v].size();
	for ( int j = 0; j < sz; j++ ) {
		int to = edge[v][j];
		if ( used[to] )
			continue;
		dfs( to, v );
		if ( haveNeedLower[to] )
			haveNeedLower[v] = haveNeedLower[to];
	}
	if ( !haveNeedLower[v] ) {
		if ( dp[v] == need )
			haveNeedLower[v] = v;
		return;
	}
	if ( !anc )
		return;
	if ( dp[v] - need == need ) {
		printf ( "%d %d\n", haveNeedLower[v], v );
		exit( 0 );
	} 
}

int haveNeedUpper[maxn];

void dfs2( int v, int anc ) {
	if ( dp[v] == need && haveNeedUpper[v] ) {
		printf ( "%d %d\n", v, haveNeedUpper[v] );
		exit( 0 );
	}
	used[v] = true;
	int sz = edge[v].size();

	vector < int > pref;
	pref.resize( sz );
	for ( int j = 0; j < sz; j++ ) {
		pref[j] = 0;
		if ( j )
			pref[j] = pref[j - 1];
		int to = edge[v][j];
		if ( used[to] )
			continue;
		if ( haveNeedLower[to] )
			pref[j] = haveNeedLower[to];
	}

	vector < int > suff;
	suff.resize( sz );
	for ( int j = sz - 1; j >= 0; j-- ) {
		suff[j] = 0;
		if ( j != sz - 1 )
			suff[j] = suff[j + 1];
		int to = edge[v][j];
		if ( used[to] )
			continue;
		if ( haveNeedLower[to] )
			suff[j] = haveNeedLower[to];
	}

	for ( int j = 0; j < sz; j++ ) {
		int to = edge[v][j];
		if ( used[to] )
			continue;
		if ( j )
			haveNeedUpper[to] = pref[j - 1];
		if ( j != sz - 1 && suff[j] )
			haveNeedUpper[to] = suff[j + 1];
		dfs2( to, v );
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
    int sum = 0;
    int root;
    for ( int j = 1; j <= n; j++ ) {
    	int x;
    	scanf ( "%d%d", &x, &a[j] );
    	if ( x ) {
	    	edge[j].pb( x );
	    	edge[x].pb( j );
	    } else
	    	root = j;
	    sum += a[j];
    }
    if ( abs( sum ) % 3 ) {
    	puts( "-1" );
    	return 0;
    }
    need = sum / 3;
    dfs( root );
    for ( int j = 0; j < maxn; j++ ) 
    	used[j] = false;
    dfs( root, 0 );
    for ( int j = 0; j < maxn; j++ ) 
    	used[j] = false;
    dfs2( root, 0 );
    puts( "-1" );
    return 0;
}