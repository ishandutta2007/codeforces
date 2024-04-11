#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

const int N = 1e5 + 5;

int n, k;
vector<pair<int,int> > G[N];
int dep[N], f[N];
pair<int,int> best;
bool flag;
int prv[N], prvw[N];

void dfs(int u,int p,int d) {
	best = max(best, mp(d, u));
	for (auto ed : G[u]) {
		int v = ed.fi;
		int w = ed.se;
		if (v != p) {
			dfs(v, u, d + w);
			prv[v] = u;
			prvw[v] = w;
		}
	}
}

int find_cen() {
	dfs(1, 1, 0);
	int rt = best.se;
	best = mp(0, 0);
	dfs(rt, rt, 0);
	int tp = best.se;
	int len = best.fi;
	best = mp(len, tp);
	int cur = 0;
	while (tp != rt) {
		best = min(best, mp(abs(cur + cur - len), tp));
		cur += prvw[tp];
		tp = prv[tp];
	}
	best = min(best, mp(abs(cur + cur - len), tp));
	return best.se;
}

void dfs1(int u,int p) {
	for (auto ed : G[u]) {
		int v = ed.fi;
		int w = ed.se;
		if (v != p) {
			dfs1(v, u);
			dep[u] = max(dep[u], dep[v] + w);
		}
	}
}

void dfs2(int u,int p,int mid) {
	int cnt = 0;
	for (auto ed : G[u]) {
		int v = ed.fi;
		int w = ed.se;
		if (v != p) {
			if (dep[v] + w > mid) {
				f[v] = 1;
				dfs2(v, u, mid);
				cnt++;
			}
		}
	}
	if (u != p && cnt > 1) flag = 0;
	if (cnt > 2) flag = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 2; i <= n; ++i) {
		int u, v, w; cin >> u >> v >> w;
		G[u].pb(mp(v, w));
		G[v].pb(mp(u, w));
	}
	int cen = find_cen();
	dfs(cen, cen, 0);
	dfs1(cen, cen);
	int low = 0, high = (int)2e9;
	while (low < high) {
		int mid = low + high >> 1;
		memset(f, 0, sizeof f);
		f[cen] = 1, flag = 1;
		dfs2(cen, cen, mid);
		int sum = 0;
		for (int i = 1; i <= n ;++i) sum += f[i];
		if (sum > k) flag = 0;
		if (flag) high = mid;
		else low = mid + 1;
	}
	cout << low << '\n';
}