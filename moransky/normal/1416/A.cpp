#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

const int N = 300005, INF = 2e9;

int n, a[N], cnt[N], loc[N], ans[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i), ans[i] = INF, cnt[i] = loc[i] = 0;
		for (int i = 1; i <= n; i++) {
			cnt[a[i]] = max(cnt[a[i]], i - loc[a[i]]);
			loc[a[i]] = i;
		}
		for (int i = 1; i <= n; i++) {
			if (loc[a[i]]) {
				cnt[a[i]] = max(cnt[a[i]], n - loc[a[i]] + 1);
			}
		}
		for (int i = n; i; i--) {
			if (cnt[i]) {
				ans[cnt[i]] = i;
			}
		}
		ans[0] = INF;
		for (int i = 1; i <= n; i++) {
			ans[i] = min(ans[i - 1], ans[i]);
			printf("%d ", ans[i] == INF ? -1 : ans[i]);
		}
		puts("");
	}	
	return 0;
}