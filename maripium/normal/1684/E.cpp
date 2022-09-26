#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		map<int, int> mp;
		for (int i = 0; i < N; ++i) {
			int a; cin >> a;
			mp[a] ++;
		}	

		vector<int> A; for (auto [v, c] : mp) A.push_back(c);
		sort(A.begin(), A.end());
		A.resize(unique(A.begin(), A.end()) - A.begin());
		int M = int(A.size());
		vector<int> C(M);
		for (auto [v, c] : mp) {
			int i = lower_bound(A.begin(), A.end(), c) - A.begin();
			C[i] ++;
		}

		int K0 = 0;
		int ans = N;
		for (int i = 0; i <= N; ++i) {
			if (K < K0) break;
			int curK = K;
			int curAns = int(mp.size()) + K0 - i;
			for (int j = 0; j < M; ++j) {
				int v = min(curK / A[j], C[j]);
				curK -= v * A[j];
				curAns -= v;
			}
			ans = min(ans, curAns);
			if (mp.count(i)) {
				int c = mp[i];
				int j = lower_bound(A.begin(), A.end(), c) - A.begin();
				C[j] --;
			} else K0++;
		}

		cout << ans << '\n';
	}
	return 0;
}