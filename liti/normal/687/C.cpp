//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxN = 500 + 10; 
int a[maxN]; 
int dp[maxN][maxN];

int main() {
	int n,k; cin >> n >> k; 
	dp[0][0] = 1; 
	for( int i = 0 ; i < n ; i++ ) { 
		cin >> a[i]; 
		for( int j = k ; j >= a[i] ; j-- ) 
			for( int p = 0 ; p <= j - a[i] ; p++ ) 
				if( dp[j-a[i]][p] ) { 
					dp[j][p] = 1; 
					dp[j][p+a[i]] = 1; 
				}
	}
	int cnt =0; 
	for( int i= 0 ; i < maxN  ; i++ ) if( dp[k][i] ) cnt++; 
	cout << cnt << endl;
	for( int i= 0 ; i < maxN  ; i++ ) if( dp[k][i] ) cout << i << ' '; 
	cout << endl;
}