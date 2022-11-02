//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e6 + 3;  

inline ll mul( ll a , ll b ) { 
	return a * 1ll * b % mod; 
}
inline ll sum( ll a , ll b ) { 
	return ( (a+b)%mod + mod ) % mod; 
}

inline ll bpow( ll a , ll b ) {  
	a %= mod; 
	ll ret = 1; 
	for( ; b ; b /= 2 ) { 
		if( b % 2 ) 
			ret = mul(ret,a);
		a = mul(a,a);
	}
	return ret; 
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	ll n,k; cin >> n >> k; 
	if( n < 63 && k > (1ll<<n) ) { 
		cout << "1 1" << endl;
		return 0; 	
	}
	ll v = bpow( 2 , n ); 
	ll rem = bpow( v , k ); 
	ll z = 1; 
	for (int i = 0 ; i < min(k,mod+10) ; i++ ) 
		z = mul( z , ( v + mod - i ) ); 

	ll rev = bpow( 2 , mod - 2 ); 
	ll tot = bpow( rev , n ); 
	for( ll t = 2 ; t <= k - 1 ; t *= 2 )  { 
		tot = mul( tot , bpow( rev , (k-1)/t ) );
	} 
	cout << mul( sum( rem , -z )  , tot ) << " " << mul(rem,tot) << endl;
}