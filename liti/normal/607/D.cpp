//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxN = 200 * 1000 + 100; 
const int mod = 1e9 + 7; 

vector<int> c[maxN]; 
pair<int,int> que[maxN]; 
int st[maxN]; 
int sz[maxN];
int par[maxN]; 
int up[maxN];

int cnt = 0; 

int dsz( int s )  { 
	for( auto x : c[s] ) 
		sz[s] += dsz(x);
	return ++sz[s]; 
}

void dfs( int s , int p = -1 , int col = 0 ) { 
	static int ind = 0; 
	up[s] = col;
	par[s] = p; 
	st[s] = ind++; 
	if( c[s].empty() ) return;
	int mx = 0; 
	for( int i = 1 ; i < (int)c[s].size() ; i++ )
		if( sz[c[s][i]] > sz[c[s][mx]] ) 
			mx = i; 
	swap( c[s][mx] , c[s][0] ) ; 
	for( auto x : c[s] ) 
		if( x != c[s][0] ) 
			dfs( x , s , x ); 
		else
			dfs( x , s , col ); 
}


int ch[maxN]; 
int zarb[4*maxN] , sum[4*maxN] , toadd[4*maxN]; 

inline void shift( int ind ) { 
	if( toadd[ind] == 0 ) return;
	sum[ind*2+1] += toadd[ind]; 
	toadd[ind*2+1] += toadd[ind]; 
	toadd[ind] = toadd[ind] * 1ll * zarb[ind*2+1] % mod; 
	sum[ind*2] += toadd[ind]; 
	toadd[ind*2] += toadd[ind]; 
	toadd[ind] = 0; 
	for( int t = 0 ; t < 2 ; t++ ) {  
		if( sum[ind*2+t] >= mod ) 
			sum[ind*2+t] -= mod; 
		if( toadd[ind*2+t] >= mod )
			toadd[ind*2+t] -= mod; 
	}
}

void upd( int p , int xl = 0 , int xr = cnt , int ind = 1 ) { 
	if( xr - xl == 1 ) { 
		zarb[ind] = ch[xl]; 
		return; 
	}
	int xm = (xl + xr) / 2; 
	shift( ind ); 
	if( p < xm ) upd( p , xl , xm , ind * 2 ) ; 
	else upd( p , xm , xr , ind * 2 + 1 ) ; 
	zarb[ind] = zarb[ind*2] * 1ll * zarb[ind*2+1] % mod; 
}
int get( int p , int xl = 0 , int xr = cnt , int ind = 1 ) { 
	if( xr - xl == 1 ) 
		return sum[ind]; 
	int xm = (xl + xr) / 2; 
	shift( ind ); 
	if( p < xm ) return get( p , xl , xm , ind * 2 ) ; 
	else return get( p , xm , xr , ind * 2 + 1 ) ; 
}

int add( int ql , int qr , int v , int xl = 0 , int xr = cnt , int ind = 1 ) { 
	if( xr <= ql || qr <= xl ) return v; 
	if( ql <= xl && xr <= qr ) { 
		sum[ind] += v; 
		if( sum[ind] >= mod ) sum[ind] -= mod; 
		toadd[ind] += v; 
		if( toadd[ind] >= mod ) toadd[ind] -= mod; 
		return v * 1ll * zarb[ind] % mod; 
	}
	int xm = (xl+xr) / 2; 
	shift( ind ) ; 
	v = add( ql , qr , v , xm , xr , ind * 2 + 1 ) % mod ; 
	return add( ql , qr , v , xl , xm , ind * 2 ) % mod;
}


int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 
	int v1 ; cin >> v1; 
	int q; cin >> q;
	que[0] = { cnt++ , v1 }; 

	for( int i = 1 ; i <= q ; i++ ) { 
		int t; cin >> t; 
		if( t == 1 ) { 
			int p , v; cin >> p >> v; p--; 
			c[p].push_back(cnt);
			que[i] = { cnt++ , v } ; 
		} else { 
			int p; cin >> p; p--; 
			que[i] = { p , -1 } ; 
		}
	}

	dsz(0);
	dfs(0); 

	for( int i = 0 ; i <= q ; i++ ) 
		if( que[i].second == -1 ) { 
			int s = que[i].first;
			cout << ch[st[s]] * 1ll * get( st[s] ) % mod << '\n';
		} else { 
			int s = que[i].first; 
			int v = que[i].second;
			int p = par[s]; 
			int last = 0; 
			if( p != -1 ) {
				last = get( st[p] ) * 1ll * (ch[st[p]]) % mod; 
				ch[st[p]]++;
			}
		   	ch[st[s]]++; 
			if( p != -1 ) 
				upd( st[p] ); 
			upd( st[s] ); 
			add( st[s] , st[s] + 1 , v ); 
			if( p == -1 ) continue; 
			add( st[p] , st[p] + 1 , v ); 
			last = (get( st[p] ) * 1ll * ch[st[p]] ) % mod - last; 
			v = ( last % mod + mod ) % mod;
			p = par[p]; 
			while( p != -1 ) { 
				v = add( st[up[p]] , st[p] + 1 , v );
				p = par[up[p]]; 
			}
		}
}