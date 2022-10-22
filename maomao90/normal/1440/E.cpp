#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
	int lo, hi, mid;
	ll val, mx, mn, lazy;
	node *l, *r;
	node(int lo, int hi): lo(lo), hi(hi), mid((lo + hi) / 2), val(0), mn(0), mx(0), lazy(-1) {
		if (lo != hi) l = new node(lo, mid), r = new node(mid + 1, hi);
	}
	void build(int *arr) {
		if (lo == hi) val = mn = mx = arr[lo];
		else {
			l -> build(arr), r -> build(arr);
			val = r -> val + l -> val;
			mn = min(r -> mn, l -> mn);
			mx = max(r -> mx, l -> mx);
		}
	}
	void propo() {
		if (lazy == -1) return;
		val = lazy * (hi - lo + 1);
		mn = lazy;
		mx = lazy;
		if (lo != hi) {
			l -> lazy = lazy;
			r -> lazy = lazy;
		}
		lazy = -1;
	}
	void update(int x, int y) {
		propo();
		if (lo > x || mn >= y) return;
		if (mx <= y && hi <= x) {
			lazy = y;
			propo();
			return;
		}
		l -> update(x, y);
		r -> update(x, y);
		val = l -> val + r -> val;
		mn = min(r -> mn, l -> mn);
		mx = max(r -> mx, l -> mx);
	}
	int query(int x, int &y) {
		propo();
		int cnt = 0;
		if (hi < x) return 0;
		if (mn > y) return 0;
		if (lo >= x && val <= y) {
			cnt += hi - lo + 1;
			y -= val;
			return cnt;
		}
		cnt += l -> query(x, y);
		cnt += r -> query(x, y);
		return cnt;
	}
} *root;

int n, q;
int a[200005];

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	root = new node(1, n);
	root -> build(a);
	for (int i = 0; i < q; i++) {
		int t, x, y; scanf("%d%d%d", &t, &x, &y);
		if (t == 1) {
			root -> update(x, y);
		} else {
			printf("%d\n", root -> query(x, y));
		}
	}
	return 0;
}