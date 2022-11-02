//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
#define rep(i,n) for( int i = 0 ; i < n ; i++ ) 
typedef long long ll;    
const int maxM = 20; 
const int maxX = maxM + 5;
typedef int mat[maxX];

const int maxN = (1<<maxM); 

int mod; 
mat a,b,c;
int e[maxN];
int m;

int comb[maxX][maxX];

void mul( mat a , mat b , mat c ) { 
	rep( p , m + 1 ) c[p] = 0;
	rep( p , m + 1 ) { 
		rep( x , m + 1 ) rep( y , m + 1 ) 
			if( x + y >= p && ( x + y - p ) % 2 == 0 ) {
				int t = (x+y-p)>>1; 
				if( t > m ) continue;
				int tmp = comb[m-p][t] * 1ll * comb[p][x-t] % mod; 
				tmp = tmp * 1ll * a[x] % mod; 
				tmp = tmp * 1ll * b[y] % mod; 
				c[p] += tmp;
				if( c[p] >= mod ) c[p] -= mod; 
			}
	}
}

int dp[maxX][(1<<maxM)];

int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> m >> t >> mod; 
	comb[0][0] = 1; 
	for( int i = 1 ; i < maxX ; i++ ) 
		for( int j = 0 ; j < maxX ; j++ ) 
			comb[i][j] = ((j?comb[i-1][j-1]:0) + comb[i-1][j]) % mod;

	int n = (1<<m);
	for( int i = 0 ; i < n; i++ ) {
		cin >> e[i];
		e[i] %= mod;
		dp[0][i] = e[i]; 
	}
	for( int i = 0 ; i <= m ; i++ ) 
		cin >> b[i];
	a[0] = 1;
	for( int i = 0 ; i < 60 ; i++ ) {
		if( (t>>i) & 1 ) {
			mul( a , b , c ) ; 
			swap( a , c ) ; 
		}
		mul( b , b , c ) ; 
		swap( b , c ) ; 
	}

	for( int i = 0 ; i < m ; i++ ) 
		for( int j = m ; j >= 0 ; j-- ) 
			for( int num = 0 ; num < n ; num++ ) {
				if( j ) dp[j][num] += dp[j-1][num ^ (1<<i)]; 
				if( dp[j][num] >= mod ) dp[j][num] -= mod; 
			}

	for( int i = 0 ; i < n ; i++ ) { 
		int ret = 0;
		for( int j = 0 ; j <= m ; j++ ) {
			ret += a[j] * 1ll * dp[j][i] % mod;
			if( ret >= mod ) ret -= mod; 
		}
		cout << ret << '\n';
	}
}