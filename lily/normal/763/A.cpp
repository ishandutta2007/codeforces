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
typedef long double LD;
#define MAXN 100005

struct edge {
	int next, to;
} e[MAXN * 2];

int n;
int c[MAXN], ecnt = 0, head[MAXN];
bool vis[MAXN];

void add(int u, int v) {
	e[++ecnt].to = v; e[ecnt].next = head[u]; head[u] = ecnt;
	e[++ecnt].to = u; e[ecnt].next = head[v]; head[v] = ecnt;
}

int dfs(int x, int fa) {
	int nowc = 0;
	for (int now = head[x]; now; now = e[now].next) {
		if (e[now].to != fa) {
			int ret = dfs(e[now].to, x);
			if (ret) return ret;
			if (nowc && c[e[now].to] != nowc) nowc = -1;
			else nowc = c[e[now].to];
		}
	}
	if (fa == 0) return 0;
	else return (nowc && nowc != c[x]) ? x : 0;
}


int main() {
	read(n);
	for (int i = 1, u, v; i < n; i++) read(u), read(v), add(u, v);
	for (int i = 1; i <= n; i++) read(c[i]); 
	int ret = 0, x = 1, cnt = 0;
	vis[1] = 1;
	while ((ret = dfs(x, 0))) {
		x = ret; cnt++;
		if (vis[x] || cnt > 1000) {x = -1; break;}
		vis[x] = 1;
	}
	if (x == -1) puts("NO");
	else printf("YES\n%d\n", x);
	return 0;
}