/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 2000*100 + 100; 

vector<int> c[maxN];
const ll inf = 1e15;
ll a[maxN];
ll dp[maxN][2];

void dfs( int s ) { 
	dp[s][1] = -inf;
	for( auto x : c[s] ) { 
		dfs( x ) ; 
		ll a = dp[s][0];
		ll b = dp[s][1];
		dp[s][0] = max( a + dp[x][0] , b + dp[x][1] ) ; 
		dp[s][1] = max( a + dp[x][1] , b + dp[x][0] ) ; 
	}
	ll a = dp[s][0];
	ll b = dp[s][1];
//	dp[s][0] = max( a , b + ::a[s] ) ; 
	dp[s][1] = max( b , a + ::a[s] ) ;

//	cout << s + 1 << ' ' << dp[s][0] << ' ' << dp[s][1] << endl;
}

int main() { 
	int n;
	cin >> n;
	for( int i = 0 ; i < n ; i++ ) { 
		int p; 
		cin>> p >> a[i]; 
		if( p != -1 ) 
			c[p-1].push_back( i ) ; 
	}
	dfs( 0 ) ; 
	cout << max( dp[0][0] ,dp[0][1] ) << endl;
}