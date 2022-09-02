#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

void solve() {
	int n;
	cin >> n;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;
	sort(as.begin(), as.end());
	as.erase(unique(as.begin(), as.end()), as.end());

	vector<pair<int, vector<int>>> subs;
	for (int ones = 0; ones <= 3; ++ones) {
		for (int twos = 0; twos <= 3; ++twos) {
			int cou = ones + twos;
			vector<int> offs;
			for (int x = 0; x <= ones; ++x) {
				for (int y = 0; y <= twos; ++y) offs.push_back(x + 2*y);
			}
			sort(offs.begin(), offs.end());
			offs.erase(unique(offs.begin(), offs.end()), offs.end());
			subs.emplace_back(cou, offs);
		}
	}

	ll res = INF;
	for (const auto& pr : subs) {
		ll min_threes = 0;
		for (ll a : as) {
			ll need = INF;
			for (int s : pr.second) {
				if (a-s >= 0 && (a-s) % 3 == 0) need = min(need, (a - s) / 3);
			}
			min_threes = max(min_threes, need);
		}
		res = min(res, min_threes + pr.first);
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}