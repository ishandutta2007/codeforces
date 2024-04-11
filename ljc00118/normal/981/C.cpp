#include<bits/stdc++.h>
#define gc() getchar()

using namespace std;

const int N = 100000 + 10;

struct Edge {
	int u, v, next;
}G[N << 1];

bool used[N];
int head[N], fa[N], g[N];
int s[N], t[N];
int n, mb = -1;
int tot = 0;

inline void addedge(int u, int v) {
	G[++tot] = (Edge) {u, v, head[u]}, head[u] = tot;
	G[++tot] = (Edge) {v, u, head[v]}, head[v] = tot;
	g[u]++, g[v]++;
}

void dfs1(int u) {
	for(int i = head[u]; i; i = G[i].next) {
		int v = G[i].v;
		if(v == fa[u]) continue;
		fa[v] = u;
		dfs1(v);
	}
}
void dfs2(int u, int k) {
	t[k] = u;
	for(int i = head[u]; i; i = G[i].next) {
		int v = G[i].v;
		if(v == fa[u]) continue;
		used[v] = 1;
		dfs2(v, k);
		break;
	}
}
void dfs3(int u, int k) {
	t[k] = u;
	if(used[u] == 1) {
		if(mb == -1) mb = u;
		else if(u != mb) {
			printf("No");
			exit(0);
		}
		return;
	}
	used[u] = 1;
	dfs3(fa[u], k);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		addedge(a, b);
	}
	for(int i = 1; i <= n; i++) {
		if(g[i] == 1) {
			used[i] = 1;
			dfs1(i);
			s[1] = i;
			dfs2(i, 1);
			break;
		}
	}
	int ans = 1;
	for(int i = 1; i <= n; i++) {
		if(i == s[1]) continue;
		if(g[i] != 1) continue;
		if(used[i] == 1) continue;
		s[++ans] = i;
		dfs3(i, ans);
	}
	for(int i = 1; i <= n; i++) {
		if(used[i] == 0) {
			printf("No");
			return 0;
		}
	}
	for(int i = 1; i <= ans; i++) {
		if(s[i] == t[i]) {
			printf("No");
			return 0;
		}
	}
	printf("Yes\n");
	printf("%d\n", ans);
	for(int i = 1; i <= ans; i++) {
		printf("%d %d\n", min(s[i], t[i]), max(s[i], t[i]));
	}
	return 0;
}