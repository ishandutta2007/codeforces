/* In the name of Allah */ 
#include <iostream>
#include <algorithm>
#include <cstring> 

using namespace std;

const int maxN = 200 + 10 ; 
typedef long long ll;

template< class T , class P >
inline bool smin( T&a , P b ) { 
	return ( a > b ? a = b , true : false ) ; 
}

pair<int,int> pri[maxN];
int ans[maxN];
ll dp[maxN][maxN];

ll count( int n ) { 
	memset( dp , 0 , sizeof dp ) ;

	dp[0][0] = 1; 
	for( int i = 0 ; i < n ; i++ ) {
		if( ans[i] != 2 ) // means can do ( 
			for( int j = 1 ; j <= i + 1 ; j++ ) {
				dp[i+1][j] += dp[i][j-1];
				smin( dp[i+1][j] , 2e18 ) ; 
			}
		if( ans[i] != 1 ) // means can do )
			for( int j = 0 ; j <= i + 1 ; j++ ) {
				dp[i+1][j] += dp[i][j+1];
				smin( dp[i+1][j] , 2e18 ) ;
			}
	}
	return dp[n][0];
}

void calc( int n , ll k  ) { 
	sort( pri , pri + n ) ; 

	//	cout << count(n) << endl;

	for( int i = 0 ; i < n ; i++ ) { 
		ans[pri[i].second] = 1; 
	//		cerr << pri[i].second << ' '  << k << ' ' << count(n) << endl;
		if( count(n) < k ) {
			k -= count(n);
			ans[pri[i].second] = 2;
		}
	}
}

int main() { 
	int n,m;
	ll k;
	cin >> n >> m >> k;

	for( int i = 0 ; i < n + m - 1 ; i++ )
		pri[i] = { n * m + 2, i } ;
	for( int i = 0 ; i < n ; i++ ) 
		for( int j = 0 ; j < m ; j++ ) { 
			int a;
			cin >> a;
			smin( pri[i+j].first , a ) ;
		}

	calc( n + m - 1, k ) ; 

	for( int i = 0 ; i < n ; i++ ) { 
		for( int j = 0 ; j < m ; j++ ) 
			cout << (ans[i+j]==1 ? '(' : ')' );
		cout << endl;
	}
}