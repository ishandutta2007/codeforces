#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	ll ones = 0, twos = 0;
	for (int i = 0; i < n; ++i) {
		ll v;
		cin >> v;
		if (v == 1) ++ones;
		else ++twos;
	}
	if ((ones & 1) || ((twos & 1) && (ones == 0))) cout << "No\n";
	else cout << "Yes\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}