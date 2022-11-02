//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
#define __sz(x) ((int)(x).size())

int main() { 
	ll n; cin >> n;
	ll a , b, c; 
	cin >> a >> b >> c; 
	ll d = b - c; 


	ll ans = 0 ;
	ll tmp = 0;
	if( n >= a ) { 
		tmp += n/a;
		ll f =  n % a;
		if( f >= b )
			tmp += ( f - b ) / d + 1; 
		ans = max( ans , tmp ) ; 
	}
	tmp = 0; 
	if( n >= b ) { 
		tmp += ( n - b ) / d + 1; 
		ll f = ( n - b ) % d + c; 
		if( f >= a ) 
			tmp += f / a; 
		ans = max( ans , tmp ) ; 
	}
	cout << ans << endl;
}