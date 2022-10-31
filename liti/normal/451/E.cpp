#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxN = 20;

ll f[maxN];

int tav( ll a, int b ) { 
	ll r = 1;
	while( b ) { 
		if( b & 1 ) 
			r = ( r * a ) % mod;
		a = ( a * a ) % mod;
		b>>=1;
	}
	return r;
}

int co( int r, ll n ) { 
	if( r > n ) 
		return 0;
	ll soorat = 1; 
	ll makhraj = 1; 

	for(int i = 0 ; i < r ; i++) {
		soorat = ( soorat * ((n-i)%mod) ) % mod;
		makhraj = ( makhraj * (i+1) ) % mod;
	}

	soorat = ( soorat * tav( makhraj, mod - 2 ) ) % mod;

	return soorat;
}

int main() { 
	int n;
	ll s;
	cin >> n >> s;

	for(int i = 0 ; i < n; i++) 
		cin >> f[i];

	int ans = 0;
	for(int i =0 ; i < (1<<n) ; i++ ) { 
		int z = 1;
		int cnt = __builtin_popcount(i) ;
		if( cnt & 1 ) 
			z = -1;

		ll sum = 0;
		for(int j = 0 ;  j< n ; j++ ) 
			if( i & (1<<j) ) 
				sum += f[j] + 1;
		ans = ans + z*co( n -1, n - 1 + s - sum ) ;
		if( ans >= mod ) 
			ans -= mod;
		if ( ans < 0 ) 
			ans += mod;
	}

	cout << ans << endl;
}