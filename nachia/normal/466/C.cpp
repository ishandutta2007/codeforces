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
		vector<LL> A(N + 1); rep(i, N) cin >> A[i + 1];
		rep(i, N) A[i + 1] += A[i];
		LL S = A[N]; if (S % 3 != 0) { cout << 0 << endl; return; }
		S /= 3;
		LL D[2] = {};
		for (UL i = 1; i < N; i++) {
			if (A[i] == S * 2) D[1] += D[0];
			if (A[i] == S) D[0]++;
		}
		cout << D[1] << endl;
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