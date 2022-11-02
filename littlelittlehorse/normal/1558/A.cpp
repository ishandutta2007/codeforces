#include <bits/stdc++.h>

using namespace std;

int test, n, m, c[200001];

int main() {
	scanf("%d", &test);
	for (; test--; ) {
		int cnt = 0;
		scanf("%d%d", &n, &m);
		int a = (n + m + 1) / 2, b = n + m - a;
		for (int i = 0; i <= a && i <= n; i++) {
			int j = n - i, k = a - i, l = m - k;
			if (k >= 0 && k <= m)
				c[++cnt] = j + k;
		}
		swap(a, b);
		for (int i = 0; i <= a && i <= n; i++) {
			int j = n - i, k = a - i, l = m - k;
			if (k >= 0 && k <= m)
				c[++cnt] = j + k;
		}
		sort(c + 1, c + cnt + 1);
		int ans = 0;
		for (int i = 1; i <= cnt; i++)
			if (i == 1 || c[i] != c[i - 1])
				++ans;
		printf("%d\n", ans);
		for (int i = 1; i <= cnt; i++)
			if (i == 1 || c[i] != c[i - 1])
				printf("%d ", c[i]);
		printf("\n");
	}
}