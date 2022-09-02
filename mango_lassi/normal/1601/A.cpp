#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	// k has to divide "count of bit i" for all i
	// and this is sufficient, as this condition still holds after subtracting!

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		int n;
		cin >> n;

		vector<ll> as(n);
		for (ll& a : as) cin >> a;

		int tot = 0;
		for (int j = 0; j < 30; ++j) {
			int cou = 0;
			for (ll a : as) cou += (bool)(a & (1ll << j));
			tot = gcd(tot, cou);
		}
		for (int i = 1; i <= n; ++i) {
			if (tot % i == 0) cout << i << ' ';
		}
		cout << '\n';
	}
}