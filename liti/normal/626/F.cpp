//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

#define __sz(x) ((int)(x).size())
typedef long long ll; 
const int mod = 1e9 + 7; 

inline int add( int a , int b ) { 
	int c = a + b;
	if( c >= mod ) c -= mod; 
	return c;
}
inline int mul( int a , int b ) { 
	return a * 1ll * b % mod; 
}

const int maxN = 200 + 10; 
const int maxK = 1000 + 10 ;
int dp[2][maxN][maxK]; 

int a[maxN];
int main() { 
	int n,k; cin >> n >> k; 
	for( int i = 0 ; i < n ; i++ )
		cin >> a[i+1]; 
	sort( a + 1 , a + n + 1 ); 
	dp[0][0][0] = 1; 
	for( int i = 1 ; i <= n ; i++ ) { 
		int id = i & 1, ld = id ^1; 
		for( int k = 0 ; k < maxN ; k++ ) 
			for( int j = 0 ; j < maxK ; j++ ) { 
				dp[id][k][j] = 0; 
			}
		for( int k = 0 ; k < maxN ; k++ ) 
			for( int j = 0 ; j < maxK ; j++ ) { 
				int nx = j + k * (a[i]-a[i-1]);
				if( nx < maxK ) { 
					dp[id][k][nx] = add( dp[id][k][nx] , mul( 1+k , dp[ld][k][j] ) );
					if( k ) 
						dp[id][k-1][nx] = add( dp[id][k-1][nx]  , mul(k,dp[ld][k][j]) ); 
					if( k + 1 < maxN ) 
						dp[id][k+1][nx] = add( dp[id][k+1][nx] , dp[ld][k][j] ); 
				}
			}
	}
	int id = n & 1; 
	int ans = 0;
	for( int j = 0 ; j <= k ; j++ ) {
		ans = add( ans , dp[id][0][j] ); 
	}
	cout << ans <<endl;
}