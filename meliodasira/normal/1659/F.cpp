#include <bits/stdc++.h>
using namespace std;

template<typename T>
void chmin(T& x, const T& y) {
	if (x > y) x = y;
}
template<typename T>
void chmax(T& x, const T& y) {
	if (x < y) x = y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int, int> pii;
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
#define rep0(i, l, r) for (int i = l; i < r; ++i)
#define gc (c = getchar())
char readc() {
	char c;
	while (isspace(gc))
		;
	return c;
}
int read() {
	char c;
	while (gc < '-')
		;
	if (c == '-') {
		int x = gc - '0';
		while (gc >= '0') x = x * 10 + c - '0';
		return -x;
	}
	int x = c - '0';
	while (gc >= '0') x = x * 10 + c - '0';
	return x;
}
#undef gc

const int N = 2e5 + 5;

int a[N], b[N], vis[N], deg[N];
int T, n, x, cnt;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		x = read();
		for (int i = 1; i <= n; i++) deg[i] = vis[i] = 0;
		for (int i = 1; i < n; i++) {
			int u = read(), v = read();
			++deg[u];
			++deg[v];
		}
		cnt = n;
		int cando = 1;
		for (int i = 1; i <= n; i++) {
			b[i] = read(), cando &= (b[i] == i);
			a[b[i]] = i;
		}
		if (cando) {
			printf("Alice\n");
			continue;
		}
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				--cnt;
				int x = i;
				while (!vis[x]) {
					vis[x] = 1;
					x = a[x];
				}
			}
		}
		int maxn = 0;
		for (int i = 1; i <= n; i++) maxn = max(maxn, deg[i]);
		if (maxn != n - 1) {
			printf("Alice\n");
			continue;
		}
		int u = 0;
		for (int i = 1; i <= n; i++) {
			if (deg[i] == maxn) {
				u = i;
			}
		}
		if (a[u] != u && (x == u || a[x] == u)) {
			printf("Bob\n");
			continue;
		}
		if (cnt == 1) {
			int s = 0, t = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] != i) {
					s = i;
					t = a[i];
					break;
				}
			}
			if (s != x && t != x) {
				printf("Alice\n");
				continue;
			}
		}
		printf("%s\n", (cnt % 2) == (x == u) ? "Alice" : "Bob");
	}
}