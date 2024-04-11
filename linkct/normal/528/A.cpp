#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 200005;
typedef long long int ll;

struct segTree{
	int t[MAXN << 2], pf[MAXN << 2], sf[MAXN << 2], maxl[MAXN << 2], pc[MAXN << 2], sc[MAXN << 2], ql, qr, qv, qp;
	void pushDown(int x, int l, int r){
		int mid = (l + r) >> 1;
		if(t[x]){
			t[x << 1] = t[x << 1 | 1] = t[x];
			pc[x << 1] = sc[x << 1] = pc[x << 1 | 1] = sc[x << 1 | 1] = t[x];
			pf[x << 1] = sf[x << 1] = maxl[x << 1] = mid - l + 1;
			pf[x << 1 | 1] = sf[x << 1 | 1] = maxl[x << 1 | 1] = r - mid;
			t[x] = 0;
		}
	}
	void maintain(int x, int l, int r){
		int mid = (l + r) >> 1;
		maxl[x] = max(max(maxl[x << 1], maxl[x << 1 | 1]), (sc[x << 1] == pc[x << 1 | 1] ? sf[x << 1] + pf[x << 1 | 1] : 0));
		pc[x] = pc[x << 1];
		if((pf[x << 1] == mid - l + 1) && (pc[x << 1] == pc[x << 1 | 1]))
			pf[x] = pf[x << 1] + pf[x << 1 | 1];
		else pf[x] = pf[x << 1];
		sc[x] = sc[x << 1 | 1];
		if((sf[x << 1 | 1] == r - mid) && (sc[x << 1 | 1] == sc[x << 1]))
			sf[x] = sf[x << 1 | 1] + sf[x << 1];
		else sf[x] = sf[x << 1 | 1];
		
	}
	void update(int x, int l, int r){
		if(l >= ql && r <= qr){
			t[x] = pc[x] = sc[x] = qv;
			pf[x] = sf[x] = maxl[x] = r - l + 1;
			return;
		}
		pushDown(x, l, r);
		int mid = (l + r) >> 1;
		if(ql <= mid) update(x << 1, l, mid);
		if(qr > mid) update(x << 1 | 1, mid + 1, r);
		maintain(x, l, r);
	}
	int query(int x, int l, int r){
		if(l == r) return pc[x];
		pushDown(x, l, r);
		int mid = (l + r) >> 1;
		if(qp <= mid) return query(x << 1, l, mid);
		return query(x << 1 | 1, mid + 1, r);
	}
	void init(int x, int l, int r){
		if(l == r){
			pc[x] = sc[x] = qv;
			pf[x] = sf[x] = maxl[x] = 1;
			return;
		}
		int mid = (l + r) >> 1;
		init(x << 1, l, mid);
		init(x << 1 | 1, mid + 1, r);
		maintain(x, l, r);
	}
}sgt[2];
struct range{
	int l, r;
}tmp[MAXN << 1];
int w, h, n, alloNum, id;
char buf[10];

int main(){
	int i, t;
	scanf("%d%d%d", &w, &h, &n);
	sgt[0].qv = ++ alloNum;
	sgt[0].init(1, 1, h);
	sgt[1].qv = ++ alloNum;
	sgt[1].init(1, 1, w);
	tmp[1].l = 1;
	tmp[1].r = h;
	tmp[2].l = 1;
	tmp[2].r = w;
	for(i = 1; i <= n; ++ i){
		scanf("%s%d", buf, &t);
		if(buf[0] == 'H'){
			sgt[0].qp = t;
			id = sgt[0].query(1, 1, h);
			sgt[0].qv = ++ alloNum;
			tmp[alloNum].l = sgt[0].ql = tmp[id].l;
			tmp[alloNum].r = sgt[0].qr = t;
			sgt[0].update(1, 1, h);
			sgt[0].qv = ++ alloNum;
			tmp[alloNum].l = sgt[0].ql = t + 1;
			tmp[alloNum].r = sgt[0].qr = tmp[id].r;
			sgt[0].update(1, 1, h);
		}else{
			sgt[1].qp = t;
			id = sgt[1].query(1, 1, w);
			sgt[1].qv = ++ alloNum;
			tmp[alloNum].l = sgt[1].ql = tmp[id].l;
			tmp[alloNum].r = sgt[1].qr = t;
			sgt[1].update(1, 1, w);
			sgt[1].qv = ++ alloNum;
			tmp[alloNum].l = sgt[1].ql = t + 1;
			tmp[alloNum].r = sgt[1].qr = tmp[id].r;
			sgt[1].update(1, 1, w);
		}
		cout << (ll)sgt[0].maxl[1] * (ll)sgt[1].maxl[1] << endl;
	}
	return 0;
}