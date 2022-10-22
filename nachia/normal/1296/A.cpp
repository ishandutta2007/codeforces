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
		bool o = false, e = false;
		bool so = false;
		rep(i, N) {
			UL a; cin >> a;
			if (a % 2) { o = true; so = !so; }
			else e = true;
		}
		if (so) cout << "YES" << endl;
		else if (o && e)cout << "YES" << endl;
		else cout << "NO" << endl;
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