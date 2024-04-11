//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 1000*100 ; 
const int mod = 1e9 + 7;
vector<pair<int,int>> c[maxN]; 
vector<pair<int,int>> q[maxN]; 
int st[maxN] , en[maxN]; 
int ans[maxN];

inline int ss( int a , int b ) { 
	a %= mod; b %= mod;
	int c = a + b;
	c %= mod; c += mod; c %= mod;
	return c;
}


int n; 
int sum[4*maxN], sum2[4*maxN], toadd[4*maxN];

inline void proc( int i , int v , int xl , int xr ) { 
	toadd[i] = ss( toadd[i] , v ) ; 
	sum2[i] = ss(sum2[i] , ll(xr-xl)*v%mod*ll(v)%mod);
	sum2[i] = ss(sum2[i] , 2*ll(v) * sum[i] % mod);
	sum[i] = ss( sum[i] , ll(xr-xl)*v%mod );
}

inline void shift( int i , int xl , int xm , int xr ) { 
	proc( i * 2, toadd[i] , xl , xm ) ; 
	proc( i * 2 + 1 , toadd[i] , xm , xr ) ; 
	toadd[i] = 0; 
}
inline void update( int i ) { 
	sum2[i] = ss( sum2[i*2] , sum2[i*2+1] ) ; 
	sum[i] = ss( sum[i*2] , sum[i*2+1] ) ; 
}

void addVal( int ql , int qr , int v , int xl = 0 , int xr = n , int ind = 1 ) { 
	if( xr <= ql || qr <= xl ) return; 
	if( ql <= xl && xr <= qr ) {
		proc( ind , v , xl , xr ); 
		return ;
	}
	int xm = (xl+xr)>>1;
	shift( ind , xl , xm , xr ) ; 
	addVal( ql , qr , v , xl , xm , ind * 2 ) ; 
	addVal( ql , qr , v , xm , xr , ind * 2 + 1 ) ; 
	update( ind ) ; 
}
int getVal( int ql , int qr , int xl = 0 , int xr = n , int ind = 1 ) { 
	if( xr <= ql || qr <= xl ) return 0; 
	if( ql <= xl && xr <= qr ) 
		return sum2[ind];
	int xm = (xl+xr)>>1;
	shift( ind , xl , xm , xr ) ; 
	return ss( getVal( ql , qr , xl , xm , ind * 2 ) , getVal( ql , qr , xm , xr , ind * 2 + 1 ) ) ;
}


void dfs( int s , int p = -1 , int cost = 0 ) { 
	static int ind = 0;
	st[s] = ind++;
	addVal( st[s] , st[s] + 1 , cost ) ; 
	for( auto x : c[s] ) if( x.first != p ) 
		dfs( x.first , s , ss(cost , x.second) ); 
	en[s] = ind;
}
void calc( int s , int p = -1 ) { 
	for( auto x : q[s] ) 
		ans[x.second] = ss(getVal( st[x.first] , en[x.first] ) , ss( - getVal( 0 , st[x.first] ) ,  - getVal( en[x.first] , n ) ) ) ; 
	for( auto x : c[s] ) if( x.first != p ) { 
		addVal( 0 , n , ss(0,x.second) ) ; 
		addVal( st[x.first] , en[x.first] , ss(-2*x.second,0) ) ; 
		calc( x.first , s ) ; 
		addVal( 0 , n , ss(0,-x.second) ) ; 
		addVal( st[x.first] , en[x.first] , ss(0,2*x.second) ) ; 
	}
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for( int i = 0 ; i < n - 1 ; i++ ) { 
		int a,b,c; cin >> a >> b >> c;
		a--; b--;
		::c[a].push_back( {b,c} ) ; 
		::c[b].push_back( {a,c} ); 
	}
	dfs( 0 ) ; 
	int m; 
	cin >> m;
	for( int i = 0 ; i < m ; i++ ) { 
		int u,v; cin >> u >> v; u--; v--;
		q[u].push_back( { v , i } ) ; 
	}
	calc( 0 ) ;
	for( int i = 0 ; i < m ; i++ ) 
		cout << ans[i] << '\n';
}