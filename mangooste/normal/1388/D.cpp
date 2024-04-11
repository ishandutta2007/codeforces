#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<ll> a(n);
	for (auto &el : a) {
		cin >> el;
	}

	vector<int> b(n), in(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		if (b[i] != -1) {
			in[--b[i]]++;
		}
	}

	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (!in[i]) {
			q.push(i);
		}
	}

	ll ans = 0;

	vector<int> bfs;

	while (q.size()) {
		int v = q.front();
		q.pop();
		bfs.push_back(v);

		ans += a[v];

		if (b[v] == -1) {
			continue;
		}

		in[b[v]]--;
		if (!in[b[v]]) {
			q.push(b[v]);
		}

		a[b[v]] += max(0ll, a[v]);

		if (a[v] < 0) {
			b[v] = -1;
		}
	}

	vector<vector<int>> rev_g(n);
	for (int i = 0; i < n; i++) {
		if (b[i] != -1) {
			rev_g[b[i]].push_back(i);
		}
	}

	reverse(bfs.begin(), bfs.end());

	vector<int> order;
	for (auto i : bfs) {
		if (b[i] == -1) {
			vector<int> loc;

			queue<int> q;
			q.push(i);

			while (q.size()) {
				int v = q.front();
				q.pop();

				loc.push_back(v);

				for (auto u : rev_g[v]) {
					q.push(u);
				}
			}

			reverse(loc.begin(), loc.end());
			for (auto el : loc) {
				order.push_back(el);
			}
		}
	}

	cout << ans << '\n';
	for (auto el : order) {
		cout << el + 1 << ' ';
	}
	cout << '\n';
}