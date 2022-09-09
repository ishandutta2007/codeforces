#include<bits/stdc++.h>
using namespace std;

const int N = 200000 + 10;

struct Edge {
	int u, v, next;
}G[N << 1];

int g[N], head[N];
bool used[N];
int n, m;
bool ok = 1;
int tot = 0, ans = 0;

inline void addedge(int u, int v) {
	G[++tot] = (Edge) {u, v, head[u]}, head[u] = tot;
	G[++tot] = (Edge) {v, u, head[v]}, head[v] = tot;
	g[u]++, g[v]++;
}
void dfs(int u) {
	for(int i = head[u]; i; i = G[i].next) {
		int v = G[i].v;
		if(used[v] == 1) continue;
		if(g[v] != 2) ok = 0;
		used[v] = 1;
		dfs(v);
	}
}
inline int read() {
	int f = 0, fu = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') fu = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		f = (f << 3) + (f << 1) + c - 48;
		c = getchar();
	}
	return f * fu;
}

int main() {
	n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		int a = read(), b = read();
		addedge(a, b);
	}
	for(int i = 1; i <= n; i++) {
		if(g[i] == 2 && used[i] == 0) {
			used[i] = 1;
			ok = 1;
			dfs(i);
			if(ok) ans++;
		}
	}
	printf("%d", ans);
	return 0;
}