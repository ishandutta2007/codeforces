#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct V {
	UL l;
	UL r;
	bool operator<(const V& ra) const {
		auto L = make_pair(r - l, ~l);
		auto R = make_pair(ra.r - ra.l, ~ra.l);
		return L < R;
	}
};

struct Problem {
public:

	UL ans[200000];

	void Solve() {
		UL T; scanf("%d", &T);
		while (T--) {
			UL N; cin >> N;
			priority_queue<V> Q;
			Q.push({ 0, N });
			UL i = 0;
			while (Q.size()) {
				V p = Q.top(); Q.pop();
				if (p.l == p.r) continue;
				i++;
				UL m = (p.l + p.r - 1) >> 1;
				ans[m] = i;
				Q.push({ p.l, m });
				Q.push({ m + 1, p.r });
			}
			rep(i, N) {
				if (i) printf(" ");
				printf("%d", ans[i]);
			} printf("\n");
		}
	}
};

int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}