#include <iostream>
#include <cstdio>

using namespace std;

const int N = 3000005;

typedef long long LL;

int h, g, a[N], dep[N], maxDep[N], adj[N], tot;

LL ans;

void inline pushup(int p) {
	maxDep[p] = max(dep[p], a[p << 1] > a[p << 1 | 1] ? maxDep[p << 1] : maxDep[p << 1 | 1]);
}

void del(int p) {
	a[p] = 0;
	if (!a[p << 1] && !a[p << 1 | 1]) { maxDep[p] = 0; return; }
	else if (!a[p << 1]) a[p] = a[p << 1 | 1], del(p << 1 | 1);
	else if (!a[p << 1 | 1]) a[p] = a[p << 1], del(p << 1);
	else {
		int t = a[p << 1] > a[p << 1 | 1] ? p << 1 : p << 1 | 1;
		a[p] = a[t], del(t);
	}
	pushup(p);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		ans = tot = 0;
		scanf("%d%d", &h, &g);
		for (int i = 1; i < (1 << h); i++) {
			scanf("%d", a + i);
			a[i << 1] = a[i << 1 | 1] = 0;
			dep[i] = dep[i >> 1] + 1;
			ans += a[i];
		}
		for (int i = (1 << h) - 1; i; i--) pushup(i);
		for (int i = 1; i < (1 << h); i++) 
			while (a[i] && maxDep[i] > g) {
				ans -= a[i], adj[++tot] = i, del(i);
			}
		printf("%lld\n", ans);
		for (int i = 1; i <= tot; i++) printf("%d " , adj[i]);
		puts("");
	}
	return 0;
}