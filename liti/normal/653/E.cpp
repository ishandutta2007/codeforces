//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

#define __sz(x) ((int)(x).size())
typedef long long ll;

const int maxN = 300 * 1000 + 100; 

vector<int> c[maxN]; 
int co[maxN]; 
int good[maxN];

set<int> rem,tmp; 
int que[maxN],en;

int main() { 
	ios::sync_with_stdio(false); 
	int n,m,k; cin >> n >> m >> k; 
	for( int i = 0 ; i < m ; i++ ) { 
		int u,v; cin >> u >> v; 
		u--; v--; 
		c[u].push_back(v); 
		c[v].push_back(u); 
	}
	for( int i = 1 ; i < n ; i++ ) 
		good[i] = true; 
	for( auto x : c[0] ) 
		good[x] = false; 

	for( int i = 1 ; i < n ; i++ ) 
		rem.insert(i); 

	int cnt = 0; 
	for( int i = 1 ; i < n ; i++ ) 
		if( co[i] == 0 ) { 
			cnt++; 
			co[i] = cnt; 
			bool gg = good[i]; 
			en = 0; 
			que[en++] = i; 
			rem.erase(i); 
			for( int j = 0 ; j < en ; j++ ) { 
				int s = que[j]; 
				for( auto x : c[s] ) 
					if( rem.count(x) ) { 
						tmp.insert(x); 
						rem.erase(x); 
					}
				for( auto x : rem ) { 
					co[x] = cnt; 
					gg |= good[x]; 
					que[en++] = x; 
				}
				rem.clear();
				rem.swap(tmp); 
			}
			if( !gg ) { 
				cout << "impossible" << endl;
				return 0; 
			}
		}
	if( cnt <= k && (int)c[0].size() + k <= n - 1 ) cout << "possible" << endl;
	else cout << "impossible" << endl;
}