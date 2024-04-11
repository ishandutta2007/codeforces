//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

int a[20];
int main() { 
	int n,l,r,x;
	cin >> n >> l >> r >> x;
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i];

	int ans = 0;
	for( int i = 0 ; i < (1<<n) ; i++ ) if( __builtin_popcount(i) >= 2 ) { 
		int mn = 1e9; 
		int mx = 0 ; 
		int sum = 0 ; 

		for( int j = 0 ; j < n ; j++ ) 
			if( i & (1<<j) ) { 
				sum += a[j];
				mx = max(mx,a[j]);
				mn = min(mn,a[j]); 
			}
		if( l <= sum && sum <= r && mx - mn >= x ) 
			ans++;
	}
	cout << ans << endl;
}