#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define b(x, y) in[mp(x, y)]
#define e(x, y) out[mp(x, y)]
typedef pair<int, int> par;
typedef long long LL;
const int N = 2000 + 10, M = N << 3;
const int oo = 0x3f3f3f3f;
struct Edge {
	int to, nxt, f;
}e[M << 1];
int head[N], tot = 1;
int dep[N];
int x[N], y[N], w[N];
int n;
map<par, int> in, out;
void adde(int u, int  v, int f) { e[++tot] = Edge{v, head[u], f}; head[u] = tot; }
void ADDE(int u, int v, int f) {
	if(!u || !v) return;
	adde(u, v, f), adde(v, u, 0); 
}

int bfs(int s, int t, int n) {
	static queue<int> q;
	memset(dep, 0x3f, (n + 2) << 2);
	dep[s] = 0;
	q.push(s);
	for(; !q.empty(); ) {
		int u = q.front();
		q.pop();
		for(int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].to;
			if(e[i].f && dep[v] > dep[u] + 1) {
				dep[v] = dep[u] + 1;
				q.push(v);
			}
		}
	}
	return dep[t] < oo;
}

LL dfs(int u, int t, int in) {
	if(u == t || !in) return in;
	LL f, flow = 0;
	for(int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if(dep[v] == dep[u] + 1 && e[i].f && (f = dfs(v, t, min(in, e[i].f))) > 0) {
			flow += f;
			e[i].f -= f, e[i ^ 1].f += f, in -= f;
			if(!in) break; 
		}
	}
	if(!flow) dep[u] = -1;
	return flow;
}

LL dinic(int s, int t, int n) {
	LL flow = 0;
	for(; bfs(s, t, n); ) flow += dfs(s, t, oo);
	return flow; 
}

int main() {
	scanf("%d", &n);
	LL ans = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d%d%d", &x[i], &y[i], &w[i]);
		b(x[i], y[i]) = i * 2 - 1, e(x[i], y[i]) = i * 2, ans += w[i];
	}
	int S = n * 2 + 1, T = S + 1; 
	for(int i = 1; i <= n; i++) {
		if(x[i] & 1) {
			if(y[i] & 1) ADDE(e(x[i], y[i]), T, w[i]);
			else ADDE(S, b(x[i], y[i]), w[i]);
		}
	}
	for(int i = 1; i <= n; i++) {
		ADDE(b(x[i], y[i]), e(x[i], y[i]), w[i]);
		int opx = 0, opy = 0;
		if((x[i] ^ y[i]) & 1) opx = 1;
		else opy = 1;
		ADDE(e(x[i], y[i]), b(x[i] + opx, y[i] + opy), oo);
		ADDE(e(x[i], y[i]), b(x[i] - opx, y[i] - opy), oo);
	}
	ans -= dinic(S, T, T);
	printf("%lld\n", ans);
	return 0;
}