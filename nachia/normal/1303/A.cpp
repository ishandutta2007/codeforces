#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Loop() {
		string S; cin >> S;
		UL ans = 0;
		rep(i, S.size()) if (S[i] == '0') ans++;
		rep(i, S.size()) if (S[i] == '0') ans--; else break;
		reverse(S.begin(), S.end());
		if (ans != 0) rep(i, S.size()) if (S[i] == '0') ans--; else break;
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