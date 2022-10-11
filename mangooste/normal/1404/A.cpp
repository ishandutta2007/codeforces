#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		bool can = true;
		vector<vector<int>> valid;
		vector<int> cnt(2, 0);
		for (int i = 0; i < k; i++) {
			int know = -1;
			for (int j = i; j < n; j += k) {
				if (s[j] == '?')
					continue;
				can &= (know == -1 || know == s[j] - '0');
				know = s[j] - '0';
			}
			if (know != -1)
				cnt[know]++;
		}
		can &= (max(cnt[0], cnt[1]) * 2 <= k);
		cout << (can ? "YES\n" : "NO\n");
	}
}