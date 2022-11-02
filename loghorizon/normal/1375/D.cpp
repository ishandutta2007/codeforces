#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1005;

int n, a[N], ans, c[N * 2], cnt[2 * N];

bool vis[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		while (true) {
			for (int i = 0; i <= n; i++) {
				cnt[i] = 0;
			}
			//for (int i = 1; i <= n; i++) printf("%d", a[i]);
			//puts("");
			for (int i = 1; i <= n; i++) cnt[a[i]]++;
			int s = 0;
			while (cnt[s]) s++;
			if (s == n) break;
			a[s + 1] = s;
			c[++ans] = s + 1;
		}
		for (int i = 0; i <= n; i++) vis[i] = false;
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				if (a[i] == i - 1) {
					vis[i] = true;
					continue;
				}
				int p = i;
				while (!vis[p]) {
					vis[p] = true;
					c[++ans] = p;
					p = a[p] + 1;
				}
				c[++ans] = i;
			}
		}
		printf("%d\n", ans);
		for (int i = 1; i <= ans; i++)
			printf("%d ", c[i]);
		puts("");
	}	
	return 0;
}