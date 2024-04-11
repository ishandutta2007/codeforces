# include <cstdio>
# include <cstring>
# include <algorithm>
# include <vector>
# include <queue>
using namespace std;

const int maxn = 1000010;
vector<int> g[maxn];
int deg[maxn];

int n, m;

bool vis[maxn];
bool connected(int u) {
	if(u == -1) return false;
	queue<int> q;
	q.push(u);
	vis[u] = true;
	int cnt = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		cnt += deg[u];
		for(auto v: g[u]) if(!vis[v]) vis[v] = true, q.push(v);
	}
	return cnt == m * 2;
}

int sl = 0;
int main() {
	scanf("%d%d", &n, &m);
	int first = -1;
	for(int i = 0; i < m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		if(first == -1) first = u;
		if(u == v) sl += 1;
		else {
			g[u].push_back(v);
			g[v].push_back(u);
		}
		deg[u] += 1;
		deg[v] += 1;
	}
	if(m <= 1 || !connected(first)) { puts("0"); return 0; }
	long long ans = 0;
	if(sl >= 2) {
		ans += 1ll * sl * (sl - 1) / 2;
	}
	if(sl >= 1) {
		if(m - sl >= 1) ans += 1ll * sl * (m - sl);
	}
	for(int i = 1; i <= n; ++i) if(g[i].size() >= 2) {
		int sz = g[i].size();
		ans += 1ll * sz * (sz - 1) / 2;
	}
	printf("%I64d\n", ans);
	return 0;
}