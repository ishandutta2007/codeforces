#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int64_t> A(N); for (auto &a : A) cin >> a;

		vector<int64_t> pref(N + 1);
		for (int i = 0; i < N; ++i) pref[i + 1] = pref[i] + A[i];
		vector<int64_t> prefs = pref;
		sort(prefs.begin(), prefs.end());
		prefs.resize(unique(prefs.begin(), prefs.end()) - prefs.begin());

		int M = int(prefs.size());

		const int64_t INF = 1e18;
		int S = 1;
		while (S < M) S *= 2;
		vector<int64_t> V0(S * 2, -INF);
		vector<int64_t> V1(S * 2, -INF);

		auto update = [&](int v, int64_t x0, int64_t x1) {
			v += S;
			V0[v] = max(V0[v], x0);
			V1[v] = max(V1[v], x1);
			for (v /= 2; v > 0; v /= 2) {
				V0[v] = max(V0[2 * v], V0[2 * v + 1]);
				V1[v] = max(V1[2 * v], V1[2 * v + 1]);
			}
		};

		auto get0 = [&](int l, int r) {
			int64_t ans = -INF;
			for (l += S, r += S; l <= r; l /= 2, r /= 2) {
				if (l % 2) ans = max(ans, V0[l++]);
				if (r % 2 == 0) ans = max(ans, V0[r--]);
			}
			return ans;
		};

		auto get1 = [&](int l, int r) {
			int64_t ans = -INF;
			for (l += S, r += S; l <= r; l /= 2, r /= 2) {
				if (l % 2) ans = max(ans, V1[l++]);
				if (r % 2 == 0) ans = max(ans, V1[r--]);
			}
			return ans;
		};

		int j0 = lower_bound(prefs.begin(), prefs.end(), pref[0]) - prefs.begin();
		update(j0, 0, 0);
		vector<int64_t> val(M, -INF);
		val[j0] = 0;
		vector<int64_t> dp(N + 1);
		for (int i = 1; i <= N; ++i) {
			int j = lower_bound(prefs.begin(), prefs.end(), pref[i]) - prefs.begin();
			dp[i] = max({val[j], get0(0, j - 1) + i, get1(j + 1, M - 1) - i});
			update(j, dp[i] - i, dp[i] + i);
			val[j] = max(val[j], dp[i]);
		}
		cout << dp[N] << '\n';
	}
	return 0;
}