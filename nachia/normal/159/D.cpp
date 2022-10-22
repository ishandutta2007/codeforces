#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {
	bool P[2001][2001] = {};
	ULL dp[2001][2] = {};

	void Solve() {
		string S; cin >> S;
		UL N = S.size();
		rep(i, N) P[i][i + 1] = true;
		rep(i, N - 1) if (S[i] == S[i + 1]) P[i][i + 2] = true;
		for (UL l = 3; l <= N; l++) {
			for (UL i = l; i <= N; i++) {
				if (S[i - l] == S[i - 1])
					P[i - l][i] = P[i - l + 1][i - 1];
			}
		}
		for (UL i = 1; i <= N; i++) {
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1];
			for (UL l = 1; l <= i; l++) {
				if (P[i - l][i]) {
					dp[i][0] += 1;
					dp[i][1] += dp[i - l][0];
				}
			}
		}
		cout << dp[N][1] << endl;
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