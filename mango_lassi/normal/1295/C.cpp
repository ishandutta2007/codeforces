#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e5;
const int C = 26;
int nxt[N+1][C];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int ti = 0; ti < tc; ++ti) {
		string s, t;
		cin >> s >> t;
		int n = s.size();

		for (int c = 0; c < C; ++c) nxt[n][c] = n;
		for (int i = n-1; i >= 0; --i) {
			for (int c = 0; c < C; ++c) nxt[i][c] = nxt[i+1][c];
			nxt[i][s[i] - 'a'] = i;
		}
		int res = 0;
		for (int j = 0; j < t.size() && res <= t.size(); ) {
			++res;
			for (int i = 0; i < n && j < t.size();) {
				i = nxt[i][t[j] - 'a'];
				if (i < n) {
					++j;
					++i;
				}
			}
		}
		if (res > t.size()) cout << -1 << '\n';
		else cout << res << '\n';
	}
}