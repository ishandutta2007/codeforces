#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;
const int M = 100 + 10;

struct Edge {
	int u, v, next;
}G[N << 1];

int f[N][M];
int a[N], head[N];
int n, m, k, s; 
int tot = 0;

inline void addedge(int u, int v) {
	G[++tot] = (Edge) {u, v, head[u]}, head[u] = tot;
	G[++tot] = (Edge) {v, u, head[v]}, head[v] = tot;
}

int main() {
	memset(f, 0x3f, sizeof(f));
	cin >> n >> m >> k >> s;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		addedge(a, b);
	}
	for(int i = 1; i <= k; i++) {
		queue <int> q;
		for(int j = 1; j <= n; j++) {
			if(a[j] == i) {
				q.push(j);
				f[j][i] = 0;
			}
		}
		while(!q.empty()) {
			int u = q.front(); q.pop();
			for(int j = head[u]; j; j = G[j].next) {
				int v = G[j].v;
				if(f[v][i] > f[u][i] + 1) {
					f[v][i] = f[u][i] + 1;
					q.push(v);
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		sort(f[i] + 1, f[i] + k + 1);
		int tmp = 0;
		for(int j = 1; j <= s; j++) tmp += f[i][j];
		printf("%d ", tmp);
	}
	return 0;
}