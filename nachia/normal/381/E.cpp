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
		string S; cin >> S;
		T t(S.size());
		UL N; cin >> N;
		vector<pair<pair<UL, UL>, UL>> Q(N);
		rep(i, N) {
			cin >> Q[i].first.second >> Q[i].first.first;
			Q[i].second = i;
		}
		sort(Q.begin(), Q.end());

		stack<UL> lp;
		vector<UL> P(S.size(), -1);
		rep(i, S.size()) {
			if (S[i] == '(') lp.push(i);
			else if(lp.size()) {
				UL p = lp.top(); lp.pop();
				P[i] = p;
			}
		}

		vector<UL> ans(N);
		UL p = 0;
		rep(i, N) {
			UL l = Q[i].first.second, r = Q[i].first.first;
			l--; r--;
			for (; p < r + 1; p++) {
				if (P[p] != -1) {
					t.add(P[p], 1);
				}
			}
			ans[Q[i].second] = t.query(l, r + 1) * 2;
		}
		rep(i, N) cout << ans[i] << endl;
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