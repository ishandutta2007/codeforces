//In the name of Allah
#include <bits/stdc++.h>

using namespace std;
#define __sz(x) ((int) x.size())
typedef long long ll;

const int maxN = 300 + 10; 
typedef int Mat[maxN][maxN];

int a[maxN]; 
Mat ans , b , c , d;
int n,t; 

void norm( Mat dp ) { 
	for( int i = n - 1 ; i >= 0 ; i-- ) 
		for( int j = i+1 ; j < n ; j++ ) { 
			dp[i][j] = max( dp[i][j] , dp[i][j-1] ) ; 
			dp[i][j] = max( dp[i+1][j] , dp[i][j] ) ; 
		}
}
void mul( Mat a , Mat b , Mat c ) {
	for( int i = 0 ; i < n ; i++ ) 
		for( int j = 0 ; j < n ; j++ ) 
			c[i][j] = 0; 
	for( int i = 0 ; i < n ; i++ ) 
		for( int j = i ; j < n ; j++ )
			for( int k = j ; k < n ; k++ )
				c[i][k] = max( c[i][k] , a[i][j] + b[j][k] ); 
}

int main() { 
	cin >> n >> t;
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i]; 
	for( int i = 0 ; i < n ; i++ ) { 
		b[i][i] = 1;
		for( int j = i + 1 ; j < n ; j++ ) 
			if( a[j] >= a[i] )
				for( int k = i ; k < j ; k++ )
					if( a[i] <= a[k] && a[k] <= a[j] ) 
						b[i][j] = max(b[i][j],b[i][k] + 1); 
		for( int j = 0 ; j < n ; j++ ) 
			d[a[i]][a[j]] = max( d[a[i]][a[j]] , b[i][j] ); 
	}
	n = maxN - 5; 
	swap( b , d ); 
	norm( b );
	int x = t;
	int y = 0;
	for( int i = 0 ; i < n ; i++ ) 
		y = max( y , d[i][i] ); 
	for( ; t ; t /= 2 ) { 
		if( t & 1 ) { 
			mul( b , ans , c ) ; 
			swap( ans, c ); 
	//		norm(ans);
		}
		mul( b , b , c ) ; 
		swap( b , c ) ; 
	//	norm(b);
	}
	int k = 0; 
	for( int i = 0 ; i < n ; i++ ) 
		for( int j = 0 ; j < n ; j++ ) 
			k = max( k , ans[i][j] ); 
	cout << k << endl;
}