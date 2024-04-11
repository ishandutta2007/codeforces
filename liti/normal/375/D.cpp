/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (((int) x.size()))
typedef long long ll;

const int maxN = 1000*100 + 10; 
vector<int> c[maxN];
int col[maxN];

int cnt[maxN]; // colors cnt 
int above[maxN]; // number of colors above above[i]

vector<pair<int,int>> que[maxN];
int ans[maxN];

int sz[maxN];
int find_sz( int s , int p = -1 ) { 
	for( auto x : c[s] ) if( x != p ) 
		sz[s] += find_sz( x , s ) ; 
	return ++sz[s];
}

void fill( int s , int p , int v ) { 
	if( v == -1 ) {
		above[cnt[col[s]]]--;
		cnt[col[s]]--;
	} else { 
		cnt[col[s]]++;
		above[cnt[col[s]]]++;
	}
	for( auto x : c[s] ) if( x != p ) 
		fill( x , s , v ) ; 
}

void dfs( int s , int p = -1 ) { 
	int val = maxN - 1;
	for( auto x : c[s]  )
		if( x != p && sz[x] > sz[val] ) 
			val = x; 
	for( auto x : c[s] ) if( x != p &&  x != val ) {
		dfs( x ,  s ); 
		fill( x , s , -1 ) ;
	}
	if( val != maxN - 1 ) 
		dfs( val , s ) ; 
	for( auto x : c[s] ) if( x != p && x != val ) 
		fill( x, s, 1 ) ; 

	cnt[col[s]]++;
	above[cnt[col[s]]]++;

	for( auto x : que[s] ) 
		ans[x.second] = above[x.first]; 
}


int main() {
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	for( int i = 0 ; i < n ; i++ ) 
		cin >> col[i];
	for( int i = 0 ; i < n - 1 ; i++ ) { 
		int u,v;
		cin >> u >> v; u--; v--; 
		c[u].push_back( v ) ; 
		c[v].push_back( u ) ; 
	}

	for( int i = 0 ; i < m ; i++ ) { 
		int u,k;
		cin >> u >> k; 
		que[u-1].push_back( {k,i} ) ; 
	}

	find_sz( 0 ) ; 
	dfs( 0 ) ; 
	for( int i = 0 ; i < m ; i++ ) 
		cout << ans[i] << '\n';
}