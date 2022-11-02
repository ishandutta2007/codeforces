# include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5+10;
int n, m;

vector<int> g[maxn], col[maxn];
int cc[maxn];

int used[maxn];

int cur, lim, dfn;
set<int> s;
int getc() {
	while(used[cur] == dfn) ++cur;
	used[cur] = dfn;
	return cur;
}

void dfs(int u,int par) {
	++dfn;
	for(auto c: col[u]) if(cc[c]) used[cc[c]] = dfn;
	cur = 1;
	for(auto c: col[u]) if(!cc[c]) cc[c] = getc();
	lim = max(lim, cur);
	for(auto v: g[u]) if(v!=par) dfs(v, u);
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		int cnt, x;
		scanf("%d", &cnt);
		while(cnt--) {
			scanf("%d", &x);
			col[i].push_back(x);
		}
	}
	for(int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 1);

	printf("%d\n", lim);
	for(int i = 1; i <= m; ++i) {
		if(cc[i] == 0) cc[i] = 1;
		printf("%d ", cc[i]);
	}
	return 0;
}