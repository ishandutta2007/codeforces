/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 1000*100 + 100; 
int disfen[maxN], fen[maxN];
int st[maxN] , en[maxN], dis[maxN];
vector<int> c[maxN];

void dfs( int s , int p = -1 , int h = 0 ) { 
	static int ind = 0;
	st[s] = ind++;
	dis[s] = h;
	for( auto x : c[s] ) if( x != p ) 
		dfs( x , s , h + 1 ) ; 
	en[s] = ind;
}

inline void add( int x , int v , int *fen ) {
	x++;
	for( ; x < maxN ; x += x & (-x) ) 
		fen[x] += v;
}

inline int get( int x , int *fen ) { 
	x++;
	int ret = 0;
	for( ; x > 0 ; x -= x & (-x) ) 
		ret += fen[x];
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n,m;
	cin >> n >> m;

	for( int i = 0 ; i < n - 1 ; i++ ) { 
		int u,v; cin >> u >> v;
		u--; v--; 
		c[u].push_back(v);
		c[v].push_back(u);
	}
	dfs(0);

	for( int i = 0 ; i < m ; i++ ) {
		int t; cin >> t;
		if( t == 1 ) { 
			int v; cin >> v; v--;
			cout << get( dis[v] , disfen ) + get( st[v] , fen ) << '\n';
		} else { 
			int v,x,d; cin >> v >> x >> d; 
			v--;
			int tmp = d - dis[v];
			if( tmp >= 0 ) {
				add( 0 , x , disfen ) ; 
				add( tmp + 1 , -x , disfen ) ; 
			}
			if( v == 0 ) continue;
			int e = min( en[v] - 1 , st[v] + d ) ; 
			tmp = max(tmp,0);
			int s = max( st[v] - (dis[v]-1) + tmp , st[v] - d ) ; 
			if( e >= s ) { 
				add( s , x , fen ) ; 
				add( e + 1 , -x , fen ) ;
			}
		}
	}
}