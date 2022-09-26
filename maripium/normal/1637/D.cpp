#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (int &a : A) cin >> a;
		vector<int> B(N); for (int &a : B) cin >> a;

		int sum = 0;
		int sum_sq = 0;
		bitset<20200> dp{}; dp[0] = 1;
		for (int i = 0; i < N; ++i) {
			sum += A[i] + B[i];
			sum_sq += A[i] * A[i] + B[i] * B[i];
			dp = (dp << A[i]) | (dp << B[i]);
		}
		int64_t ans = sum * sum;
		for (int i = 0; i <= sum; ++i) if (dp[i]) ans = min<int64_t>(ans, i * i + (sum - i) * (sum - i));
		ans += int64_t(N - 2) * sum_sq;
		cout << ans << '\n';
	}
	return 0;
}