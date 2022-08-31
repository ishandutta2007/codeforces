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

vector<int> adj[N];
deque<int> q;
int a[N], b[N], cnt[N], deg[N], dis[N];
int T, n;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		int maxn = 0;
		for (int i = 1; i <= n + 1; i++) cnt[i] = 0, dis[i] = 1e9;
		for (int i = 1; i <= n; i++) adj[i].clear(), deg[i] = 0;
		for (int i = 1; i <= n; i++) a[i] = read(), ++cnt[a[i]], maxn = max(maxn, cnt[a[i]]);
		for (int i = 1; i <= n; i++) b[i] = read();
		int id = 0, cntt = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt[i] == maxn) {
				id = i;
				++cntt;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (a[i] == id || b[i] == id) continue;
			adj[a[i]].push_back(b[i]);
			++deg[b[i]];
		}
		queue<int> qq;
		for (int i = 1; i <= n; i++) {
			if (!deg[i]) {
				qq.push(i);
			}
		}
		while (!qq.empty()) {
			int u = qq.front();
			qq.pop();
			for (auto v: adj[u]) {
				--deg[v];
				if (!deg[v]) qq.push(v);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (deg[i]) {
				ans = 1;
			}
		}
		if (ans == 1) {
			printf("WA\n");
			continue;
		}
		for (int i = 1; i <= n; i++) {
			if (a[i] == id || b[i] == id) {
				int v = (b[i] == id ? n + 1 : b[i]);
				adj[a[i]].push_back(v);
			}
		}
		dis[id] = 0;
		q.push_front(id);
		while (!q.empty()) {
			int u = q.front();
			q.pop_front();
			// fprintf(stderr, "u = %d, dis[u] = %d\n", u, dis[u]);
			for (auto v: adj[u]) {
				// fprintf(stderr, "u = %d, v = %d\n", u, v);
				if (cnt[v] == maxn) {
					if (dis[v] > dis[u] + 1) {
						dis[v] = dis[u] + 1;
						q.push_back(v);
					}
				} else {
					if (dis[v] > dis[u]) {
						dis[v] = dis[u];
						q.push_front(v);
					}
				}
			}
		}
		if (dis[n + 1] == cntt - 1) {
			printf("AC\n");
		} else {
			printf("WA\n");
		}
	}
}