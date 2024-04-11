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
	vector<int> b(n);
	reverse(a.begin(), a.end());
	for (int i = 1; i < n; i += 2) {
		b[i] = a.back();
		a.pop_back();
	}
	for (int i = 0; i < n; i += 2) {
		b[i] = a.back();
		a.pop_back();
	}
	int ans = 0;
	for (int i = 1; i < n - 1; i++)
		ans += (b[i - 1] > b[i] && b[i] < b[i + 1]);
	cout << ans << '\n';
	for (int i = 0; i < n; i++)
		cout << b[i] << ' ';
	cout << '\n';
}