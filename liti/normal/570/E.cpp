//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int mod = 1e9 + 7;

const int maxN = 500 + 10;
int dp[2][maxN][maxN];
string a[maxN];
int n,m;

inline int gg( int i1 , int j1 , int i2 , int j2 ) { 
	if( min(min(i1,j1),min(i2,j2)) < 0 ) return 0;
	if( max(i1,i2) >= n || max(j1,j2) >= m ) return 0;
	int k = (i1 + j1) + 1;
	if( k != n-1-i2 + m-1-j2 + 1 ) return 0;
	return dp[k%2][i1][n-1-i2];
}

inline int sum( int a , int b ) { 
	return ( a + b ) % mod;
}

int main() { 
	cin >> n >> m;
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i]; 

	if( a[0][0] != a[n-1][m-1] ) { 
		cout << 0 << endl; 
		return 0; 
	}
	dp[1][0][0] = 1; 
	for( int k = 2 ; k <= (n+m)/2 ; k++ ) 
		for( int i1 = 0 ; i1 < k ; i1++ ) 
			for( int ip2 = 0 ; ip2 < k ; ip2++ ) { 
				int j1 = k - i1 - 1; 
				int jp2 = k - ip2 - 1; 
				int i2 = n - 1 - ip2;
				int j2 = m - 1 - jp2; 
				if( min(min(i1,j1),min(i2,j2)) < 0 || max(i1,i2) >= n
					   	|| max(j1,j2) >= m || a[i1][j1] != a[i2][j2] ) {
					dp[k%2][i1][ip2] = 0;
				   	continue;
				}
				dp[k%2][i1][ip2] = sum( 
					sum( gg(i1-1,j1,i2+1,j2) , gg(i1-1,j1,i2,j2+1) ) , 
					sum( gg(i1,j1-1,i2+1,j2) , gg(i1,j1-1,i2,j2+1) ) ) ;
			}
	int ans = 0;
	int k = ( n + m ) / 2; 
	for( int i1 = 0 ; i1 < k ; i1++ ) 
		for( int ip2 = 0 ; ip2 <k ; ip2++ ) { 
				int j1 = k - i1 - 1; 
				int jp2 = k - ip2 - 1; 
				int i2 = n - 1 - ip2;
				int j2 = m - 1 - jp2; 
				if( (n+m-1) % 2 && ( i1 != i2 || j1 != j2 ) ) continue;
				if( abs( i1 - i2 ) + abs( j1 - j2 ) > 1 ) continue;
				ans = sum( ans , dp[k%2][i1][ip2] );
		}
	cout << ans << endl;
}