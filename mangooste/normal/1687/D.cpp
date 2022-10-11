#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;

	for (ll mn = 1;; mn++) {
		if (mn * (mn + 1) < a[0]) continue;
		ll from = max(0ll, mn * mn - a[0]), to = mn * (mn + 1) - a[0];
		ll valid_l = from, valid_r = to;

		auto query = [&](ll value) {
			return ceil((-1 + sqrtl(1 + 4 * (value + from))) / 2 - 1e-5);
		};

		for (int i = 0; i < n && valid_l <= valid_r;) {
			int l = i, r = n, need = query(a[i]);
			while (r - l > 1) {
				int mid = (l + r) >> 1;
				(query(a[mid]) == need ? l : r) = mid;
			}
			valid_l = max(valid_l, 1ll * need * need - a[i]);
			valid_r = min(valid_r, 1ll * need * (need + 1) - a[r - 1]);
			i = r;
		}

		if (valid_l <= valid_r) {
			cout << valid_l << '\n';
			return 0;
		}
	}
}