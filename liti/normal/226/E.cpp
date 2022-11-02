//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 1000 * 100 + 10; 
const int maxL = 20;
const int maxS = 2*maxN*maxL;
struct Seg { 
	Seg() { sum = l = r = 0; } 
	int sum,l,r; 
};
Seg seg[maxS]; 
int scnt;
int n; 

int add( int p , int v , int id , int xl = 0 , int xr = n ) { 
	if( xr - xl == 1 ) { 
		seg[scnt].sum = v + seg[id].sum; 
		return scnt++; 
	}
	int xm = (xl+xr)>>1;
	int l = seg[id].l , r = seg[id].r;
	if( p < xm ) 
		l = add( p , v , l , xl , xm ) ; 
	else
		r = add( p , v , r , xm , xr ) ; 
	seg[scnt].sum = seg[l].sum + seg[r].sum;
	seg[scnt].l = l , seg[scnt].r = r; 
	return scnt++;
}
int get( int ql , int qr , int id , int xl = 0 , int xr = n ) { 
	if( xr <= ql || qr <= xl ) return 0; 
	if( ql <= xl && xr <= qr ) return seg[id].sum;
	int xm = (xl+xr)>>1;
	return get( ql , qr , seg[id].l , xl , xm ) + 
		get( ql , qr , seg[id].r , xm , xr ); 
}

vector<int> c[maxN];
int st[maxN] , en[maxN]; 
int par[maxN][maxL], h[maxN]; 

void dfs( int s , int p , int h ) { 
	::h[s] = h; 
	par[s][0] = p;
	static int ind = 0;
	st[s] = ind++; 
	for( int i = 1 ; i < maxL ; i++ ) 
		par[s][i] = par[par[s][i-1]][i-1]; 
	for( auto x : c[s] ) 
		dfs( x , s , h + 1 ) ; 
	en[s] = ind;
}
int root[maxN]; // root id 

inline int lca( int u , int v ) { 
	if( h[u] > h[v] ) swap( u , v ); 
	for( int i = 0 ; i < maxL ; i++ ) if( (h[v] - h[u]) & (1<<i) ) 
		v = par[v][i];
	if( u == v ) return u; 
	for( int i = maxL - 1 ; i >= 0 ; i-- ) 
		if( par[u][i] != par[v][i] ) 
			u = par[u][i] , v = par[v][i]; 
	return par[u][0];
}
inline int gg( int u , int i1 , int i2 ) { 
	i1 = root[i1], i2 = root[i2];
	return h[u] - (get( 0 , st[u] + 1 , i2 ) - get( 0 , st[u] + 1 , i1 ));
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	scnt = 1;
	cin >> n; 
	n++;
	for( int i = 1 ; i < n ; i++ ) { 
		int p ; cin >> p; 
		c[p].push_back( i ) ; 
	}
	dfs( 0 , 0 , 0 ) ; 
	
	int m; cin >> m;
	for( int i = 1 ; i <= m ; i++ ) { 
		int t; cin >> t; 
		if( t == 1 ) { 
			int v; cin >> v; 
			root[i] = add( st[v] , 1 , root[i-1] ); 
			root[i] = add( en[v] , -1 , root[i] ) ; 
		} else { 
			root[i] = root[i-1];
			int u,v,k,y;
			cin >> u >> v >> k >> y;
			int w = lca(u,v);
			int p = par[w][0];
			int all = gg(u,y,i) + gg(v,y,i) - gg(p,y,i) - gg(w,y,i);
			all -= gg(u,y,i) - gg(par[u][0],y,i);
			all -= gg(v,y,i) - gg(par[v][0],y,i);
			if( all < k ) { 
				cout << -1 << '\n';
				continue;
			}
			if( k > gg(par[u][0],y,i) - gg(p,y,i) ) { 
				swap( u , v ) ; 
				k = all - k + 1;
			}
			u = par[u][0];
			for( int x = maxL - 1 ; x >= 0 ; x-- ) 
				if( gg(u,y,i) - gg( par[u][x],y,i ) < k ) { 
					k -= gg(u,y,i) - gg( par[u][x], y , i ) ; 
					u = par[u][x]; 
				}
			cout << u << '\n';
		}
	}
}