//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxN = 100 * 1000 + 10; 
const int maxK = 3 * maxN; 
const int maxL = 18; 
typedef pair<int,int> pii; 
const int inf = 1e9 + 100; 

vector<int> c[maxK]; 
set<pii> curr[maxK]; 

int mn[4 * maxK];
int st[maxK],sz[maxK],head[maxK]; 
int par[maxK][maxL], h[maxK]; 

int mark[maxK], lo[maxK], que[maxK*2], en = 0; 

vector<int> e[maxK]; //edges of block composition tree
int cnt; 

void dec( int s , int p ) { 
	static int ind = 0; 
	mark[s] = true; 
	lo[s] = st[s] = ind++; 
	for( auto x : c[s] ) 
		if( !mark[x] ) { 
			que[en++] = s, que[en++] = x; 
			dec( x , s ); 
			lo[s] = min( lo[s] , lo[x] ); 
			//cerr << "!! SHIT " << s << ' ' << st[s] << "  "  << x << ' ' << lo[x] << endl;
			if( lo[x] >= st[s] ) { 
				int id = cnt++; 
				//cerr << "BEG " << id <<endl;
				do { 
					int y = que[--en]; 
					//cerr << y << ' ';
					e[y].push_back( id ); 
					e[id].push_back( y ); 
				} while( que[en] != s );
				//cerr << endl;
			}
		} else if( x != p )
			lo[s] = min( lo[s] , st[x] ); 
}

int dsz( int s) { 
	mark[s] = 1;
	for( auto x : e[s] ) if( !mark[x] ) 
		sz[s] += dsz( x  ) ; 
	return ++sz[s]; 
}

void dfs( int s , int p , int head ) { 
	static int ind = 0; 
	mark[s] = true; 
	::head[s] = head; 
	st[s] = ind++; 
	par[s][0] = p; 
	for( int k = 1 ; k < maxL ; k++ ) 
		par[s][k] = par[par[s][k-1]][k-1]; 
	int mx = maxK-1; 
	for( auto x : e[s] ) if(!mark[x] && sz[mx] < sz[x] )
		mx = x; 
	if( mx == maxK-1 ) return; 
	h[mx] = h[s] + 1; 
	dfs( mx , s , head ); 
	for( auto x : e[s] ) if( !mark[x] ) { 
		h[x] = h[s]+1; 
		dfs( x , s , x ); 
	}
}

int w[maxK]; 

void smin( int p , int v , int xl = 0 , int xr = cnt , int ind = 1 ) { 
	if( xr - xl == 1 ) { 
		mn[ind] = v; 
		return;
	}
	int xm = (xl+xr)/2; 
	if( p < xm ) smin( p , v, xl , xm , ind * 2 ) ; 
	else smin( p , v , xm , xr , ind * 2 + 1 ); 
	mn[ind] = min( mn[ind*2] , mn[ind*2+1] ) ; 
}
int gmin( int ql , int qr , int xl = 0 , int xr = cnt , int ind = 1 ) { 
	if( xr <= ql || qr <= xl ) return inf; 
	if( ql <= xl && xr <= qr ) return mn[ind]; 
	int xm = (xl+xr)/2; 
	return min( gmin( ql , qr , xl , xm , ind * 2 ) , 
			gmin( ql , qr , xm , xr , ind * 2 + 1 ) ) ; 
}

inline void update( int i , int p ) { 
	int s = i; 
	for( int t = 0 ; t < 2 ; t++ ) { 
		int last = -1;
	    if( curr[s].size() ) last = curr[s].begin()->first; 
		curr[s].erase( { w[i] , i } ) ; 
		curr[s].insert( { p , i } ); 
		int now = curr[s].begin()->first;
		if( last != now  ) 
			smin( st[s] , now ); 
		s = par[s][0]; 
	}
	w[i] = p; 
} 

inline int getMin( int u , int w ) { 
	int mn = inf; 
	while( st[u] >= st[w] ) { 
		int h = head[u]; 
		if( st[h] < st[w] ) h = w; 
		mn = min( mn , gmin( st[h] , st[u] + 1 ) );
		u = par[h][0]; 
		if( h == 0 ) break;
	}
	return mn;
}

inline int getH( int u , int h ) { 
	for( int i = 0 ; i < maxL ; i++ ) 
		if( (h>>i) & 1 ) 
			u = par[u][i]; 
	return u;
}
inline int LCA( int u , int v ) { 
	if( h[u] < h[v] ) swap( u , v ) ; 
	u = getH( u , h[u] - h[v] ); 
	if( u == v ) return u; 
	for( int k = maxL - 1 ; k >= 0 ; k-- ) 
		if( par[u][k] != par[v][k] ) 
			u = par[u][k] , v = par[v][k]; 
	return par[u][0];
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	int n,m,q; 
	cin >> n >> m >> q; 
	for( int i = 0 ; i < n ; i++ ) 
		cin >> w[i]; 
	for( int i = 0 ; i < m ; i++ ) { 
		int u,v;
		cin >> u >> v;
		u--; v--; 
		c[u].push_back(v); 
		c[v].push_back(u); 
	}
	cnt = n; 
	dec( 0 , -1 ); 


	memset( mark , 0 , sizeof mark ); 
	memset( st , 0 , sizeof st ); 
	dsz( 0 ); 
	memset( mark , 0 , sizeof mark ); 
	dfs( 0 , 0 , 0 ); 

	for( int i = 0 ; i < n ; i++ ) 
		update(i,w[i]); 

	for( int i = 0 ; i < q ; i++ ) { 
		int u,v; 
		char ch; cin >> ch >> u >> v;  
		if( ch == 'C' ) { 
			u--; 
			update( u , v );
		} else { 
			u--; v--; 
			int w = LCA(u,v); 
			//cerr << u << ' ' << v << " -> " << w << endl;
			int ans = min( getMin( u , w ) , getMin( v , w ) ) ; 
			//cerr << getMin( u , w ) <<  ' ' << getMin( v , w ) << endl;
			if( w >= n ) ans = min( ans , ::w[par[w][0]] ) ; 
			cout << ans << '\n';
		}
	} 
}