#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;

const int maxn = 3e5 + 10;
const ll inf = 4e18;
int n,m,st[maxn];
struct node {
	int l, r, x, y;
}a[maxn], b[maxn];

struct convex {
	vector <int> v;
	int nw;
	#define X(i) a[i].x
	#define Y(i) a[i].y
	#define slope(i, j) (1.0 * (Y(j) - Y(i)) / (X(j) - X(i)))
	void build() {
		if (v.empty()) return;
		int tp = 0;
		for (int x : v) {
			while (tp > 1 && slope(st[tp], x) > slope(st[tp - 1], x)) --tp;
			st[++tp]=x;
		}
		v.clear();
		for (int i = 1; i <= tp; ++i) v.push_back(st[i]);
	}
	ll query(int k) {
		#define calc(i) (1ll * a[i].x * k + a[i].y)
		if (v.empty()) return -inf;
		int len = v.size();
		while (nw + 1 < len && calc(v[nw]) <= calc(v[nw + 1])) ++nw;
		return calc(v[nw]);
		#undef calc
	}
}tr[maxn << 2];
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define mid ((l + r) >> 1)
void update(int rt, int l, int r, int i) {
	if (a[i].l > r || a[i].r < l) return;
	if (a[i].l <= l && r <= a[i].r) return tr[rt].v.push_back(i);
	update(ls, l, mid, i), update(rs, mid + 1, r, i);
}

void build(int rt, int l, int r) {
	tr[rt].build();
	if (l == r) return;
	build(ls, l, mid), build(rs, mid + 1, r);
}

ll query(int rt, int l, int r, int i) {
	ll res = tr[rt].query(b[i].x);
	if (l == r) return res;
	if (b[i].l <= mid) return max(res, query(ls, l, mid, i));
	else return max(res, query(rs, mid + 1, r, i));
}
#undef ls
#undef rs
#undef mid

int id[maxn];
ll ans[maxn];

int main() {
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		int t; scanf("%d", &t);
		if (t == 1) {
			id[i] = ++n;
			scanf("%d%d", &a[n].x, &a[n].y);
			a[n].l = i;
		}
		if (t == 2) {
			int x; scanf("%d", &x);
			a[id[x]].r = i - 1;
		}
		if (t == 3) {
			b[++m].l = i, b[m].r = m;
			scanf("%d", &b[m].x);
		}
	}
	sort(a + 1, a + n + 1, [] (node p, node q) { return p.x < q.x || (p.x == q.x && p.y < q.y); });
	for (int i = 1; i <= n; ++i) {
		if (!a[i].r) a[i].r = q;
		update(1, 1, q, i);
	}
	build(1, 1, q);
	sort(b + 1, b + m + 1, [] (node p, node q) { return p.x < q.x; });
	for (int i = 1; i <= m; ++i) ans[b[i].r] = query(1, 1, q, i);
	for (int i = 1; i <= m; ++i)
		if (ans[i] > -inf) printf("%lld\n", ans[i]);
		else printf("EMPTY SET\n");
	return 0;
}