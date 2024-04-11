#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 100005;

int n, p[N], f[N], sz[N], loc[N], dat[N*4];

bool vis[N];

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}

void inline merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	f[x] = y, sz[y] += sz[x];
}

void inline pushup(int p) {
	dat[p] = max(dat[p << 1], dat[p << 1 | 1]);
}

void build(int p, int l, int r) {
	dat[p] = 0;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
}

void change(int p, int l, int r, int x, int k) {
	if (l == r) {
		dat[p] = k;
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) change(p << 1, l, mid, x, k);
	else change(p << 1 | 1, mid + 1, r, x, k);
	pushup(p);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int mx = 0;
		scanf("%d", &n);
		bool ok = true;
		for (int i = 1; i <= n; i++) scanf("%d", p + i), loc[p[i]] = i, f[i] = i, sz[i] = 1, vis[i] = false;
		f[n + 1] = n + 1;
		vis[n + 1] = false;
		build(1, 1, n);
		for (int i = 1; i <= n; i++) {
			int x = loc[i], d = 0;
			if (vis[x - 1]) d = sz[find(x - 1)];
			mx = dat[1];
			if (d < mx) {
				ok = false;
				break;
			}

			vis[x] = true;
			change(1, 1, n, x, 0);
			if (vis[x + 1]) merge(x, x + 1);
			if (vis[x - 1]) merge(x - 1, x);
			if (find(x) + 1 <= n) change(1, 1, n, find(x) + 1, sz[find(x)]);
		}
		puts(ok ? "Yes" : "No");
	}
	return 0;
}