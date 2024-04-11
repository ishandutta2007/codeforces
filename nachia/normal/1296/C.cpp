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
		map<pair<int, int>, UL> s;
		pair<UL, UL> ans = { 0, 0 }; UL l = 10000000;
		s[{ 0, 0 }] = 1;
		pair<UL, UL> p = { 0, 0 };
		for (UL i = 1; i <= N; i++) {
			char c; cin >> c;
			if (c == 'L') p.first--;
			if (c == 'R') p.first++;
			if (c == 'U') p.second++;
			if (c == 'D') p.second--;
			auto itr = s.find(p);
			if (itr != s.end()) {
				if (l > i - itr->second) {
					l = i - itr->second;
					ans = { itr->second, i };
				}
			}
			s[p] = i + 1;
		}
		if (l == 10000000) cout << -1 << endl;
		else cout << ans.first << " " << ans.second << endl;
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