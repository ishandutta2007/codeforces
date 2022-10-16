#include <cstdio>
#include <iostream>
using namespace std;
const int N = 3505;
int n, m, K, a[N];
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &m, &K);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		K = min(K, m - 1);
		int ans = 0;
		int p = m - 1 - K;
		for (int i = 0; i <= K; i++) {
			int v = 2e9;
			for (int j = 0; j <= p; j++)
				v = min(v, max(a[i + 1 + j], a[n - (K - i) - (p - j)]));
			ans = max(ans, v);
		}
		printf("%d\n", ans);
	}
	return 0;
}