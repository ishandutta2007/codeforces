//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

#define __sz(x) ((int)(x).size())
typedef long long ll; 
typedef long double ld;

const int maxN = 5000 + 1000; 
ld p[maxN],dp[maxN*2];

int a[maxN],cnt[maxN*2]; 

int main() { 
	int n; cin >> n;  
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i]; 
	sort( a , a + n ) ; 
	ld c = 1/ld(n) * 1/ld(n-1) * 2;
	for( int i = 0 ; i < n ; i++ ) 
		for( int j = i + 1 ; j < n ; j++ ) { 
			p[a[j]-a[i]] += c; 
			cnt[a[j]-a[i]]++; 
		}
	for( int i = 0 ; i < maxN ; i++ ) 
		for( int j = 0 ; j < maxN ; j++ ) 
			dp[i+j] += p[i] * p[j]; 
	ld ans = 0; 
	for( int i = 2*maxN - 1 ; i >= 0 ; i-- ) {
		ans += cnt[i+1] * c * dp[i];
		if( i ) cnt[i-1] += cnt[i];
	}
	cout << fixed << setprecision(9) << ans << endl;
}