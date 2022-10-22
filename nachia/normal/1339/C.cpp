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

	void Loop() {
		UL N; cin >> N;
		vector<LL> A(N); rep(i, N) cin >> A[i];
		LL ans = 0;
		LL buf = -10000000000;
		rep(i, N) {
			if (A[i] >= buf) {
				buf = A[i];
			}
			else {
				ans = max(ans, buf - A[i]);
			}
		}
		UL t = 0;
		while ((1ull << t) <= ans) t++;
		cout << t << endl;
	}

	void Solve() {
		UL Q; cin >> Q;
		rep(i, Q) {
			Loop();
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