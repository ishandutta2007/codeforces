#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 400005, S = 301, P = 1e9 + 7, K = 62;
int n, Q, a[N], id[N], d[N], inv[S], tot = 0;
bool inline check(int x) {
	for (int i = 2; i * i <= x; i++)
		if(x % i == 0) return false;
	return true;
}
int inline power(int a, int b) {
	int res = 1;
	while(b) {
		if(b & 1) res = (LL)res * a % P;
		a = (LL)a * a % P;
		b >>= 1;
	}
	return res;
}
LL div(int x) {
	LL res = 0;
	for (int i = 0; i < tot; i++) {
		if(x % d[i] == 0) {
			res |= 1ll << i;
			while(x % d[i] == 0) x /= d[i];
		}
	}
	return res;
}
struct T{
	int l, r, v; 
};
struct T2{
	int l, r;
	LL v;
};
struct Mul{
	T t[N << 2];
	int tag[N << 2];
	void inline pushup(int p) {
		t[p].v = (LL)t[p << 1].v * t[p << 1 | 1].v % P;
	}
	void inline pushdown(int p) {
		if(tag[p] == 1) return;
		t[p << 1].v = (LL)t[p << 1].v * power(tag[p], t[p << 1].r - t[p << 1].l + 1) % P;
		t[p << 1 | 1].v = (LL)t[p << 1 | 1].v * power(tag[p], t[p << 1 | 1].r - t[p << 1 | 1].l + 1) % P;
 		tag[p << 1] = (LL)tag[p << 1] * tag[p] % P;
 		tag[p << 1 | 1] = (LL)tag[p << 1 | 1] * tag[p] % P;
		tag[p] = 1;
	}
	void build(int p, int l, int r) {
		t[p].l = l, t[p].r = r, tag[p] = 1;
		if(l == r) {
			t[p].v = a[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(p << 1, l, mid);
		build(p << 1 | 1, mid + 1, r); 
		pushup(p); 
	}
	void change(int p, int x, int y, int k) {
		if(x <= t[p].l && t[p].r <= y) {
			t[p].v = (LL)t[p].v * power(k, t[p].r - t[p].l + 1) % P;
			tag[p] = (LL)tag[p] * k % P;
			return ;
		}
		pushdown(p);
		int mid = (t[p].l + t[p].r) >> 1;
		if(x <= mid) change(p << 1, x, y, k);
		if(mid + 1 <= y) change(p << 1 | 1, x, y, k);
		pushup(p); 
	}
	
	int query(int p, int x, int y) {
		if(x <= t[p].l && t[p].r <= y) {
			return t[p].v;
		}
		pushdown(p);
		int res = 1;
		
		int mid = (t[p].l + t[p].r) >> 1;
		if(x <= mid) res = (LL)res * query(p << 1, x, y) % P;
		if(mid + 1 <= y) res = (LL)res * query(p << 1 | 1, x, y) % P;
		return res;
	}
}t1;	

struct ST{
	T2 t[N << 2];
	LL tag[N << 2];
	void inline pushup(int p) {
		t[p].v = t[p << 1].v | t[p << 1 | 1].v;
	}
	void inline pushdown(int p) {
		if(!tag[p]) return;
		t[p << 1].v |= tag[p];
		t[p << 1 | 1].v |= tag[p];
		tag[p << 1] |= tag[p];
		tag[p << 1 | 1] |= tag[p];
		tag[p] = 0; 
	}
	void build(int p, int l, int r) {
		t[p].l = l, t[p].r = r; tag[p] = 0;
		if(l == r) {
			t[p].v = div(a[l]);
			return;
		}
		int mid = (l + r) >> 1;
		build(p << 1, l, mid);
		build(p << 1 | 1, mid + 1, r); 
		pushup(p);
	}
	void change(int p, int x, int y, LL k) {
		if(x <= t[p].l && t[p].r <= y) {
			t[p].v |= k;
			tag[p] |= k;
			return ;
		}
		pushdown(p);
		int mid = (t[p].l + t[p].r) >> 1;
		if(x <= mid) change(p << 1, x, y, k);
		if(mid + 1 <= y) change(p << 1 | 1, x, y, k);
		pushup(p); 
	}
	
	LL query(int p, int x, int y) {
		if(x <= t[p].l && t[p].r <= y) {
			return t[p].v;
		}
		LL res = 0;
		pushdown(p);
		int mid = (t[p].l + t[p].r) >> 1;
		if(x <= mid) res |= query(p << 1, x, y);
		if(mid + 1 <= y) res |= query(p << 1 | 1, x, y);
		return res;
	}
}t2;	

int main(){
	
 	for (int i = 2; i < S; i++) {
		if(check(i)) {
			id[i] = tot;
			d[tot++] = i;	
		}
	}
	for (int i = 0; i < tot; i++) {
		inv[i] = power(d[i], P - 2);
	}
	scanf("%d%d", &n, &Q);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
		
	t1.build(1, 1, n);
	t2.build(1, 1, n);
	while(Q--) {
		char op[10]; int l, r, x;
		scanf("%s", op);
		if(op[0] == 'M'){
			scanf("%d%d%d", &l, &r, &x);
			t1.change(1, l, r, x);
			t2.change(1, l, r, div(x));
		} else {
			scanf("%d%d", &l, &r);
			LL ans = t1.query(1, l, r), st = t2.query(1, l, r);
	
			for (int i = 0; i < tot; i++) {
				if(st >> i & 1){
					ans = ans * inv[i] % P * (d[i] - 1) % P;
				}
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}