#include <bits/stdc++.h>
#define LL long long
#define par pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 2.5e5 + 10, LG = 38;
const LL OO = 300000000007;

set<par> g[N];
int deg[N], id[N], vis[N];
int rt[N], lc[N * LG], rc[N * LG], cnt[N * LG], tot = 0;
LL sum[N * LG];
LL dp[N][2];

void adde(int u, int v, int w) { g[u].insert({v, w}); }

int newd() {
	tot++;
	sum[tot] = lc[tot] = rc[tot] = cnt[tot] = 0;
	return tot;
}

void modify(int &p, LL l, LL r, LL x, LL v) {
	if(!p) p = newd();
	cnt[p]++, sum[p] += v;
	if(l == r) return;
	LL mid = (l + r) / 2;
	if(x <= mid) modify(lc[p], l, mid, x, v);
	else modify(rc[p], mid + 1, r, x, v);
	return;
}

LL find(int p, int q, LL l, LL r, LL rk) {
	if(l == r) return l;
	LL mid = (l + r) / 2;
	return cnt[rc[p]] + cnt[rc[q]] >= rk ? find(rc[p], rc[q], mid + 1, r, rk) : find(lc[p], lc[q], l, mid, rk - cnt[rc[p]] - cnt[rc[q]]);
}

LL quer(int p, LL l, LL r, LL L, LL R) {
	if(!p) return 0;
	if(L <= l && r <= R) return cnt[p];
	LL res = 0, mid = (l + r) / 2;
	if(L <= mid) res += quer(lc[p], l, mid, L, R);
	if(R > mid) res += quer(rc[p], mid + 1, r, L, R);
	return res;
}

LL query(int p, LL l, LL r, LL L, LL R) {
	if(!p) return 0;
	if(L <= l && r <= R) return sum[p];
	LL res = 0, mid = (l + r) / 2;
	if(L <= mid) res += query(lc[p], l, mid, L, R);
	if(R > mid) res += query(rc[p], mid + 1, r, L, R);
	return res;
}

LL ask(int p, int q, LL k, LL ed) {
	ed = min(ed, OO - 1);
	int c = quer(p, 0, OO, ed + 1, OO) + quer(q, 0, OO, ed + 1, OO), d = quer(p, 0, OO, ed, OO) + quer(q, 0, OO, ed, OO);
	LL s = query(p, 0, OO, ed + 1, OO) + query(q, 0, OO, ed + 1, OO);
	if(d <= k) return s + (d - c) * ed;
	return s + (k - c) * ed;
}

void Dfs(int u, int fa, int K, int w) {
	vis[u] = 1;
	LL res = 0;
	int p = 0;
	for(par e : g[u]) {
		int v = e.x, w = e.y;
		if(v == fa) continue;
		Dfs(v, u, K, w);
		res += dp[v][0];
		if(dp[v][1] - dp[v][0] <= 0) modify(p, 0, OO, dp[v][0] - dp[v][1], dp[v][0] - dp[v][1]);
	}
	res += sum[rt[u]];
	LL ed1 = find(p, rt[u], 0, OO, K), ed2 = find(p, rt[u], 0, OO, K - 1);
	dp[u][0] = - ask(p, rt[u], K, ed1) + w + res;
	dp[u][1] = - ask(p, rt[u], K - 1, ed2) + res;
	return;
}

int cmp(int x, int y) { return deg[x] < deg[y]; }

void del(int x) {
	for(par e : g[x]) {
		int v = e.x, w = e.y;
		g[v].erase({x, w});
		modify(rt[v], 0, OO, w, w);
	}
	g[x].clear();
	return;
}

vector<LL> minimum_closure_costs(int n, vector<int> U, vector<int> V, vector<int> W) {
	LL sum = 0;
	for(int i = 0; i < n - 1; i++) {
		adde(U[i], V[i], W[i]), adde(V[i], U[i], W[i]);
		sum += W[i];
		deg[U[i]]++, deg[V[i]]++;
	}
	for(int i = 1; i <= n; i++) id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	vector<LL> ans(n, 0);
	ans[0] = sum;
	int las = 0;
	for(int k = 1; k < n; k++) {
		while(las + 1 <= n && deg[id[las + 1]] <= k) del(id[++las]);
		for(int i = las + 1; i <= n; i++) vis[id[i]] = 0;
		int temp = tot;
		for(int i = las + 1; i <= n; i++) {
			if(vis[id[i]]) continue;
			Dfs(id[i], 0, k, 0);
			ans[k] += dp[id[i]][0];
		}
		tot = temp;
	}
	return ans;
}


int main() {
	int n;
	scanf("%d", &n);
	vector<int> A, B, C;
	for(int i = 0; i < n - 1; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		A.push_back(u), B.push_back(v), C.push_back(w);
	}
	vector<LL> ans = minimum_closure_costs(n, A, B, C);
	for(int i = 0; i < n; i++) printf("%lld ", ans[i]);
	printf("\n");
	return 0;
}