#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, n, a[2000001], f[2000001];
const int p = 1000000007;

int main() {
	scanf("%d", &test);
	for (; test--; ) {
		scanf("%d", &n);
		int ans = 1 << 30;
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = n; i; --i)
			if (i == n || a[i] != a[i + 1])
				f[i] = i;
			else
				f[i] = f[i + 1];
		for (int i = 1; i < n; i++) {
			int tot = f[i] + 1 - i + 1, cur = f[i] + 1;
			if (cur == n + 1)
				--tot;
			for (; cur <= n;) {
				int l = cur, r = n + 1, m = (l + r) >> 1;
				for (; l + 1 < r; m = (l + r) >> 1)
					if (a[m] < 2 * a[cur] - a[i])
						l = m;
					else
						r = m;
				if (r == n + 1)
					break;
				++tot; cur = r;
			}
			ans = min(ans, n - tot);
		}
		printf("%d\n", ans);
	}
}