/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;
typedef long double ld;

const int maxN = 2000 + 10;
ld dp[maxN][maxN];

int main() {
	int n , t; 
	ld p ;
	cin >> n >> p >> t; 

	dp[0][0] = 1; 

	for( int k = 0 ; k < t ; k++ ) // in k seconds 
		for( int i = 0 ; i <= n ; i++ ) { // i people has entered 
			if( i != n ) {
				dp[k+1][i+1] += p * dp[k][i];
				dp[k+1][i] += (1-p) * dp[k][i];
			} else { 
				dp[k+1][i] += dp[k][i];
			}
		}

	ld ret = 0;
	for( int i = 0 ; i <= n  ;i++ )
		ret += i * dp[t][i] ; 
	cout << fixed << setprecision(9) ;
	cout << ret << endl;
}