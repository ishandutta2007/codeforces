#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 105;

int n, d, a[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &d);
		int ans = 0;
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		ans = a[1];
		for (int i = 2; i <= n; i++) {
			int t = i - 1;
			int o = min(a[i], d / t);
			ans += o;
			d -= o * t;
		}
		printf("%d\n", ans);
	}
	return 0;
}