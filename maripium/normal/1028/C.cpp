#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int inf = 1e9;

struct Rect {
	int lx, ly, rx, ry;
	Rect(int lx = -inf, int ly = -inf,int rx = inf,int ry = inf) : lx(lx), ly(ly), rx(rx), ry(ry) {}
};

Rect Gay() {
	return Rect(inf, inf, -inf, -inf);
}

Rect merge(Rect L, Rect R) {
	if (L.lx == inf) return Gay();
	if (R.lx == inf) return Gay();
	if (L.rx < R.lx || L.lx > R.rx) return Gay();
	if (L.ry < R.ly || L.ly > R.ry) return Gay();
	Rect ret;
	ret.lx = max(L.lx, R.lx);
	ret.rx = min(L.rx, R.rx);
	ret.ly = max(L.ly, R.ly);
	ret.ry = min(L.ry, R.ry);
	return ret;
}

int n;
Rect a[N];
Rect t[N << 2];

void build(int v,int l,int r) {
	if (l == r) {
		t[v] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(v << 1, l, mid);
	build(v << 1 | 1, mid + 1, r);
	t[v] = merge(t[v << 1], t[v << 1 | 1]);
}

Rect get(int v,int l,int r,int L,int R) {
	if (L > r || R < l || L > R) return Rect();
	if (L <= l && R >= r) return t[v];
	int mid = l + r >> 1;
	return merge(get(v << 1, l, mid, L, R), get(v << 1 | 1, mid + 1, r, L, R));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].lx >> a[i].ly >> a[i].rx >> a[i].ry;
	}
	
	build(1, 1, n);
	for (int i = 1; i <= n; ++i) {
		Rect cur = merge(get(1, 1, n, 1, i - 1), get(1, 1, n, i + 1, n));
		if (cur.lx != inf) {
			cout << cur.lx << ' ' << cur.ly << '\n';
			return 0;
		}
	}
}