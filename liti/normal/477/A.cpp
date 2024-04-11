/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll  mod = 1e9 + 7;

int main() { 
	ll a,b;
	cin >> a >> b;

	ll res = 0;
	for( int i = 1 ; i < b ; i++ ) { 
		ll tmp = a*b + 1 + b + 1 ; 
		tmp %= mod;
		tmp *= a; 
		tmp %= mod;
		tmp *= i;
		tmp %= mod;
		tmp *= mod / 2 + 1 ; 
		tmp %= mod;
		res = (res + tmp) % mod;
	}

	cout << res << endl;
}