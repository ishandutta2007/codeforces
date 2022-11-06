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

int w[maxn];
int c[maxn];
vector < pair < int, int > > edge[maxn];
vector < pair < pair < int, int >, pair < int, int > > > allEdges;
int usedEdges[maxn];
int anc[maxn];
int SZ[maxn];
int tin[maxn];
int tout[maxn];
int timer = 1;
pair < int, int > up[maxn][20];

void init() {
	for ( int j = 0; j < maxn; j++ )
		anc[j] = j, SZ[j] = 1, tout[j] = inf;
	for ( int j = 0; j < maxn; j++ )
		for ( int i = 0; i < 20; i++ )
			up[j][i] = mp( 0, 0 );
	for ( int j = 0; j < maxn; j++ )
		usedEdges[j] = false;
}

int findSet( int v ) {
	return v == anc[v] ? v : anc[v] = findSet( anc[v] );
}

void unionSets( int u, int v ) {
	u = findSet( u );
	v = findSet( v );
	if ( SZ[u] < SZ[v] )
		swap( u, v );
	SZ[u] += SZ[v];
	anc[v] = u;
}


void dfs ( int v, int p, int cost ) {
	tin[v] = ++timer;
	up[v][0] = mp( p, cost );
	for ( int i = 1; i < 20; i++ ) {
		up[v][i].f = up[up[v][i - 1].f][i - 1].f;
		up[v][i].s = max( up[v][i - 1].s, up[up[v][i - 1].f][i - 1].s );
	}
	for (size_t i=0; i<edge[v].size(); ++i) {
		int to = edge[v][i].f;
		if (to != p && usedEdges[edge[v][i].s] )
			dfs (to, v, w[edge[v][i].s] );
	}
	tout[v] = ++timer;
}

bool upper (int a, int b) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
	if (upper (a, b))  return a;
	if (upper (b, a))  return b;
	for (int i = 19; i >= 0; --i )
		if ( !upper (up[a][i].f, b) )
			a = up[a][i].f;
	return up[a][0].f;
}

int goUp( int u, int v ) {
	if ( u == v )
		return 0;
	int curAns = 0;
	for (int i = 19; i >= 0; --i )
		if ( !upper (up[u][i].f, v) ) {
			curAns = max( curAns, up[u][i].s );
			u = up[u][i].f;
		}
	return max( curAns, up[u][0].s );
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    init();
    int n, m;
    scanf ( "%d%d", &n, &m );
    for ( int j = 0; j < m; j++ )
    	scanf ( "%d", &w[j] );
    for ( int j = 0; j < m; j++ )
    	scanf ( "%d", &c[j] );
    int S;
    for ( int j = 0; j < m; j++ ) {
    	int u, v;
    	scanf ( "%d%d", &u, &v );
    	edge[u].pb( mp( v, j ) );
    	edge[v].pb( mp( u, j ) );
    	allEdges.pb( mp( mp( w[j], j ), mp( u, v ) ) );
    }
    scanf ( "%d", &S );
    sort( allEdges.begin(), allEdges.end() );
    ll sum = 0LL;
    for ( int j = 0; j < m; j++ ) {
    	int u = allEdges[j].s.f;
    	int v = allEdges[j].s.s;
    	int num = allEdges[j].f.s;
    	if ( findSet( v ) != findSet( u ) ) {
    		usedEdges[num] = true;
    		unionSets( u, v );
    		sum += 1LL * allEdges[j].f.f;
    	}
    }
    dfs( 1, 0, 0 );
    ll ans = sum;
    int road = -1;
    for ( int j = 0; j < m; j++ ) {
    	int num = allEdges[j].f.s;
    	if ( usedEdges[num] ) {
    	    if ( ans >= sum - 1LL * S / c[num] ) {
                ans = min( ans, sum - 1LL * S / c[num] );
                road = num;
    	    }
    		continue;
    	}
    	ll curSum = sum;
    	curSum += 1LL * w[num];
    	curSum -= 1LL * S / c[num];
    	int u = allEdges[j].s.f;
    	int v = allEdges[j].s.s;
    	int c = lca( u, v );
    	int maxW = 0;
    	maxW = max( maxW, goUp( u, c ) );
    	maxW = max( maxW, goUp( v, c ) );
    	curSum -= maxW;
    	if ( curSum <= ans ) {
    		ans = curSum;
    		road = num;
    	}
    }
    cout << ans << endl;
    w[road] -= S / c[road];
    init();
    for ( int j = 0; j < m; j++ ) {
    	int num = allEdges[j].f.s;
    	if ( num == road ) {
    		int u = allEdges[j].s.f;
    		int v = allEdges[j].s.s;
    		unionSets( u, v );
    		usedEdges[num] = true;
    		allEdges[j].f.f = w[road];
    		break;
    	}
    }
    sort( allEdges.begin(), allEdges.end() );
    for ( int j = 0; j < m; j++ ) {
    	int u = allEdges[j].s.f;
    	int v = allEdges[j].s.s;
    	int num = allEdges[j].f.s;
    	if ( findSet( v ) != findSet( u ) ) {
    		usedEdges[num] = true;
    		unionSets( u, v );
    	}
    }
    for ( int j = 0; j < m; j++ )
    	if ( usedEdges[j] ) 
    		printf ( "%d %d\n", j + 1, w[j] );
    return 0;
}