//In the name of Allah
#include <bits/stdc++.h>
using namespace std;


struct P { 
	int a , b , c; 
};

const int maxN = 100 * 1000 + 100; 
vector<P> ans; 
vector<int> rem[maxN],c[maxN];

int mark[maxN];
int h[maxN];

bool dfs( int s , int p = -1 ) { 
	mark[s] = 1; 

	for( auto x : c[s] ) 
		if( !mark[x] ) { 
			h[x] = h[s] + 1; 
			if( dfs( x , s ) ) 
				rem[s].push_back( x ); 
		} else if( x != p && h[x] < h[s] ) 
			rem[s].push_back( x ); 
	bool ret = 1 ^ (rem[s].size() % 2); 
	if( !ret ) 
		rem[s].push_back( p ); 
	for( int i = 0 ; i < (int)rem[s].size() ; i += 2 ) 
		ans.push_back( { rem[s][i] + 1 , s + 1 , rem[s][i+1] + 1 } ) ; 
	return ret; 
}

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(0); 
	int n,m; cin >> n >> m; 
	for( int i = 0 ; i < m ; i++ ) { 
		int u,v; cin >> u >> v; 
		u--; v--; 
		c[u].push_back(v); 
		c[v].push_back(u); 
	}
	for( int i = 0 ; i < n ; i++ ) 
		if( !mark[i] && !dfs(i) ) { 
			cout << "No solution\n"; 
			return 0; 
		}
	for( int i = 0 ; i < (int)ans.size() ; i++ ) 
		cout << ans[i].a << ' ' << ans[i].b << ' ' << ans[i].c << '\n';
}