#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		string S; cin >> S;
		vector<int> pref(2 * N + 1);
		for (int i = 0; i < 2 * N; ++i) {
			if (S[i] == '(') pref[i + 1] = pref[i] + 1;
			else pref[i + 1] = pref[i] - 1;
		}

		// 0
		if (*min_element(pref.begin(), pref.end()) == 0) {
			cout << "0\n";
			continue;
		}

		// if 0
		int first = -1;
		int last = -1;
		for (int i = 0; i <= 2 * N; ++i) if (pref[i] == -1) {
			if (first == -1) first = i;
			last = i;
		}
		int l = max_element(pref.begin(), pref.begin() + first) - pref.begin();
		int r = max_element(pref.begin() + last + 1, pref.end()) - pref.begin();
		int h = max_element(pref.begin(), pref.end()) - pref.begin();
		if (pref[l] + pref[r] >= pref[h]) {
			cout << "1\n";
			cout << l + 1 << ' ' << r << '\n';
		} else {
			cout << "2\n";
			cout << l + 1 << ' ' << h << '\n';
			cout << h + 1 << ' ' << r << '\n';
		}
	}
	return 0;
}