#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N + 1);
		for (int i = 0; i < N; ++i) {
			int a; cin >> a;
			A[i + 1] = A[i] ^ a;
		}
		vector<int> dp(N + 1);
		dp[0] = 0;
		map<int, int> last;
		last[0] = 0;
		for (int i = 1; i <= N; ++i) {
			dp[i] = dp[i - 1] + 1;
			if (last.count(A[i])) {
				int j = last[A[i]];
				dp[i] = min(dp[i], dp[j] + i - j - 1);
			}
			last[A[i]] = i;
		}
		cout << dp[N] << '\n';
	}	
	return 0;
}