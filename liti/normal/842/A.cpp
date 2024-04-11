//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef pair<int,int> pii; 

int main() {
	ll l, r, x, y, k;
	cin >> l >> r >> x >> y >> k;
	for( int i = x ; i <= y ; i++ ) {
		ll v = 1ll * i * k ;
		if( l <= v && v <= r ) { 
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0; 
}