/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;
int _c = 0;
template <class _T> inline void read(_T &_a) {
	_a = 0; bool _f = 0;
	while (_c < '0' || _c > '9') _f |= _c == '-', _c = getchar();
	while (_c >= '0' && _c <= '9') _a = _a * 10 + _c - '0', _c = getchar();
	if (_f) _a = -_a;
}

typedef long long LL;
typedef double LD;
#define N 55
#define M 505

struct Edge {
	int u, v, w;
	void re() {
		read(u); read(v); read(w);
	}
} E[M];

struct edge {
	int next, to, f;	
} e[M * 16];

int n, m, K, head[N], ecnt;

void add(int u, int v, int f) {
	e[++ecnt].to = v; e[ecnt].next = head[u]; e[ecnt].f = f; head[u] = ecnt;
	e[++ecnt].to = u; e[ecnt].next = head[v]; e[ecnt].f = 0; head[v] = ecnt;
}

int cur[N], tag[N];
queue <int> q;

bool bfs() {
	memset(tag, 0, sizeof(tag));
	tag[1] = 1; q.push(1);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int now = head[x]; now; now = e[now].next) {
			if (e[now].f && !tag[e[now].to]) {
				tag[e[now].to] = tag[x] + 1;
				q.push(e[now].to);
			}
		}
	}
	return !!tag[n];
}

int dfs(int x, int flow) {
	if (x == n) return flow;
	int lft = flow;
	for (int &now = cur[x]; now; now = e[now].next) {
		if (e[now].f && tag[e[now].to] > tag[x]) {
			int ret = dfs(e[now].to, min(lft, e[now].f));
			if (ret) {
				lft -= ret;
				e[now].f -= ret, e[now ^ 1].f += ret;
				if (!lft) return flow;
			}
		}
	}
	return flow - lft;
}

bool dinic() {
	int ret = 0;
	while (ret < K && bfs()) {
		for (int i = 1; i <= n; i++) cur[i] = head[i];
		ret += dfs(1, K);
	}
	return ret >= K;
}

bool check(LD mid) {
	memset(head, 0, sizeof(head)); ecnt = 1;
	for (int i = 1; i <= M; i++) {
		add(E[i].u, E[i].v, int(min(E[i].w / mid, LD(K + 1))));
	}
	return dinic();
}

int main() {
	read(n); read(m); read(K);
	LD l = 0, r = 0;
	for (int i = 1; i <= m; i++) E[i].re(), r = max(r, LD(E[i].w));
	while (r - l > (1e-6 / K)) {
		LD mid = (l + r) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}
	printf("%.7lf\n", (l + r) / 2 * K);
	return 0;
}