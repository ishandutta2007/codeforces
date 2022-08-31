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

const int N = 1e5 + 5;

vector<pii> adj[N];
int f[30][N], can[30][N];
int n, m, q;

int find(int id, int x) {
	return f[id][x] == x ? x : f[id][x] = find(id, f[id][x]);
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	m = read();
	for (int i = 1; i <= m; i++) {
		int u = read(), v = read(), w = read();
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	for (int b = 0; b < 30; b++) {
		for (int i = 1; i <= n; i++) f[b][i] = i;
		for (int u = 1; u <= n; u++) {
			for (auto v: adj[u]) {
				if ((v.second >> b) & 1) {
					f[b][find(b, u)] = find(b, v.first);
				}
			}
		}
		if (b != 0) {
			for (int u = 1; u <= n; u++) {
				for (auto v: adj[u]) {
					if (!(v.second & 1)) {
						can[b][find(b, u)] = 1;
					}
				}
			}
		}
	}
	q = read();
	while (q--) {
		int u = read(), v = read(), ans = 2;
		for (int i = 0; i < 30; i++) {
			if (find(i, u) == find(i, v)) {
				ans = 0;
				break;
			}
		}
		if (ans == 2) {
			for (int i = 1; i < 30; i++) {
				if (can[i][find(i, u)]) {
					ans = 1;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
}