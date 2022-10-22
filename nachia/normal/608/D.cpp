#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)


struct Problem {
	
	UL dp[500][501];

	void Solve() {
		UL N; cin >> N;
		vector<UL> C(N); rep(i, N) cin >> C[i];
		for (UL S = 0; S <= N; S++) {
			rep(L, N - S + 1) {
				UL buf = 100000;
				if (S <= 1) { dp[L][S] = 1; continue; }
				for (UL i = 1; i < S; i++) {
					buf = min(buf, dp[L][i] + dp[L + i][S - i]);
				}
				if (C[L] == C[L + S - 1]) {
					buf = min(buf, dp[L + 1][S - 2]);
				}
				dp[L][S] = buf;
			}
		}
		cout << dp[0][N] << endl;
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