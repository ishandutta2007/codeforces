//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

map<ll,int> F; 
int mod;
ll f( ll n ) { 
	if( F.count(n) ) return F[n]; 
	ll k = n /2; 
	if( n % 2 == 0 ) 
		return F[n] = ( f(k) * f(k) % mod + f(k-1)*f(k-1) % mod ) % mod;
	else
		return F[n] = ( f(k) * f(k+1) % mod + f(k-1)*f(k) % mod ) % mod;
}

int bpow( int a , ll b ) { 
	int res = 1; 
	while( b > 0 ) { 
		if( b & 1 )
			res = res * 1ll * a % mod; 
		b/=2;
		a = a * 1ll * a % mod; 
	}
	return res; 
}
int main() { 
	ll n,k,l; 
	cin >> n >> k >> l >> mod; 
	if( mod == 1 ||  k >= (1ULL<<min(l,63ll)) ) {
		cout << 0 << endl;
		return 0; 
	}
	int x = 0;
	for( int i= 0 ; i < l ; i++ ) if( (k>>i) & 1 ) x++;
	F[0] = 1 , F[1] = 1;
//	cout << x << endl << f(3) << endl;
	cout << bpow( ( bpow( 2 , n ) - f(n+1) + mod ) % mod , x ) *1ll* bpow( f(n+1) , l - x ) % mod << endl;
}