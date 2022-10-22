#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef double db;
const int N = 1e6 + 10;
struct node {
	int sum, pre;
	node() {sum = pre = 0; }
	node(int Sum, int Pre) {sum = Sum, pre = min(Pre, 0); }
	friend node operator + (const node a, const node b) {
		return node(a.sum + b.sum, min(a.pre, b.pre + a.sum));
	}
};
node t[N << 2];
int n, m, a[N], b[N], id[N], add[N];

void modify(int p, int l, int r, int x, int v) {
	if(l == r) return void(t[p] = node(v, v));
	int mid = (l + r) / 2;
	if(x <= mid) modify(p << 1, l, mid, x, v);
	else modify(p << 1 | 1, mid + 1, r, x, v);
	return t[p] = t[p << 1] + t[p << 1 | 1], void();
}

node query(int p, int l, int r, int L, int R) {
	if(L > R) return node();
	if(L <= l && r <= R) return t[p];
	int mid = (l + r) / 2;
	if(R <= mid) return query(p << 1, l, mid, L, R);
	if(L > mid) return query(p << 1 | 1, mid + 1, r, L, R);
	return query(p << 1, l, mid, L, mid) + query(p << 1 | 1, mid + 1, r, mid + 1, R);
}

void build(int p, int l, int r, int v) {
	if(l == r) return void(t[p] = node(v, v));
	int mid = (l + r) / 2;
	build(p << 1, l, mid, v), build(p << 1 | 1, mid + 1, r, v);
	return t[p] = t[p << 1] + t[p << 1 | 1], void();
}

void solve() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), id[i] = i;
	for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
	sort(b + 1, b + m + 1);
	sort(id + 1, id + n + 1, [&](int x, int y) {
		if(a[x] != a[y]) return a[x] < a[y];
		return x < y;
	});
	build(1, 1, n, 1);
	int r = 0;
	i64 ans = 0;
	for(int i = 1; i <= m; i++) {
		if(b[i] == b[i - 1]) {
			add[i] = add[i - 1];
			continue;
		}
		while(r + 1 <= n && a[id[r + 1]] < b[i]) {
			r++, modify(1, 1, n, id[r], -1);
		}
		int rr = r;
		while(rr + 1 <= n && a[id[rr + 1]] == b[i]) {
			rr++, modify(1, 1, n, id[rr], 0);
		}
		add[i] = r + t[1].pre;
	}
	for(int i = 1; i <= m; i++) ans += add[i];
	build(1, 1, n, 0);
	for(int i = 1; i <= n; i++) {
		ans += query(1, 1, n, id[i] + 1, n).sum;
		modify(1, 1, n, id[i], 1);
	}
	printf("%lld\n", ans);
	return;
}

int main() {
	int T;
	for(scanf("%d", &T); T--; solve());
	return 0;
}