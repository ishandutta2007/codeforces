#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Loop() {
		UL N, m, K; cin >> N >> m >> K; m--;
		vector<UL> A(N); rep(i, N) cin >> A[i];
		if (m < K) K = m;
		vector<UL> B(m + 1);
		rep(i, m + 1) {
			B[i] = max(A[i], A[i + N - m - 1]);
		}
		UL ans = 0;
		for (UL i = 0; i <= K; i++) {
			UL ansbuf = 2000000000;
			rep(j, m - K + 1) {
				ansbuf = min(ansbuf, B[i + j]);
			}
			ans = max(ans, ansbuf);
		}
		cout << ans << endl;
	}

	void Solve() {
		UL t; cin >> t;
		rep(i, t) Loop();
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