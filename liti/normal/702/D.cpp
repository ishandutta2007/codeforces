//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
const int maxN = 1000 * 1000 * 10; 

ll d; 
int k , a, b , t; 
ll gg( ll x ) { 
	return x * a + ( d - x ) * b + (max(0ll,x-1)/k) * t; 
}

int main() { 
	cin >> d >> k >> a >> b >> t; 

	ll ans = d * b; 
	for( ll x = 0 ; x < min(d,(ll)maxN) ; x++ ) 
		ans = min( ans , gg(x) ) ; 
	for( ll x = d ; x >= max(0ll,d - maxN) ; x-- ) 
		ans = min( ans , gg(x) ) ; 
	cout << ans << endl;
}