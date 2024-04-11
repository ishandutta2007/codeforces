#include <iostream>
#include <cstdio>

using namespace std;

const int N = 30;

typedef long long LL;

int n, q, b[N], x, c[N];

LL K, res, ans, s;

void inline solve(int i) {
	if (s >= K) ans = min(ans, res + K);
	if (K <= 0 || i == x) return;
	res++;
	if (i == x + 1) K -= min(K, 2ll);
	if (i - 1 >= x && (1 << (i - 1 - x)) <= K) {
		K -= 1 << (i - 1 - x), res += (1 << (i - 1 - x)) - 1;
		s += (1 << (i - 1 - x)) * ((1ll << x) - 1);
	}
	if (K <= 0) return;
	solve(i - 1);
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) scanf("%d", b + i);
	while (q--) {
		int opt; scanf("%d%d", &opt, &x);
		if (opt == 1) {
			int y; scanf("%d", &y);
			b[x] = y;
		} else {
			scanf("%lld", &K);
			s = 0;
			LL now = 0;
			for (int i = 0; i <= x; i++) {
				now += b[i];
				s += ((1ll << i) - 1) * b[i];
			}
			res = 0;
			K = max(0ll, K - now);
			for (int i = x + 1; i < n; i++) {
				if (K <= 0) break;
				int t = 1 << (i - x);
				int a = min((LL)b[i], K / t);
				s += ((1ll << x) - 1) * t * a;
				res += (LL)a * (t - 1);
				K -= (LL)a * t;
				c[i] = a;
			}
			ans = 9e18;
			if (s >= K) ans = res + K;
			for (int i = x + 1; i < n; i++) {
				if (K <= 0) break;
				int d = (1 << (i - x));
				if ((b[i] - c[i]) && K < d) {
					solve(i);
					break;
				}
			}
			if (K > 0) res = 9e18;
			if (K > 0 && ans == 9e18) puts("-1");
			else printf("%lld\n", min(ans, res));
		}
	}
	return 0;
}