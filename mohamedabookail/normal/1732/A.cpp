/**
*    author:  Mohamed Abo Okail
*    created: 23/1O/2O22
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

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		int n;;
		cin >> n;
		vector < ll > a(n), b(n);
		ll g = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			g = _gcd(g, a[i]);
		}
		b = a;
		if(g == 1) {
			cout << 0 << endl;
			continue;
		}
		ll ans = 1e9;
		for (int i = 0; i < n; i++) {
			a[i] = _gcd(a[i], i + 1);
			g = 0;
			for (int j = 0; j < n; j++) {
				g = _gcd(g, a[j]);
			}
			if(g == 1) {
				ans = min(ans, 1LL * n - i);
			}
			a.clear();
			a = b;
		}
		cout << min(ans, 3LL) << endl;
	}
}