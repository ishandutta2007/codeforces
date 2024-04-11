//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxN = 1000 * 100 + 1000 ; 
vector<int> c[maxN]; 
int mark[maxN]; 

void dfs( int s , int col ) { 
	mark[s] = col; 
	for( auto x : c[s] ) 
		if( !mark[x] ) 
			dfs( x , 3 - col ) ; 
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); 
	int n,m; cin >> n >> m;
	for( int i =0 ;i < m  ; i++ ){ 
		int u,v; cin >> u >> v; 
		u--; v--; 
		c[u].push_back(v); 
		c[v].push_back(u); 
	}
	for( int i = 0 ; i < n ; i++ ) 
		if( !mark[i] ) 
			dfs(i,1); 
	int cnt = 0; 
	for( int i = 0 ; i < n ; i++ ) { 
		if( mark[i] == 1 ) cnt++; 
		for( auto x : c[i] ) 
			if( mark[i] == mark[x] ) { 
				cout << -1 << endl;
				return 0; 
			}
	}
	cout << cnt << endl;
	for( int i = 0 ; i < n ; i++ ) 
		if( mark[i] == 1 ) 
			cout << i + 1 << ' ' ; 
	cout << endl << n - cnt << endl; 
	for( int i = 0 ; i < n ; i++ ) 
		if( mark[i] == 2 ) 
			cout << i + 1 << ' '; 
	cout << endl;
}