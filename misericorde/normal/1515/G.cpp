#include <bits/stdc++.h>

using ll = long long;
const int maxn = 4e5 + 2222;

int n,m,q,low[maxn],dfn[maxn],vis[maxn],idx,in[maxn],cnt,hd[maxn],tl,d[maxn],anc[maxn][20];

struct edge {
	int v,w,nxt;
} E[maxn << 1];

void add_edge(int u,int v,int w) { E[++tl].v = v; E[tl].w = w; E[tl].nxt = hd[u]; hd[u] = tl; }

std::vector<int>ch[maxn];
std::stack<int>stk;
ll g[maxn],dp[maxn];

ll gcd(ll a,ll b) { return b == 0 ? a : gcd(b,a % b); }

void tarjan(int u) {
	stk.push(u);
	low[u] = dfn[u] = ++idx;
	for (int v:ch[u]) {
		if (!dfn[v]) {
			tarjan(v);
			low[u] = std::min(low[u],low[v]);
		} else if (!in[v])
			low[u] = std::min(low[u],dfn[v]);
	} if (low[u] == dfn[u]) {
		++cnt;
		while (1) {
			int x = stk.top(); stk.pop();
			in[x] = cnt;
			if (x == u) break;
		} 
	}
}

int lca(int u,int v) {
	if (!u) return v;
	if (d[u] < d[v]) std::swap(u,v);
	for (int i = 18; i >= 0; i --) if (d[anc[u][i]] >= d[v]) u = anc[u][i];
	if (u == v) return u;
	for (int i = 18; i >= 0; i --) if (anc[u][i] != anc[v][i]) {
		u = anc[u][i]; v = anc[v][i];
	} return anc[u][0];
}		

ll dis(int u,int v) { 
	return std::abs(dp[u] - dp[v]);
}

void dfs(int u,int f) {
	vis[u] = 1;
	anc[u][0] = f;
	d[u] = d[f] + 1;
	for (int i = 1; i <= 18; ++ i) 
		anc[u][i] = anc[anc[u][i-1]][i-1];
	for (int i = hd[u]; i; i = E[i].nxt) {
		int v = E[i].v, w = E[i].w;
		if (in[v] != in[u]) continue;
		if (!vis[v]) {
			dp[v] = dp[u] + w;
			dfs(v,u);
		} else {
			ll len = std::abs(dp[u] + w - dp[v]);
		//	printf(">%lld\n",len);
			if (!g[in[u]]) g[in[u]] = len;
			else g[in[u]] = gcd(g[in[u]],len);
		}
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= m; ++ i) {
		int a,b,l;
		scanf("%d%d%d",&a,&b,&l);
		add_edge(a,b,l);
		ch[a].push_back(b);
	} for (int i = 1; i <= n; ++ i)
		if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= n; ++ i) 
		if (!vis[i]) dfs(i,0);
	scanf("%d",&q);
	while (q--) {
		ll s,t;
		int u;
		scanf("%d%lld%lld",&u,&s,&t);
		s = t - s;
	//	printf(">%lld\n",g[in[u]]);
		ll d = gcd(t,g[in[u]]);
		if (s % d == 0) puts("YES");
		else puts("NO");
	}
	return 0;
}