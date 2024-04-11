//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = (1<<24);
const int maxK = 1000 * 10+ 100;
const int maxL = 24;
int dp[3][maxN];

int main() { 
	ios::sync_with_stdio(false);
	int n; 
	cin >> n; 
	for( int i = 0 ; i < n ; i++ ) { 
		string s; cin >> s; 
		int num = 0; 
		for( int j = 0 ; j < 3 ; j++ ) 
			num |= 1<<(s[j]-'a');
		for( int sub = num ; sub ; sub = (sub-1) & num ) 
			dp[__builtin_popcount(sub)-1][sub]++;
	}
	for( int t = 0 ; t < 3 ; t++ )
		for( int i = 0 ; i < maxL ; i++ )
			for( int num = maxN - 1 ; num >= 0 ; num-- )
				if( (num>>i) & 1 ) 
					dp[t][num] += dp[t][num ^ (1<<i)];
	int ans = 0;
	for( int num = 0 ; num < maxN ; num ++ ) { 
		dp[1][num] -= 3 * dp[2][num];
		dp[0][num] -= 3 * dp[2][num];
		dp[0][num] -= 2 * dp[1][num];
		int tmp = dp[0][num] + dp[1][num] + dp[2][num];
		ans ^= tmp*tmp;
	}
	cout << ans << endl;
}