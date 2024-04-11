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
		UL N; cin >> N;
		map<string, UL> G;
		rep(i, N) {
			string S; cin >> S;
			auto p = G.find(S);
			if (p == G.end()) {
				G.insert({ S, 1 });
				cout << "OK" << endl;
			}
			else {
				cout << S << p->second << endl;
				p->second++;
			}
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