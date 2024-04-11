#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct UF {
	UL N; vector<UL> V;
	void init(UL n) {
		N = n; V.resize(N); rep(i, N) V[i] = i;
	}
	UL root(UL p) {
		if (V[p] == p) return p;
		return V[p] = root(V[p]);
	}
	void unite(UL a, UL b) {
		UL A = root(a), B = root(b);
		V[A] = B;
	}
};

struct Problem {

	void Solve() {
		UL N; cin >> N;
		vector<UL> A(N), B(N);
		rep(i, N) cin >> A[i];
		rep(i, N) cin >> B[i];
		UL a, b; a = b = 0;
		rep(i, N) {
			if (A[i] == B[i])continue;
			if (A[i])a++; else b++;
		}
		if (a == 0) { cout << -1 << endl; return; }
		UL ans = b / a + 1;
		cout << ans << endl;
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