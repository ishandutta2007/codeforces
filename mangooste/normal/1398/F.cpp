#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	string s;
	cin >> n >> s;

	int i = 0;
	while (i < n && s[i] == '?') i++;
	for (int ii = 0; ii < i; ii++) s[ii] = '0' + (ii == n || s[i] == '1');
	int j = n - 1;
	while (j >= 0 && s[j] == '?') j--;
	for (int jj = n - 1; jj > j; jj--) s[jj] = s[j];

	vector<int> a, b;
	for (int i = 0; i < n;) {
		int j = i;
		while (j < n && (s[j] == '?' || s[j] == s[i])) j++;
		a.push_back(j - i);
		b.push_back(0);
		for (int k = j - 1; k >= i && s[k] == '?'; k--) a.back()--, b.back()++;
		i = j;
	}
	set<pair<int, int>> open;
	for (int i = 0; i < a.size(); i++) open.insert({a[i] + b[i] + (i ? b[i - 1] : 0), i});

	for (int x = 1; x <= n; x++) {
		auto it = open.lower_bound({x, 0});
		vector<int> valid;
		for (auto now = it; now != open.end(); now++) valid.push_back(now->second);
		sort(valid.begin(), valid.end());
		vector<int> na, nb;
		for (auto i : valid) {
			na.push_back(a[i]);
			nb.push_back(b[i]);
		}
		int ans = 0;
		for (int i = 0; i < valid.size(); i++) {
			int ind = valid[i];
			int now;
			if (!i || valid[i] != valid[i - 1] + 1) now = a[ind] + b[ind] + (ind ? b[ind - 1] : 0);
			else now = na[i] + nb[i];
			ans += now / x;
			now %= x;
			now = min(nb[i], now);
			if (i != valid.size() - 1 && valid[i + 1] == valid[i] + 1) na[i + 1] += now;
		}
		cout << ans << ' ';
	}
	cout << '\n';
}