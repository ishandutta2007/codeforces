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

const int maxn = 300500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int parent[maxn];
vector < int > edge[maxn];
int center[maxn];
int treeSz[maxn];
int maxSize[maxn];
bool used[maxn];

bool correct( int v, int curV ) {
	int cnt = treeSz[v] / 2;
	if ( maxSize[curV] > cnt )
		return 0;
	if ( treeSz[v] - treeSz[curV] > cnt )
		return 0;
	return 1;
}

void dfs( int v ) {
	vector < int > centers;
	used[v] = true;
	int sz = edge[v].size();
	for ( int j = 0; j < sz; j++ ) {
		int to = edge[v][j];
		if ( used[to] )
			continue;
		dfs( to );
		treeSz[v] += treeSz[to];
		maxSize[v] = max( maxSize[v], treeSz[to] );
		centers.pb( center[to] );
	}
	treeSz[v] += 1;
	if ( !sz ) {
		center[v] = v;
		return;
	}
	sz = centers.size();
	for ( int j = 0; j < sz; j++ ) {
		int curV = centers[j];
		while ( curV != parent[v] && !correct( v, curV ) )
			curV = parent[curV];
		if ( curV != parent[v] ) {
			center[v] = curV;
			return;
		}
	}
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, q;
    scanf ( "%d%d", &n, &q );
    for ( int j = 2; j <= n; j++ ) {
    	int v;
    	scanf ( "%d", &v );
    	edge[v].pb( j );
    	parent[j] = v;
    }
    parent[1] = -1;
    dfs( 1 );
    while ( q-- ) {
    	int v;
    	scanf ( "%d", &v );
    	printf( "%d\n", center[v] );
    }
    return 0;
}