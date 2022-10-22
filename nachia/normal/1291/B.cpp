#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	bool odd(char c) { return (c - '0') % 2 == 1; }

	void Loop() {
		UL N; cin >> N;
		vector<UL> A(N); rep(i, N) cin >> A[i];
		UL p = 1;
		UL q = 0;
		while (p < N) {
			if (A[p] <= q) { q = A[p - 1]; break; }
			q++;
			p++;
		}
		while (p < N) {
			if (q == 0) { cout << "No" << endl; return; }
			q = min(q - 1, A[p]);
			p++;
		}
		cout << "Yes" << endl;
	}

	void Solve() {
		UL t; cin >> t; rep(i, t) Loop();
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