#include <bits/stdc++.h>
using namespace std;

#define N 101111

int n;
long long a[N];
int g[227][227], h[227][227];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
		if (a[i] == 0) i--, n--;
	}
	if (n > 226) return puts("3"), 0;
	memset(g, 0x3f, sizeof g);
	memset(h, 0x3f, sizeof h);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) if (i != j && (a[i] & a[j])) {
			h[i][j] = g[i][j] = 1;
		}
	}
	for (int i = 1; i <= n; i++) h[i][i] = 0;
	int ans = 0x3f3f3f3f;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i < k; i++)
			for (int j = 1; j < k; j++) if (i != j) {
				ans = min((long long)ans, (long long)h[i][j] + g[i][k] + g[j][k]);
			}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				h[i][j] = min(h[i][j], h[i][k] + h[k][j]);
			}
	}
	printf("%d\n", ans > n ? -1 : ans);
}