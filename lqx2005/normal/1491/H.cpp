#include<bits/stdc++.h>

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define x first
#define y second
#define mp make_pair
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef pair<int, int> par;
typedef long long LL;
typedef double db;
const int N = 1e5 + 10, B = 316;
int n, q;
int pa[N];
int off[N], pre[N], add[N];
int l[N], r[N], bl[N], mxB;
int vis[N], C[N],  tot = 0;

int Pa(int x) { return x <= 1 ? 0 : max(1, pa[x] - add[bl[x]]); }

void del(int l, int r, int x) {
	rep(i, l, r) pa[i] = max(1, pa[i] - x);
	return;
}

void build(int p, int x = 0) {
	if(off[p]) {
		add[p] += x;
		return;
	}
	rep(i, l[p], r[p]) {
		pa[i] = max(1, pa[i] - x);
		if(pa[i] < l[p]) pre[i] = i;
		else pre[i] = pre[pa[i]], off[p] = 1;
	}
	off[p] ^= 1;
	return;
}

void change(int L, int R, int x) {
	if(bl[L] == bl[R]) {
		del(L, R, x);
		build(bl[L]);
		return;
	}
	rep(i, bl[L] + 1, bl[R] - 1) build(i, x);
	del(L, r[bl[L]], x);
	del(l[bl[R]], R, x);
	build(bl[L]), build(bl[R]);
	return;
}

void initB() {
	pre[1] = 1;
	mxB = (n - 2) / B + 1;
	rep(i, 2, n) bl[i] = (i - 2) / B + 1;
	l[bl[2]] = r[bl[2]] = 2;
	rep(i, 3, n) {
		if(bl[i - 1] != bl[i]) l[bl[i]] = i;
		r[bl[i]] = i;
	}
	rep(i, 1, mxB) build(i);
	return;
}


int query(int u, int v) {
	if(u <= 1 || v <= 1) return 1;
	if(u == v) return u;
	C[tot = 1] = u;
	for(int x = pre[u]; x; ) {
		C[++tot] = x;
		vis[x] = tot;
		x = pre[Pa(x)];
	}
	int pr = v;
	int blc(-1), nu(-1), nv(-1);
	for(int x = pre[v]; x; ) {
		if(vis[x]) {
			blc = x;
			nu = C[vis[x] - 1];
			nv = pr;
			break;
		}
		pr = x;
		x = pre[Pa(x)];
	}
	assert(blc > 0 && nu > 0 && nv > 0);
	rep(i, 1, tot) vis[C[i]] = 0;
	tot = 0;
	for(int x = nu; x != blc; x = Pa(x)) vis[x] = 1, C[++tot] = x;
	vis[blc] = 1;
	C[++tot] = blc;
	int lca = blc;
	for(int x = nv; x != blc; x = Pa(x)) {
		if(vis[x]) {
			lca = x;
			break;
		}
	}
	rep(i, 1, tot) vis[C[i]] = 0;
	tot = 0;
	return lca;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	rep(i, 2, n) cin >> pa[i];
	initB();
	int t, l, r, x, u, v;
	rep(i, 1, q) {
		cin >> t;
		if(t == 1) {
			cin >> l >> r >> x;
			change(l, r, x);
		} else {
			cin >> u >> v;
			cout << query(u, v) << endl;
		}
	}
	return 0;
}