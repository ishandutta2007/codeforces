#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct node {
	unordered_map<int, int> cnt;
	int del;

	node() : cnt({}), del(0) {}

	inline int size() {
		return cnt.size();
	}

	inline int merge(node &n, int k) {
		int res = 0;
		for (auto [len, num] : n.cnt) {
			if (cnt.find(k - len - n.del - del) != cnt.end()) res += num * cnt[k - len - n.del - del];
		}
		while (n.cnt.size()) {
			auto [len, num] = *n.cnt.begin();
			n.cnt.erase(n.cnt.begin());
			cnt[len + n.del - del] += num;
		}
		return res;
	}
};

int n, k, ans = 0;
vector<vector<int>> g;
vector<node> each;

void dfs(int v, int pr) {
	each[v].cnt[0]++;
	for (auto u : g[v]) {
		if (u == pr) continue;
		dfs(u, v);
		each[u].del++;
		if (each[u].cnt.size() > each[v].cnt.size()) swap(each[u], each[v]);
		ans += each[v].merge(each[u], k);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	g.resize(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	each.resize(n);
	dfs(0, 0);
	cout << ans << '\n';
}