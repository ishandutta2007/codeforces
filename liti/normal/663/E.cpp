//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxL = 21; 
const int maxN = (1<<maxL); 

int dp[maxL][maxN];
int num[maxN];
int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 
	int n,m; cin >>n >> m; 
	for( int i = 0 ;i < n ; i++ ) { 
		string s;
		cin >> s;
		for( int j = 0 ; j < m ; j++ ) 
			num[j] = num[j] * 2 + s[j] - '0';
	}
	for( int i = 0 ; i < m ; i++ )
		dp[0][num[i]]++; 

	for( int i = 0 ; i < n ; i++ ) 
		for( int j = n ; j >= 0 ; j-- ) 
			for( int num = 0 ; num < (1<<n) ; num++ ) {
				if( j ) dp[j][num] += dp[j-1][num ^ (1<<i)]; 
			}
	int ans = n * m;
	for( int i = 0 ; i < (1<<n) ; i++ ) { 
		int tmp = 0; 
		for( int j = 0 ; j <= n ; j++ ) { 
//			cerr << j << ' ' << dp[j][i] << endl;
			tmp += min( j , n - j ) * dp[j][i]; 
		}
//		cerr << "FINAL " << i << ' ' <<tmp << endl;
		ans = min(ans,tmp);
	}
	cout << ans << endl;
}