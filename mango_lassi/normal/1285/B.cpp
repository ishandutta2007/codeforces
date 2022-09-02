#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		int n;
		cin >> n;
		vector<ll> as(n);
		for (ll& v : as) cin >> v;

		bool fail = false;
		ll sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += as[i];
			if (sum <= 0) fail = true;
		}

		sum = 0;
		for (int i = n-1; i >= 0; --i) {
			sum += as[i];
			if (sum <= 0) fail = true;
		}

		if (fail) cout << "NO\n";
		else cout << "YES\n";
	}
}