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

vector<pii> adj[N];
vector<int> edg[N];
queue<int> q;
int vis[N], deg[N], dir[N], pos[N];
int n, m, now;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	n = read();
	m = read();
	rep(i, 1, m) {
		int opt = read(), u = read(), v = read();
		adj[u].emplace_back(v, opt - 1);
		adj[v].emplace_back(u, opt - 1);
	}
	rep(i, 1, n) {
		if (vis[i]) continue;
		vector<int> seq;
		vis[i] = 1;
		q.push(i);
		dir[i] = 0;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			seq.push_back(u);
			for (auto v: adj[u]) {
				if (!vis[v.first]) {
					vis[v.first] = 1;
					dir[v.first] = dir[u] ^ 1;
					q.push(v.first);
				}
			}
		}
		for (auto u: seq) {
			for (auto i: adj[u]) {
				if (dir[u] == dir[i.first]) {
					printf("NO\n");
					return 0;
				}
				if (dir[u] ^ i.second) {
					edg[u].push_back(i.first);
					++deg[i.first];
				}
			}
		}
		int cnt = (int)seq.size();
		for (auto u: seq) {
			if (!deg[u]) {
				q.push(u);
			}
		}
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			pos[u] = now;
			--now;
			--cnt;
			for (auto v: edg[u]) {
				--deg[v];
				if (!deg[v]) q.push(v);
			}
		}
		if (cnt) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	rep(i, 1, n) {
		printf("%c %d\n", dir[i] ? 'R' : 'L', pos[i]);
	}
}