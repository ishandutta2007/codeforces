/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 1000 + 10;
inline void smax( int& a, int b ) {
	a = max( a , b ) ; 
}

int dp[maxN];
int a[5][maxN];
int cnt[maxN];
int main() { 
	int n, k;
	cin >> n >> k;

	for( int i = 0 ; i < k ; i++ ) 
		for( int j =0 ; j < n ; j++ ) 
			cin >> a[i][j];

	int ans =1 ; 

	dp[a[0][0]] = 1; 
	for( int i = 1 ; i < n ; i++ ) { 
		dp[a[0][i]] = 1;
		memset( cnt , 0 , sizeof cnt ) ; 
		for( int j = 0 ; j < k ; j++ ) 
			for( int t = 0 ; t < n ; t++ ) 
				if( a[j][t] == a[0][i] ) 
					break;
				else
					cnt[ a[j][t] ]++;
		for( int j = 1 ; j <= n ; j++ ) 
			if( cnt[j] == k )
				smax( dp[a[0][i]] , dp[j] + 1 ) ; 
		smax( ans , dp[a[0][i]] ) ; 
	}

	cout << ans << endl;
}