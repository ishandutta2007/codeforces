//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
#define SZ(x) ((int) (x).size())

const int maxN = 5000 + 10; 
const int mod = 1e9 + 7;
const int b1 = 701 , b2 = 727;
int dp[maxN][maxN]; 

int hsh1[maxN][maxN];
int hsh2[maxN][maxN]; 


inline int add( int a , int b ) { 
	int c = a + b; 
	if( c >= mod ) c-= mod; 
	return c; 
}

string s; 
inline bool cmp( int i1 , int i2 , int len ) { 
	int s = 0 , e = len + 1; 
	while( e - s > 1 ) { 
		int m = ( s + e ) / 2; 
		if( hsh1[i1][i1+m] == hsh1[i2][i2+m] &&
		 hsh2[i1][i1+m] == hsh2[i2][i2+m] ) 
			s = m; 
		else 
			e = m; 
	}
	if( s == len || ::s[i1+s] < ::s[i2+s] ) 
		return false;
	return true; 
}

int main() { 
	int n; 
	cin >> n;
	cin >> s; 
	for( int i = 0 ; i < n ; i++ ) { 
		hsh1[i][i+1] = hsh2[i][i+1] = s[i]; 
		for( int j = i + 2 ; j <= n ; j++ ) { 
			hsh1[i][j] = add( hsh1[i][j-1] * b1 , s[j-1] ) ; 
			hsh2[i][j] = add( hsh2[i][j-1] * b2 , s[j-1] ) ; 
		}
	}

	for( int j = 1 ; j <= n ; j++ ) 
		dp[0][j] = 1; 
	for( int i = 1 ; i < n ; i++ ) { 
		if( s[i] == '0' ) continue;
		int sum = 0; 
		for( int j = i + 1 ; j <= n ; j++ ) { 
			dp[i][j] = sum; 
			if( i - ( j - i ) >= 0 && cmp( i , i - ( j - i ) , j - i ) ) 
				dp[i][j] = add( sum , dp[i - (j-i)][i] ); 
			if( i - ( j - i ) >= 0 ) 
				sum = add(sum,dp[i - (j-i)][i]); 
		}
	}
	int ans = 0;
	for( int st = 0 ; st < n ; st++ ) 
		ans = add(ans, dp[st][n] );
	cout << ans << endl;
}