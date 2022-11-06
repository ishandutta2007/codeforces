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
#include <cassert>


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

vector < int > edge[maxn];
vector < int > leaves;
set < int > newLeaves;
set < int >::iterator it;
int deg[maxn];

void solve( int n, int k ) {
	if ( n == 1 ) {
		leaves.pb( 1 );
		return;
	}
	solve( n - k, min( n - k - 1, k ) );
	int sz = leaves.size();
	newLeaves.clear();
	for ( int j = 0; j < sz; j++ ) {
		edge[leaves[j]].pb( n - k + 1 + j );
		edge[n - k + 1 + j].pb( leaves[j] );
		++deg[leaves[j]];
		if ( deg[leaves[j]] == 1 )
			newLeaves.insert( leaves[j] );
		else
			newLeaves.erase( leaves[j] );

		++deg[n - k + 1 + j];
		if ( deg[n - k + 1 + j] == 1 )
			newLeaves.insert( n - k + 1 + j );
		else
			newLeaves.erase( n - k + 1 + j );
	}

	for ( int j = n - k + 1 + sz; j <= n; j++ ) {
		edge[j].pb( leaves[0] );
		edge[leaves[0]].pb( j );

		++deg[leaves[0]];
		if ( deg[leaves[0]] == 1 )
			newLeaves.insert( leaves[0] );
		else
			newLeaves.erase( leaves[0] );

		++deg[j];
		if ( deg[j] == 1 )
			newLeaves.insert( j );
		else
			newLeaves.erase( j );
	}

	leaves.clear();
	for ( it = newLeaves.begin(); it != newLeaves.end(); it++ )
		leaves.pb( *it );
	// assert( leaves.size() <= k + 1 );
}

int dist[maxn];

void dfs( int v, int anc ) {
	int sz = edge[v].size();
	for ( int j = 0; j < sz; j++ )
		if ( edge[v][j] != anc ) {
			dist[edge[v][j]] = 1 + dist[v];
			dfs( edge[v][j], v );
		}
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, k;
    scanf ( "%d%d", &n, &k );
    solve( n, k );

    dfs( 1, -1 );
    int v = 1;
    for ( int j = 1; j <= n; j++ )
    	if ( dist[j] > dist[v] )
    		v = j;
    dist[v] = 0;
    dfs( v, -1 );

    v = 1;
    for ( int j = 1; j <= n; j++ )
    	if ( dist[j] > dist[v] )
    		v = j;
    printf( "%d\n", dist[v] );

    for ( int j = 1; j <= n; j++ ) {
    	int sz = edge[j].size();
    	for ( int i = 0; i < sz; i++ )
    		if ( j < edge[j][i] )
    			printf( "%d %d\n", j, edge[j][i] );
    }
    return 0;
}