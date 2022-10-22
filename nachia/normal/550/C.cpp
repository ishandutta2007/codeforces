#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

template<class Ty>
using passive_queue = priority_queue<Ty, vector<Ty>, greater<Ty>>;

struct Problem {

	bool dp[1000] = {};

	void Solve() {
		string S; cin >> S;
		UL N = S.size();
		dp[0] = true;
		rep(i, N) if (S[i] == '0') { cout << "YES" << endl << 0 << endl; return; }
		rep(i, N) {
			UL d = S[i] - '0';
			for(UL j = 99; j != -1; j--) if (dp[j]) dp[10 * j + d] = true;
		}
		for (UL i = 8; i < 1000; i += 8) {
			if (dp[i]) {
				cout << "YES" << endl;
				cout << i << endl; return;
			}
		}
		cout << "NO" << endl;
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