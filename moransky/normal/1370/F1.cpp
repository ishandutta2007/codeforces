#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 1005;

int n, rt, d, dep[N], ans, p1, p2, c[N], len, maxd;

int head[N], numE = 0;

vector<int> g[N];

char s[10];

struct E{
	int next, v;
} e[N << 1];

void inline add(int u, int v) {
	e[++numE] = (E) { head[u], v };
	head[u] = numE;
}

void dfs(int u, int last) {
	g[dep[u]].push_back(u);
	maxd = max(maxd, dep[u]);
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if (v == last) continue;
		dep[v] = dep[u] + 1;
		dfs(v, u);
	}
}

bool inline check(int x) {
	int p, dis;
	printf("? %d ", (int)g[x].size());
	for (int i = 0; i < g[x].size(); i++) {
		printf("%d ", g[x][i]);
	}
	puts("");
	fflush(stdout);
	scanf("%d%d", &p, &dis);	
	if (dis == d) {
		if (x > ans) ans = x, p1 = p; 
		return true;
	} else return false;
}

void dfs2(int u, int last, int dis) {
	if (dis == d) c[++len] = u;
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if (v == last) continue;
		dfs2(v, u, dis + 1);
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		memset(head, 0, sizeof head);
		scanf("%d", &n); maxd = numE = ans = len = 0;
		for (int i = 0; i < n; i++) g[i].clear();
		for (int i = 1, u, v; i < n; i++) {
			scanf("%d%d", &u, &v);
			add(u, v); add(v, u);
		}
		printf("? %d ", n);
		for (int i = 1; i <= n; i++) printf("%d ", i);
		puts("");
		fflush(stdout);
		scanf("%d%d", &rt, &d);	
		dep[rt] = 0;
		dfs(rt, 0);
		int l = (d & 1) ? d / 2 + 1 : d / 2, r = min(d, maxd);
		if (l == r) check(r);
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (check(mid)) l = mid;
			else r = mid - 1;
		}
		if (ans != r) check(r);
		dfs2(p1, 0, 0);
		printf("? %d ", len);
		for (int i = 1; i <= len; i++)
			printf("%d ", c[i]);
		puts("");
		fflush(stdout);
		scanf("%d%d", &p2, &d);
		printf("! %d %d\n", p1, p2);
		fflush(stdout);
		scanf("%s", s);
	}
	return 0;
}