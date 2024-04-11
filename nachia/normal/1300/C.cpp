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
		vector<UL> SA(N + 1), SrA(N + 1);
		rep(i, N) {
			SA[i + 1] = SA[i] | A[i];
			SrA[i + 1] = SrA[i] | A[N - i - 1];
		}
		UL v = 0;
		UL ansp = 0;
		rep(i, N) {
			if (v < (A[i] & ~SA[i] & ~SrA[N - i - 1])) {
				ansp = i;
				v = A[i] & ~SA[i] & ~SrA[N - i - 1];
			}
			//cout << (A[i] & ~SA[i] & ~SrA[N - i - 1]) << endl;
		}
		cout << A[ansp];
		rep(i, N) {
			if (i == ansp) continue;
			cout << " " << A[i];
		}
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