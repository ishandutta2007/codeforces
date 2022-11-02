//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxN = 200 * 1000 + 100; 
vector<int> c[maxN]; 
bool good[maxN]; 
int sz[maxN]; 

int k; 
int dfs( int s , int p = -1 ) { 
	int mx = 0; 
	for( auto x : c[s] ) if( x != p ) { 
		int v = dfs( x , s ) ; 
		mx = max( v , mx ); 
		sz[s] += v; 
	}
	if( good[s] ) sz[s]++; 

	mx = max( mx , 2 * k - sz[s] ); 
	if( mx <= k ) throw(s); 
	return sz[s]; 
}

long long ans = 0; 
void sss( int s , int p = -1 , int h = 0 ) { 
	for( auto x : c[s] ) if( x != p ) 
		sss( x , s , h + 1 ); 
	if( good[s] ) ans += h; 
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 
	int n; cin >> n >> k;
	for( int i =0 ; i < 2 * k ; i++ ) {
		int x; cin >> x; 
		x--; 
		good[x] = true; 
	}

	for(int i = 0 ; i < n-1 ; i++ ) { 
		int u,v; cin >> u >> v; 
		u--; v--; 
		c[u].push_back(v); 
		c[v].push_back(u); 
	}

	try { 
		dfs(0); 
	} catch ( int u ) { 
		sss(u); 
	}
	cout << ans << endl;
}