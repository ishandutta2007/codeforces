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
		for (int i = 0; i < n; i++) {
			s[i] -= '0', t[i] -= '0';
		}
		vector<int> ops;
		for (int i = n - 1, L = 0, R = n - 1, x = 0, rev = 0; i >= 0; i--) {
			if (((rev ? s[L] : s[R]) ^ x) != t[i]) {
				if (((rev ? s[R] : s[L]) ^ x) == t[i]) {
					s[(rev ? R : L)] ^= 1;
					ops.push_back(0);
				}
				ops.push_back(i);
				rev ? R-- : L++;
				x ^= 1, rev ^= 1;
			} else {
				rev ? L++ : R--;
			}
		}
		cout << ops.size();
		for (auto &el : ops) {
			cout << ' ' << el + 1;
		}
		cout << '\n';
	}
}