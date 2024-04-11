//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

const int maxN = 300 * 1000 + 100;
set<pair<ll,int>> curr[maxN]; 
ll toadd[maxN];
vector<int> del[maxN]; 
vector<int> c[maxN]; 
int h[maxN]; 
ll dp[maxN]; 

int dfs( int s , int p = -1 ) { 
	int ret = h[s]; 
	for( auto x : c[s] ) if( x != p ) { 
		h[x] = h[s] + 1; 
		int v = dfs( x , s  ); 
		ret = min( ret , v ); 

		dp[s] += dp[x];
		if( v == h[x] ) { 
			while( curr[x].size() && h[curr[x].begin()->second] > h[s] )
				curr[x].erase(curr[x].begin()); 
			if( curr[x].size() == 0 ) { 
				cout << -1 << endl;
				exit(0); 
			}
			auto y = curr[x].begin(); 
			ret = min( ret , h[y->second] ); 
			assert( y->first + toadd[x] >= 0 ) ; 
			dp[s] += y->first + toadd[x]; 
			toadd[x] = -y->first; 
			curr[x].erase(y); 
		}

		if( curr[x].size() > curr[s].size() ) { 
			curr[x].swap(curr[s]); 
			swap( toadd[x] , toadd[s] ) ; 
		}
		auto hint = curr[s].begin(); 
		for( auto y : curr[x] ) { 
			// y + toadd[x] = zzz + toadd[s] -> zzz = y + toadd[x] - toadd[s]; 
			hint = curr[s].insert( hint , { y.first + toadd[x] - toadd[s] , y.second } ) ; 
		} 
		curr[x].clear(); 
	} 
	return ret; 
}

int main() { 
	ios::sync_with_stdio(false); 
	int n,m; cin >> n >> m;
	for( int i = 0 ; i < n - 1 ; i++ ) { 
		int u,v; cin >> u >> v; u--; v--; 
		c[u].push_back(v);
		c[v].push_back(u); 
	}
	for( int i = 0 ; i < m ; i++ ) { 
		int u,v,c; cin >> u >> v >> c;
		u--; v--; 
		curr[u].insert( { c , v } ) ; 
	//	del[v].push_back(c); 
	}
	dfs(0); 
	cout << dp[0] << endl;
}