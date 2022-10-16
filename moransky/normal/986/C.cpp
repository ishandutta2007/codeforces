// Skyqwq
#include <iostream>
#include <cstdio>

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

const int N = 22, M = (1 << N) + 1;

int n, m, a[M], S, f[M], b[M], sz[M];

bool st[M], vis[M];

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}

void inline merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (sz[x] > sz[y]) swap(x, y);
	sz[y] += sz[x], f[x] = y;
}

int main() {
	read(n), read(m);
	S = (1 << n) - 1;
	for (int i = 1; i <= m; i++) f[i] = i, sz[i] = 1;
	for (int i = 1; i <= m; i++) read(a[i]), vis[a[i]] = 1, st[a[i] ^ S] = 1, b[a[i]] = i;
	for (int i = S; ~i; i--) {
		for (int j = 0; j < n; j++) {
			if (i >> j & 1) {
				st[i ^ (1 << j)] |= st[i];
			}
		}
	}
	for (int i = 0; i <= S; i++) {
		if (!b[i]) continue;
		for (int j = 0; j < n; j++) {
			if (i >> j & 1) continue;
			int t = i | (1 << j);
			if (st[t]) {
				if (!b[t]) b[t] = b[i];
				else merge(b[t], b[i]);
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		if (b[a[i] ^ S]) {
			merge(i, b[a[i] ^ S]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; i++)
		if (find(i) == i) ans++;
	printf("%d\n", ans);
	return 0;
}