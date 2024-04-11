//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxN = 100*1000 + 100; 
vector<int> c[maxN]; 
int good[maxN]; 
int n,m;
int ans = 0; 

void dfs( int s , int p = -1, int cnt = 0 ) { 
	cnt += good[s];
	if( good[s] == 0 ) cnt = 0;
	if( cnt > m ) return;
	if( (int)c[s].size() == 1 && p != -1 ) 
		ans++;
	for( auto x : c[s] ) if( x != p ) 
		dfs( x , s , cnt ); 
}

int main() { 
	cin >> n >> m; 
	for( int i = 0 ; i < n ; i++ ) 
		cin >> good[i]; 
	for( int i = 0 ; i < n - 1 ; i ++ ) { 
		int u,v; cin >> u >> v; 
		u--; v--;
		c[u].push_back(v);
		c[v].push_back(u); 
	}
	dfs(0);
	cout << ans << endl;
}