#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct fenwik {
	int n;
	vector<ll> bit;

	inline void resize(int n_) {
		n = n_;
		bit.resize(n + 1, 0);
	}

	inline void add(int pos, ll val) {
		for (pos++; pos <= n; pos += pos & -pos) {
			bit[pos] += val;
		}
	}

	inline void add(int L, int R, ll val) {
		add(L, val);
		add(R, -val);
	}

	ll get(int pos) {
		ll res = 0;
		for (pos++; pos > 0; pos -= pos & -pos) {
			res += bit[pos];
		}
		return res;
	}
};

const ll INF = 1e15;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n), p(n);
	for (auto &el : a) {
		cin >> el;
	}
	for (auto &el : p) {
		cin >> el;
	}

	int m;
	cin >> m;
	vector<int> b(m), where(n + 1, -1);
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		where[b[i]] = i + 1;
	}

	vector<vector<int>> poses(n + 1);
	for (int i = 0; i < n; i++) {
		poses[a[i]].push_back(i);
	}

	for (int i = 0, j = 0; i < m; i++) {
		j = lower_bound(poses[b[i]].begin(), poses[b[i]].end(), j) - poses[b[i]].begin();
		if (j == poses[b[i]].size()) {
			cout << "NO\n";
			return 0;
		}
		j = poses[b[i]][j];
	}

	where[0] = 0;
	b.push_back(0);
	rotate(b.begin(), b.end() - 1, b.end());
	m++;

	fenwik bit;
	bit.resize(m);
	bit.add(1, m, INF);

	for (int i = 0; i < n; i++) {
		int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		bit.add(0, pos, p[i]);
		bit.add(pos, m, min(0, p[i]));

		if (where[a[i]] != -1) {
			bit.add(pos, pos + 1, min(0ll, bit.get(pos - 1) - p[i] - bit.get(pos)));
		}
	}

	cout << "YES\n";
	cout << bit.get(m - 1);
}