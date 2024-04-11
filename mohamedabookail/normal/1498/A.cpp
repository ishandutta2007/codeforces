/**
*    author:  Mohamed Abo Okail
*    created: 3O/O3/2O21
**/
#include <bits/stdc++.h>

using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}

ll sumD(ll n) {
	if(!n) return 0;
	return n % 10 + sumD(n / 10);
}

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		while(_gcd(n, sumD(n)) == 1) {
			n++;
		}
		cout << n << endl;
	}
}