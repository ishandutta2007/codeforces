/**
*    author:  Mohamed Abo Okail
*    created: 07/O7/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}
 
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		ll a, b; cin >> a >> b;
		if(a == b) {
			cout << "0 0" << endl;
		}
		else if(abs(a - b) == 1) {
			cout << "1 0" << endl;
		}
		else if(a == 0 || b == 0) {
			cout << max(a, b) << ' ' << 0 << endl;
		}
		else if(_gcd(a, b) == abs(a - b)) {
			cout << abs(a - b) << ' ' << 0 << endl;
		}
		else {
			if(a < b) swap(a, b);
			cout << a - b << ' ' << min((a - b) - (b % (a - b)), (a - b) - ((a - b) - (b % (a - b)))) << endl;
		}
	}
}