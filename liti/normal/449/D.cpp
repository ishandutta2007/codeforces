#include <bits/stdc++.h>

using namespace std;

const int maxN = 1000*1000 + 10; 
const int maxK = 20;
const int maxS = 1<<maxK;
const int mod = 1e9 + 7;
typedef long long ll;

int a[maxN];
int dp[maxS][2];
int tav[maxS];

int main() { 
	ios::sync_with_stdio(false);

	tav[0] = 1;
	for(int i = 1 ; i < maxS ; i++ ) 
		tav[i] = ( tav[i-1] * 2 ) % mod;

	int n;
	scanf("%d", &n);

	for(int i= 0 ; i < n ; i++ ) {
		scanf( "%d", a + i ) ;
		dp[maxS-1-a[i]][maxK%2]++; 
	}

	for(int i = maxK - 1 ; i >= 0; i-- ) {
		bool ind = i%2;
		for( int x = 0 ; x < maxS ; x++ ) 
			dp[x][ind] = ( dp[x][!ind] + ( (  (x>>i)&1 ) ? dp[x&(~(1<<i))][!ind] : 0 ) ) % mod; 
	}

	int res = 0; 

	for(int i = 0 ; i < maxS ; i++ ) {
		int tmp = tav[dp[i][0]];

		int z = 1; 
		if( __builtin_popcount(i) & 1 ) 
			z = -1;
		res += z*tmp;
		res = ( res%mod + mod ) % mod;
	}

	cout << res << endl;
}