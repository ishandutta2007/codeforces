//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

ll gcd( ll a , ll b ) { 
	if( b == 0 ) return a; 
	return gcd( b , a % b ); 
}

int main() { 
	ll t,w,b;
	cin >> t >> w >> b; 
	if( w == b && b == 1 ) { 
		cout << "1/1" << endl;
		return 0; 
	}
	ll d = gcd(w,b);
	ll x = w / d; 
	if( t / x < b ) { 
		ll ans = min(t,min(b,w) -1); 
		ll gg = gcd(ans,t);
		cout << ans / gg << '/' << t / gg; 
		return 0; 
	}
	ll lcm = b * x; 
	ll y = min( w , b ); 
	ll ans = (1+t / lcm) * y - 1; 
	ans -= max(0ll,y-1 - t % lcm);

	ll gg = gcd( ans , t ); 
	cout << ans / gg << '/' << t / gg; 
}