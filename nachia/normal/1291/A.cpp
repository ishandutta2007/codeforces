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
		string S; cin >> S;
		vector<UL> odds;
		rep(i, N) if (odd(S[i])) odds.push_back(i);
		if (odds.size() < 2) { cout << -1 << endl; return; }
		for (UL i = odds[0]; i <= odds[1]; i++) {
			cout << S[i];
		} cout << endl;
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