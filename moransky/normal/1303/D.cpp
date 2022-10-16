#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int M = 100005, L = 63;
LL n, d[L];
int m, a[M], cnt[L];
int main() {
	d[0] = 1;
	for (int i = 1; i < L; i++) d[i] = d[i - 1] << 1;
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%lld%d", &n, &m);
		memset(cnt, 0, sizeof cnt);
		LL s = 0;
		for (int i = 1; i <= m; i++) {
			scanf("%d", a + i), s += a[i];
			int v = lower_bound(d, d + (L - 1), a[i]) - d;
			cnt[v]++;
		}
		if (s < n) puts("-1");
		else {
			LL ans = 0;
			for (int i = 0; i < L; i++) {
				if (n >> i & 1) {
					if (cnt[i]) cnt[i]--;
					else {
						LL val = 0;
						for (int j = i - 1; ~j; j--) val += (1ll << j) * cnt[j];
						if (val < (1ll << i)) {
							for (int j = i + 1; j < L; j++) {
								if (cnt[j]) {
									cnt[j]--;
									for (int k = j - 1; k >= i; k--)
										cnt[k] ++;
									ans += j - i;
									break;
								}
							}
						} else {
							LL u = (1ll << i);
							for (int j = i - 1; ~j; j--) {
								if ((1ll << j) * cnt[j] > u) {
									cnt[j] -= u / (1ll << j);
									u = 0;
								} else {
									u -= (1ll << j) * cnt[j];
									cnt[j] = 0;
								}
								if (u == 0) break;
							}
						}
					}
				}
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}