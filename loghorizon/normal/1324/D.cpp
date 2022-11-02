#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 200005;

typedef long long LL;
int n, a[N], b[N], d[N];
LL ans = 0;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= n; i++) scanf("%d", b + i);
	for (int i = 1; i <= n; i++) d[i] = b[i] - a[i];
	sort(d + 1, d + 1 + n);
	for (int i = 1; i <= n; i++) {
		int x = a[i] - b[i];
		if (x <= d[1]) continue;
		int l = lower_bound(d + 1, d + 1 + n, x) - 1 - d;
		ans += l;
		if (x > 0) ans--;
	}
	printf("%lld\n", ans / 2);
	return 0;
}