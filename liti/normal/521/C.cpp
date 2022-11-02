/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int mod = 1e9 + 7;

int tav( int a , int b ) { 
	int res = 1;
	while( b ) { 
		if( b & 1 ) 
			res = res*1ll*a % mod;
		b >>=1 ;
		a = a*1ll*a % mod;
	}
	return res;
}
int rev( int a ) {
	return tav( a , mod - 2 ) ; 
}

int choose( int r , int n ) { 
	int res = 1;
	for( int i =  0 ; i < r ; i++ ) 
		res = res*1ll*(n-i) % mod;
	for( int i = 0 ; i < r ; i++ ) 
		res = res*1ll*rev(i+1) % mod;
	return res;
}

int main() { 
	//k = 0
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s; 
	int ch = choose(k,n-1);
	int ans = 0;
	for( int i = n - 1 ; i >= 0 ; i-- ) { 
		int x = s[i] - '0';
		int tmp = tav( 10 , n - i - 1 ) * 1ll * x % mod;
		tmp = tmp * 1ll * ch % mod;
		ans += tmp;
		ans %= mod;
		ch = ch * 1ll * rev( i ) % mod ; 
		ch = ch * 1ll * ( i - k ) % mod;
		if( i - k < 0 ) 
			ch = 0;
	}
	if( k == 0 ) {
		cout << ans << endl;
		return 0;
	}

	int tmp = 0;
	ch = choose(k-1,n-2);
	for( int i = n - 2 ; i >= 0 ; i-- ) { 
//		cout << ch << endl;
		int x = s[i] - '0';
		int a = i; 
		int b = n - i - 1 ; 
		// tmp /= 10; 
		// tmp += ch( k - 1 , a  ) / 10 
		tmp = tmp * 1ll * rev( 10 ) % mod;
		tmp += ch * 1ll * rev( 10 ) % mod;
		tmp %= mod;
		ans += tmp * 1ll * x % mod * 1ll * tav(10,b) % mod;
		ans %= mod;
		ch = ch *1ll * rev(a) % mod;
		ch = ch * 1ll * (a-(k-1)) % mod ; 
		if( a - (k - 1) < 0 ) 
			ch = 0;
	}

	cout << ans << endl;
}