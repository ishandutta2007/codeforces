#include<bits/stdc++.h>
#define sz(a) int((a).size())
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef pair<int, int> par;
typedef long long ll;
typedef double db;
const int N = 5e5 + 10;
int n, dep[N], son[N], mx[N];
ll ans[N], sum[N];
vector<int> g[N], d[N];
int *l[N], *r[N], *s[N];
int pre[N], suf[N];
ll prew[N], sufw[N];
void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	d[dep[u]].push_back(u);
	mx[u] = 0;
	for(int v : g[u]) {
		dfs(v, u);
		if(mx[son[u]] < mx[v]) {
			son[u] = v;
		}
	}
	mx[u] = mx[son[u]] + 1;
	return;
}

void dfs2(int u, int fa) {
	ans[u] += ans[fa];
	for(int v : g[u]) {
		dfs2(v, u);
	}
	return;
}

void dfs1(int u, int fa) {
	if(son[fa] != u) {
		l[u] = new int[mx[u] + 1];
		r[u] = new int[mx[u] + 1];
		s[u] = new int[mx[u] + 1];
	} else {
		l[u] = l[fa] + 1;
		r[u] = r[fa] + 1;
		s[u] = s[fa] + 1;
	}
	vector<int> ls, rs;
	int f = 0;
	for(int v : g[u]) {
		dfs1(v, u);
		if(v == son[u]) {
			f = 1;
		} else {
			if(!f) ls.push_back(v);
			else rs.push_back(v);
		}
	}
	reverse(ls.begin(), ls.end());
	int w = son[u];
	for(int v : ls) {
		for(int j = 0; j <= mx[v]; j++) {
			pre[l[w][j]] = l[v][j], suf[r[v][j]] = r[w][j];
			prew[l[w][j]] = 1ll * dep[u] * s[v][j], sufw[r[v][j]] = 1ll * dep[u] * s[w][j];
			l[w][j] = l[v][j], s[w][j] += s[v][j];
		}
	}
	for(int v : rs) {
		for(int j = 0; j <= mx[v]; j++) {
			pre[l[v][j]] = l[w][j], suf[r[w][j]] = r[v][j];
			prew[l[v][j]] = 1ll * dep[u] * s[w][j], sufw[r[w][j]] = 1ll * dep[u] * s[v][j];
			r[w][j] = r[v][j], s[w][j] += s[v][j];
		}		
	}
	l[u][0] = r[u][0] = u, s[u][0] = 1;
	return;
}

int main() {
	scanf("%d", &n);
	int rt = 0;
	for(int i = 1, p; i <= n; i++) {
		scanf("%d", &p);
		if(p == 0) rt = i;
		else g[p].push_back(i);
	}
	mx[0] = -1;
	dfs(rt, 0);
	dfs1(rt, 0);
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < sz(d[i]); j++) {
			int u = d[i][j];
			sum[u] = sum[pre[u]] + prew[u];
			ans[u] += sum[u];
		}
		for(int j = sz(d[i]) - 1; j >= 0; j--) {
			int u = d[i][j];
			sum[u] = sum[suf[u]] + sufw[u];
			ans[u] += sum[u];
		}
		for(int v : d[i]) ans[v] += dep[v];
	}
	dfs2(rt, 0);
	for(int i = 1; i <= n; i++) printf("%lld ", ans[i] - dep[i]);
	printf("\n");
	return 0;
}