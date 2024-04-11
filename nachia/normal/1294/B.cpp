#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Loop() {
		UL N; cin >> N;
		vector<pair<UL, UL>> P(N);
		rep(i, N) cin >> P[i].first >> P[i].second;
		string ans;
		sort(P.begin(), P.end());
		UL x = 0, y = 0;
		rep(i, N) {
			if (P[i].second < y) { cout << "NO" << endl; return; }
			for (UL j = x; j < P[i].first; j++) ans.push_back('R');
			for (UL j = y; j < P[i].second; j++) ans.push_back('U');
			x = P[i].first; y = P[i].second;
		}
		cout << "YES" << endl;
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