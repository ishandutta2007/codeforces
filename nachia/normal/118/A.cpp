#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		string S; cin >> S;
		rep(i, S.size()) {
			if ('A' <= S[i] && S[i] <= 'Z') S[i] = (S[i] - 'A' + 'a');
			if (S[i] == 'a' || S[i] == 'o' || S[i] == 'i'
				|| S[i] == 'e' || S[i] == 'u' || S[i] == 'y');
			else cout << '.' << S[i];
		}
		cout << endl;
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