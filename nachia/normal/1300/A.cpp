#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Loop() {
		UL N; cin >> N;
		LL S = 0, Z = 0;
		rep(i, N) {
			LL a; cin >> a;
			S += a;
			if (a == 0) Z++;
		}
		UL ans = Z;
		if (-S == ans) ans++;
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