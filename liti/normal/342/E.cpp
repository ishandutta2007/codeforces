//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000 * 100 + 100; 
const int maxL = 20; 
const int SQ = 320; 

vector<int> c[maxN]; 
int dis[maxN]; 

vector<int> curr; 
bool isgood[maxN]; 
int n;

int que[maxN];
inline void bfs() { 
	memset( dis , -1 , sizeof dis ); 
	int en = 0; 
	for( int i = 0 ; i < n ; i++ ) 
		if( isgood[i] ) {
			que[en++] = i; 
			dis[i] = 0; 
		}
	for( int i = 0 ; i < en ; i++ ) { 
		int s = que[i]; 
		for( auto x : c[s] ) if( dis[x] == -1 ) { 
			dis[x] = dis[s] + 1; 
			que[en++] = x;
		}
	}
}

int h[maxN]; 
int par[maxN][maxL];

void dfs( int s , int p = 0 ) { 
	h[s] = h[p] + 1; 
	par[s][0] = p; 
	for( int k = 1 ; k < maxL ; k++ ) 
		par[s][k] = par[par[s][k-1]][k-1];
	for( auto x : c[s] ) if( x != p ) 
		dfs( x , s ); 
}

inline int getH( int u , int h ) { 
	for( int k = 0 ; k < maxL ; k++ ) 
		if( h & (1<<k) ) 
			u = par[u][k]; 
	return u;
}

inline int lca( int u , int v ) { 
	if( h[u] < h[v] ) swap(u,v); 
	u = getH( u , h[u] - h[v] ); 
	if( u == v ) return u; 
	
	for( int k = maxL - 1 ; k >= 0 ; k-- ) 
		if( par[u][k] != par[v][k] ) 
			u = par[u][k] , v = par[v][k]; 
	return par[u][0]; 
}

inline int getDist( int u , int v ) { 
	int w = lca(u,v); 
	return h[u] + h[v] - 2 * h[w]; 
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 
	int m; cin >> n >> m; 

	for( int i = 0 ; i < n - 1 ; i++ ) { 
		int a,b; cin >> a >> b; 
		a--; b--; 
		c[a].push_back(b); 
		c[b].push_back(a); 
	}
	dfs(0);
		
	memset( dis , 31 , sizeof dis ); 

	curr.push_back(0); 
	isgood[0] = true;
	for( int i = 0 ; i < m ; i++ ) {
		if( curr.size() == SQ ) { 
			bfs(); 
			curr.clear(); 
		}
		int t; cin >> t; 
		int u; cin >> u; u--; 
		if( t == 1 ) { 
			curr.push_back(u); 
			isgood[u] = true; 
		} else { 
			int ans = dis[u]; 
			for( auto x : curr ) 
				ans = min( ans , getDist(u,x) );
			cout << ans << '\n'; 
		}
	}
}