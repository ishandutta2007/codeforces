#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Loop() {
		string S, T; cin >> S >> T;
		set<UL> nx[256];
		rep(i, S.size()) { nx[S[i]].insert(i); }
		UL p = S.size(), cy = 0;
		rep(i, T.size()) {
			char c = T[i];
			if (nx[c].empty()) { cout << -1 << endl; return; }
			auto itr = nx[c].upper_bound(p);
			if (nx[c].end() == itr) { itr = nx[c].begin(); cy++; }
			p = *itr;
		}
		cout << cy << endl;
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