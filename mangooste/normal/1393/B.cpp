#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXA = 100100;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> cnt(MAXA, 0);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	set<pair<int, int>, greater<pair<int, int>>> can;
	for (int i = 1; i < MAXA; i++) {
		if (cnt[i]) can.emplace(cnt[i], i);
	}
	int q;
	cin >> q;
	while (q--) {
		char tp;
		int x;
		cin >> tp >> x;
		if (cnt[x]) can.erase({cnt[x], x});
		cnt[x] += (tp == '+' ? 1 : -1);
		if (cnt[x]) can.insert({cnt[x], x});
		if (!can.size() || can.begin()->first < 4) {
			cout << "NO\n";
			continue;
		}
		int need = 2 - min(2, (can.begin()->first - 4) / 2);
		vector<pair<int, int>> save = {*can.begin()};
		can.erase(can.begin());
		bool ok = true;
		while (need && ok) {
			if (can.empty()) {
				ok = false;
				continue;
			}
			save.push_back(*can.begin());
			ok &= (can.begin()->first > 1);
			need -= min(need, can.begin()->first / 2);
			can.erase(can.begin());
		}
		cout << (ok ? "YES\n" : "NO\n");
		for (auto x : save) can.insert(x);
	}
}