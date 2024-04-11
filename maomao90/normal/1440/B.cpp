#include <bits/stdc++.h>
using namespace std;

int t;
int n, k;
int a[1000005];
long long ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n * k; i++) scanf("%d", &a[i]);
		ans = 0;
		for (int i = 1; i <= k; i++) {
			int step = n / 2 + 1;
			ans += a[n * k - step * i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}