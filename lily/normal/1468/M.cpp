#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const int N = 100010;
const int INF = 0x3f3f3f3f;
const int SQ = 50;
int _w;

int n;
vector<int> vec[N], num[N*2], disc;

int vis[N];

bool solve_big_single( int u ) {
    for( int i = 1; i <= n; ++i )
	vis[i] = -1;
    for( int x : vec[u] ) {
	for( int v : num[x] ) {
	    if( v == u ) continue;
	    if( vis[v] == -1 ) {
		vis[v] = 1;
	    } else {
		printf( "%d %d\n", min(u, v), max(u, v) );
		return true;
	    }
	}
    }
    return false;
}

bool solve_big() {
    for( int i = 1; i <= n; ++i ) {
	int sz = (int)vec[i].size();
	if( sz >= SQ ) {
	    if( solve_big_single(i) ) {
		return true;
	    }
	}
    }
    return false;
}

gp_hash_table<ll,int> mp;

bool solve_small_single( int u ) {
    int sz = (int)vec[u].size();
    for( int i = 0; i < sz; ++i )
	for( int j = i+1; j < sz; ++j ) {
	    int x = vec[u][i];
	    int y = vec[u][j];
	    if( x > y ) swap(x, y);
	    ll h = 1LL * x * INF + y;
	    if( mp.find(h) != mp.end() ) {
		int v = mp[h];
		printf( "%d %d\n", min(u, v), max(u, v) );
		return true;
	    }
	    mp[h] = u;
	}
    return false;
}

bool solve_small() {
    mp.clear();
    for( int i = 1; i <= n; ++i ) {
	int sz = (int)vec[i].size();
	if( sz < SQ ) {
	    if( solve_small_single(i) ) {
		return true;
	    }
	}
    }
    return false;
}

int main() {
    int T;
    _w = scanf( "%d", &T );
    while( T-- ) {
	_w = scanf( "%d", &n );
	disc.clear();
	for( int i = 1; i <= n; ++i ) {
	    vec[i].clear();
	    int k;
	    _w = scanf( "%d", &k );
	    vec[i].resize(k);
	    for( int j = 0; j < k; ++j ) {
		_w = scanf( "%d", &vec[i][j] );
		disc.push_back( vec[i][j] );
	    }
	}
	sort(disc.begin(), disc.end());
	auto discend = unique(disc.begin(), disc.end());
	for( int i = 1; i <= n; ++i ) {
	    for( int j = 0; j < (int)vec[i].size(); ++j ) {
		int x = vec[i][j];
		vec[i][j] = int(lower_bound(disc.begin(), discend, x) - disc.begin());
		x = vec[i][j];
		num[x].clear();
	    }
	}
	for( int i = 1; i <= n; ++i )
	    for( int x : vec[i] )
		num[x].push_back(i);
	if( solve_big() ) continue;
	if( solve_small() ) continue;
	puts("-1");
    }
    return 0;
}