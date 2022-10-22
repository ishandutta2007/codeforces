#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL Q, X; cin >> Q >> X;
		vector<UL> buf(X);
		UL ans = 0;
		rep(i, Q) {
			UL q; cin >> q; q %= X;
			buf[q]++;
			while (buf[ans % X] >= (ans / X) + 1) ans++;
			cout << ans << endl;
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