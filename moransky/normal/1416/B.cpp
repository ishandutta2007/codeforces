#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

const int N = 10005;

int n, a[N], s, x[N * 3], y[N * 3], z[N * 3], tot;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n); s = 0;
		for (int i = 1; i <= n; i++) scanf("%d", a + i), s += a[i];
		if (s % n) { puts("-1"); continue; }
		s /= n; tot = 0;
		for (int i = 2; i <= n; i++) {
			if (a[i] % i) {
				int k = i - (a[i] % i);
				a[1] -= k, a[i] += k;
				++tot;
				x[tot] = 1, y[tot] = i, z[tot] = k;
			}
			++tot;
			x[tot] = i, y[tot] = 1, z[tot] = a[i] / i;
			//printf("%d %d %d\n", i, 1, a[i] / i);
			a[1] += a[i], a[i] = 0;
		}
		for (int i = 2; i <= n; i++) {
			++tot;
			x[tot] = 1, y[tot] = i, z[tot] = s;
		}
		printf("%d\n", tot);
		for (int i = 1; i <= tot; i++) printf("%d %d %d\n", x[i], y[i], z[i]);
	}	
	return 0;
}