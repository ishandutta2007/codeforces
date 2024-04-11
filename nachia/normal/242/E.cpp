#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct RXQ {
	UL N;
	UL NN;
	vector<pair<UL, bool>> V;
	void init(UL n) {
		NN = n;
		N = 1; while (N < n) N *= 2;
		V.assign(N * 2 - 1, { 0, false });
	}
	UL sum(UL l, UL r, UL a = -1, UL b = -1, UL i = -1) {
		if (i == -1) { a = 0; b = N; i = 0; }
		if (l <= a && b <= r) { return V[i].first; }
		if (r <= a || b <= l) return 0;
		UL tmp = sum(l, r, a, (a + b) >> 1, (i << 1) + 1);
		tmp += sum(l, r, (a + b) >> 1, b, (i << 1) + 2);
		if (V[i].second) tmp = min(r, b) - max(l, a) - tmp;
		return tmp;
	}
	void flip (UL l, UL r, UL a = -1, UL b = -1, UL i = -1) {
		if (i == -1) { a = 0; b = N; i = 0; }
		if (l <= a && b <= r) {
			V[i].second = !V[i].second;
			V[i].first = b - a - V[i].first;
			return;
		}
		if (r <= a || b <= l) return;
		flip(l, r, a, (a + b) >> 1, (i << 1) + 1);
		flip(l, r, (a + b) >> 1, b, (i << 1) + 2);
		V[i].first = V[(i << 1) + 1].first + V[(i << 1) + 2].first;
		if (V[i].second) V[i].first = min(NN, b) - a - V[i].first;
	}
};

struct Problem {

	void Solve() {
		UL N; cin >> N;
		RXQ BIT[20];
		rep(i, 20) BIT[i].init(N);
		UL BITN = BIT[0].N;
		{
			vector<UL> A(N); rep(i, N) cin >> A[i];
			rep(b, 20) {
				rep(i, N) if (A[i] & (1 << b)) BIT[b].V[BITN - 1 + i].first = 1;
				for(int i = BITN - 2; i >= 0; i--)
					BIT[b].V[i].first =
					BIT[b].V[(i << 1) + 1].first + BIT[b].V[(i << 1) + 2].first;
			}
		}
		UL Q; cin >> Q;
		vector<ULL> ans;
		rep(i, Q) {
			UL c; cin >> c;
			if (c == 1) {
				UL l, r; cin >> l >> r; l--;
				ULL tmp = 0;
				rep(b, 20) {
					tmp <<= 1;
					tmp += BIT[19 - b].sum(l, r);
				}
				ans.push_back(tmp);
			}
			else if (c == 2) {
				UL l, r; cin >> l >> r; l--;
				UL x; cin >> x;
				rep(b, 20) {
					if (x & (1 << b)) {
						BIT[b].flip(l, r);
					}
				}
			}
		}
		rep(i, ans.size()) cout << ans[i] << endl;
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