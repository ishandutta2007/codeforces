#include <bits/stdc++.h>
using namespace std;

int n;
int cnt[105];
int m;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &cnt[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		if (x > 1) cnt[x - 1] += y - 1;
		if (x < n) cnt[x + 1] += cnt[x] - y;
		cnt[x] = 0;
	}
	for (int i = 1; i <= n; i++) printf("%d\n", cnt[i]);
	return 0;
}