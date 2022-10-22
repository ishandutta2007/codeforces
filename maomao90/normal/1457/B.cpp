#include <bits/stdc++.h>
using namespace std;

int t;
int n, k;
int c[100005];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++) scanf("%d", &c[i]);
		int ans = 1000000005;
		for (int i = 1; i <= 100; i++) {
			int cur = 0;
			for (int j = 0; j < n; j++) {
				if (c[j] != i) {
					j += k - 1;
					cur++;
				}
			}
			ans = min(cur, ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}