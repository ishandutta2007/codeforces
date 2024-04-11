#include <bits/stdc++.h>
#define par pair<int, int>
#define x first
#define y second
#define mp make_pair
using namespace std;
const int N = 100 + 10, M = N << 2, oo = 0x3f3f3f3f;
struct Edge {
	int to, nxt, f, c;
}e[M << 1];
int head[N], tot = 1;
int h[N], dis[N], eid[N], vis[N];
int n, m;
int deg[N];
void adde(int u, int v, int f, int c) {
	e[++tot] = Edge{v, head[u], f, c};
	head[u] = tot;
}

void fadde(int u, int v, int f, int c) {
	adde(u, v, f, c), adde(v, u, 0, -c);
}

int Dijkstra(int s, int t, int n) {
	for(int i = 1; i <= n; i++) {
		eid[i] = vis[i] = 0, dis[i] = oo;
	}
	priority_queue<par, vector<par>, greater<par> > pq;
	dis[s] = 0;
	pq.push(mp(0, s));
	while(!pq.empty()) {
		int u = pq.top().y;
		pq.pop();
		if(vis[u]) continue;
//		cout << u << endl;
		vis[u] = 1;
		for(int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].to, w = e[i].c + h[u] - h[v];
//			cout << u <<" " << v <<" " << w << endl;
			if(e[i].f && dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				pq.push(mp(dis[v], v));
				eid[v] = i;
			}
		}
	}
//	dis[u] + h[u] + w >= dis[v] + h[v];
	for(int i = 1; i <= n; i++) {
		h[i] += dis[i];
	}
//	cout << dis[t] << endl;
	return dis[t] < oo;
}

int MFMC(int s, int t, int n) {
	int cost = 0;
	while(Dijkstra(s, t, n)) {
		int fl = oo;
		for(int i = eid[t]; i; i = eid[e[i ^ 1].to]) {
			fl = min(fl, e[i].f);
		}
//		cout << "flow = "<< fl << endl;
		for(int i = eid[t]; i; i = eid[e[i ^ 1].to]) {
			e[i].f -= fl, e[i ^ 1].f += fl;
			cost += fl * e[i].c;
		}
	}
	return cost;
}

int main() {
	cin >> n >> m;
	int sum = 0;
	for(int i = 1, u, v, f, c; i <= m; i++) {
		cin >> u >> v >> c >> f;
		int d = max(0, f - c);
		sum += d;
		if(d) fadde(v, u, d, 0);
		fadde(v, u, f - d, 1);
		d = max(0, c - f);
		if(d) fadde(u, v, d, 1);
		fadde(u, v, oo, 2);
		deg[u] += f, deg[v] -= f;
	}
	fadde(n, 1, oo, 0);
	int s = n + 1, t = n + 2;
	for(int i = 1; i <= n; i++) {
		if(deg[i] > 0) fadde(i, t, deg[i], 0);
		if(deg[i] < 0) fadde(s, i, - deg[i], 0);
	}
	cout << MFMC(s, t, n + 2) + sum << endl;
//	return 0;
}