#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {
public:

	void Solve() {
		UL t; scanf("%d", &t);
		while (t--) {
			ULL a, b, c, d; scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
			ULL ans = b;
			if (a > b) {
				a -= b;
				if (c <= d) { printf("-1\n"); continue; }
				d = c - d;
				ULL t = (a - 1) / d + 1;
				t *= c;
				ans += t;
			}
			printf("%lld\n", ans);
		}
	}
};

int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}