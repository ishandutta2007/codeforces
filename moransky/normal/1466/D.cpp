#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 1e5 + 5;

LL ans;

int n, d[N];

struct E{
	int v, id;
	bool operator < (const E &b) const {
		return v > b.v;
	}
} e[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n); ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &e[i].v); e[i].id = i;
			d[i] = 0; ans += e[i].v;
		}
		sort(e + 1, e + 1 + n);
		for (int i = 1; i < n; i++) {
			int u, v; scanf("%d%d", &u, &v);
			d[u]++, d[v]++;
		}
		int cnt = n - 2;
		printf("%lld ", ans);
		for (int i = 1; i <= n; i++) {
			int p = e[i].id;
			int t = min(cnt, d[p] - 1);
			for (int j = 0; j < t; j++)
				ans += e[i].v, printf("%lld ", ans);
			cnt -= t;
		}
		puts("");
	}	
	return 0;
}