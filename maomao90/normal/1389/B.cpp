#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;
int n, k, z;
int a[100005];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &k, &z);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int ans = 0;
		for (int i = 0; i <= z; i++) {
			int cur = 0, mx = 0;
			for (int j = 1; j <= k + 1 - i * 2; j++) {
				cur += a[j];
				if (j + 1 <= n) mx = max(a[j] + a[j + 1], mx);
			}
			ans = max(ans, cur + mx * i);
		}
		printf("%d\n", ans);
		for (int i = 1; i <= n; i++) a[i] = 0;
	}
	return 0;
}