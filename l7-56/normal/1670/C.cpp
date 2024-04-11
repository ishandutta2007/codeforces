#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 1e5 + 10, mod = 1e9 + 7;
int n, a[maxn], b[maxn], d[maxn], pos[maxn], vis[maxn], ans;
void work() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), pos[a[i]] = i, vis[i] = 0;
	for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
	for (int i = 1; i <= n; ++i) scanf("%d", &d[i]);
	ans = 1;
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		int j = i, res = 2, len = 0;
		do {
			vis[j] = 1;
			if (d[j]) res = 1;
			j = pos[b[j]];
			++len;
		} while (j != i);
		if (len == 1) res = 1;
		ans = 1ll * ans * res % mod;
	}
	printf("%d\n", ans);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}