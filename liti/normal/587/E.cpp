//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxN = 2 * 1000 * 100 + 100;
const int maxS = 4 * maxN; 
typedef vector<int> Base; 

Base seg[maxS]; 
int toxor[maxS]; 
int n; 

inline int gg( int x ) { 
	return 1<<(31 - __builtin_clz(x)); 
}

inline Base merge( Base a , Base b ) { 
	for( auto x : b ) { 
		for( auto y : a ) 
			if( x & gg(y) ) 
				x ^= y; 
		if( x ) { 
			for( auto& y : a ) 
				if( y & gg(x) )
					y ^= x; 
			a.push_back(x); 
		}
	}
	return a; 
}

inline void handle( int ind , int qv ) { 
	if( qv == 0 ) return;
	for( auto& x : seg[ind] ) 
		if( x & 1 ) 
			x ^= qv; 
	seg[ind] = merge( Base() , seg[ind] ); 
	toxor[ind] ^= qv; 
}

inline void shift( int ind  ) { 
	handle( ind * 2  , toxor[ind] ); 
	handle( ind * 2 + 1, toxor[ind] ); 
	toxor[ind] = 0; 
}

void add( int ql , int qr , int qv , int xl = 0 , int xr = n , int ind = 1 ) { 
	if( xr <= ql || qr <= xl ) return; 
	if( ql <= xl && xr <= qr ) {
		handle( ind , qv ); 
		return; 
	}
	int xm = (xl+xr)/2; 
	shift( ind ); 
	add( ql , qr , qv , xl , xm , ind * 2 ); 
	add( ql , qr , qv , xm , xr , ind * 2 + 1 ); 
	seg[ind] = merge( seg[ind*2] , seg[ind*2+1] ); 
}
Base get( int ql , int qr , int xl = 0 , int xr = n , int ind = 1 ) { 
	if( xr <= ql || qr <= xl ) return Base(); 
	if( ql <= xl && xr <= qr ) return seg[ind]; 
	int xm = (xl+xr)/2; 
	shift( ind ); 
	return merge( get( ql , qr , xl , xm , ind * 2 ) , 
			get( ql , qr , xm , xr , ind * 2 + 1 ) ) ; 
}
int a[maxN]; 
void build( int xl = 0 , int xr = n , int ind = 1 ) { 
	if( xr - xl == 1 ) { 
		seg[ind].push_back(a[xl]); 
		return; 
	}
	int xm = (xl+xr)/2; 
	build( xl , xm , ind * 2 ); 
	build( xm , xr , ind * 2 + 1 ); 
	seg[ind] = merge( seg[ind*2] , seg[ind*2+1] ); 
}
	
int main() { 
	//ios::sync_with_stdio(false); cin.tie(0);
	int q; cin >> n >> q; 
	for( int i = 0 ; i < n ; i++ ) {
		cin >> a[i]; 
		a[i] = 2 * a[i] + 1; 
	}
	build(); 

	for( int i = 0 ; i < q ; i++ ) { 
		int t; cin >> t; 
		if( t == 1 ) { 
			int l,r,k; cin >> l >> r >> k; 
			add( l - 1 , r , k*2 ); 
		} else { 
			int l,r; 
			cin >> l >> r;
			auto ret = get(l-1,r); 
			for( auto& x : ret ) 
				if( x & 1 ) x--; 
			cout << (1<<merge(Base(),ret).size()) << endl;
		}
	} 
}