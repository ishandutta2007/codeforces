#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
	f = 0; _T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
	while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
	f *= fu;
}

template <typename T>
void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const ll INF = 0x7f7f7f7f7f7f7f7f;
const int N = 1e5 + 5;

struct edge_t { int u, v, next, w, id; } G[N];

priority_queue < pair <ll, int> > Q;
queue <int> que[N];
ll dis[N];
int head[N], add[N], I[N];
int n, m, q, tot;

inline void addedge(int u, int v, int w, int id) {
	G[++tot] = (edge_t) {u, v, head[u], w, id}, head[u] = tot;
}

int main() {
	memset(dis, 0x7f, sizeof(dis));
	read(n); read(m); read(q);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		read(u); read(v); read(w);
		addedge(u, v, w, i);
	}
	dis[1] = 0; Q.push(make_pair(0, 1));
	while (!Q.empty()) {
		pair <ll, int> u = Q.top(); Q.pop();
		if (-u.first > dis[u.second]) continue;
		for (int i = head[u.second]; i; i = G[i].next) {
			int v = G[i].v;
			if (dis[v] > dis[u.second] + G[i].w) {
				dis[v] = dis[u.second] + G[i].w;
				Q.push(make_pair(-dis[v], v));
			}
		}
	}
	while (q--) {
		int opt; read(opt);
		if (opt == 1) {
			int x; read(x);
			print(dis[x] == INF ? -1 : dis[x], '\n');
		} else {
			memset(add, 0x7f, sizeof(add)); memset(I, 0, sizeof(I));
			int k; read(k);
			for (int i = 1, id; i <= k; i++) read(id), I[id] = 1;
			add[1] = 0; que[0].push(1);
			for (int v = 0; v <= k; v++) {
				while (!que[v].empty()) {
					int u = que[v].front(); que[v].pop();
					// cout << ": " << u << " " << v << endl;
					if (v > add[u]) continue;
					for (int i = head[u]; i; i = G[i].next) {
						if (add[G[i].v] > add[u] + dis[u] + G[i].w + I[G[i].id] - dis[G[i].v]) {
							add[G[i].v] = add[u] + dis[u] + G[i].w + I[G[i].id] - dis[G[i].v];
							if (add[G[i].v] <= k) que[add[G[i].v]].push(G[i].v);
						}
					}
				}
			}
			for (int i = 1; i <= n; i++) if (add[i] != 0x7f7f7f7f) dis[i] += add[i];
			for (int i = 1; i <= m; i++) G[i].w += I[G[i].id];
		}
	}
	return 0;
}