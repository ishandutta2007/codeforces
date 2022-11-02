//In the name of Allah
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

typedef pair<ll,ll> point; 
#define X first
#define Y second

inline ll cross( point a , point b , point c ) { //cross( AB , AC ) 
	return ( b.X - a.X ) * ( c.Y - a.Y ) - ( b.Y - a.Y ) * ( c.X - a.X ) ; 
}

const int maxN = 1000 * 100 + 100; 

point a[maxN]; 
point curr[maxN]; 
int ind[maxN] , en;

const int maxL = 20; 
int h[maxN],par[maxN][maxL]; 
vector<int> c[maxN];

void dfs( int s , int p ) { 
	par[s][0] = p; 
	for( int k = 1 ; k < maxL ; k++ ) 
		par[s][k] = par[par[s][k-1]][k-1]; 
	for( auto x : c[s] ) {
		h[x] = h[s] + 1; 
		dfs( x , s ); 
	}
}

inline int getH( int u , int h ) { 
	for( int i = 0 ; i < maxL ; i++ ) 
		if( (h>>i) & 1 ) 
			u = par[u][i]; 
	return u; 
}

inline int getLCA( int u , int v ) { 
	if( h[u] > h[v] ) swap(u,v); 
	v = getH( v , h[v] - h[u] ); 
	if( v == u ) return u; 
	for( int k = maxL - 1 ; k >= 0 ; k-- ) 
		if( par[u][k] != par[v][k] ) { 
			u = par[u][k] ; 
			v = par[v][k] ; 
		}
	return par[u][0]; 
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 

	int n; cin >> n; 
	for( int i = 0 ; i < n ; i++ ) {
		cin >> a[i].X >> a[i].Y; 
		a[i].X *= -1; 
	}
	reverse( a , a + n ); 

	curr[en++] = a[0]; 
	ind[0] = n - 1; 
	for( int i = 1 ; i < n ; i++ ) { 
		while( en > 1 && cross( curr[en-2] , curr[en-1] , a[i] ) > 0 ) 
			en--; 
		c[ind[en-1]].push_back( n - i - 1 ); 
		//cout << n - i - 1 << " points to " << ind[en-1] << endl;
		ind[en] = n - i - 1; 
		curr[en++] = a[i]; 
	}

	dfs( n - 1 , n - 1  );

	int q; cin >> q;
	for( int i = 0 ; i < q ; i++ ) { 
		int u,v; cin >> u >> v; 
		u--; v--; 
		cout << getLCA( u , v ) + 1 << ' ';
	}
}