//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxN = 200 * 1000 + 100; 
const int mod = 1e9 + 7;
const int maxX = 1000*1000 + 10; 

int a[maxN], psum[maxN]; 
vector<int> prime[maxX];

vector<pair<int,int>> que[maxN];
int ans[maxN];
int last[maxX];

inline int bpow( int a , int b ) { 
	int ret =1;
	for( ; b ; b /= 2 ) { 
		if( b & 1 ) ret = ret * 1ll * a % mod;
		a = a * 1ll * a % mod; 
	}
	return ret; 
}

int seg[4*maxN]; 
int n; 

int getVal( int ql , int qr , int xl = 0 , int xr = n , int ind = 1 ) { 
	if( xr <= ql || qr <= xl ) return 1;
	if( ql <= xl && xr <= qr ) return seg[ind]; 
	int xm = (xl+xr)/2; 
	return getVal( ql , qr , xl , xm , ind * 2 ) * 1ll * 
		getVal( ql , qr , xm , xr , ind * 2 + 1 ) % mod; 
}

void rmVal( int p , int x , int xl = 0 , int xr = n , int ind = 1 ) { 
	if( xr - xl == 1 ) { 
		seg[ind] = seg[ind] * 1ll * bpow( (1 - bpow(x,mod-2) + mod) % mod , mod - 2 ) % mod;  
		return; 
	}
	int xm = (xl+xr)/2;
	if( p < xm ) rmVal( p , x, xl , xm , ind * 2 ) ; 
	else rmVal( p , x, xm , xr , ind * 2 + 1 ) ; 
	seg[ind] = seg[ind*2] * 1ll * seg[ind*2+1] % mod; 
}
void addVal( int p , int xl = 0 , int xr = n , int ind = 1 ) { 
	if( xr - xl == 1 ) { 
		seg[ind] = 1;
		for( auto x : prime[a[p]] ) 
			seg[ind] = seg[ind] * 1ll * ((1 - bpow(x,mod-2) + mod) % mod) % mod;  
		return; 
	}
	int xm = (xl+xr)/2;
	if( p < xm ) addVal( p , xl , xm , ind * 2 ) ; 
	else addVal( p , xm , xr , ind * 2 + 1 ) ; 
	seg[ind] = seg[ind*2] * 1ll * seg[ind*2+1] % mod; 
}

int main() {
	fill( seg , seg + 4*maxN , 1 );
	for( int i = 2 ; i < maxX ; i++ ) 
		if( prime[i].empty() ) 
			for( int j = i ; j < maxX ; j += i ) 
				prime[j].push_back(i); 
	scanf("%d" , &n);
	psum[0] = 1;
	for( int i = 0 ; i < n ; i++ ) { 
		scanf("%d" , a + i);
		psum[i+1] = psum[i] * 1ll * a[i] % mod;
	}
	int q;
	scanf("%d" , &q);
	for( int i = 0 ; i < q ; i++ ) {
		int l,r;
		scanf("%d %d" , &l , &r );
		l--; 
		que[r].push_back( {l,i} ); 
	}

	memset( last , -1 , sizeof last ); 
	for( int i = 0 ; i <= n ; i++ ) { 
		for( auto x : que[i] ) { 
			ans[x.second] = psum[i] * 1ll * bpow( psum[x.first] , mod - 2 ) % mod * 1ll *
				getVal( x.first , i ) % mod; 
		}
		if( i == n ) break;
		for( auto x : prime[a[i]] ) { 
			if( last[x] != -1 ) 
				rmVal( last[x] , x ); 
			last[x] = i;
		}
		addVal( i ); 
	}
	for( int i =0 ; i < q ; i++ ) 
		printf( "%d\n" , ans[i] );
}