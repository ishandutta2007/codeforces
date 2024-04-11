//In the name of Allah
#include <bits/stdc++.h>
using namespace std;
const int maxN = 3000 * 100 + 100; 
typedef long long ll;

int a[maxN]; 
char ch[maxN]; 
const int base = 727;
ll mod1 = 1e9 + 7 , mod2 = 1e9 + 9; 

vector<int> c[maxN]; 
set<pair<ll,ll>> curr[maxN]; 

pair<int,int> ans; 


void dfs( int s , int p = -1 , ll now1 = 0 , ll now2 = 0 ) { 
	for( auto x : c[s] ) if( x != p ) 
		dfs( x , s , (now1 * base + ch[s]) % mod1 , (now2 * base + ch[s]) % mod2 ); 

	curr[s].insert( { (now1 * base + ch[s]) % mod1 , (now2 * base + ch[s]) % mod2 } ); 
	for( auto x : c[s] ) if( x != p ) { 
		if( curr[x].size() > curr[s].size() ) curr[x].swap(curr[s]); 
		auto hnt = curr[s].begin();
		while( curr[x].size() ) { 
			hnt = curr[s].insert( hnt , *curr[x].begin() ); 
			curr[x].erase(curr[x].begin());
		}
	}
	if( ans.first < a[s] + curr[s].size() ) 
		ans = { a[s] + curr[s].size() , 0 }; 
	if( ans.first == a[s] + curr[s].size() ) 
		ans.second++; 
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); 
	int n; cin >> n; 
	for( int i = 0 ; i < n ;i++ ) 
		cin >> a[i]; 
	for( int j = 0; j < n ; j++ ) 
		cin >> ch[j]; 
	for( int i = 0 ; i < n - 1; i++ ) { 
		int u,v; cin >> u >> v; 
		u--; v--; 
		c[u].push_back(v); 
		c[v].push_back(u); 
	}
	dfs(0);
	cout << ans.first << endl << ans.second << endl;
}