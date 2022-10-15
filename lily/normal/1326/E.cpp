#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second

#define N 601111

// segtree.cpp @ fstqwq/CodeForcesTemplate
template <class V, class UPD> class Tree {
public:
	struct Node {
		int l, r;
		V v;
	} t[N * 2] ;
	int tcnt, L, R;
	int build(int l, int r) {
		int x = ++tcnt;
		if (l < r) {
			int mid = (l + r) / 2;
			t[x].l = build(l, mid);
			t[x].r = build(mid + 1, r);
			t[x].v = t[t[x].l].v + t[t[x].r].v;
		}
		else {
			t[x].l = t[x].r = 0;
			t[x].v = l & 1 ? V(0, 0) : V(0, 0);
		}
		return x;
	}

	void upd(int x, int l, int r, const int& p, const UPD& v) {
		if (l == r) {
			t[x].v = v;
			return; 
		}
		int mid = (l + r) / 2;
		if (p <= mid) upd(t[x].l, l, mid, p, v);
		else upd(t[x].r, mid + 1, r, p, v);
		t[x].v = t[t[x].l].v + t[t[x].r].v;
	}
	V qry(int x, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return t[x].v;
		int mid = (l + r) / 2;
		if (qr <= mid) return qry(t[x].l, l, mid, ql, qr);
		if (ql >  mid) return qry(t[x].r, mid + 1, r, ql, qr);
		return qry(t[x].l, l, mid, ql, mid) + qry(t[x].r, mid + 1, r, mid + 1, qr);
	}

	Tree () {}
	void init(int l, int r) {
		L = l, R = r;
		tcnt = 0;
		build(l, r);
	}
	inline void upd(int p, const UPD &v) {upd(1, L, R, p, v);}
	inline V qry(int l, int r) {return qry(1, L, R, l, r);}
};


struct V {
	int pre, add;
	V () {}
	V (int x, int y) {pre = x; add = y;}
	friend V operator + (const V &u, const V &v) {
		if (v.pre > u.add) return {u.pre + v.pre - u.add, v.add};
		else return {u.pre, u.add + v.add - v.pre};
	}
};

Tree <V, V> t;

int n;
int p[N], q[N], ip[N];
int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(p[i]);
		ip[p[i]] = i;
	}
	for (int i = 1; i <= n; i++) read(q[i]);
	t.init(1, 2 * n);
	int ans = n + 1;
	for (int i = 1; i <= n; i++) {
		while (t.t[1].v.add == 0) {
			ans--;
			t.upd(ip[ans] * 2 - 1, V(0, 1));
		}
		printf("%d ", ans);
		t.upd(q[i] * 2, V(1, 0));
	}

}