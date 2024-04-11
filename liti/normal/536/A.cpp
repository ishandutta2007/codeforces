//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(x) ((int)(x).size())

int main() {
	int A,B,n; 
	cin >> B >> A >> n; 

	for( int i = 0 ; i < n ; i++ ) { 
		int l,t,mx;
		cin >> l >> t >> mx; 
		if( ll(l-1)*A + B > t ) { 
			cout << -1 << endl;
			continue;
		}
		ll s = l , e = 1e9;
		while( e - s > 1 ) { 
			int m = ( s + e ) >> 1; 
			int mm = min( mx , m - l + 1 ) ;
			ll sum = ( ll(l-1)*A + B + ll( m - 1 ) * A + B ) * ll( m - l + 1 ) /2 ; 
//			if( m == 2 ) 
//				cout << l << ' '  <<( ll(l-1)*A + B + ll( m - 1 ) * A + B ) << endl;
			if( sum <= mm * ll(t) && t >= ll(m-1)*A + B ) 
				s = m;
			else
				e = m;
		}
		cout << s << '\n' ;
	}
}