#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
const int mod = 1e9 + 7;

void add(int &a,int b) {
	a += b; if (a >= mod) a -= mod;
}

struct segTree {
	int t[N << 2], lz[N << 2];
	void push(int v,int l,int r) {
		if (!lz[v]) return;
		add(t[v], 1ll * lz[v] * (r - l + 1) % mod);
		if (l < r) {
			add(lz[v << 1], lz[v]);
			add(lz[v << 1 | 1], lz[v]);
		}
		lz[v] = 0;
	}
	void upd(int v,int l,int r,int L,int R,int val) {
		push(v, l, r);
		if (L > r || R < l) return;
		if (L <= l && R >= r) {
			lz[v] = val; push(v, l, r);
			return;
		}
		int mid = l + r >> 1;
		upd(v << 1, l, mid, L, R, val);
		upd(v << 1 | 1, mid + 1, r, L, R, val);
		t[v] = t[v << 1], add(t[v], t[v << 1 | 1]);
	}
	int get(int v,int l,int r,int L,int R) {
		push(v, l, r);
		if (L > r || R < l) return 0;
		if (L <= l && R >= r) return t[v];
		int mid = l + r >> 1;
		int ret = get(v << 1, l, mid, L, R);
		add(ret, get(v << 1 | 1, mid + 1, r, L, R));
		return ret;
	}
} st[2];

int n, q;
vector<int> G[N];
int le[N], ri[N], lev[N];
int tot = 0;

void dfs(int u) {
	le[u] = ++tot;
	for (int v : G[u]) {
		lev[v] = lev[u] + 1;
		dfs(v);
	}
	ri[u] = tot;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		int p; cin >> p;
		G[p].push_back(i);
	}
	
	dfs(1);
	
	cin >> q;
	while (q--) {
		int op; cin >> op;
		if (op == 1) {
			int u, x, k; cin >> u >> x >> k;
			add(x, 1ll * lev[u] * k % mod);
			st[0].upd(1, 1, n, le[u], ri[u], x);
			st[1].upd(1, 1, n, le[u], ri[u], k);
		}
		else {
			int v; cin >> v;
			int res = st[0].get(1, 1, n, le[v], le[v]);
			int tmp = st[1].get(1, 1, n, le[v], le[v]);
			add(res, mod - 1ll * lev[v] * tmp % mod);
			cout << res << '\n';
		}
		
	}
}