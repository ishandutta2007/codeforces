/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxK = 63;

int main() { 
	int n;
	cin >> n;

	for( int i = 0 ; i < n ; i++ ) { 
		ll l,r;
		cin >> l >> r ;

		ll curr = 0;
		for( int i = maxK - 1 ; i >= 0 ; i-- ) 
			if( curr + (1LL<<i) > l && curr + (1LL<<i) - 1 <= r ) {
				cout <<  curr + (1LL<<i) - 1 << endl;
				break;
			} else if ( curr + (1LL<<i) <= l ) 
				curr += (1LL<<i);
	}
}