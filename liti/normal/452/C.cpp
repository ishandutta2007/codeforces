/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;
const int maxN = 1000 + 10;
typedef long double ld;

ld dp[maxN][maxN];

int main() { 
	int n,m;
	cin >> n >> m;
	dp[1][1] = 1;
	int cnt = m*n;
	for(int i = 2 ; i <= n ; i++ ) {
		for(int j = 1 ; j <= m + 1 ; j++ ) {
			ld p = ld( m - ( j - 1 ) ) / ( cnt - (i-1) ) ;
			dp[i][j] = p * dp[i-1][j-1] ;
			dp[i][j-1] += (1-p)*dp[i-1][j-1];
//			cerr << i << ' ' << j << ' ' << p << ' ' <<
//				dp[i-1][j-1] << ' ' << dp[i][j] << endl;
		}
	}

	ld mE = 0 ; 
	ld p = 0;
	for(int i = 1 ; i <= m ; i++ ) 
	{
//		cerr << i << ' ' << dp[n][i] << endl;
		mE += i*dp[n][i] ;
		p += dp[n][i];
	}

//	cerr << mE << ' ' << p << endl;

	cout << fixed << setprecision(9)  << mE/n << endl;
}