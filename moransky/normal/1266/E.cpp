#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

typedef long long LL;

const int N = 2e5 + 5;

int n, a[N], q;

LL ans;

map<int, int> c[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i), ans += a[i];
	scanf("%d", &q);
	while (q--) {
		int u, s, t; scanf("%d%d%d", &s, &t, &u);
		if (c[s].count(t)) {
			a[c[s][t]]++;
			if (a[c[s][t]] > 0) ans++;
		}
		c[s][t] = u;
		a[u]--;
		if (a[u] >= 0) ans--;
		printf("%lld\n", ans);
	}
	return 0;
}