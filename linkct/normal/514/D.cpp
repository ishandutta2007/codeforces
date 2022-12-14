#include <cstdio>
const int MAXN = 100005;

inline int max(int a, int b){return a > b ? a : b;}
struct segtree{
	int t[MAXN << 2];
	void build(int x, int l, int r, int arr[]){
		if(l == r){
			t[x] = arr[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(x << 1, l, mid, arr);
		build(x << 1 | 1, mid + 1, r, arr);
		t[x] = max(t[x << 1], t[x << 1 | 1]);
	}
	int query(int x, int l, int r, int ql, int qr){
		if(l >= ql && r <= qr) return t[x];
		int mid = (l + r) >> 1, ret = 0;
		if(ql <= mid) ret = max(ret, query(x << 1, l, mid, ql, qr));
		if(qr > mid) ret = max(ret, query(x << 1 | 1, mid + 1, r, ql, qr));
		return ret;
	}
}sgt[5];
int n, m, k, init[5][MAXN], ans[10];

bool check(int l, int r){
	int i, tmp[10];
	for(i = tmp[0] = 0; i < m; ++ i){
		tmp[i + 1] = sgt[i].query(1, 1, n, l, r);
		tmp[0] += tmp[i + 1];
	}
	if(tmp[0] > k) return false;
	if(r - l + 1 > ans[0]){
		ans[0] = r - l + 1;
		for(i = 0; i < m; ++ i)
			ans[i + 1] = tmp[i + 1];
	}
	return true;
}
int main(){
	int i, j, pos;
	scanf("%d%d%d", &n, &m, &k);
	for(i = 1; i <= n; ++ i)
		for(j = 0; j < m; ++ j)
			scanf("%d", &init[j][i]);
	for(i = 0; i < m; ++ i)
		sgt[i].build(1, 1, n, init[i]);
	for(i = pos = 1; i <= n; ++ i){
		while(pos < n && check(i, pos + 1)) pos ++;
		if(!check(i, pos)) pos ++;
	}
	for(i = 1; i <= m; ++ i) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}