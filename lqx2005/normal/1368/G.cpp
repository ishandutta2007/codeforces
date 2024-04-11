#include<bits/stdc++.h>

using namespace std;

#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define x first
#define y second
#define mp make_pair
#define p(x, y) ((x) * m + (y) + 1)
#define mid ((l + r) >> 1)
#define lc (p + 1)
#define rc (p + ((mid - l + 1) << 1))
typedef pair<int, int> par;
typedef long long LL;
constexpr int N(4e5 + 10);

struct scan {
	int l, r, v;
};
vector<scan> q[N];
int n, m, cir[N], vis[N], near[N], re[N], fa[N], nxt[N], tot = 0;
int dfn[N], l[N], r[N], dfc = 0;
int tag[N << 1], sum[N << 1];

string s[N];
vector<int> g[N];

int dx[256], dy[256];

int gf(int x) { return fa[x] == x ? x : fa[x] = gf(fa[x]); }
int unite(int x, int y) {
	x = gf(x), y = gf(y);
	if(x == y) return 1;
	return fa[x] = y, 0; 
}

void adde(int u, int v) { g[u].push_back(v); }

int in(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }

void add(int x, int y) {
	int nx = x + dx[s[x][y]], ny = y + dy[s[x][y]];
	if(!in(nx, ny)) return;
	adde(p(x, y), p(nx, ny)), adde(p(nx, ny), p(x, y));
	return;
}

void dfs(int u) {
	dfn[u] = l[u] = ++dfc;
	for(int &v : g[u]) {
		dfs(v);
	}
	r[u] = dfc;
	return;
}

void upd(int p, int l, int r) {
	if(tag[p]) sum[p] = r - l + 1;
	else if(l == r) sum[p] = 0;
	else sum[p] = sum[lc] + sum[rc];
	return;
}

void modify(int p, int l, int r, int L, int R, int v) {
	if(L <= l && r <= R) {
		tag[p] += v;
		upd(p, l, r);
		return;
	}
	if(L <= mid) modify(lc, l, mid, L, R, v);
	if(R > mid) modify(rc, mid + 1, r, L, R, v);
	return upd(p, l, r), void();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	dx['U'] = 2, dx['D'] = -2;
	dy['L'] = 2, dy['R'] = -2;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) fa[i] = i;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		for(int j = 0; j < m; j++) {
			char c = s[i][j];
			int x = i + dx[c];
			int y = j + dy[c];
			int nx = i + dx[c] / 2, ny = j + dy[c] / 2;
			if(in(x, y)) nxt[p(i, j)] = p(x, y);
			near[p(i, j)] = p(nx, ny);
		}
	}
	tot = n * m;
	vector<int> rt;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int a = p(i, j);
			re[a] = a;
			if(!nxt[a]) {
				rt.push_back(a);
				continue;
			}
			if(!unite(a, nxt[a])) continue;
			assert(0);
			vector<int> c;
			for(; !cir[a]; cir[a] = 1, c.push_back(a), a = nxt[a]);
			int ce = ++tot;
			for(int k = 0; k < int(c.size()); k++) adde(ce, c[k]), re[c[k]] = ce;
			rt.push_back(ce);
		}
	}
	int RT = ++tot;
	for(int i = 0; i < int(rt.size()); i++) adde(RT, rt[i]);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int a = p(i, j);
			if(cir[a]) continue;
			if(nxt[a]) adde(nxt[a], a);
		}
	}
	dfs(RT);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if((i + j) & 1) continue;
			int a = p(i, j), b = near[a];
			a = re[a], b = re[b];
			q[l[a]].push_back(scan{l[b], r[b], 1});
			q[r[a] + 1].push_back(scan{l[b], r[b], -1});
		}
	}
	LL ans = 0;
	for(int i = 1; i <= dfc; i++) {
		for(scan &v : q[i]) modify(1, 1, dfc, v.l, v.r, v.v);
		ans += sum[1];
	}
	cout << ans << endl;
	return 0;
}