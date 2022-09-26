#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		string S; cin >> S;
		vector<int> pref(N * M);
		for (int i = 0; i < N * M; ++i) {
			pref[i] = (S[i] == '1');
			if (i) pref[i] += pref[i - 1];
		}
		vector<int> row(N * M);
		for (int i = 0; i < N * M; ++i) {
			int v = pref[i];
			if (i >= M) v -= pref[i - M];
			row[i] = (v > 0);
			if (i >= M) row[i] += row[i - M];
		}
		vector<bool> was(M);
		vector<int> col(N * M);
		for (int i = 0; i < N * M; ++i) {
			bool add = (!was[i % M]) && (S[i] == '1');
			if (add) {
				col[i] = 1;
				was[i % M] = 1;
			}
			if (i) col[i] += col[i - 1];
		}
		for (int i = 0; i < N * M; ++i) cout << row[i] + col[i] << ' '; cout << '\n';
	}
}