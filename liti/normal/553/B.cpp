//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 50 + 10; 
ll dp[maxN]; 
int used[maxN];
int main() { 
	int n; ll l; 
	cin >> n >> l; 
	dp[0] = 1; 
	dp[1] = 1; 
	for( int i = 2 ; i < maxN ; i++ ) 
		dp[i] = dp[i-1] + dp[i-2];

	l--;
	for( int i = 0 ; i < n ; i++ ) { 
		int k = n - i; 
		if( dp[k-1] > l )
			cout << i + 1 << ' '  ; 
		else { 
			l -= dp[k-1];
			cout << i + 2 << ' ' << i + 1 << ' ' ; 
			i++; 
		}
	}
}