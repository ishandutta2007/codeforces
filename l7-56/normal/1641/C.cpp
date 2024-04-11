#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 2e5 + 10;
int n,q;
struct SegTree {
	int cov[maxn << 2], len[maxn << 2];
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	void clear(int rt, int l, int r) {
		cov[rt] = len[rt] = 0;
		if (l == r) return;
		clear(ls, l, mid), clear(rs, mid + 1, r);
	}
	void push_up(int rt) { len[rt] = len[ls] + len[rs]; }
	void push_down(int rt, int l, int r) { if (cov[rt]) cov[ls] = cov[rs] = 1, len[ls] = mid - l + 1, len[rs] = r - mid; }
	void upd(int rt, int l, int r, int pos) {
		if (l == r) return cov[rt] = 2, len[rt] = 0, void();
		push_down(rt, l, r), pos <= mid ? upd(ls, l, mid, pos) : upd(rs, mid + 1, r, pos), push_up(rt);
	}
	void COV(int rt, int l, int r, int L, int R) {
		if (L > r || R < l) return;
		if (L <= l && r <= R) return cov[rt] = 1, len[rt] = r - l + 1, void();
		push_down(rt, l, r), COV(ls, l, mid, L, R), COV(rs, mid + 1, r, L, R), push_up(rt);
	}
	int query_sum(int rt, int l, int r, int L, int R) {
		if (L > r || R < l) return 0;
		if (L <= l && r <= R) return len[rt];
		push_down(rt, l, r); return query_sum(ls, l, mid, L, R) + query_sum(rs, mid + 1, r, L, R);
	}
	int query_pos(int rt, int l, int r, int pos) {
		if (l == r) return cov[rt];
		push_down(rt, l, r); return pos <= mid ? query_pos(ls, l, mid, pos) : query_pos(rs, mid + 1, r, pos);
	}
	int query1(int rt, int l, int r) {
		if (l == r) return l;
		push_down(rt, l, r);
		if (len[ls] == mid - l + 1) return query1(rs, mid + 1, r);
		return query1(ls, l, mid);
	}
	int query1(int rt, int l, int r, int L, int R) {
		if (L > r || R < l) return -1;
		if (L <= l && r <= R) {
			if (len[rt] == r - l + 1) return -1;
			return query1(rt, l, r);
		}
		push_down(rt, l, r);
		return max(query1(ls, l, mid, L, R), query1(rs, mid + 1, r, L, R));
	}
	#undef ls
	#undef rs
	#undef mid
}T;
struct ope {
	int op, l, r, x, id;
}a[maxn];

namespace prework {
	struct que {
		int id, l, r, mid;
	}t[maxn];
	int tot;
	SegTree T;
	void solve() {
		for (int i = 1; i <= q; ++i)
			if (a[i].op == 0 && a[i].x) t[++tot] = {i, a[i].id, q + 1, (q + 1 + a[i].id) >> 1};
		for (bool flg = 1; flg; ) {
			T.clear(1, 1, n);
			sort(t + 1, t + tot + 1, [] (que a, que b) { return a.mid < b.mid; });
			// for (int i = 1; i <= tot; ++i) printf("#%d [%d, %d] %d\n", t[i].id, t[i].l, t[i].r, t[i].mid);
			int pos = 1;
			for (int i = 1; i <= q; ++i) {
				if (a[i].op == 0 && a[i].x == 0) T.COV(1, 1, n, a[i].l, a[i].r);
				while (pos <= tot && t[pos].mid <= i) {
					int j = t[pos].id;
					int cnt = T.query_sum(1, 1, n, a[j].l, a[j].r);
					// printf("%d : %d\n", j, cnt);
					if (cnt >= a[j].r - a[j].l) t[pos].r = t[pos].mid;
					else t[pos].l = t[pos].mid + 1;
					++pos;
				}
			}
			flg = 0;
			for (int i = 1; i <= tot; ++i) {
				t[i].mid = (t[i].l + t[i].r) >> 1;
				// printf("%d %d\n", t[i].l, t[i].r);
				flg |= (t[i].l < t[i].r);
			}
			// printf("flg : %d\n", flg);
		}
		sort(t + 1, t + tot + 1, [] (que a, que b) { return a.mid < b.mid; });
		T.clear(1, 1, n);
		int pos = 1;
		for (int i = 1; i <= q; ++i) {
			if (a[i].op == 0 && a[i].x == 0) T.COV(1, 1, n, a[i].l, a[i].r);
			while (pos <= tot && t[pos].mid <= i) {
				int j = t[pos].id;
				a[j] = {2, T.query1(1, 1, n, a[j].l, a[j].r), 0, 1, t[pos].mid};
				++pos;
			}
		}
		while (pos <= tot) {
			int j = t[pos].id;
			a[j] = {2, 1, 0, 1, q + 1};
			++pos;
		}
	}
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= q; ++i) {
		scanf("%d", &a[i].op); a[i].id = i;
		if (!a[i].op) scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].x);
		else scanf("%d", &a[i].l);
	}
	prework :: solve();
	sort(a + 1, a + q + 1, [] (ope x, ope y) { return x.id < y.id; });
	T.clear(1, 1, n);
	for (int i = 1; i <= q; ++i) {
		// printf("(%d, %d, %d, %d, %d)\n", a[i].op, a[i].l, a[i].r, a[i].x, a[i].id);
		if (a[i].op == 0) T.COV(1, 1, n, a[i].l, a[i].r);
		else if (a[i].op == 1) {
			int x = T.query_pos(1, 1, n, a[i].l);
			if (x == 1) printf("NO\n");
			else if (x == 2) printf("YES\n");
			else printf("N/A\n");
		}
		else T.upd(1, 1, n, a[i].l);
	}
	return 0;
}