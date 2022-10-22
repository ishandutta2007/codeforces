#include <bits/stdc++.h>
#define x first
#define y second
#define pi pair<int, int>
#define pb push_back
#define i64 long long
#define mid ((l + r) >> 1)
#define ls (p + 1)
#define rs (p + ((mid - l + 1) << 1))
using namespace std;
const int N = 1e5 + 10, oo = 0x3f3f3f3f;
struct node {
	int pre, sum;
	node() {pre = sum = 0; }
	node(int Pre, int Sum) {pre = Pre, sum = Sum; }
	node(int Val) {pre = sum = Val; }
	friend void operator += (node &a, const int v) {
		a.pre += v, a.sum += v;
	}
	friend node operator + (const node a, const node b) {
		return node(max(b.pre, a.pre + b.sum), a.sum + b.sum);
	}
};
int n, q;
vector<int> g[N];
int tag[N << 1];
node t[N << 1];
int pa[N], son[N], sze[N], top[N], dfn[N], rev[N], dfc = 0;
int L[N], R[N];
void dfs1(int u, int fa) {
	pa[u] = fa;
	sze[u] = 1;
	for(int &v : g[u]) {
		if(v == fa) continue;
		dfs1(v, u);
		sze[u] += sze[v];
		if(sze[son[u]] < sze[v]) {
			son[u] = v;
		}
	}
	return;
}

void dfs2(int u, int tp) {
	top[u] = tp;
	L[u] = dfn[u] = ++dfc, rev[dfc] = u;
	if(son[u]) dfs2(son[u], tp);
	for(int &v : g[u]) {
		if(v == pa[u] || v == son[u]) continue;
		dfs2(v, v);
	}
	R[u] = dfc;
	return;
}

void cover(int p, int l, int r) {
	tag[p] = 1;
	t[p] = l - r - 1;
}

void pushd(int p, int l, int r) {
	if(!tag[p]) return;
	cover(ls, l, mid), cover(rs, mid + 1, r);
	tag[p] = 0;
}

void modify(int p, int l, int r, int x, int v) {
	if(l == r) {
		t[p] += v;
		// cout << t[p].pre <<" " << t[p].sum << endl;
		return;
	}
	pushd(p, l, r);
	if(x <= mid) modify(ls, l, mid, x, v);
	else modify(rs, mid + 1, r, x, v);
	return t[p] = t[ls] + t[rs], void();
}

void Cover(int p, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		cover(p, l, r);
		return;
	}
	pushd(p, l, r);
	if(L <= mid) Cover(ls, l, mid, L, R);
	if(R > mid) Cover(rs, mid + 1, r, L, R);
	return t[p] = t[ls] + t[rs], void();
}

node query(int p, int l, int r, int L, int R) {
	if(L <= l && r <= R) return t[p];
	pushd(p, l, r);
	if(R <= mid) return query(ls, l, mid, L, R);
	if(L > mid) return query(rs, mid + 1, r, L, R);
	return query(ls, l, mid, L, R) + query(rs, mid + 1, r, L, R);
}

void build(int p, int l, int r) {
	tag[p] = 0;
	if(l == r) {
		t[p] = -1;
		return;
	}
	build(ls, l, mid), build(rs, mid + 1, r);
	t[p] = t[ls] + t[rs];
	return;
}

node Query(int x) {
	node res(-oo, 0);
	for(; x; ) {
		res = query(1, 1, n, dfn[top[x]], dfn[x]) + res;
		// cout << res.pre <<" " << res.sum << endl;
		x = pa[top[x]];
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(int i = 2, fa; i <= n; i++) {
		cin >> fa;
		g[i].pb(fa), g[fa].pb(i);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	build(1, 1, n);
	for(int i = 1; i <= q; i++) {
		int opt, x;
		cin >> opt >> x;
		if(opt == 1) {
			modify(1, 1, n, dfn[x], 1);
		} else if(opt == 2) {
			Cover(1, 1, n, L[x], R[x]);
			int val = Query(x).pre;
			if(val >= 0) {
				modify(1, 1, n, dfn[x], -val - 1);
			}
		} else {
			int val = Query(x).pre;
			if(val >= 0) cout << "black" << endl;
			else cout << "white" << endl;
		}
	}
	return 0;
}