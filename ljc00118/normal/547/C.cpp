#include <bits/stdc++.h>
#define mid (l + r >> 1)
using namespace std;
const int N = 500005;
bool p[N + 10];
int n, q, x, a[N], mu[N], pr[N], flag[N];
long long k, f[N], ans;
void init() {
	mu[1] = 1;
	for (int i = 2; i <= N; ++i) {
		if (!p[i])
			pr[++pr[0]] = i, mu[i] = -1;
		for (int j = 1; j <= pr[0] && i * pr[j] <= N; ++j) {
			p[i * pr[j]] = 1;
			if (i % pr[j] == 0) {
				mu[i * pr[j]] = 0;
				break;
			}
			mu[i * pr[j]] = -mu[i];
		}
	}
}
void modify(int n, int opt) {
	for (int i = 1; i * i <= n; ++i)
		if (n % i == 0) {
			ans -= mu[i] * f[i] * (f[i] - 1) / 2;
			f[i] += opt;
			ans += mu[i] * f[i] * (f[i] - 1) / 2;
			if (n / i == i) continue;
			ans -= mu[n / i] * f[n / i] * (f[n / i] - 1) / 2;
			f[n / i] += opt;
			ans += mu[n / i] * f[n / i] * (f[n / i] - 1) / 2;
		}
}
int main() {
	init();
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	memset(flag, -1, sizeof flag);
	while (q--) {
		scanf("%d", &x);
		flag[x] = -flag[x];
		modify(a[x], flag[x]);
		printf("%lld\n", ans);
	}
	return 0;
}