#include <cstdio>
#define MAXN 100005
#define lch(x) (x << 1)
#define rch(x) ((x << 1) + 1)

int init[MAXN], n, q;
inline int gcd(int a, int b){return !b ? a : gcd(b, a % b);}
struct segtree{
	int gcdv[MAXN << 2], minv[MAXN << 2], cnt[MAXN << 2], ql, qr, qv;

	void maintain(int x){
		gcdv[x] = gcd(gcdv[lch(x)], gcdv[rch(x)]);
		if(minv[lch(x)] < minv[rch(x)])
			minv[x] = minv[lch(x)], cnt[x] = cnt[lch(x)];
		else if(minv[lch(x)] > minv[rch(x)])
			minv[x] = minv[rch(x)], cnt[x] = cnt[rch(x)];
		else minv[x] = minv[lch(x)], cnt[x] = cnt[lch(x)] + cnt[rch(x)];
	}
	void init(int x, int l, int r, int arr[]){
		if(l == r){
			gcdv[x] = minv[x] = arr[l];
			cnt[x] = 1;
			return;
		}
		int mid = (l + r) >> 1;
		init(lch(x), l, mid, arr);
		init(rch(x), mid + 1, r, arr);
		maintain(x);
	}
	int queryGcd(int x, int l, int r){
		if(l >= ql && r <= qr) return gcdv[x];
		int mid = (l + r) >> 1, ret = 0;
		if(ql <= mid) ret = queryGcd(lch(x), l, mid);
		if(qr > mid) ret = (ret ? gcd(ret, queryGcd(rch(x), mid + 1, r)) : queryGcd(rch(x), mid + 1, r));
		return ret;
	}
	int getSelected(int x, int l, int r){
		if(l >= ql && r <= qr)
			return minv[x] == qv ? cnt[x] : 0;
		int mid = (l + r) >> 1, ret = 0;
		if(ql <= mid) ret += getSelected(lch(x), l, mid);
		if(qr > mid) ret += getSelected(rch(x), mid + 1, r);
		return ret;
	}
}sgt;

int main(){
	int i;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i)
		scanf("%d", &init[i]);
	sgt.init(1, 1, n, init);
	scanf("%d", &q);
	for(i = 1; i <= q; ++ i){
		scanf("%d%d", &sgt.ql, &sgt.qr);
		sgt.qv = sgt.queryGcd(1, 1, n);
		printf("%d\n", sgt.qr - sgt.ql + 1 - sgt.getSelected(1, 1, n));
	}
	return 0;
}