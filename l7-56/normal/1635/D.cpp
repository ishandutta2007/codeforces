#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 2e5 + 10, mod = 1e9 + 7;
int n,p,a[maxn],fib[maxn],sf[maxn],ans;

void p2(int x) {
	if (!x) return;
	p2(x >> 1);
	printf("%d", x & 1);
}

int main() {
	scanf("%d%d", &n, &p);
	fib[0] = fib[1] = sf[0] = 1; sf[1] = 2;
	for (int i = 2; i <= p; ++i) fib[i] = (fib[i - 1] + fib[i - 2]) % mod, sf[i] = (sf[i - 1] + fib[i]) % mod;
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	set <int> r;
	for (int i = 1; i <= n; ++i) {
		bool flg = 0;
		for (int t = a[i]; t;) {
			if (r.find(t) != r.end()) { flg = 1; break; }
			if (t & 1) t >>= 1;
			else if ((t & 3) == 0) t >>= 2;
			else break;
		}
		if (flg) continue;
		// p2(a[i]);
		// printf("\n%d\n", a[i]);
		int len = 0;
		for (int t = a[i]; t; t >>= 1) ++len;
		if (p < len) continue;
		ans = (ans + sf[p - len]) % mod;
		r.insert(a[i]);
	}
	printf("%d\n", ans);
	return 0;
}