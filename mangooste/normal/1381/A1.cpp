#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s, t;
		cin >> n >> s >> t;
		vector<int> ops;
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == t[i]) {
				continue;
			}
			if (i == 0) {
				ops.push_back(0);
			} else {
				if (s[0] == t[i]) {
					ops.push_back(0);
					s[0] = (s[0] == '1' ? '0' : '1');
				}
				ops.push_back(i);
				reverse(s.begin(), s.begin() + i + 1);
				for (int j = 0; j <= i; j++) {
					s[j] = (s[j] == '1' ? '0' : '1');
				}
			}
		}
		cout << ops.size();
		for (auto &el : ops) {
			cout << ' ' << el + 1;
		}
		cout << '\n';
	}
}