#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	string str;
	cin >> str;
	int n = str.size();
	sort(str.begin(), str.end());

	vector<int> cou(26, 0);
	for (char c : str) ++cou[c - 'a'];
	string apps;
	for (int i = 0; i < 26; ++i) {
		if (cou[i] > 0) apps.push_back('a' + i);
	}
	
	if (apps.size() > 1) {
		int ini = -1;
		for (int j = 0; j < apps.size(); ++j) {
			if (cou[apps[j] - 'a'] == 1) {
				ini = j;
				break;
			}
		}
		if (ini != -1) {
			str[0] = apps[ini];
			--cou[apps[ini] - 'a'];
			for (int i = 1; i < n; ++i) {
				bool found = 0;
				for (int j = 0; j < 26; ++j) {
					if (cou[j] > 0) {
						char off = 'a' + j;
						--cou[j];
						str[i] = off;
						found = 1;
						break;
					}
				}
				assert(found);
			}
		} else if (cou[apps[0] - 'a'] - 2 <= (n - 2) / 2) {
			// First letter uncommon enough
			str[0] = apps[0];
			str[1] = apps[0];
			cou[apps[0] - 'a'] -= 2;

			char pre = apps[0];
			for (int i = 2; i < n; ++i) {
				bool found = 0;
				for (int j = 0; j < 26; ++j) {
					char off = 'a' + j;
					if (cou[j] > 0 && (off != apps[0] || pre != apps[0])) {
						--cou[j];
						str[i] = off;
						pre = off;
						found = 1;
						break;
					}
				}
				assert(found);
			}
		} else if (apps.size() == 2) {
			// Two letters
			reverse(str.begin(), str.end());
			swap(str[0], str[cou[apps[1] - 'a']]);
		} else {
			// Three letters
			str[0] = apps[0];
			str[1] = apps[1];
			--cou[apps[0] - 'a'];
			--cou[apps[1] - 'a'];
			char pre = apps[1];
			for (int i = 2; i < n; ++i) {
				bool found = 0;
				for (int j = 0; j < 26; ++j) {
					char off = 'a' + j;
					if (cou[j] > 0 && (off != apps[1] || pre != apps[0])) {
						--cou[j];
						str[i] = off;
						pre = off;
						found = 1;
						break;
					}
				}
				assert(found);
			}
		}
	}
	cout << str << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}