//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    
ll n;
int m,mod; 

ll solve( ll ql , ll qr , ll u , ll xl = 0 , ll xr = n , ll val = 0 , int t = 0 ) { 
	if( xr <= ql || qr <= xl ) return 0; 
	if( ql <= xl && xr <= qr ) { 
//		cerr << "BUG " << xl << ' ' << xr << endl;
		u--; 
		if( u - val < 0 ) return 0;
		ll k = 1 + ( u - val ) / (1LL<<t); 
		ll kp = 2*val + ( (k-1) * (1LL<<t) );
		ll ret = k;
		if( kp & 1 ) k >>=1;
		else kp >>=1;
		ret += k % mod * (kp % mod) % mod ; 
		if( ret >= mod ) ret -= mod;
		return ret;
	}
	ll xm = (xl+xr+1)>>1; 
	ll ret = solve( ql , qr , u , xl , xm , val , t + 1  ) +
		solve( ql , qr , u , xm , xr , val + (1LL<<t) , t + 1 ) ; 
	if( ret >= mod ) ret -= mod;
	return ret; 
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> mod;
	for( int i = 0 ; i < m ; i++ ) { 
		ll l , r , u , v; 
		cin >> l >> r >> u >> v; 
		l--;
		ll ret = solve( l , r , min(n,v) ) - solve( l , r , min(n,u - 1) ); 
		ret = ( ret + mod ) % mod;
		cout << ret << '\n';
	}
}