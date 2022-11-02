#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000*1000 + 100; 
int a[maxN];
int dp[2][maxN];

int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	int n,m; 
	cin >> n >> m;
	for( int i = 0 ; i < n ; i++ )
		cin >> a[i];
	if( n >= m + 1 ) { 
		cout << "YES" << endl;
		return 0;
	}

	for( int i = 0 ; i < n ; i++ ) { 
		for( int j = m-1 ; j >= 0 ; j-- ) if( dp[i&1^1][j] ) 
			dp[i&1][(j+a[i])%m] = 1; 
		for( int j = 0 ; j < m ; j++ ) dp[i&1][j] |= dp[i&1^1][j];
		dp[i&1][a[i]%m] = 1;

		//for( int j = 0 ; j < m ; j++ ) 
			//cout << dp[j] << " \n"[j==m-1];
	}
	cout << ( dp[n&1^1][0] ? "YES" : "NO" ) << endl;
}