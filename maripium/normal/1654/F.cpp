#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int N; cin >> N;
	string S; cin >> S;
	vector<int> rnk(1 << N);
	for (int i = 0; i < 1 << N; ++i) rnk[i] = S[i] - 'a';

	for (int z = 0; z < N; ++z) {
		vector<pair<int, int>> rnks(1 << N);
		vector<int> ord(1 << N); iota(ord.begin(), ord.end(), 0);
		for (int i = 0; i < 1 << N; ++i) rnks[i] = {rnk[i], rnk[i ^ (1 << z)]};
		sort(ord.begin(), ord.end(), [&](int i, int j) { return rnks[i] < rnks[j]; });

		for (int i = 0, r = 0; i < 1 << N; r++) {
			int j = i;
			while (j < (1 << N) && rnks[ord[j]] == rnks[ord[i]]) {
				rnk[ord[j++]] = r;
			}
			i = j;
		}
	}

	int best = 0;
	while (rnk[best]) best++;
	for (int i = 0; i < 1 << N; ++i) cout << S[i ^ best];
	return 0;
}