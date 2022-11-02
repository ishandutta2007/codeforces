//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxT = 200 + 10; 
const int maxN = 20 + 1; 
const int maxS = (1<<maxN); 
typedef long double ld;

ld dp[maxS];
ld p[maxN], psum[maxS], ans[maxN];
int ind[maxN];
int cnt;

int main() { 
	cout << fixed << setprecision(10); 
	cerr << fixed << setprecision(10); 
	int n,k; cin >> n >> k;
	for( int i = 0 ; i < n ; i++ ) {
		cin >> p[cnt]; 
		if( p[cnt] > 0.0001 ) { 
			ind[i] = cnt;
			cnt++ ;
		} else
			ind[i] = -1; 
	}
	swap(n,cnt);
    k = min( n , k );
	int tot = (1<<n); 
	for( int mask = 1 ; mask < tot ; mask++ ) 
		psum[mask] = psum[mask - (mask&-mask)] + p[__builtin_ctz(mask)]; 


	dp[0] = 1; 
	for( int mask = 1 ; mask < tot ; mask++ )  { 
		if( __builtin_popcount(mask) > k ) continue; 
		for( int i = 0 ; i < n ; i++ )
			if( (mask>>i) & 1 ) {
				int nmask = mask ^ (1<<i); 
				dp[mask] += dp[nmask] * p[i] / (1 - psum[nmask]); 
			}
		if( __builtin_popcount(mask) == k ) 
			for( int i = 0 ; i < n ; i++ ) 
				if( (mask>>i) & 1 ) 
					ans[i] += dp[mask]; 
	}

	swap(n,cnt); 

	for( int i = 0 ; i < n ; i++ )
		if( ind[i] == -1 ) 
			cout << 0 << ' ' ; 
		else
			cout << ans[ind[i]] << ' ' ; 
	cout << endl;
}