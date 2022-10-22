#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)


struct Problem {

	bool dp[501][501][501] = {};

	void Solve() {
		UL N, K; cin >> N >> K;
		vector<UL> C(N); rep(i, N) cin >> C[i];
		dp[0][0][0] = true;
		for (UL i = 1; i <= N; i++) {
			UL c = C[i - 1];
			for (UL k = 0; k <= K; k++) {
				for (UL p = 0; p <= k; p++)
					dp[i][k][p] = dp[i - 1][k][p];
				if (k < c) continue;
				for (UL p = 0; p <= K - c; p++) {
					dp[i][k][p] = dp[i][k][p] || dp[i - 1][k - c][p];
					dp[i][k][p + c] = dp[i][k][p + c] || dp[i - 1][k - c][p];
				}
			}
		}
		vector<UL> ans;
		rep(i, K + 1) {
			if (dp[N][K][i]) ans.push_back(i);
		}
		cout << ans.size() << endl;
		rep(i, ans.size()) { if (i) cout << " "; cout << ans[i]; }
		cout << endl;
	}
	
	Problem();
};
int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
Problem::Problem() {
	cout << fixed << setprecision(10);
}