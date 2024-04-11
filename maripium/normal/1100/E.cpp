#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

struct edge {
	int to, cost, id;
	edge(int to = 0,int cost = 0,int id = 0) : to(to), cost(cost), id(id) {}
};

int n, m;
vector<edge> g[N];
vector<edge> new_g[N];
int topo[N], pos[N];
int now;
bool visit[N];
vector<int> rev;

void dfs(int u) {
	visit[u] = true;
	for (auto e : new_g[u]) {
		if (visit[e.to]) {
		} else {
			dfs(e.to);
		}
	}
	topo[++now] = u;
	pos[u] = n - now + 1;
} 

bool check(int mid) {
	now = 0;
	rev.clear();
	for (int u = 1; u <= n; ++u) {
		visit[u] = false;
		new_g[u].clear();
		for (auto e : g[u]) {
			if (e.cost > mid) {
				new_g[u].push_back(e);
			}
		}
	}
	for (int u = 1; u <= n; ++u) {
		if (visit[u] == false) {
			dfs(u);
		}
	}
	reverse(topo + 1, topo + 1 + n);
	for (int u = 1; u <= n; ++u) {
		for (auto e : new_g[u]) {
			if (pos[u] > pos[e.to]) {
				return false;
			}
		}
	}
	for (int u = 1; u <= n; ++u) {
		for (auto e : g[u]) {
			if (pos[u] > pos[e.to]) {
				rev.push_back(e.id);
			}
		}
	}
	return true;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		g[u].push_back(edge(v, w, i));
	}
	int low = 0, high = 1e9;
	while (low < high) {
		int mid = (low + high) >> 1;
		if (check(mid)) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	assert(check(low));
	printf("%d %d\n", low, (int)rev.size());
	sort(rev.begin(), rev.end());
	for (int id : rev) {
		printf("%d ", id);
	}
}