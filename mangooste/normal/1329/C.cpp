#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int h, g;
		cin >> h >> g;
		int n = (1 << h) - 1, m = (1 << g) - 1;
		vector<int> a(n);
		for (auto &el : a) {
			cin >> el;
		}

		vector<int> dep(n, 0);
		for (int i = 1; i < n; i++) {
			dep[i] = dep[(i - 1) / 2] + 1;
		}

		vector<int> where(n);
		iota(where.begin(), where.end(), 0);

		vector<int> start(n);
		iota(start.begin(), start.end(), 0);

		vector<int> vers(n);
		iota(vers.begin(), vers.end(), 0);
		sort(vers.begin(), vers.end(), [&](int i, int j) {
			return a[i] > a[j];
		});

		vector<int> order;
		ll sum = accumulate(a.begin(), a.end(), 0ll);

		for (auto v : vers) {
			if (order.size() == n - m) {
				break;
			}

			v = where[v];

			vector<pair<int, int>> way;
			way.reserve(25);
			int now = v;
			while (2 * now + 2 < n && a[2 * now + 1] + a[2 * now + 2]) {
				way.emplace_back(now, start[now]);
				now = 2 * now + 1 + (a[2 * now + 1] < a[2 * now + 2]);
			}
			way.emplace_back(now, start[now]);

			if (dep[v] + way.size() - 1 < g) {
				continue;
			}

			order.push_back(v);
			sum -= a[v];

			for (int i = 1; i < way.size(); i++) {
				where[way[i].second] = way[i - 1].first;
				a[way[i - 1].first] = a[way[i].first];
				start[way[i - 1].first] = start[way[i].first];
			}
			a[way.back().first] = 0;
		}

		cout << sum << '\n';
		for (auto el : order) {
			cout << el + 1 << ' ';
		}
		cout << '\n';
	}
}