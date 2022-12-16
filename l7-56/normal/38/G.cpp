#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 1e5 + 10;
int a[maxn],c[maxn],n,b[maxn],cnt;
struct Splay {
	struct node {
		int son[2], fa, siz, mx, val, id;
	}tr[maxn];
	int tot,rt;
	#define son(x, y) tr[x].son[y]
	#define fa(x) tr[x].fa
	#define siz(x) tr[x].siz
	#define mx(x) tr[x].mx
	#define val(x) tr[x].val
	#define id(x) tr[x].id
	void init() {
		tot = 2;
		son(1, 1) = 2, fa(2) = 1;
		val(1) = mx(1) = n + 1;
		val(2) = mx(2) = -1;
		siz(1) = 2, siz(2) = 1;
		rt = 1;
	}
	int NEW(int i) {
		int x = ++tot;
		son(x, 0) = son(x, 1) = fa(x) = 0;
		siz(x) = 1, mx(x) = val(x) = a[i], id(x) = i;
		return x;
	}
	void push_up(int o) {
		if (!o) return;
		int ls = son(o, 0), rs = son(o, 1);
		siz(o) = siz(ls) + siz(rs) + 1;
		mx(o) = max(max(mx(ls), mx(rs)), val(o));
	}
	int get(int x) { return x == son(fa(x), 1); }
	void rotate(int x) {
		int y = fa(x), z = fa(y), f1 = get(x), f2 = get(y);
		son(y, f1) = son(x, !f1);
		if (son(y, f1)) fa(son(y, f1)) = y;
		fa(y) = x, son(x, !f1) = y, fa(x) = z;
		if (z) son(z, f2) = x;
		push_up(y), push_up(x);
	}
	void splay(int x, int target) {
		for (int f = fa(x); f != target; rotate(x), f = fa(x))
			if (fa(f) != target) get(x) == get(f) ? rotate(f) : rotate(x);
		if (target == 0) rt = x;
	}
	int get_id_by_rk(int o, int k) {
		if (siz(son(o, 0)) >= k) return get_id_by_rk(son(o, 0), k);
		else if (siz(son(o, 0)) + 1 == k) return o;
		else return get_id_by_rk(son(o, 1), k - siz(son(o, 0)) - 1);
	}
	int & split(int l, int r) {
		int x = get_id_by_rk(rt, l - 1), y = get_id_by_rk(rt, r + 1);
		// printf("[%d, %d] %d %d\n", l, r, x, y);
		splay(x, 0), splay(y, x);
		return son(son(rt, 1), 0);
	}
	void ins(int &o, int f, int i) {
		if (!o) {
			o = NEW(i), fa(o) = f;
			splay(o, 0);
			return;
		}
		if (a[i] <= max(mx(son(o, 1)), val(o))) ins(son(o, 1), o, i);
		else ins(son(o, 0), o, i);
	}
	void print(int o) {
		if (!o) return;
		print(son(o, 0));
		b[++cnt] = id(o);
		print(son(o, 1));
	}
	#undef son
	#undef fa
	#undef siz
	#undef mx
	#undef val
	#undef id
}T;

int main() {
	scanf("%d", &n);
	T.init();
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &a[i], &c[i]);
		int &x = T.split(max(i - c[i] + 1, 2), i);
		T.ins(x, T.tr[T.rt].son[1], i);
	}
	T.print(T.rt);
	for (int i = 2; i < cnt; ++i) printf("%d ", b[i]);
	return 0;
}