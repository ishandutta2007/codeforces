#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

int n, m;
vector <int> E[100010], F[100010];
int color[100010], S[100010], U[100010], cs;
void add_edge(int x, int y) {
	E[x].pb(y), E[y].pb(x);
}

void dfs(int x, int fa) {
	color[x] = 1;
	S[x] = U[x] = ++cs;
	for(int e : E[x]) if(e != fa) {
		if(color[e] == 0) {
			dfs(e, x);
			if(U[e] == S[e]) F[x].pb(e), F[e].pb(x);
			U[x] = min(U[x], U[e]);
		}
		else if(color[e] == 1) U[x] = min(U[x], S[e]);
	}
	color[x] = 2;
}

vector <pii> ans;

int D[100010];
void qdfs(int x, int fa) {
	color[x] = 1;
	vector <int> child;
	for(int e : F[x]) if(e != fa) child.pb(e);
	if(szz(child) == 0) return;
	vector <pii> v;
	for(int e : child) {
		qdfs(e, x);
		if(D[e]) v.pb({0, D[e]});
		else v.pb({1, e});
	}
	sort(all(v));
	int l = szz(v);
	if(l % 2) {
		for(int i = 0; i+1 < l; i += 2) {
			ans.pb({v[i].Se, v[i+1].Se});
		}
		D[x] = v[l-1].Se;
	}
	else {
		for(int i = 0; i+2 < l; i += 2) {
			ans.pb({v[i].Se, v[i+1].Se});
		}
		if(v[l-1].Fi == 1) D[x] = v[l-2].Se;
		else ans.pb({v[l-2].Se, v[l-1].Se});
	}
}

void solve() {
	rep(i, m) {
		int c, p = -1;
		scanf("%d", &c);
		while(c--) {
			int x;
			scanf("%d", &x);
			if(p != -1) add_edge(p, x);
			p = x;
		}
	}

	cs = 0;
	dfs(1, -1);

	for(int i=1;i<=n;i++) color[i] = D[i] = 0;
	for(int i=1;i<=n;i++) if(!color[i] && szz(F[i]) == 1) {
		int p = F[i][0];
		qdfs(p, i);
		if(D[p]) ans.pb({D[p], i});
	}

	printf("%d\n", szz(ans));
	for(auto [x, y] : ans) printf("%d %d\n", x, y);

	ans.clear();
	for(int i=1;i<=n;i++) {
		E[i].clear();
		F[i].clear();
		color[i] = 0;
	}
}

int main() {
	while(scanf("%d%d", &n, &m) == 2) {
		if(!n && !m) break;
		solve();
	}

	return 0;
}