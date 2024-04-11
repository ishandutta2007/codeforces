#include <bits/stdc++.h>
#define mid ((l + r) >> 1)
#define ls (p + 1)
#define rs (p + ((mid - l + 1) << 1))
using namespace std;
const int N = 1e6 + 10, V = 1e6;
int n, q, a[N];
int mn[N << 1], cnt[N << 1], tag[N << 1];

void upd(int p, int l, int r) {
	mn[p] = min(mn[ls], mn[rs]);
	cnt[p] = 0;
	if(mn[p] == mn[ls]) cnt[p] += cnt[ls];
	if(mn[p] == mn[rs]) cnt[p] += cnt[rs];
	return;
}

void pushd(int p, int l, int r) {
	if(!tag[p]) return;
	tag[ls] += tag[p], mn[ls] += tag[p];
	tag[rs] += tag[p], mn[rs] += tag[p];
	tag[p] = 0;
	return;
}

void modify(int p, int l, int r, int L, int R, int v) {
	if(R < l || L > r) return;
	if(L <= l && r <= R) {
		tag[p] += v;
		mn[p] += v;
		return;
	}
	pushd(p, l, r);
	if(L <= mid) modify(ls, l, mid, L, R, v);
	if(R > mid) modify(rs, mid + 1, r, L, R, v);
	return upd(p, l, r);
}

void change(int p, int l, int r, int x, int v) {
	if(l == r) return cnt[p] += v, void();
	pushd(p, l, r);
	if(x <= mid) change(ls, l, mid, x, v);
	else change(rs, mid + 1, r, x, v);
	return upd(p, l, r);
}

void flip(int p, int v) {
	change(1, 1, V, a[p], v);
	if(a[p - 1] > a[p]) modify(1, 1, V, a[p], a[p - 1] - 1, v);
	if(a[p] > a[p + 1]) modify(1, 1, V, a[p + 1], a[p] - 1, v);
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		change(1, 1, V, a[i], 1);
	}
	a[0] = V + 1, a[n + 1] = 0;
	for(int i = 1; i <= n + 1; i++) {
		if(a[i - 1] > a[i]) {
			modify(1, 1, V, a[i], a[i - 1] - 1, 1);
		}
	}
	for(int i = 1; i <= q; i++) {
		int p, v;
		cin >> p >> v;
		flip(p, -1);
		a[p] = v;
		flip(p, 1);
		cout << cnt[1] << endl;
	}
	return 0;
}