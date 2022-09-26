#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	auto ok = [&](int len) {
		vector<int> x(len, inf);
		for (int i = 1; i <= n; ++i) {
			int cur = a[i] - a[i - 1];
			if (x[(i - 1) % len] == inf) x[(i - 1) % len] = cur;
			if (x[(i - 1) % len] != cur) return false;
		}
		return true;
	};
	vector<int> res;
	for (int i = 1; i <= n; ++i) if (ok(i)) res.push_back(i);
	cout << res.size() << '\n';
	for (int l : res) cout << l << ' '; cout << '\n';
}