#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using ull = uint64_t;

using namespace std;


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	int n;
	cin >> n;
	map<string, vector<int>> m;

	for (int i = 0; i < n; ++i) {
		string tp;
		int x;
		cin >> tp >> x;
		m[tp].push_back(x);
	}

	for (auto& pn: m) {
		sort(pn.second.rbegin(), pn.second.rend());
	}
	int sz = m["11"].size(), ans = 0;
	for (int x: m["11"]) {
		ans += x;
	}

	vector<int> ls = m["00"];

	int mn = min(m["01"].size(), m["10"].size());

	for (string tp: {"01", "10"}) {
		for (int i = 0; i < m[tp].size(); ++i) {
			if (i < mn) {
				ans += m[tp][i];
			} else {
				ls.push_back(m[tp][i]);
			}
		}
	}

	sort(ls.rbegin(), ls.rend());
	ls.resize(sz);
	for (int x: ls) {
		ans += x;
	}

	cout << ans << "\n";

	return 0;
}