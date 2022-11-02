//In the name of Allah
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxN = 18 + 1; 
const int maxS = (1<<maxN) + 10;
int a[maxN]; 
ll dp[maxS][maxN]; 
int c[maxN][maxN];

int main() { 
	int m,n,k;
	cin >> n >> k >> m; 
	for( int i = 0 ; i < n ; i++ ) {
		cin >> a[i];
		dp[(1<<i)][i] = a[i]; 
	}

	for( int i = 0 ; i < m ; i++ ) { 
		int x,y,z; cin >> x >> y >> z; 
		x--; y--; 
		c[x][y]  += z;
	}
	ll ans = 0;
	for( int mask = 1 ; mask < (1<<n) ; mask++ ) { 
		if( __builtin_popcount(mask) == k ) 
			for( int i = 0 ; i < n ; i++ ) if( (mask>>i) & 1 ) 
				ans = max( ans , dp[mask][i] ); 

		for( int i = 0 ; i < n ; i++ ) if( ( (mask>>i) & 1 ) == 0 ) 
			for( int j = 0 ; j < n ; j++ ) if( (mask>>j) & 1 ) 
				dp[mask^(1<<i)][i] = max( dp[mask^(1<<i)][i] , dp[mask][j] + c[j][i] + a[i] );
	}
	cout << ans << endl;
}