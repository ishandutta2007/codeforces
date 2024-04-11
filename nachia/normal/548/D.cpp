#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct T {
	vector<UL> n;
	UL Sz;
	T(UL sz) {
		Sz = 1; while (Sz < sz) Sz <<= 1;
		n.resize(Sz * 2 - 1);
	}
	void upd(UL p, UL v) {
		n[p] += v;
		if (p != 0) upd((p - 1) >> 1, v);
	}
	void add(UL p, UL v) { upd(Sz - 1 + p, v); }
	UL query(UL l, UL r, UL a = -1, UL b = -1, UL p = -1) {
		if (a == -1) { a = 0; b = Sz; p = 0; }
		if (l <= a && b <= r) return n[p];
		if (b <= l || r <= a) return 0;
		return query(l, r, a, (a + b) >> 1, p + p + 1) +
			query(l, r, (a + b) >> 1, b, p + p + 2);
	}
};

struct Problem {

	void Solve() {
		UL N; cin >> N;
		vector<UL> A(N); rep(i, N) cin >> A[i];
		vector<UL> ans(N);

		vector<pair<UL, UL>> Q(N);
		rep(i, N) Q[i] = { A[i], i };
		sort(Q.rbegin(), Q.rend());
		vector<UL> dp(N, 0);
		rep(i, N) {
			UL p = Q[i].second, v = Q[i].first;
			UL l = 1;
			if (p != 0) l += dp[p - 1];
			if (p != N - 1) l += dp[p + 1];
			if (p != 0) dp[p - dp[p - 1]] = l;
			if (p != N - 1) dp[p + dp[p + 1]] = l;
			ans[l - 1] = max(ans[l - 1], v);
		}

		for (UL i = N - 1; i > 0; i--) {
			ans[i - 1] = max(ans[i - 1], ans[i]);
		}
		rep(i, N) {
			if (i) cout << " ";
			cout << ans[i];
		} cout << endl;
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