//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef pair<int,int> pii; 
const int maxN = 1000 * 100 + 100; 
const int mod = 1e9 + 7; 
typedef int Arr[maxN];

map<int,Arr> ans; 

inline int sum( int a , int b ) { 
	int c = a + b; 
	if( c >= mod ) c -= mod; 
	return c; 
}
inline int mul( int a , int b ) { 
	return a * 1ll * b % mod; 
}

inline int bpow( int a , int b ) { 
	int ret = 1; 
	for( ; b ; b /= 2 ) { 
		if( b & 1 ) ret = mul( ret , a ) ; 
		a = mul( a , a ); 
	}
	return ret; 
}

int fact[maxN], ifact[maxN]; 

int *dp; 
string s; 

inline int cmb( int n , int r ) { 
	if( r < 0 || r > n ) return 0; 
	return mul( fact[n] , mul( ifact[r] , ifact[n-r] ) ); 
}
inline void calc() { 
	int n = s.size(); 
	if( ans.count(n) == 0 ) { 
		dp = ans[n]; 
		for( int i = 0 ; i < n ; i++ ) 
			dp[i] = 0; 

		int z = 1; 
		for( int i = n ; i < maxN ; i++ ) { 
			dp[i] = mul( cmb( i - 1 , n - 1 )  , z ); 
			dp[i] = sum( dp[i] , mul( dp[i-1] , 26 ) ); 
			z = mul( z , 25 ) ; 
		}
	} else 
		dp = ans[n]; 
}


int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 

	fact[0] = 1; 
	for( int i = 1 ; i < maxN ; i++ ) 
		fact[i] = mul( fact[i-1] , i ); 
	ifact[maxN-1] = bpow( fact[maxN-1] , mod - 2 ) ; 
	for( int i = maxN - 2 ; i >= 0 ; i-- ) 
		ifact[i] = mul( ifact[i+1] , i + 1 ); 

	int m; cin >> m; 
	cin >> s; 
	calc(); 
	for( int i = 0 ; i < m ; i++ ) { 
		int t; cin >> t; 
		if( t == 1 ) {
		   	cin >> s;
			calc(); 
		} else { 
			int x; cin >> x; 
			cout << dp[x] << '\n';
		}
	}
}