/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 20000*100 + 10;

int main() { 
	ll c , hr , hb , wr , wb;
	cin >> c >> hr >> hb >> wr >> wb;

	// hr / wr , hb / wb 

	ll ans = 0 ; 
	for( int t = 0 ; t < 2 ; t++ ) { 
		ll x = c / wr;
		for( ll i = max(0ll,x - maxN) ; i < x + maxN ; i++ ) { 
			ll w = wr * i;
			if( w > c ) break;

			ll tmp = i * hr;
			tmp += ( c - w ) / wb * hb;
			ans = max( ans , tmp ) ;
		}
		swap( hr , hb ) ; 
		swap( wr , wb ) ; 
	}
	cout << ans << endl;
}