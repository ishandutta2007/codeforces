#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;
	sort(a.begin(), a.end());
	if (n == 1)
		return cout << "0\n" << a[0] << '\n', 0;
	int ans = (n - 1) / 2;
	cout << ans << '\n';
	int pos = ans;
	cout << a[a.size() - 2];
	for (int i = 1; i < n - 1; i++) {
		cout << ' ';
		if (i % 2 == 0)
			cout << a[pos++];
		else
			cout << a[i / 2];
	}
	cout << ' ' << a.back() << '\n';
}