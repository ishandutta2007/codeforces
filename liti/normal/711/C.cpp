//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxN = 100 + 10; 

int a[maxN]; 

ll dp[maxN][maxN], odp[maxN][maxN]; 
int p[maxN][maxN]; 

int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	int n,m,k; cin >> n >> m >> k; 
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i]; 
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < m ; j++ ) 
			cin >> p[i][j+1]; 
	memset( dp , 31 , sizeof dp ); 
	dp[0][0] = 0; 
	for( int i = 0 ; i < n ; i++ ) { 
		swap( dp , odp ); 
		memset( dp , 31 , sizeof dp ); 
		for( int len = 0 ; len <= k ; len++ ) 
			for( int co = 0 ; co <= m ; co++ ) 
				for( int co2 = 1 ; co2 <= m ; co2++ )  
					if( a[i] == 0 || a[i] == co2 ) { 
						ll pr = 0; 
						if( a[i] == 0 ) 
							pr = p[i][co2]; 
						int add = (co!=co2); 
						dp[len+add][co2] = min( dp[len+add][co2] , odp[len][co] + pr ); 
					}
	}

	ll ans = 1e18; 
	for( int col = 1 ; col <= m ; col++ ) 
		ans = min( ans , dp[k][col] ); 
	if( ans > 10000 * 1ll * 100000000 ) 
		cout << -1 << endl;
	else 
		cout << ans << endl;
}