# include <bits/stdc++.h>

using namespace std;

const int maxn = 300010;
vector<int> g[maxn];

int dist[maxn];

void bfs(int s) {
	queue<int> q;
	memset(dist, -1, sizeof(dist));
	dist[s] = 0;
	q.push(s);
	while(!q.empty()) {
		s = q.front(); q.pop();
		for(auto u: g[s]) {
			if(dist[u] == -1) {
				dist[u] = dist[s] + 1;
				q.push(u);
			}
		}
	}
}

int n, m;

int pt[maxn];	//party
int id[maxn];
bool center[maxn];
int sgn[] = {0, -1, 1};

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bfs(1);
	int cnt = 0;
	int cnt_dist1 = 0;
	for(int i = 1; i <= n; ++i) if(dist[i] == 1) ++cnt_dist1;

	center[1] = true;
	for(int i = 2; i <= n; ++i) if(dist[i] == 1 && g[i].size() == cnt_dist1) {
		center[i] = true;
		for(auto x: g[i]) if(dist[x] > 1) center[i] = false;
	}

	for(int i = 1; i <= n; ++i) if(dist[i] == 1) {
		if(center[i]) continue;
		if(pt[i] == 0) pt[i] = ++cnt;
		for(auto x: g[i]) if(!center[x]) {
			if(pt[x] == pt[i]) continue;
			if(pt[x] == 0) pt[x] = pt[i];
			else { puts("NO"); return 0;}
		}
	}

	if(cnt > 2) { puts("NO"); return 0; }

	pt[1] = -1;
	queue<int> q;
	for(int i = 2; i <= n; ++i) if(pt[i]) q.push(i);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(auto v: g[u]) {
			if(pt[v]) continue;
			pt[v] = pt[u];
			q.push(v);
		}
	}

	for(int i = 1; i <= n; ++i) {
		if(center[i]) {
			id[i] = n;
		} else {
			id[i] = n + dist[i] * sgn[pt[i]];
		}
	}

	map<int, int> ct;
	for(int i = 1;i <= n; ++i) ct[id[i]] ++;

	bool flag = true;
	for(int i = 1; i <= n; ++i) {
		if (1 + g[i].size() != ct[id[i]] + ct[id[i]-1] + ct[id[i]+1]) {flag = false; break; }
		for(auto x: g[i]) if(abs(id[x] - id[i]) > 1) {flag = false; break; }
	}

	if(!flag) { puts("NO"); return 0; }
	puts("YES");
	for(int i = 1; i <= n; ++i) printf("%d ", id[i]);
	puts("");

	return 0;
}