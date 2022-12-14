#include <cstdio>
const int MAX = 100005, INF = (1 << 30) - 1;

struct segtree{
	int a[MAX << 2], o[MAX << 2], ql, qr, qv;

	void pushDown(int x){
		if(o[x]){
			a[x << 1] |= o[x];
			a[x << 1 | 1] |= o[x];
			o[x << 1] |= o[x];
			o[x << 1 | 1] |= o[x];
			o[x] = 0;
		}
	}
	int query(int x, int l, int r){
		if(l >= ql && r <= qr) return a[x];
		pushDown(x);
		int mid = (l + r) >> 1, ret = INF;
		if(ql <= mid) ret &= query(x << 1, l, mid);
		if(qr > mid) ret &= query(x << 1 | 1, mid + 1, r);
		return ret;
	}
	void update(int x, int l, int r){
		if(l >= ql && r <= qr){
			o[x] |= qv;
			a[x] |= qv;
			return;
		}
		pushDown(x);
		int mid = (l + r) >> 1;
		if(ql <= mid) update(x << 1, l, mid);
		if(qr > mid) update(x << 1 | 1, mid + 1, r);
		a[x] = a[x << 1] & a[x << 1 | 1];
	}
}sgt;
struct query{
	int l, r, v;
}q[MAX];
int n, m;

int main(){
	int i;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= m; ++ i){
		scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].v);
		sgt.ql = q[i].l, sgt.qr = q[i].r, sgt.qv = q[i].v;
		sgt.update(1, 1, n);
	}
	for(i = 1; i <= m; ++ i){
		sgt.ql = q[i].l, sgt.qr = q[i].r;
		if(sgt.query(1, 1, n) != q[i].v){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for(i = 1; i <= n; ++ i){
		sgt.ql = sgt.qr = i;
		printf("%d%c", sgt.query(1, 1, n), i == n ? '\n' : ' ');
	}
	return 0;
}