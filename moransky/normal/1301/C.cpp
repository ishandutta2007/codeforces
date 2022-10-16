#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
int n, m;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		int t = n - m;
		LL ans = (LL)n * (n + 1) / 2;
		int k = t / (m + 1);
		if (t % (m + 1) == 0) {
			ans -= (LL)(m + 1) * (t / (m + 1)) * (t / (m + 1) + 1) / 2;
		} else {
		    int p = t % (m + 1);
			ans -= (LL)(m + 1 - p) * (t / (m + 1)) * (t / (m + 1) + 1) / 2;
			ans -= (LL)(p) * (t / (m + 1) + 1) * (t / (m + 1) + 2) / 2;
		}
		printf("%lld\n", ans);
	}
	return 0;
}