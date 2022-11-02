//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef pair<int,int> pii; 

const int maxN = 10 + 2; 
int dp[maxN][maxN]; 

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 
	int n,t; cin >> n >> t; 
	int f = (1<<15); 
	for( int k = 0 ; k < t ; k++ ) { 
		dp[0][0] += f; 
		for( int i = 0 ; i < n ; i++ ) 
			for( int j = 0 ; j <= i ; j++ ) { 
				int x = max(0,dp[i][j] - f)/2;  
				dp[i][j] = min(dp[i][j],f);
				dp[i+1][j] += x; 
				dp[i+1][j+1] += x; 
			}
	}
	int ans = 0; 
	for( int i = 0 ; i < n ; i++ ) 
		for( int j = 0 ; j <= i; j++ ) 
			ans += dp[i][j] == f; 
	cout << ans << endl;
}