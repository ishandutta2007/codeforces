#include<bits/stdc++.h>
using namespace std;

using ld = double;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, X; cin >> N >> X;
	vector<int> C(N);
	for (int i = 0; i < N; i++) {
		cin >> C[i]; C[i] *= 2; C[i] -= X;
	}
	//cerr << "C: "; for (int i = 0; i < N; i++) { cerr << C[i] << ' '; } cerr << '\n';
	int tot = 0;
	for (int i = 0; i < N; i++) {
		tot += C[i];
	}
	vector<vector<ld>> dp(tot+1, vector<ld>(N+1));
	dp[0][0] = 1;

	int curTot = 0;
	for (int i = 0; i < N; i++) {
		for (int v = curTot; v >= 0; v--) {
			for (int c = 0; c <= i; c++) {
				dp[v + C[i]][c+1] += dp[v][c] * (c+1) / double(N-c);
			}
		}
		curTot += C[i];
	}
	assert(curTot == tot);

	double ans = tot;
	for (int v = 0; v <= tot; v++) {
		for (int c = 1; c <= N; c++) {
			//if (dp[v][c] > 0) { cerr << v << ' ' << c << ' ' << dp[v][c] << '\n'; }
			// c is number remaining
			if (v >= X * N) {
				ans += dp[v][c] * (X * N - v) / double(c);
			}
		}
	}

	ans += N * X;
	ans /= 2;
	cout << fixed << setprecision(20) << ans << '\n';

	return 0;
}