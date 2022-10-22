#include<bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define p0(x) ((x) * 2 - 1)
#define p1(x) ((x) * 2)
#define rev(x) (((x) + 1) >> 1)
using namespace std;
typedef __int128 lll;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
const int N = 6e5 + 10;
const ll oo = 0x3f3f3f3f3f3f3f3f;
int n, q;
vector<int> son[N];
vector<tuple<int, int, int>> cur[N];
vector<pair<int, ll>> e[N];
int used[N], siz[N], mx[N], id[N];
ll dis[N], ans[N];
void addedge(int u, int v, ll w) {e[u].eb(v, w), e[v].eb(u, w);}
void dfs(int u, int fa, int &c, int all, vector<int> &id) {
	siz[u] = 1, mx[u] = 0;
	id.eb(u);
	for(int v : son[u]) {
		if(v == fa || used[p0(v)]) continue;
		dfs(v, u, c, all, id);
		siz[u] += siz[v];
		mx[u] = max(mx[u], siz[v]);
	}
	mx[u] = max(mx[u], all - siz[u]);
	if(c == -1 || mx[c] > mx[u]) c = u;
	return;
}
void dfsid(int u, int fa, int id) {
	::id[u] = id;
	siz[u] = 1;
	for(int v : son[u]) {
		if(v == fa || used[p0(v)]) continue;
		dfsid(v, u, id);
		siz[u] += siz[v];
	}
	return;
}
priority_queue<pair<ll, int>> pq;
void dijkstra(int s) {
	dis[s] = 0;
	pq.emplace(- dis[s], s);
	while(!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		for(auto [v, w] : e[u]) {
			if(used[v]) continue;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				pq.emplace(- dis[v], v);
			}
		}
	}
	return;
}
void divide(int u, int all) {
	vector<int> id;
	id.clear();
	int c = -1;
	dfs(u, 0, c, all, id);
	cur[u].swap(cur[c]);
	u = c;
	dijkstra(p0(u));
	for(auto [u, v, i] : cur[u]) ans[i] = min(ans[i], dis[u] + dis[v]);
	for(int v : id) dis[p0(v)] = dis[p1(v)] = oo;
	dijkstra(p1(u));
	for(auto [u, v, i] : cur[u]) ans[i] = min(ans[i], dis[u] + dis[v]);
	for(int v : id) dis[p0(v)] = dis[p1(v)] = oo;
	used[p0(u)] = used[p1(u)] = 1;
	for(int v : son[u]) {
		if(used[p0(v)]) continue;
		dfsid(v, 0, v);
		cur[v].clear();
	}
	for(auto [u, v, i] : cur[u]) if(!used[u]) cur[::id[rev(u)]].eb(u, v, i);
	for(int v : son[u]) {
		if(used[p0(v)]) continue;
		divide(v, siz[v]);
	}
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dis, 0x3f, sizeof(dis));
	memset(ans, 0x3f, sizeof(ans));
	cin >> n;
	for(int i = 1; i <= n; i++) {
		ll w;
		cin >> w;
		addedge(p0(i), p1(i), w);
	}
	for(int i = 1, u, v; i < n; i++) {
		ll w1, w2;
		cin >> u >> v >> w1 >> w2;
		son[u].eb(v), son[v].eb(u);
		addedge(p0(u), p0(v), w1), addedge(p1(u), p1(v), w2);
	}
	cin >> q;
	for(int i = 1; i <= q; i++) {
		int u, v;
		cin >> u >> v;
		cur[1].eb(u, v, i);
	}
	divide(1, n);
	for(int i = 1; i <= q; i++) cout << ans[i] << endl;
	return 0;
}