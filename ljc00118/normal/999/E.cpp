#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
	while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
	f *= fu;
}

const int N = 5000 + 5;

struct Edge {
	int u, v, next;
}G[N];

int low[N], dfn[N], in[N], col[N], st[N], inst[N], head[N], x[N], y[N];
int n, m, s, len, tot, cnt, Index;

inline void addedge(int u, int v) {
	G[++tot] = (Edge) {u, v, head[u]}, head[u] = tot;
}

void tarjan(int u) {
	low[u] = dfn[u] = ++Index;
	st[++len] = u; inst[u] = 1;
	for(int i = head[u]; i; i = G[i].next) {
		int v = G[i].v;
		if(dfn[v] == 0) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if(inst[v]) low[u] = min(low[u], dfn[v]);
	}
	if(low[u] == dfn[u]) {
		cnt++;
		while(st[len + 1] != u) {
			int t = st[len--];
			inst[t] = 0;
			col[t] = cnt;
		}
	}
}

int main() {
	cin >> n >> m >> s;
	for(int i = 1; i <= m; i++) {
		int a, b; read(a); read(b);
		x[i] = a; y[i] = b;
		addedge(a, b);
	}
	for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i);
	for(int i = 1; i <= m; i++) {
		if(col[x[i]] == col[y[i]]) continue;
		in[col[y[i]]]++;
	}
	int ans = 0; if(!in[col[s]]) ans--;
	for(int i = 1; i <= cnt; i++) if(!in[i]) ans++;
	cout << ans << endl;
	return 0;
}