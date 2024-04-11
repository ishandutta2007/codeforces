// LUOGU_RID: 93300863
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;
#define fir first
#define sec second

const int maxn = 1e6 + 10;
const db eps = 1e-9;
typedef pair <db, db> pdd;
int n, a, b, p[maxn], q[maxn];
void work() {
	scanf("%d%d%d", &n, &a, &b);
	pdd lpos, rpos; lpos = rpos = pdd(a, b);
	multiset <pdd> s;
	for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
	for (int i = 1; i <= n; ++i) scanf("%d", &q[i]);
	if (a + b == 0) {
		for (int i = 1; i <= n; ++i) printf("0\n");
		return;
	}
	for (int i = 1; i <= n; ++i) {
		lpos.fir -= p[i], lpos.sec += q[i], rpos.fir += p[i], rpos.sec -= q[i];
		s.insert({db(q[i]) / p[i], p[i] * 2});
		while (!s.empty() && lpos.fir < -eps) {
			pdd t = *s.begin(); s.erase(s.begin());
			db d = lpos.fir + t.sec;
			if (d > 0) s.insert({t.fir, d}), t.sec -= d;
			lpos.fir += t.sec, lpos.sec -= t.fir * t.sec;
		}
		while (!s.empty() && rpos.sec < -eps) {
			pdd t = *--s.end(); s.erase(--s.end());
			db d = rpos.sec / t.fir + t.sec;
			if (d > 0) s.insert({t.fir, d}), t.sec -= d;
			rpos.fir -= t.sec, rpos.sec += t.fir * t.sec;
		}
		printf("%.9Lf\n", rpos.fir);
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) work();
	return 0;
}