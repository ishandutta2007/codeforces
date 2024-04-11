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
	for (int i = 0; i + 2 < n; i++)
		if (a[i] == a[i + 1] && a[i + 1] == a[i + 2])
			return cout << "cslnb\n", 0;

	for (int i = 1; i + 1 < n; i++)
		if (a[i] == a[i + 1] && a[i - 1] + 1 == a[i])
			return cout << "cslnb\n", 0;

	int sum = 0;
	for (int i = 0; i + 1 < n; i++)
		if (a[i] == a[i + 1])
			sum++;
	if (sum > 1 || (n != 1 && a[0] == a[1] && a[0] == 0))
		return cout << "cslnb\n", 0;

	int last = -1;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		assert(a[i] >= last);
		if (a[i] == last)
			continue;
		last++;
		cnt = (cnt + a[i] - last) % 2;
	}
	if (cnt == 0)
		cout << "cslnb\n";
	else
		cout << "sjfnb\n";
}