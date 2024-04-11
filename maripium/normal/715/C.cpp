#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;

const int N = 1e5 + 5;
typedef pair<int,int> ii;

int n, mod, phi;
int child[N];
bool visit[N];
int f[N], g[N], dis[N];
int pw[N], ipw[N];
vector<ii> G[N];
map<int,int> mp;
int res = 0;

int fpow(int x,int y) {
	int res = 1;
	while (y) {
		if (y & 1) res = res * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return res; 
}
int calc_phi(int mod) {
    int res = 1;
    int cur = mod;
    for(int i = 2; i <= sqrt(mod); ++i) {
        bool ok = 0;
        while(cur % i == 0) {
            cur /= i;
            res *= i;
            ok = 1;
        }
        if(ok) res = res / i * (i - 1);
    }
    if(cur - 1) res = res * (cur - 1);
    return res;
}
void dfs(int u,int p) {
	child[u] = 1;
	for (auto v : G[u]) if (v.fi != p && !visit[v.fi]) {
		dis[v.fi] = dis[u] + 1;
		f[v.fi] = (10 * f[u] + v.se) % mod;
		g[v.fi] = (v.se * pw[dis[u]] + g[u]) % mod;
		dfs(v.fi, u); child[u] += child[v.fi];
	}
}
int find_cen(int u,int p,int r) {
	for (auto v : G[u]) if (v.fi != p && !visit[v.fi]) {
		if (child[v.fi] >= child[r] / 2) return find_cen(v.fi, u, r);
	}
	return u;
}

void upd(int u,int p,int add) {
	mp[g[u]] += add;
	for (auto v : G[u]) if (v.fi != p && !visit[v.fi]) {
		upd(v.fi, u, add);
	}
}
void solve(int u,int p) {
	int val = (mod - 1LL * f[u] * fpow(pw[dis[u]], phi - 1) % mod) % mod;
	res += mp[val];
	res += (!f[u]) + (!g[u]);
	for (auto v : G[u]) if (v.fi !=  p && !visit[v.fi]) {
		solve(v.fi, u);
	}
}
void centroid(int u) {
	dfs(u, u);
	int cen = find_cen(u, u, u);
	visit[cen] = true;
	f[cen] = g[cen] = dis[cen] = 0;
	dfs(cen, cen);
	for (auto v : G[cen]) if (!visit[v.fi]) {
		upd(v.fi, cen, 1);
	}
	for (auto v : G[cen]) if (!visit[v.fi]) {
		upd(v.fi, cen, -1);
		solve(v.fi, cen);
		upd(v.fi, cen, 1);
	}
	for (auto v : G[cen]) if (!visit[v.fi]) {
		upd(v.fi, cen, -1);
	}
	for (auto v : G[cen]) if (!visit[v.fi]) {
		centroid(v.fi);
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> mod;
	for (int i = 0;i < n - 1;++i) {
		int u, v, w; cin >> u >> v >> w;
		G[u].pb(ii(v, w)), G[v].pb(ii(u, w));
	}
	pw[0] = 1;
	for (int i = 1;i <= n;++i) pw[i] = pw[i - 1] * 10 % mod;
	phi = calc_phi(mod);
	centroid(n - 1);
	cout << res << endl;
}