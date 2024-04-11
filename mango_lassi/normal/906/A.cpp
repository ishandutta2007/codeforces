#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int C = 26;
bool can[C];
bool tmp[C];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int res = 0;
	int cou = C;
	for (int i = 0; i < C; ++i) can[i] = 1;
	for (int i = 0; i < n; ++i) {
		char t;
		string str;
		cin >> t >> str;
		if (t == '.') {
			for (auto c : str) {
				if (can[c-'a']) {
					can[c-'a'] = 0;
					--cou;
				}
			}
		} else if (t == '!') {
			if (cou == 1) ++res;

			for (int c = 0; c < C; ++c) tmp[c] = 0;
			for (auto c : str) tmp[c-'a'] = 1;
			for (int c = 0; c < C; ++c) {
				if (! tmp[c] && can[c]) {
					can[c] = 0;
					--cou;
				}
			}

		} else {
			if (cou == 1 && i < n-1) ++res;
			if (can[str[0] - 'a']) {
				can[str[0] - 'a'] = 0;
				--cou;
			}
		}
	}
	cout << res << '\n';
}