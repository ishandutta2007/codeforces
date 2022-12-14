#include <cstdio>
#include <algorithm>
typedef long long int LL;
using namespace std;
const int MAXN = 200005, INF = 1000000000;

struct sgtNode{
	int length, cover, l, r;
}t[MAXN * 35];
struct Events{
	int t, y1, y2, type;
	void var(int _t, int _y1, int _y2, int _type){
		t = _t, y1 = _y1, y2 = _y2, type = _type;
	}
	bool operator < (const Events &rhs) const{
		return t == rhs.t ? type > rhs.type : t < rhs.t;
	}
}event[MAXN];
int n, rt, nodeSize;

void maintain(int x){t[x].length = t[t[x].l].length + t[t[x].r].length;}
void sgtUpdate(int &x, int l, int r, int ql, int qr, int qv){
	if(!x) x = ++ nodeSize;
	if(l >= ql && r <= qr){
		t[x].cover += qv;
		if(!t[x].cover) maintain(x);
		else if(t[x].cover == qv) t[x].length = r - l + 1;
		return;
	}
	int mid = (l + r) >> 1;
	if(ql <= mid) sgtUpdate(t[x].l, l, mid, ql, qr, qv);
	if(qr > mid) sgtUpdate(t[x].r, mid + 1, r, ql, qr, qv);
	if(!t[x].cover) maintain(x);
}
int main(){
	int i, prev, x1, x2, y1, y2; LL ans = 0LL;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i){
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if(x1 > x2) swap(x1, x2), swap(y1, y2);
		else if(y1 > y2) swap(x1, x2), swap(y1, y2);
		event[i * 2 - 1].var(x1, y1, y2, 1);
		event[i * 2].var(x2 + 1, y1, y2, 0);
	}
	n <<= 1;
	sort(event + 1, event + 1 + n);
	for(i = 1, prev = event[1].t; i <= n; ++ i){
		sgtUpdate(rt, -INF, INF, event[i].y1, event[i].y2, event[i].type ? 1 : -1);
		if(i == n || event[i].t == event[i + 1].t) continue;
		ans += LL(t[rt].length) * (event[i + 1].t - prev);
		prev = event[i + 1].t;
	}
	printf("%I64d\n", ans);
	return 0;
}