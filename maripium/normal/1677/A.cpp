#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> P(N); for (int &a : P) cin >> a, --a;

		vector<vector<int>> pref(N, vector<int>(N + 1));
		vector<vector<int>> suff(N, vector<int>(N + 1));

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) pref[i][j + 1] = pref[i][j] + (P[j] < P[i]);
		}

		for (int i = 0; i < N; ++i) {
			for (int j = N - 1; j >= 0; --j) {
				suff[i][j] = suff[i][j + 1] + (P[j] < P[i]);
			}
		}

		int64_t ans = 0;
		for (int b = 0; b < N; ++b) {
			for (int c = b+1; c < N; ++c) ans += pref[c][b] * suff[b][c + 1];
		}
		cout << ans << '\n';
	}
	return 0;
}