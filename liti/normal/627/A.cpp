//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

#define __sz(x) ((int)(x).size())
typedef long long ll; 

int main() { 
	ll s,x; cin >> s >> x;
	int cnt = 0; 
	for( int i = 0 ; i < 50 ; i++ ) 
		if( (x>>i) & 1 ) 
			cnt++; 
	ll ans = (1LL<<cnt); 
	s -= x; 
	bool check = true;
	for( int i = 0 ; i < 50 ; i++ ) 
		if( (s>>i) & 1 ) {  
			if( i == 0 || ((x>>(i-1)) & 1) == 1 ) { 
				cout << 0 << endl;
				return 0; 
			}
			check = false; 
		}

	cout << ans - 2 * int(check) << endl;
}