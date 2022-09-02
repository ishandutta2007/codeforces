#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<ll> vals(n);
	for (ll& v : vals) cin >> v;
	sort(vals.begin(), vals.end());

	ll odd = 0, even = 0;
	for (int i = n-1; i >= 0; --i) {
		int t = (n-1 - i) & 1;
		if (t == 0 && ((vals[i] % 2) == 0)) even += vals[i];
		else if (t == 1 && ((vals[i] % 2) == 1)) odd += vals[i];
	}
	if (odd == even) {
		cout << "Tie\n";
	} else if (odd > even) {
		cout << "Bob\n";
	} else {
		cout << "Alice\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}