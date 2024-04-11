#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)


struct Problem {

	void Solve() {
		UL N; cin >> N;
		vector<UL> A(N); rep(i, N) cin >> A[i];
		sort(A.rbegin(), A.rend());
		vector<UL> B(1000001, 10000000); rep(i, N) B[A[i]] = A[i];
		for (UL i = 1000000; i > 0; i--) B[i - 1] = min(B[i], B[i - 1]);
		UL ans = 0;
		rep(i, N) {
			for (UL j = ans + 2; (ULL)j * j < A[i]; j++) {
				if (B[j] == j) ans = max(ans, A[i] % j);
			}
			for (UL j = 2; (ULL)j * j < A[i]; j++) {
				UL p = A[i] / j + 1;
				if (p <= ans) break;
				if (B[p] < A[i]) ans = max(ans, A[i] % B[p]);
			}
		}
		cout << ans << endl;
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