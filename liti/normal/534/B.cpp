/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 1000 + 100; 
int dp[111][maxN];

int main() { 
	int v1 , v2; 
	int t, d; 
	cin >> v1 >> v2 >> t >> d; 

	memset( dp , -1 , sizeof dp ) ; 
	dp[1][v1] = v1; 
	for( int i = 2 ; i <= t ; i++ ) { 
		for( int k = 1 ; k < maxN ; k++ ) {
			for( int dx = max( 0 , k - d ) ; dx <= min( maxN , k + d ) ; dx++ ) 
				if( dp[i-1][dx] != -1 ) 
					dp[i][k] = max( dp[i][k] , dp[i-1][dx] + k ) ; 
		}
	}
	cout << dp[t][v2] << endl;
}