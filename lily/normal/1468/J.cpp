#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 200010;
const ll INFLL = 1e18;
int _w;

struct Edge {
    int u, v, w;
    bool operator<( const Edge &rhs ) const {
	return w < rhs.w;
    }
};

int n, m, k;
vector<Edge> edge;
vector<int> mst;

namespace DSU {
    int pa[N];

    void init() {
	for( int i = 1; i <= n; ++i )
	    pa[i] = i;
    }
    int find( int u ) {
	return pa[u] == u ? u : pa[u] = find( pa[u] );
    }
    bool link( int u, int v ) {
	u = find(u);
	v = find(v);
	if( u == v ) return false;
	pa[u] = v;
	return true;
    }
}

void calc_mst() {
    mst.clear();
    DSU::init();
    for( Edge e : edge ) {
	int u = e.u;
	int v = e.v;
	int w = e.w;
	if( DSU::link(u, v) ) {
	    mst.push_back(w);
	}
    }
    sort(mst.begin(), mst.end());
    int mx = mst.back();
    if( mx <= k ) {
	ll ans = INFLL;
	for( Edge e : edge )
	    ans = min(ans, (ll)abs(e.w - k) );
	printf( "%lld\n", ans );
    } else {
	ll ans = 0;
	for( int w : mst )
	    ans += max(0, w-k);
	printf( "%lld\n", ans );
    }
}

int main() {
    int T;
    _w = scanf( "%d", &T );
    while( T-- ) {
	_w = scanf( "%d%d%d", &n, &m, &k );
	edge.clear();
	for( int i = 1; i <= m; ++i ) {
	    int u, v, w;
	    _w = scanf( "%d%d%d", &u, &v, &w );
	    edge.push_back( (Edge){u, v, w} );
	}
	sort(edge.begin(), edge.end());
	calc_mst();
    }
    return 0;
}