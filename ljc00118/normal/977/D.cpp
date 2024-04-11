#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100 + 10;

struct Edge {
	int u, v, next;
}G[N * N];
LL a[N], opt[N];
int used[N], head[N];
int n;
int tot = 0;

inline void addedge(int u, int v) {
	G[++tot] = (Edge) {u, v, head[u]}, head[u] = tot;
}
void dfs(int u, int from) {
	if(u > n) {
		for(int i = 1; i <= n; i++) printf("%lld ", opt[i]);
		exit(0);
	}
	for(int i = head[from]; i; i = G[i].next) {
		int v = G[i].v;
		if(!used[v]) {
			opt[u] = a[v];
			used[v] = 1;
			dfs(u + 1, v);
			used[v] = 0;
		}
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(a[i] == a[j] * 3) addedge(i, j);
			if(a[i] * 2 == a[j]) addedge(i, j);
		}
	}
	for(int i = 1; i <= n; i++) {
		opt[1] = a[i];
		used[i] = 1;
		dfs(2, i);
		used[i] = 0;
	}
	return 0;
}