//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 4000 + 10;
const int mod = 1e9 + 7; 

inline int sum( int a , int b ) { 
	int c = a + b; 
	if( c >= mod ) c -= mod; 
	return c; 
}

int ch[maxN][maxN];
int tav[maxN];
int bad[maxN][maxN];
int val[maxN];
int dp[maxN];
int main() { 
	int n; 
	cin >> n; 
	tav[0] = 1;
	for( int i = 1 ; i <= n ; i++ ) 
		tav[i] = sum(tav[i-1],tav[i-1]);

	ch[0][0] = 1; 
	for( int i = 1 ; i <= n ; i++ ) 
		for( int j = 0 ; j <= i ; j++ )
			ch[i][j] = sum( ( j ? ch[i-1][j-1] : 0 ) , ch[i-1][j] ); 

	bad[0][0] = 1; 
	for( int i = 1 ; i <= n ; i++ ) 
		for( int j = 1 ; j <= i ; j++ ) 
			bad[i][j] = sum( bad[i-1][j] * ll(j) % mod , bad[i-1][j-1]);
	dp[0] = val[0] = 1;
	for( int i = 1 ; i <= n ; i++ ) { 
		for(int j = 0 ; j <= i ; j++ ) 
			dp[i] = sum( dp[i] , bad[i][j] ); 
		val[i] = dp[i];
		for( int j = 1 ; j <= i ; j++ ) {
			int z = 1; if( j & 1 ) z = -1;
			int tmp = ch[i][j] *1ll* val[i-j] % mod;
			tmp = ( tmp * z + mod ) % mod ;
			dp[i] = sum( dp[i] , tmp ) ; 
		}
	}

	int ans = 0;
	for( int i = 1 ; i <= n ; i++ ) {
		int tmp = ch[n][i] * 1ll * dp[n-i] % mod;
		tmp = tmp * ll( tav[i] - 1 + mod ) % mod;
		ans = sum( ans , tmp ) ; 
	}
	cout << ans << endl;
}