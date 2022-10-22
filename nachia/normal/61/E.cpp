#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

template<class Ty>
using passive_queue = priority_queue<Ty, vector<Ty>, greater<Ty>>;

struct RSQ {
	UL N; vector<ULL> V;
	RSQ(UL n) {
		N = 1; while (N < n) N *= 2;
		V.assign(N * 2 - 1, 0);
	}
	void add(UL p, ULL v) {
		UL i = p + N - 1; V[i] += v;
		while (i != 0) { i = (i - 1) >> 1; V[i] += v; }
	}
	ULL sum(UL l, UL r, UL a = -1, UL b = -1, UL i = -1) {
		if (i == -1) { a = 0; b = N; i = 0; }
		if (l <= a && b <= r) { return V[i]; }
		if (r <= a || b <= l) { return 0; }
		return sum(l, r, a, (a + b) >> 1, (i << 1) + 1) +
			sum(l, r, (a + b) >> 1, b, (i << 1) + 2);
	}
};

struct Problem {

	void Solve() {
		UL N; cin >> N;
		vector<pair<UL, UL>> A(N); rep(i, N) { cin >> A[i].first; A[i].second = i; }
		RSQ G(N);
		RSQ H(N);
		sort(A.rbegin(), A.rend());
		ULL ans = 0;
		rep(i, N) {
			UL v = A[i].second;
			ans += H.sum(0, v);
			H.add(v, G.sum(0, v));
			G.add(v, 1);
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