/**
*    author:  Mohamed Abo Okail
*    created: 19/O5/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n"

ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector < ll > a(n);
		ll prime = 1e9 + 7;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector < pair < ll, ll > > x, y;
		for (int i = 1; i < n; i++) {
			ll mn = min(a[i], a[i - 1]);
			if((i & 1) == 0) continue; 
			x.push_back(make_pair(i, i + 1));
			y.push_back(make_pair(mn, prime));
			a[i - 1] = mn;
			a[i] = prime;
		}

		cout << sz(x) << endl;
		for (int i = 0; i < sz(x); i++) {
			cout << x[i].first << ' ' << x[i].second << ' ' << y[i].first << ' ' << y[i].second << endl;
		}
	}
}