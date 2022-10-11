#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &el : a)
			cin >> el;
		vector<int> l(n);
		for (auto &el : l)
			cin >> el;
		vector<int> els;
		for (int i = 0; i < n; i++)
			if (l[i] == 0)
				els.push_back(a[i]);
		sort(els.rbegin(), els.rend());
		int now = 0;
		for (int i = 0; i < n; i++)
			if (l[i] == 0)
				a[i] = els[now++];
		for (auto x : a)
			cout << x << ' ';
		cout << '\n';
	}
}