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
		deque<UL> Q;
		bool used[26] = {};
		UL p = 0;
		Q.push_back(S[0]); used[S[0] - 'a'] = true;
		for (UL i = 1; i < S.size(); i++) {
			if (used[S[i] - 'a']) {
				if (p != 0) if (Q[p - 1] == S[i]) { p--; continue; }
				if (p != Q.size() - 1) if (Q[p + 1] == S[i]) { p++; continue; }
				cout << "NO" << endl; return;
			}
			else {
				if (p == 0) { Q.push_front(S[i]); used[S[i] - 'a'] = true; continue; }
				if (p == Q.size() - 1) {
					Q.push_back(S[i]); p++;
					used[S[i] - 'a'] = true; continue;
				}
				cout << "NO" << endl; return;
			}
		}
		rep(i, 26) {
			if (!used[i]) Q.push_back(i + 'a');
		}
		cout << "YES" << endl;
		rep(i, Q.size()) {
			cout << (char)Q[i];
		}
		cout << endl;
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