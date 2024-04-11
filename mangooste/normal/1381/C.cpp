#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, x, y;
		cin >> n >> x >> y;
		vector<int> a(n);
		for (auto &el : a) {
			cin >> el;
			el--;
		}
		int need = y - x;
		vector<vector<int>> where(n + 1);
		for (int i = 0; i < n; i++) {
			where[a[i]].push_back(i);
		}
		int free = 0;
		while (where[free].size()) {
			free++;
		}
		set<pair<int, int>, greater<pair<int, int>>> st;
		for (int i = 0; i < n + 1; i++) {
			st.insert({where[i].size(), i});
		}
		vector<int> ans(n, free);
		while (x--) {
			auto [sz, x] = *st.begin();
			st.erase(st.begin());
			ans[where[x].back()] = x;
			where[x].pop_back();
			st.insert({sz - 1, x});
		}
		int d = st.begin()->first;
		vector<pair<int, int>> poses;
		while (st.size()) {
			auto [sz, x] = *st.begin();
			st.erase(st.begin());
			while (where[x].size()) {
				poses.emplace_back(where[x].back(), x);
				where[x].pop_back();
			}
		}
		for (int i = 0; i < poses.size() && need; i++) {
			int j = (i + d) % poses.size();
			if (poses[j].second != poses[i].second) {
				need--;
				ans[poses[j].first] = poses[i].second;
			}
		}
		if (need) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for (auto &el : ans) {
			cout << el + 1 << ' ';
		}
		cout << '\n';
	}
}