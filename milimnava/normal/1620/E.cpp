#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m = 0; cin >> n;
	vector<int> opt(n), x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> opt[i] >> x[i];
		if (opt[i] == 1) ++m;
		if (opt[i] == 2) cin >> y[i];
	}
	vector<int> ans(m), id(500001);
	for (int i = 1; i <= 500000; i++) id[i] = i;
	int now = m - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (opt[i] == 1) ans[now] = id[x[i]], --now;
		else id[x[i]] = id[y[i]];
	}
	for (int i = 0; i < m; i++) cout << ans[i] << ' ';
	cout << endl;
	return 0;
}