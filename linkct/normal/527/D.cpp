#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 210005;

struct sgtTree{
	int t[MAXN * 8], ql, qr, qp, qv;
	int query(int x, int l, int r){
		if(qr < ql) return 0;
		if(l >= ql && r <= qr) return t[x];
		int mid = (l + r) >> 1, ret = 0;
		if(ql <= mid) ret = max(ret, query(x << 1, l, mid));
		if(qr > mid) ret = max(ret, query(x << 1 | 1, mid + 1, r));
		return ret;
	}
	void update(int x, int l, int r){
		if(l == r){
			t[x] = qv;
			return;
		}
		int mid = (l + r) >> 1;
		if(qp <= mid) update(x << 1, l, mid);
		else update(x << 1 | 1, mid + 1, r);
		t[x] = max(t[x << 1], t[x << 1 | 1]);
	}
}sgt;
struct points{
	int x, w;
	bool operator < (const points& rhs) const{
		return x < rhs.x;
	}
}point[MAXN];
int tmp[MAXN * 2], cnt, n, f[MAXN];

int main(){
	int i, ans = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i){
		scanf("%d%d", &point[i].x, &point[i].w);
		tmp[++ cnt] = point[i].x + point[i].w;
		tmp[++ cnt] = point[i].x - point[i].w;
	}
	sort(tmp + 1, tmp + 1 + cnt);
	sort(point + 1, point + 1 + n);
	cnt = unique(tmp + 1, tmp + 1 + cnt) - tmp - 1;
	for(i = 1; i <= n; ++ i){
		sgt.ql = 1;
		sgt.qr = lower_bound(tmp + 1, tmp + 1 + cnt, point[i].x - point[i].w) - tmp;
		f[i] = sgt.query(1, 1, cnt) + 1;
		sgt.qp = lower_bound(tmp + 1, tmp + 1 + cnt, point[i].x + point[i].w) - tmp;
		sgt.qv = f[i];
		sgt.update(1, 1, cnt);
		ans = max(ans, f[i]);
	}
	printf("%d\n", ans);
	return 0;
}