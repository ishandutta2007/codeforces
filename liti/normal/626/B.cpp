//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

#define __sz(x) ((int)(x).size())
typedef long long ll; 

const int maxN = 200 + 10; 
int dp[maxN][maxN][maxN];
int main() { 
	int n; cin >> n; 
	string s; cin >> s; 
	int r=0,g=0,b=0; 
	for( int i =0 ; i < n ; i++ ) {
		if( s[i] == 'R' ) 
			r++; 
		if( s[i] == 'G' ) 
			g++; 
		if( s[i] == 'B' ) 
			b++; 
	}
	dp[1][0][0] = 1; 
	dp[0][1][0] = 2; 
	dp[0][0][1] = 4; 
	for( int sum = 2 ; sum < maxN ; sum++ ) 
		for( int r = 0 ; r <= sum ; r++ ) 
			for( int g = 0 ; r + g <= sum ; g++ ) { 
				int b = sum - r - g; 
				if( r >= 2 ) dp[r][g][b] |= dp[r-1][g][b];
				if( g >= 2 ) dp[r][g][b] |= dp[r][g-1][b];
				if( b >= 2 ) dp[r][g][b] |= dp[r][g][b-1];
				if( r >= 1 ) { 
					if( g >= 1 ) dp[r][g][b] |= dp[r-1][g-1][b+1]; 
					if( b >= 1 ) dp[r][g][b] |= dp[r-1][g+1][b-1]; 
				}
				if( g >= 1 && b >= 1 ) dp[r][g][b] |= dp[r+1][g-1][b-1]; 
			}
	string ans = "";
	if( dp[r][g][b] & 1 ) ans += "R";
	if( dp[r][g][b] & 2 ) ans += "G"; 
	if( dp[r][g][b] & 4 ) ans += "B"; 
	sort( ans.begin() , ans.end() ) ; cout << ans << endl;
}