//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxN = 500 + 10; 

int a[maxN];
vector<int> pos[maxN];
int dp[maxN][maxN];

inline void smin( int& a , int b ) { 
	a = min( a, b ); 
}
int main() { 
	int n; cin >> n;
	for( int i = 0 ; i < n ; i++) { 
		cin >> a[i]; a[i]--;
		pos[a[i]].push_back( i ); 
	}

	for( int i = n - 1 ; i >= 0 ; i-- ) {
		dp[i][i] = dp[i][i+1] = 1; 
		for( int j = i + 2 ; j <= n ; j++ ) { 
			dp[i][j] = ( j - i ); 
			for( int k = i + 1 ; k < j ; k++ ) 
				smin( dp[i][j] , dp[i][k] + dp[k][j] ) ; 
			if( a[i] == a[j-1] ) smin( dp[i][j] , dp[i+1][j-1] ); 
		}
	}
	cout << dp[0][n] << endl;
}