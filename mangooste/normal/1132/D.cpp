#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<ll> a(n), b(n);
	for (auto &x : a)
		cin >> x;
	for (auto &x : b)
		cin >> x;

	auto check = [&](ll x) {
		// cout << "checking " << x << endl;
		vector<vector<pair<int, ll>>> evs(k);
		for (int i = 0; i < n; i++) {
			ll when = a[i] / b[i] + 1;
			// cout << "when = " << when << endl;
			if (when < k)
				evs[when].emplace_back(i, b[i] * when - a[i]);
		}

		for (int i = 1, pos = 0; i < k; i++)
			while (evs[i].size()) {
				auto [ind, cnt] = evs[i].back();
				evs[i].pop_back();

				if (!x)
					return false;
				ll need = (cnt + x - 1) / x;
				// cout << "i = " << i << " cnt = " << cnt << " pos = " << pos << " need = " << need << endl;
				pos += need;
				if (pos > i)
					return false;
				cnt = x * need - cnt;
				ll when = cnt / b[ind] + 1;
				if (i + when < k)
					evs[i + when].emplace_back(ind, b[ind] * when - cnt);
			}

		return true;
	};

	ll lb = -1, rb = 2e12;
	while (rb - lb > 1) {
		ll mid = (lb + rb) / 2;
		(check(mid) ? rb : lb) = mid;
	}
	cout << (check(rb) ? rb : -1) << '\n';
}