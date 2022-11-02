//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 100 * 1000 + 10; 
int par[maxN];
vector<int> c[maxN];
pair<int,int> e[maxN];

int dfind( int u ) { 
	return par[u] == -1 ? u : par[u] = dfind( par[u] ) ; 
}

void dmerge( int u , int v ) { 
	u = dfind(u) , v = dfind(v); 
	if( u == v ) return;
	par[u] = v; 
}
bool check[maxN];
bool co[maxN];
void dfs( int s , int c = 0 ) { 
	co[s] = c;
	check[s] = true;
	for( auto x : ::c[s] ) if( !check[x] ) 
		dfs( x , c ^ 1 ) ; 
}



int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	memset( par , -1 , sizeof par ); 
	int n,m; 
	cin >> n >> m; 
	int cnt = 0;
	for( int i = 0 ; i < m ; i++) {
		int a,b,c; cin >> a >> b >> c; a--; b--; 
		if( c ) 
			dmerge( a , b ) ; 
		else 
			e[cnt++] = { a , b } ; 
	} 
	for( int i = 0 ; i < cnt ; i++ ) { 
		int a = e[i].first , b= e[i].second;
		a = dfind(a) , b = dfind(b); 
		c[a].push_back( b ) ;
		c[b].push_back( a ) ; 
	}
	cnt = 0;
	for( int i = 0 ; i < n; i++ ) 
		if( dfind(i) == i && !check[i] ) {
			dfs( i ); 
			cnt++; 
		}
	for( int i = 0 ; i < n ; i++ ) 
		for( auto x : c[i] ) 
			if( co[i] == co[x] ){ 
				cout << 0 << endl;
				return 0; 
			}
	int ret = 1; 
	int mod = 1e9 + 7;
	for( int i = 0 ; i < cnt - 1 ; i++ ) 
		ret = (ret + ret) % mod;
	cout << ret <<endl;
}