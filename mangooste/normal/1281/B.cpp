#include <bits/stdc++.h>

using namespace std;

signed main() {
	int tt;
	cin >> tt;
	while (tt--) {
		string s, c;
		cin >> s >> c;
		for (int i = 0; i < s.size(); i++) {
			int ind = -1;
			char min_char = s[i] - 1;
			for (int j = i + 1; j < s.size(); j++) {
				if (min_char >= s[j]) {
					min_char = s[j];
					ind = j;
				}
			}
			if (ind != -1) {
				swap(s[i], s[ind]);
				break;
			}
		}
		cout << (s < c ? s : "---") << '\n';
	}
}