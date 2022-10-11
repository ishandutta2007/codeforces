#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string need = "abacaba";

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		vector<int> poses;
		for (int i = 0; i < n - 6; i++) {
			if (s.substr(i, 7) == need) {
				poses.push_back(i);
			}
		}
		if (poses.size()) {
			if (poses.size() > 1) {
				cout << "No\n";
			} else {
				cout << "Yes\n";
				for (auto &el : s) {
					cout << (el == '?' ? 'z' : el);
				}
				cout << '\n';
			}
		} else {
			bool any = false;
			for (int i = 0; i < n - 6 && !any; i++) {
				bool can = true;
				for (int j = i; j < i + 7 && can; j++) {
					can &= (s[j] == '?' || s[j] == need[j - i]);
				}
				if (can) {
					string t = s;
					for (auto &el : t) {
						el = (el == '?' ? 'z' : el);
					}
					for (int j = i; j < i + 7; j++) {
						t[j] = need[j - i];
					}
					int cnt = 0;
					for (int j = max(0, i - 20); j < min(n - 6, i + 20); j++) {
						cnt += (t.substr(j, 7) == need);
					}
					if (cnt == 1) {
						any = true;
						cout << "Yes\n" << t << '\n';
					}
				}
			}
			if (!any) {
				cout << "No\n";
			}
		}
	}
}