//In the name of Allah
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int mod = 1e9 + 7; 

inline int sum( int a , int b ) { 
	return ( ( a + b ) % mod + mod ) % mod; 
}
inline int mul( int a , int b ) { 
	return a * 1ll * b % mod; 
}
inline int bpow( int a , int b ) { 
	int r = 1; 
	for( ; b ; b /= 2 ) { 
		if( b & 1 ) r = mul( r , a ); 
		a = mul( a , a ); 
	}
	return r; 
}
const int maxN = 1000 * 1000 + 10; 
int fact[maxN],inv[maxN];
int comb[maxN];

inline int cmb( int n , int r ) { 
	if( comb[n] != -1 ) return comb[n]; 
	if( r > n ) return comb[n] = 0; 
	return comb[n] = mul( fact[n] , mul( inv[r] , inv[n-r] ) ); 
}

int f[maxN]; 
vector<int> divi[maxN]; 
int val[maxN]; 
int cnt[maxN];
int ss; 
int k;

inline void add( int v ) { 
	for( auto x : divi[v] ) { 
		ss = sum( ss , -val[x] ); 
		cnt[x]++;
		val[x] = mul(cmb( cnt[x] , k ) , f[x] );
		ss = sum( ss , val[x] ) ;  
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); 

	memset( comb , -1 , sizeof comb ) ; 
	fact[0] = inv[0] = 1; 

	for( int i = 1 ; i < maxN ; i++ ) { 
		fact[i] = mul(fact[i-1] , i); 
		inv[i] = bpow( fact[i] , mod - 2 ); 
	}

	for( int i = 1 ; i < maxN ; i++ ) 
		for( int j = i ; j < maxN ; j+= i ) 
			divi[j].push_back(i); 
	f[1] = 1; 
	for( int i = 2 ; i < maxN ; i++ ) {
		for( auto x : divi[i] ) if( x != i )  
			f[i] = sum(f[i],f[x]); 
		f[i] = sum(i ,- f[i]); 
	}

	int n,q; cin >> n >> k >> q; 
	for( int i = 0 ; i < n ; i++ ) { 
		int x; cin >> x; 
		add( x ) ; 
	}
	for( int i = 0 ; i < q ; i++ ) { 
		int x; cin >> x; 
		add(x); 
		cout << ss << '\n'; 
	}
}