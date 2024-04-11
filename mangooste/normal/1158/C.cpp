#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct sparse_table {
	int n;
	vector<vector<int>> sparse;

	inline int max_bit(int n) {
		return 31 - __builtin_clz(n);
	}

	sparse_table(vector<int> &a) : n(a.size()) {
		sparse.resize(max_bit(n) + 1, vector<int>(n));
		for (int i = 0; i < n; i++) sparse[0][i] = a[i];
		for (int level = 1; level < sparse.size(); level++) {
			for (int i = 0; i + (1 << level) <= n; i++) {
				sparse[level][i] = max(sparse[level - 1][i], sparse[level - 1][i + (1 << level - 1)]);
			}
		}
	}

	int get(int L, int R) {
		int level = max_bit(R - L);
		return max(sparse[level][L], sparse[level][R - (1 << level)]);
	}
};

bool check(vector<int> &nxt) {
	int n = nxt.size();
	sparse_table sparse(nxt);
	for (int i = 0; i < n; i++) {
		if (nxt[i] != -1 && sparse.get(i, nxt[i]) > nxt[i]) return false;
	}
	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> nxt(n);
		for (auto &x : nxt) {
			cin >> x;
			x = max(-1, x - 1);
		}
		if (!check(nxt)) {
			cout << "-1\n";
			continue;
		}
		int now = n;
		vector<int> ans(n, -1);
		for (int i = 0; i < n; i++) {
			vector<int> way;
			int v = i;
			while (v < n && ans[v] == -1 && nxt[v] != -1) {
				way.push_back(v);
				v = nxt[v];
			}
			if (v < n && ans[v] == -1) way.push_back(v);
			reverse(way.begin(), way.end());
			for (auto v : way) ans[v] = now--;
		}
		for (auto x : ans) cout << (x == -1 ? now-- : x) << ' ';
		cout << '\n';
	}
}