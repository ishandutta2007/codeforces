#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Loop() {
		UL a, b, c; cin >> a >> b >> c;
		UL N; cin >> N;
		UL A = a + b + c + N;
		if (A % 3) { cout << "NO" << endl; return; }
		A /= 3;
		if (max(a, max(b, c)) > A) cout << "NO" << endl;
		else cout << "YES" << endl;
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