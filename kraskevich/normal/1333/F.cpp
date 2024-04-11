#include <bits/stdc++.h>
using namespace std;

void solve_fast(int n) {
	vector<vector<int>> ds(n + 1);
	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			ds[j].push_back(i);
		}
	}
	vector<int> ps;
	for (int i = 1; i <= n; i++) {
		if (ds[i].size() < 2) {
			ps.push_back(i);
		}
	}
	vector<pair<int, int>> sz;
	sz.push_back({1, ps.size()});
	vector<bool> taken(n + 1);
	for (int p : ps) {
		taken[p] = true;
	}
	vector<bool> seen(n + 1);
	while (sz.back().second < n) {
		int t = sz.back().first;
		t++;
		int cnt = sz.back().second;
		for (int pos = 0; pos < ps.size() && t * 1ll * ps[pos] <= n && ps[pos] <= t; pos++) {
			int cur = t * ps[pos];
			if (taken[cur]) {
				continue;
			}
			auto it = upper_bound(ds[cur].begin(), ds[cur].end(), t);
			bool ok = true;
			for (auto i = it; i != ds[cur].end(); i++) {
				if (seen[*i]) {
					ok = false;
					break;
				}
			}
			if (!ok) {
				continue;
			}
			for (auto i = it; i != ds[cur].end(); i++) {
				seen[*i] = true;
			}
			cnt++;
			taken[cur] = true;
		}
		sz.push_back({t, cnt});
	}
	int pos = 0;
	for (int i = 2; i <= n; i++) {
		while (sz[pos].second < i) {
			++pos;
		}
		cout << sz[pos].first << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n;
	cin >> n;
	solve_fast(n);
}