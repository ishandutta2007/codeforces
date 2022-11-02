//In the name of allah
#include <bits/stdc++.h>
using namespace std; 

const int maxN = 100 + 10; 
const int maxM = 1000 + 100;
typedef long double ld;

int a[maxN];
ld dp[2][maxN*maxM], psum[2][maxN*maxM]; 

int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	int n,m; 
	cin >> n >> m; 
	int sum = 0;
	for( int i = 0 ; i < n ; i++ ) { 
		cin >> a[i];
		sum += a[i]; 
	}
	cout << fixed << setprecision(11);
	if( m == 1 ) { 
		cout << 1 << endl;
		return 0; 
	}

	dp[0][0] = 1; 
	for( int j = 1 ; j <= n * m ; j++ ) 
		psum[0][j] = psum[0][j-1] + dp[0][j-1]; 


	ld x = 1 / ld(m-1);
	for( int i = 1 ; i <= n ; i++ ) {
		dp[i&1][0] = 0;
		for( int j = 1 ; j <= i * m ; j++ ) { 
			dp[i&1][j] = x * (psum[(i-1)&1][j] - psum[(i-1)&1][max(0,j-m)]);
			if( j - a[i-1] >= 0 ) 
				dp[i&1][j] -= x * dp[(i-1)&1][j-a[i-1]]; 
	//		cout << i << ' ' << j << ": " << dp[i][j] << endl;
		} 
		for( int j = 1 ; j <= n * m ; j++ ) 
			psum[i&1][j] = psum[i&1][j-1] + dp[i&1][j-1]; 
	}
	ld ans = 0; 
	for( int j = 1 ; j < sum ; j++ ) 
		ans += dp[n&1][j]; 
	cout << 1 + (m-1) * ans << endl;
}