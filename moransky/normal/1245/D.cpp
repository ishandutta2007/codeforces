// Skyqwq
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(-x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 2005;

int n, x[N], y[N], c[N], k[N], t, f[N];

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}

struct E{
	int u, v;
	LL w;
	bool operator < (const E b) const {
		return w < b.w;
	}
} e[N * N];

typedef pair<int, int> PII;

vector<int> ans;

vector<PII> d;
 
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(x[i]), read(y[i]);
	for (int i = 1; i <= n; i++) read(c[i]);
	for (int i = 1; i <= n; i++) read(k[i]);
	for (int i = 0; i <= n; i++) f[i] = i;
	for (int i = 1; i <= n; i++) {
		e[++t] = (E) { i, 0, c[i] };
		for (int j = 1; j < i; j++) {
			LL d = abs(x[i] - x[j]) + abs(y[i] - y[j]);
			e[++t] = (E) { i, j, d * (k[i] + k[j]) };
		}
	}
	sort(e + 1, e + 1 + t);
	LL res = 0;
	for (int i = 1; i <= t; i++) {
		int x = e[i].u, y = e[i].v;
		if (find(x) != find(y)) {
			if (y == 0) {
				ans.pb(x);
			} else {
				d.pb(mp(x, y));
			}
			res += e[i].w;
			f[find(x)] = y;
		}
	}
	printf("%lld\n", res);
	printf("%lu\n", ans.size());
	for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
	puts("");
	printf("%lu\n", d.size());
	for (int i = 0; i < d.size(); i++)
		printf("%d %d\n", d[i].fi, d[i].se);
	return 0;
}