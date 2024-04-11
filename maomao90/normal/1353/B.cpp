#include <bits/stdc++.h>
using namespace std;

int t;
int n, k;
int a[35], b[35];
int ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		for (int i = 0; i < n; i++) scanf("%d", &b[i]);
		sort(a, a + n);
		sort(b, b + n, greater<int>());
		for (int i = 0; i < min(n, k); i++) {
			if (b[i] > a[i]) swap(a[i], b[i]);
		}
		ans = 0;
		for (int i = 0; i < n; i++) ans += a[i];
		printf("%d\n", ans);
	}
	return 0;
}