// Skyqwq
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 1e5 + 5;

int n, d, m, t1, t2;
LL a[N], b[N];

int main() {
	scanf("%d%d%d", &n, &d, &m); ++d;
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		if (x > m) b[++t2] = x;
		else a[++t1] = x;
	}
	sort(a + 1, a + 1 + t1, greater<LL>() );
	sort(b + 1, b + 1 + t2, greater<LL>() );
	for (int i = 1; i <= n; i++) a[i] += a[i - 1];
	for (int i = 1; i <= n; i++) b[i] += b[i - 1];
	LL ans = a[t1];
	for (int i = 1; (i - 1) * d + 1 <= n && i <= t2; i++) {
		ans = max(ans, b[i] + a[n - ((i - 1) * d + 1)]);
	}
	printf("%lld\n", ans);
	return 0;
}