#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	const int MOD = 998244353;

	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		vector<int> V(N); for (int &v : V) cin >> v;

		auto solve = [&]() {
			for (int i = N - K; i < N; ++i) if (V[i] > 0) return 0;
			int ans = 1;
			for (int i = 1; i <= K; ++i) ans = int64_t(ans) * i % MOD;
			for (int i = 0; i < N - K; ++i) {
				if (V[i] == 0) {
					ans = int64_t(ans) * (K + 1) % MOD;
				} else if (V[i] == -1) {
					ans = int64_t(ans) * (K + 1 + i) % MOD;
				}
			}
			return ans;
		};
		cout << solve() << '\n';
	}
	return 0;
}