/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;
typedef long double ld;

const int maxN = 30 + 4;
const int maxK = 200 + 1;

#define rep(i,n) for( int i = 0 ; i < n ; i++ ) 
#define fff(i,s,e) for( int i = s ; i < e ; i++ ) 

ld ch( int n , int r ) {
	ld res = 1;
	for( int i = 0 ; i < r ; i++ ) 
		res *= n-i;
	for( int i =0 ; i < r ; i++ ) 
		res /= (i+1);
	return res;
}

ld dp[maxN][maxN][maxK];
int a[maxN];
int n,t;

int main() { 
	cin >> n >> t;
	rep(i,n)
		cin >> a[i];

	rep(i,n) rep(j,n) if( i != j ) 
		dp[i][j][0] = i>j;

	ld choose = ch(n+1,2);
	fff( k , 1 , t + 1 ) rep(i,n) rep(j,n) if( i != j ) { 
		rep( x , n ) fff( y , x , n ) {
			int ii = i , jj = j;
			if( x <= i && i <= y ) 
				ii = y-(i - x);
			if( x <= j && j <= y ) 
				jj = y-(j - x);
			dp[i][j][k] += dp[ii][jj][k-1] / choose;
		}
	}
	ld res = 0;
	rep( i , n ) fff( j , i + 1 , n )
		if( a[i] < a[j] ) 
			res += dp[i][j][t];
		else
			res += dp[j][i][t];
	cout << fixed << setprecision(9) << res << endl;
}