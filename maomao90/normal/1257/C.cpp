#include <bits/stdc++.h>

using namespace std;

#define INF 1000000005

int T;
int n;
int a[200005];
int cnt[200005];
int ans;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		memset(cnt, 0, sizeof cnt);
		ans = INF;
		int l = 0, r = 0, maxval = 0;
		while (r < n) {
			while (maxval < 2 && r < n) {
				maxval = max(maxval, ++cnt[a[r++]]);
			}
			if (maxval == 2) ans = min(ans, r - l);
			while (maxval == 2) {
                ans = min(ans, r - l);
				if (cnt[a[l++]]-- == 2) {
					maxval = 1;
				}
			}
		}
		if (ans == INF) printf("-1\n");
		else printf("%d\n", ans);
	}
	return 0;
}