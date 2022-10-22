#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Loop() {
		ULL N, G, B; cin >> N >> G >> B;
		ULL ans = N;
		ULL must = (N + 1) / 2;
		ULL must2 = (must - 1) / G;
		must -= must2 * G;
		ULL must3 = must2 * (G + B) + must;
		ans = max(ans, must3);
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