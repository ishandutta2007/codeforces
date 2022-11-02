//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 5000 + 100; 

int pr[maxN];
int nx[maxN];
ll dp[maxN][maxN];
int main() { 
	string a; 
	cin >> a; 
	int sz = __sz(a) ; 
	int last = -1; 
	for( int i = 0 ; i < sz ; i++ ) {
		if( a[i] == '+' ) 
			last = i;
		pr[i] = last; 
	}
	last = -1; 
	for( int i = sz - 1 ; i >= 0; i-- ) { 
		if( a[i] == '+' ) 
			last = i;
		nx[i] = last;
	}
	for( int i = sz - 1 ; i >= 0 ; i-=2  ) {
		dp[i][i] = a[i] - '0';
		for( int j = i + 2 ; j < sz ; j+= 2 ) 
			if( pr[j] < i ) 
				dp[i][j] = dp[i][j-2] * dp[j][j]; 
			else
				dp[i][j] = dp[i][pr[j]-1] + dp[pr[j]+1][j]; 
	}
	ll ans = dp[0][sz-1];
	for( int i = 0 ; i < sz ; i+=2 ) 
		for( int j = i + 2 ; j < sz ; j+= 2 ) { 
			ll val = dp[i][j];
			ll tmp = 0; 
			if( i  ) { 
				if( a[i-1] != '*' ) continue;
				int x = pr[i];
				if( x == -1 ) 
					val *= dp[0][i-2]; 
				else{
					tmp += dp[0][pr[i]-1];
					val *= dp[pr[i]+1][i-2]; 
				}
			}
	//		cout << i << ' ' << j << ' ' << val <<  ' ' <<  tmp << endl;
			if( j != sz -1 ) { 
				if( a[j+1] != '*' ) 
					continue;
				int x = nx[j];
				if( x == -1 ) 
					val *= dp[j+2][sz-1];
				else { 
					tmp += dp[x+1][sz-1];
					val *= dp[j+2][x-1]; 
				}
			}
	//		cout << i << ' ' << j << ' ' << val <<  ' ' <<  tmp << endl;
			ans = max( ans , val + tmp ) ;
		}
	cout << ans << endl;
}