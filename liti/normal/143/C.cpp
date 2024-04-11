//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

int main() { 
	int n; 
	cin >> n;
	ll mn = 1e15, mx = 0; 
	for( int i = 1 ; i < 400*100 + 10 && i <= n ; i++ ) 
		if( n % i == 0 ) { 
			for( int k = 1 ; k < 400*100 + 10 && k <= n / i ; k++ ) if( n/i % k == 0 ) {
				int x = n/i/k;
				// i , k , x 
				mx = max( mx , (i+1) * ll(k+2) * ll(x+2) - i * ll(k) * ll(x) ) ; 
				mx = max( mx , (i+2) * ll(k+1) * ll(x+2) - i * ll(k) * ll(x) ) ; 
				mx = max( mx , (i+2) * ll(k+2) * ll(x+1) - i * ll(k) * ll(x) ) ; 
				mn = min( mn , (i+1) * ll(k+2) * ll(x+2) - i * ll(k) * ll(x) ) ; 
				mn = min( mn , (i+2) * ll(k+1) * ll(x+2) - i * ll(k) * ll(x) ) ; 
				mn = min( mn , (i+2) * ll(k+2) * ll(x+1) - i * ll(k) * ll(x) ) ; 
			}
		}
	cout << mn << ' ' << mx << endl;
}