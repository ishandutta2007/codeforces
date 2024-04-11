#include<bits/stdc++.h>

using namespace std;

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()
#define x first
#define y second
#define mp make_pair
#define pb push_back

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> par;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
const int N = 2e5 + 10;
const LL inf = 0x3f3f3f3f3f3f3f3f;
int n, m;
int s[N], t[N], c[N], cnt = 0, id[N], vis[N];
vector<int> g[N];
LL mn[N], siz[N], sz[N];
int gp[N], fa[N];
set<int> vex;

int gf(int x) { return fa[x] == x ? x : fa[x] = gf(fa[x]); }

void Dfs(int u, int rt) {
	gp[u] = rt;
	sz[rt]++;
	sort(ALL(g[u]));
	int now = 0;
	vector<int> nex;
	for(auto v : vex) {
		while(now < SZ(g[u]) && g[u][now] < v) now++;
		if(now < SZ(g[u]) && g[u][now] == v) {
			continue;
		}
		nex.push_back(v);
	}
	for(auto v : nex) vex.erase(v);
	for(auto v : nex) Dfs(v, rt);
	return;
}

int cmp(int x, int y) { return c[x] < c[y]; }

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) vex.insert(i);
	int Xor = 0;
	for(int i = 1; i <= m; i++) {
		cin >> s[i] >> t[i] >> c[i];
		Xor ^= c[i];
		g[s[i]].push_back(t[i]), g[t[i]].push_back(s[i]);
	}
	for(int i = 1; i <= n; i++) {
		if(gp[i]) continue;
		vex.erase(i);
		Dfs(i, i);
	}
	memset(mn, 0x3f, sizeof(mn));
	for(int i = 1; i <= m; i++) {
		if(gp[s[i]] == gp[t[i]]) ckmin(mn[gp[s[i]]], (LL) c[i]), siz[gp[s[i]]]++;
	}
	LL ans = Xor;
	for(int i = 1; i <= n; i++) {
		if(gp[i] ^ i) continue;
		if(sz[i] * (sz[i] - 1) / 2 - siz[i] >= sz[i]) {
			ans = 0;
		} else {
		}
	}
	for(int i = 1; i <= m; i++) id[i] = i;
	sort(id + 1, id + m + 1, cmp);
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++) {
		int u = gp[s[id[i]]], v = gp[t[id[i]]];
		if(gf(u) == gf(v)) continue;
		u = gf(u), v = gf(v);
		fa[u] = v;
		vis[id[i]] = 1;
	}
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++) {
		if(vis[i]) fa[gf(s[i])] = gf(t[i]);
	}
	for(int i = 1; i <= m; i++) {
		if(vis[id[i]]) continue;
		int u = s[id[i]], v = t[id[i]];
		if(gf(u) == gf(v)) continue;
		ckmin(ans, (LL)c[id[i]]);
		break;
	}
	for(int i = 1; i <= m; i++) if(vis[i]) ans += c[i];
	cout << ans << endl;
	return 0;
}