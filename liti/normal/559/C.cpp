//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 2000 + 10; 
const int maxM = 1000* 100 * 4; 
const int mod = 1e9 + 7;
inline int bpow( int a , int b ) { 
	int res = 1;
	for( ; b ; b /= 2 ) { 
		if( b & 1 ) res = res * 1ll * a % mod;
		a = a * 1ll * a % mod;
	}
	return res; 
}
int fact[maxM];
inline int ch( int r , int n ) { 
	return fact[n] * 1ll * bpow( fact[r] * 1ll * fact[n-r] % mod , mod - 2 ) % mod; 
}

int dp[maxN];
typedef pair<int,int> pii;
pii a[maxN];
int main() {
	ios::sync_with_stdio(false);

	fact[0] = 1;
	for( int i = 1 ; i < maxM ; i++ ) 
		fact[i] = fact[i-1] * 1ll * i % mod;

	int h,w,n;
	cin >> h >> w >> n;
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i].first >> a[i].second;
	a[n++] = { h , w } ; 
	sort( a , a + n , []( pii a , pii b ) { return a.first + a.second < b.first + b.second; } ); 
	for( int i = 0 ; i < n ; i++ ) { 
		dp[i] = ch( a[i].first - 1 , a[i].first + a[i].second - 2 ); 
	//	cerr << i << ' ' << dp[i] << endl;
		for( int j = 0 ; j < i ; j++ )
			if( a[j].first <= a[i].first && a[j].second <= a[i].second ) 
				dp[i] = ( dp[i] + mod - dp[j] * 1ll * ch( a[i].first - a[j].first ,
						   	a[i].first - a[j].first + a[i].second - a[j].second ) % mod ) % mod;
	//	cerr << i << ' ' << dp[i] << endl;
	}
	cout << dp[n-1] << endl;
}