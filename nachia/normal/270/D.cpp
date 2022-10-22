#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)



struct Problem {

	void Solve() {
		UL N, M; cin >> N >> M;
		vector<UL> A(N);
		rep(i, N) { float x; cin >> A[i] >> x; A[i]--; }
		vector<UL> P(M);
		rep(i, N) {
			UL a = A[i];
			UL buf = 0;
			rep(j, a + 1) buf = max(buf, P[j]);
			P[a] = buf + 1;
		}
		UL ans = 0;
		rep(i, M) ans = max(ans, P[i]);
		cout << (N - ans) << endl;
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