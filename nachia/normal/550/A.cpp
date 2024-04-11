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

	void Solve() {
		string S; cin >> S;
		vector<UL> A, B;
		rep(i, S.size() - 1) {
			if (S[i] == 'A' && S[i + 1] == 'B') { A.push_back(i); }
			else if (S[i] == 'B' && S[i + 1] == 'A') { B.push_back(i); }
		}
		if (A.empty()) cout << "NO" << endl;
		else if (B.empty()) cout << "NO" << endl;
		else if (A.front() + 1 < B.back()) cout << "YES" << endl;
		else if (B.front() + 1 < A.back()) cout << "YES" << endl;
		else cout << "NO" << endl;
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