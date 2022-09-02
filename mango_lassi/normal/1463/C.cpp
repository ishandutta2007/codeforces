#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int sign(ll v) {
	return (v < 0 ? -1 : (v > 0));
}

void solve() {
	int n;
	cin >> n;
	vector<pair<ll, ll>> cmd(n);
	for (auto& pr : cmd) cin >> pr.first >> pr.second;

	int res = 0;
	ll x = 0, t = 0, cx = 0;
	for (int j = 0; j < cmd.size(); ++j) {
		ll nt = cmd[j].first;
		if (nt - t >= abs(x - cx)) {
			if (j > 0) {
				ll tx = cmd[j-1].second;
				if ((x <= tx && tx <= cx) || (cx <= tx && tx <= x)) ++res;
			}
			x = cx;
			cx = cmd[j].second;
		} else {
			ll nx = x + sign(cx - x) * (nt - t);
			if (j > 0) {
				ll tx = cmd[j-1].second;
				if ((x <= tx && tx <= nx) || (nx <= tx && tx <= x)) ++res;
			}
			x = nx;
		}
		t = nt;
	}

	ll tx = cmd.back().second;
	if ((x <= tx && tx <= cx) || (cx <= tx && tx <= x)) ++res;

	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}