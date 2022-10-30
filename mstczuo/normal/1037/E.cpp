# include <bits/stdc++.h>
using namespace std;

const int N = 200010;
pair<int,int> edge[N];
vector<int> g[N];
vector<int> G[N];
int n, m, K; 
int deg[N];
bool inq[N];

queue<int> q;
int ans;
void process(const int lim) {
	while(!q.empty()) {
		int u = q.front(); q.pop(); ans--;
		for(int i = 0; i < (int)g[u].size(); ++i) {
			int v = g[u][i], ti = G[u][i];
			if(ti < lim) continue;
			if(--deg[v] < K && inq[v]) {
				inq[v] = false;
				q.push(v);
			}
		}
	}
}

void debug() {
	for(int i = 1; i <= n; ++i) printf("%d ", deg[i]);
	puts("");
}

int res[N];
int main() {
	scanf("%d%d%d", &n, &m, &K);
	for(int i = 1; i <= n; ++i) deg[i] = 0;
	for(int i = 0; i < m; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		edge[i] = make_pair(x, y);
		g[x].push_back(y);
		G[x].push_back(m-1-i);
		g[y].push_back(x);
		G[y].push_back(m-1-i);
		deg[x] ++;
		deg[y] ++;
	}

	ans = n;
	for(int i = 1; i <= n; ++i) 
		if(deg[i] >= K) inq[i] = 1; else q.push(i);
	process(0);

	reverse(edge, edge + m);
	for(int i = 0; i < m; ++i) {
		res[i] = ans;
		int x, y; tie(x, y) = edge[i];
		if(inq[x] && inq[y]) {
			if(deg[x] - 1 < K) {
				--deg[x];
				inq[x] = 0; q.push(x);
			} else if(deg[y] - 1 < K) {
				--deg[y];
				inq[y] = 0; q.push(y);
			} else {
				--deg[x]; --deg[y];
			}
		}
		process(i);
	}
	reverse(res, res + m);
	for(int i = 0; i < m; ++i) printf("%d\n", res[i]);
	return 0;
}