//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxN = 100 * 1000 + 100; 
const int maxL = 20 + 1;
vector<int> c[maxN]; 

int st[maxN],en[maxN],ind; 
int h[maxN],par[maxN][maxL];

void dfs( int s , int p = 0) { 
	st[s] = ind++; 
	par[s][0] = p; 
	for( int k = 1 ; k < maxL ; k++ ) 
		par[s][k] = par[par[s][k-1]][k-1]; 
	for( auto x : c[s] ) 
		if( x != p ) { 
			h[x] = h[s] + 1; 
			dfs( x , s ) ; 
		}
	en[s] = ind; 
}

inline bool cmp( const int& a , const int& b ) { 
	return st[a] < st[b]; 
}

inline int getH( int u , int h ) { 
	for( int k = 0 ; k < maxL ; k++ )
		if( (h>>k) & 1 ) 
			u = par[u][k]; 
	return u; 
}

inline int getLCA( int u , int v ) { 
	if( h[u] > h[v] ) swap(u,v); 
	v = getH( v , h[v] - h[u] ); 
	if( u == v ) return u; 
	for( int k = maxL - 1 ; k >= 0 ; k-- ) 
		if( par[u][k] != par[v][k] ) { 
			u = par[u][k]; 
			v = par[v][k]; 
		}
	return par[u][0]; 
}

int a[maxN*2],cnt; 
int good[maxN],ans; 
bool check; 

bool solve( int s ) { 
	ind++; //asume that a[ind] was s
	int count = 0; 
	while( ind < cnt && st[a[ind]] < en[s] ) {
		if( good[a[ind]] && good[s] && par[a[ind]][0] == s ) 
			check = false;
		bool v = solve( a[ind] ); 
		if( v && good[s] ) ans++; 
		else if( v ) count++; 
	}
	if( count > 1 ) { 
		ans++; 
		return 0; 
	}
	count += good[s]; 
	return count > 0; 
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 
	int n; cin >> n;
	for( int i = 0 ; i < n - 1 ; i++ ) { 
		int u,v; cin >> u >> v; 
		u--; v--; 
		c[u].push_back(v); 
		c[v].push_back(u); 
	}

	dfs(0); 

	int q; cin >> q; 
	for( int t = 0 ; t < q ; t++ ) { 
		int m; cin >> m; 
		for( int i = 0 ; i < m ; i++ ) { 
			cin >> a[i]; a[i]--; 
			good[a[i]] = true; 
		}
		sort( a , a + m , cmp ); 
		check = true; 
		cnt = m; 
		for( int i = 0 ; i + 1 < m ; i++ ) 
			a[cnt++] = getLCA( a[i] , a[i+1] ) ; 
		sort( a , a + cnt , cmp ); 
		cnt = unique( a , a + cnt ) - a; 
		ind = ans = 0; 
		solve(a[0]); 
		if( check ) 
			cout << ans << '\n'; 
		else
			cout << "-1\n";

		for( int i = 0 ; i < cnt ; i++ ) 
			good[a[i]] = false; 
	}
}