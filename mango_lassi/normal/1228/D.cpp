#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<pair<vector<int>, int>> conns(n);

	for (int j = 0; j < m; ++j) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].first.push_back(b);
		conns[b].first.push_back(a);
	}

	for (int i = 0; i < n; ++i) {
		sort(conns[i].first.begin(), conns[i].first.end());
		conns[i].second = {i};
	}
	sort(conns.begin(), conns.end());

	bool works = true;
	int cur = 0, siz = 0;
	vector<int> group(n, -1);
	for (int i = 0; i <= n; ++i) {
		if (i > 0 && (i == n || conns[i].first != conns[i-1].first)) {
			if (conns[i-1].first.size() != n - siz) works = false;
			siz = 0;
			++cur;
			if (i == n) break;
		}
		++siz;
		group[conns[i].second] = cur;
	}
	if (cur != 3) works = false;

	if (works) {
		for (auto v : group) cout << v+1 << ' '; cout << '\n';
	} else {
		cout << -1 << '\n';
	}
}