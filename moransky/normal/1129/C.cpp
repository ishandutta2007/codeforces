// Skyqwq
#include <iostream>
#include <cstdio>
#include <cstring>

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

const int N = 3005, S = N * N, P = 1e9 + 7;

int n, a[N], tr[S][2], pos[S], idx = 1, f[S], ans[N];

void inline add(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}

void dfs(int p, int u, int v, int s) {
	if (!p) return;
	if (u == 5 && (s == 3 || s == 5 || s == 14 || s == 15)) return;
	if (u > 1) add(f[p], v);
	if (u < 5) {
		dfs(tr[p][0], u + 1, v, s * 2);
		dfs(tr[p][1], u + 1, v, s * 2 + 1);
	} 
}

int main() {
	memset(pos, 0x3f, sizeof pos);
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) {
		int p = 1;
		for (int j = i; j <= n; j++) {
			int ch = a[j];
			if (!tr[p][ch]) tr[p][ch] = ++idx;
			p = tr[p][ch];
			chkMin(pos[p], j);
		}
	}
	f[1] = 1;
	for (int i = 1; i <= idx; i++) {
		dfs(i, 1, f[i], 0);
	}
	for (int i = 2; i <= idx; i++) add(ans[pos[i]], f[i]);
	for (int i = 1; i <= n; i++) add(ans[i], ans[i - 1]), printf("%d\n", ans[i]);
	return 0;
}