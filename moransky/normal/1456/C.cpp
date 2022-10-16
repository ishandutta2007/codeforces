#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 500005;

int n, K, a[N];

LL suf[N], s[N], ans = -9e18;

int main() {
	scanf("%d%d", &n, &K);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	sort(a + 1, a + 1 + n);
	for (int i = n; i; i--)
		suf[i] = suf[i + 1] + a[i];
	for (int i = n; i; i--)
		s[i] = s[i + 1] + suf[i];
	
	LL sum = 0;
	
	for (int i = 1; i <= n; i++) {
		int t = ((i - 1ll) / (K + 1));
		sum += (LL)a[i] * t;
		ans = max(ans, sum + t * suf[i + 1] + s[i + 1]);
	}
	printf("%lld\n", ans);
	return 0;
}