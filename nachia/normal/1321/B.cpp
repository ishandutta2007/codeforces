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
		vector<pair<int, int>> B(N);
		rep(i, N) {
			UL b; cin >> b;
			B[i] = { b - i, b };
		}
		sort(B.begin(), B.end());
		LL ans = 0;
		LL S = 0;
		int p = -100000000;
		rep(i, N) {
			if (p != B[i].first) {
				p = B[i].first;
				S = 0;
			}
			S += B[i].second;
			ans = max(ans, S);
		}
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