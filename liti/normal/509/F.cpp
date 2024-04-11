/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 500 + 10;
const int mod = 1e9 + 7;

int dp[maxN][maxN];
int a[maxN];

int main() { 
	int n;
	cin >> n ;
	for( int i= 0 ;i < n ; i++ ) 
		cin >> a[i];

	if( n == 1 ) { cout << 1 << endl; return 0; } 

	for( int i = 0 ; i < n ; i++ ) 
		dp[i][i+1] = 1;

	for( int i = n - 2  ; i > 0 ; i-- ) 
		for( int j = i + 2 ; j <= n ; j++ ) {
			for( int k = i + 2; k < j ; k++ )
				if( a[k] > a[i] ) 
					dp[i][j] = (dp[i][j] + ll(dp[i+1][k])*dp[k][j]) % mod;
			dp[i][j] = (dp[i][j] + dp[i+1][j]) % mod;
			if( a[i+1] > a[i] ) 
				dp[i][j] = (dp[i][j] + dp[i+1][j]) % mod;
		}

		
	cout << dp[1][n] << endl;
}