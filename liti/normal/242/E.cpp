//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 100*1000 + 10; 
const int maxL = 20 + 2; 

int seg[maxL][4*maxN];
int add[maxL][4*maxN];
int n; 

inline void shift( int k , int ind ,int xl ,int xr )  { 
	if( add[k][ind] == 0 ) return;
	int xm = (xl + xr) / 2; 
	add[k][ind] = 0;
	add[k][ind*2] ^= 1; 
	add[k][ind*2+1] ^= 1;
	seg[k][ind*2] = (xm-xl) - seg[k][ind*2];
	seg[k][ind*2+1] = (xr-xm) - seg[k][ind*2+1];
}

inline void update( int k , int ind ) { 
	seg[k][ind] = seg[k][ind*2] + seg[k][ind*2+1]; 
}


void ch( int ql , int qr , int k , int xl = 0 , int xr = n , int ind = 1 ) { 
	if( xr <= ql || qr <= xl ) 
		return;
	if( ql <= xl && xr <= qr ) { 
		add[k][ind] ^= 1 ; 
		seg[k][ind] = ( xr - xl ) - seg[k][ind];
		return;
	}
	shift(k,ind,xl,xr); 
	int xm = (xl+xr) >> 1; 
	ch( ql , qr , k , xl , xm , ind * 2 ) ; 
	ch( ql , qr , k , xm , xr , ind * 2 + 1 ) ; 
	update( k , ind ) ; 
}

int gs( int ql , int qr , int k , int xl = 0 , int xr = n , int ind = 1 ) { 
	if( xr <= ql || qr <= xl ) 
		return 0; 
	if( ql <= xl && xr <= qr ) 
		return seg[k][ind];
	int xm = (xl+xr)/2; 
	shift(k ,ind , xl , xr ); 
	int ret = gs( ql , qr , k , xl , xm , ind * 2 ) + 
		gs( ql , qr , k , xm , xr , ind * 2 + 1 ) ; 
	update( k , ind ) ; 
	return ret;
}


int main() {
	ios::sync_with_stdio(false);
	cin >> n; 
	for( int i = 0 ; i < n ; i++ ) { 
		int x; cin >> x; 
		for( int k = 0 ; k < maxL ; k++ ) if( (x>>k) & 1 ) 
			ch( i , i + 1 , k ) ; 
	}
	int q; 
	cin >> q; 
	for( int i = 0 ; i < q ; i++ ) { 
		int t; cin >> t; 
		if( t == 1 ) { 
			int l,r; cin >> l >> r; 
			l--; 
			ll ret = 0;
			for( int k = 0 ; k < maxL ; k++ ) 
				ret += ( 1LL<<k) *  gs( l , r ,k  ) ; 
			cout << ret << '\n';
		} else { 
			int l,r,x; cin >> l >> r >> x; l--;
			for( int k = 0 ; k < maxL ; k++ ) if( (x>>k) & 1 ) 
				ch( l , r , k ) ; 
		}
	}
}