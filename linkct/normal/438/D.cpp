#include <cstdio>
#include <iostream>
using namespace std;
typedef long long int ll;
const int MAXN = 100005;

struct segTree{
	int maxv[MAXN << 2], ql, qr, qv, qp;
	ll sum[MAXN << 2];
	void maintain(int x){
		maxv[x] = max(maxv[x << 1], maxv[x << 1 | 1]);
		sum[x] = sum[x << 1] + sum[x << 1 | 1];
	}
	void singleUpdate(int x, int l, int r){
		if(l == r){
			maxv[x] = sum[x] = qv;
			return;
		}
		int mid = (l + r) >> 1;
		if(qp <= mid) singleUpdate(x << 1, l, mid);
		else singleUpdate(x << 1 | 1, mid + 1, r);
		maintain(x);
	}
	ll query(int x, int l, int r){
		if(l >= ql && r <= qr) return sum[x];
		int mid = (l + r) >> 1;
		ll ret = 0;
		if(ql <= mid) ret += query(x << 1, l, mid);
		if(qr > mid) ret += query(x << 1 | 1, mid + 1, r);
		return ret;
	}
	void rangeUpdate(int x, int l, int r){
		if(maxv[x] < qv) return;
		if(l == r){
			maxv[x] %= qv;
			sum[x] %= (ll)qv;
			return;
		}
		int mid = (l + r) >> 1;
		if(ql <= mid) rangeUpdate(x << 1, l, mid);
		if(qr > mid) rangeUpdate(x << 1 | 1, mid + 1, r);
		maintain(x);
	}
}sgt;
int n, m;

int main(){
	int i, type;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &sgt.qv);
		sgt.qp = i;
		sgt.singleUpdate(1, 1, n);
	}
	for(i = 1; i <= m; ++ i){
		scanf("%d", &type);
		switch(type){
			case 1:
				scanf("%d%d", &sgt.ql, &sgt.qr);
				cout << sgt.query(1, 1, n) << endl;
				break;
			case 2:
				scanf("%d%d%d", &sgt.ql, &sgt.qr, &sgt.qv);
				sgt.rangeUpdate(1, 1, n);
				break;
			case 3:
				scanf("%d%d", &sgt.qp, &sgt.qv);
				sgt.singleUpdate(1, 1, n);
				break;
		}
	}
	return 0;
}