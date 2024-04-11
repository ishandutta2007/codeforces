#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int C = 20;
bool cou[C][C];
int inds[C]; // Highest index that gets this color

void solve() {
	int n;
	cin >> n;

	string str, tar;
	cin >> str >> tar;
	
	// We are only interested in what letter pairs we have
	for (int c = 0; c < C; ++c) {
		inds[c] = c;
		for (int d = 0; d < C; ++d) {
			cou[c][d] = 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		cou[str[i] - 'a'][tar[i] - 'a'] = 1;
	}


	int res = 0;
	bool fail = 0;
	for (int c = C-1; c >= 0; --c) {
		for (int d = 0; d < C; ++d) {
			if (cou[c][d]) {
				if (inds[d] < c) fail = 1;
				else if (inds[d] > c) {
					int t = inds[d];
					for (int c2 = 0; c2 < C; ++c2) {
						if (inds[c2] == t) inds[c2] = c;
					}
					++res;
				}
			}
		}
	}
	if (fail) cout << -1 << '\n';
	else cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		solve();
	}
}