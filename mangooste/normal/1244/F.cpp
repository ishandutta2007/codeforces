#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, k;
	string s;
	cin >> n >> k >> s;
	for (auto &c : s)
		c = (c == 'W' ? 0 : 1);

	int pos = -1;
	for (int i = 0; i < n; i++)
		if (s[i] == s[(i + n - 1) % n] || s[i] == s[(i + 1) % n])
			pos = i;

	if (pos == -1) {
		k %= 2;
		for (auto &c : s)
			cout << (c ^ k ? 'B' : 'W');
		return cout << '\n', 0;
	}

	rotate(s.begin(), s.begin() + pos, s.end());
	s.push_back(s[0]);
	n++;

	string ans(n, 0);
	vector<int> st;
	for (int i = 0; i < n; i++) {
		if (s[(i - 1 + n) % n] != s[i] && s[(i + 1) % n] != s[i]) {
			st.push_back(i);
			continue;
		}
		ans[i] = s[i];
		for (auto j : st) {
			int when = min(j - st[0], st.back() - j) + 1;
			if (k <= when)
				ans[j] = s[j] ^ (k % 2);
			else
				ans[j] = (j - st[0] < st.back() - j ? s[st[0] - 1] : s[st.back() + 1]);
		}
		st.clear();
	}

	ans.pop_back();
	if (pos)
		rotate(ans.begin(), ans.end() - pos, ans.end());
	for (auto &c : ans)
		cout << (c ? 'B' : 'W');
	cout << '\n';
}