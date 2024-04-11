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
		UL ans = 0;
		UL M = 0;
		while (N != 0) {
			ans += N;
			N += M;
			M = N % 10;
			N /= 10;
		}
		cout << ans << endl;
	}

	void Solve(){
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