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
	}

	void Solve() {
		UL N, M; cin >> N >> M;
		string S[20]; rep(i, N) cin >> S[i];
		string T[20]; rep(i, M) cin >> T[i];
		UL q; cin >> q;
		rep(i, q) {
			UL n; cin >> n;
			cout << S[(n - 1) % N] << T[(n - 1) % M] << endl;
		}
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