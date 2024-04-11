#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> count_sort(string s) {
	vector<int> cnt(26, 0);
	for (auto c : s) cnt[c - 'a']++;
	return cnt;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		string s, t;
		cin >> n >> s >> t;
		if (count_sort(s) != count_sort(t)) {
			cout << "-1\n";
			continue;
		}
		vector<vector<int>> nxt(n + 1, vector<int>(26, -1));
		for (int i = n - 1; i >= 0; i--) {
			nxt[i] = nxt[i + 1];
			nxt[i][s[i] - 'a'] = i;
		}
		int ans = n;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				string need = t.substr(i, j - i + 1);
				int pos = 0;
				bool ok = true;
				for (int i = 0; i < need.size() && ok; i++) {
					if (nxt[pos][need[i] - 'a'] == -1) ok = false;
					else pos = nxt[pos][need[i] - 'a'] + 1;
				}
				if (ok) ans = min(ans, i + n - j - 1);
			}
		}
		cout << ans << '\n';
	}
}