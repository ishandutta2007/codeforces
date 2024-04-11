#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

int N, K, R;
vector <int> E[200020];
int dep[200020], up[200020][20];
int pp[200020], nxt[200020][20];
pii clo[200020];
int exi[200020];
pii dis[200020];
int st[200020], en[200020], cs;
const int INF = 1e9;

void pdfs(int x, int fa) {
	clo[x] = pii(INF, -1);
	st[x] = ++cs;
	if(exi[x]) clo[x] = pii(dep[x], x);
	for(int e : E[x]) if(e != fa) {
		dep[e] = dep[x] + 1;
		up[e][0] = x;
		for(int i=1;i<20;i++) up[e][i] = up[ up[e][i-1] ][i-1];
		pdfs(e, x);
		if(clo[x].Fi > clo[e].Fi) {
			clo[x] = clo[e];
		}
	}
	en[x] = cs;
}
int get_lca(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	rep(i, 20) if(1<<i & (dep[x] - dep[y])) x = up[x][i];
	for(int i=19;i>=0;i--) if(up[x][i] != up[y][i]) x = up[x][i], y = up[y][i];
	return x == y ? x : up[x][0];
}
int get_len(int x, int y) {
	int lca = get_lca(x, y);
	return dep[x] + dep[y] - dep[lca] * 2;
}
int climb(int x, int l) {
	rep(i, 20) if(1<<i & l) x = up[x][i];
	return x ? x : 1;
}

int get_u(int x, int k) {
	int px = climb(x, (k+1) / 2);
	if(clo[px].Fi < dep[x]) return clo[px].Se;
	if(k > (k+1)/2) {
		px = up[px][0];
		k -= (k+1) / 2 + 1;
		if(dis[px].Fi <= k) return dis[px].Se;
	}
	return 0;
}

void DFS(int x, int fa) {
	if(x > 1) {
		pp[x] = get_u(x, K);
	}
	for(int e : E[x]) if(e != fa) {
		DFS(e, x);
	}
}

void BFS(vector <int> q) {
	rep(i, szz(q)) {
		int t = q[i];
		for(int e : E[t]) if(dis[e].Fi == -1) {
			dis[e].Fi = dis[t].Fi + 1;
			dis[e].Se = dis[t].Se;
			q.pb(e);
		}
	}
}

int Get(int x, int p) {
	int res = get_len(x, p);
	for(int i=19;i>=0;i--) {
		if(nxt[x][i] == 0) continue;
		int px = nxt[x][i];
		if(st[p] <= st[px] && st[px] <= en[p]) x = px;
	}
	return min(res, get_len(x, p));
}

void solve() {
	scanf("%d%d%d", &N, &K, &R);
	rep(i, N-1) {
		int x, y;
		scanf("%d%d", &x, &y);
		E[x].pb(y);
		E[y].pb(x);
	}
	for(int i=1;i<=N;i++) dis[i].Fi = -1;
	vector <int> qqq;
	for(int i=1;i<=R;i++) {
		int x; scanf("%d", &x);
		exi[x] = 1;
		qqq.pb(x);
		dis[x] = pii(0, x);
	}
	BFS(qqq);
	pdfs(1, -1);
	DFS(1, -1);
	for(int i=1;i<=N;i++) nxt[i][0] = pp[i];
	for(int i=1;i<20;i++) {
		for(int j=1;j<=N;j++) nxt[j][i] = nxt[ nxt[j][i-1] ][i-1];
	}
	auto trial = [&](int x, int y) {
		int lca = get_lca(x, y);
		int v1 = Get(x, lca);
		int v2 = Get(y, lca);
		if(v1 + dis[lca].Fi <= K) v1 = min(v1, dis[lca].Fi);
		if(v2 + dis[lca].Fi <= K) v2 = min(v2, dis[lca].Fi);
		return v1 + v2 <= K || (v1 + dis[lca].Fi <= K && v2 + dis[lca].Fi <= K);
	};
	int q; scanf("%d", &q);
	rep(qq, q) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%s\n", trial(x, y) ? "YES" : "NO");
	}
}

int main() {
	int T = 1; //scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		solve();
	}
	return 0;
}