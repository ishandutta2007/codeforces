#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	// Possible IFF no value occurs > (n+1)/2 times

	// Merge intervals that don't have the same tag occur twice in a row
	// We need at least #intervals - 1 jumps!

	int res = 0;
	vector<int> cou(n, 0), coll(n, 0);

	int pre = -1;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		++cou[v - 1];
		if (v == pre) {
			++res;
			coll[v - 1] += 2;
		}
		if (i == 0) ++coll[v - 1];
		if (i == n-1) ++coll[v - 1];
		pre = v;
	}

	bool fail = 0;
	for (auto v : cou) {
		if (v > (n + 1) / 2) fail = 1;
	}
	
	if (! fail) {
		int ans = res;
		for (auto c : coll) ans = max(ans, res + (c - (2*(res + 1) - c) - 1) / 2);
		cout << ans << '\n';

		/*
		cerr << res << '\n';
		for (auto c : coll) cerr << c << ": " << (c - (2*(res + 1) - c) - 1) << '\n';
		*/
	} else {
		cout << -1 << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int ti = 0; ti < n; ++ti) solve();
}