#include <cstdio>
#include <algorithm>
#define fi first
#define se second
using namespace std;
typedef pair <int, int> pii;
typedef long long int LL;
const int MAXN = 500005, INF = 0x3f3f3f3f;

int n, pf[MAXN], sa[MAXN], rank[MAXN], height[MAXN];
int auxA[MAXN], auxB[MAXN], auxSort[MAXN], auxVal[MAXN];
pii tr[MAXN << 2]; char str[MAXN];

pii merge(pii a, pii b){
	if(a.fi == b.fi) return pii(a.fi, a.se + b.se);
	return a.fi > b.fi ? b : a;
}
inline int getVal(int x[], int pos){return pos > n ? -1 : x[pos];}
void getSA(){
	int i, j, p, sigma = 2, *x = auxA, *y = auxB, *t;
	for(i = 1; i <= sigma; ++ i) auxSort[i] = 0;
	for(i = 1; i <= n; ++ i) ++ auxSort[x[i] = str[i] == '(' ? 1 : 2];
	for(i = 2; i <= sigma; ++ i) auxSort[i] += auxSort[i - 1];
	for(i = n; i; -- i) sa[auxSort[x[i]] --] = i;
	for(j = 1, p = 0; p < n; j <<= 1, sigma = p){
		for(i = n - j + 1, p = 0; i <= n; ++ i) y[++ p] = i;
		for(i = 1; i <= n; ++ i) if(sa[i] > j) y[++ p] = sa[i] - j;
		for(i = 1; i <= sigma; ++ i) auxSort[i] = 0;
		for(i = 1; i <= n; ++ i) ++ auxSort[auxVal[i] = x[y[i]]];
		for(i = 2; i <= sigma; ++ i) auxSort[i] += auxSort[i - 1];
		for(i = n; i; -- i) sa[auxSort[auxVal[i]] --] = y[i];
		for(t = x, x = y, y = t, x[sa[1]] = p = 1, i = 2; i <= n; ++ i)
			if(y[sa[i]] == y[sa[i - 1]] && getVal(y, sa[i] + j) == getVal(y, sa[i - 1] + j)) x[sa[i]] = p;
			else x[sa[i]] = ++ p;
	}
	for(i = 1; i <= n; ++ i) rank[sa[i]] = i;
	for(i = 1, p = 0; i <= n; ++ i){
		if(rank[i] == 1) continue;
		if(p) -- p;
		j = sa[rank[i] - 1];
		while(str[i + p] == str[j + p]) ++ p;
		height[rank[i]] = p;
	}
}
void sgtBuild(int x, int l, int r){
	if(l == r){
		tr[x] = pii(pf[r], 1);
		return;
	} int mid = (l + r) >> 1;
	sgtBuild(x << 1, l, mid);
	sgtBuild(x << 1 | 1, mid + 1, r);
	tr[x] = merge(tr[x << 1], tr[x << 1 | 1]);
}
void sgtUpdate(int x, int l, int r, int p){
	if(l == r){
		tr[x] = pii(INF, 0);
		return;
	} int mid = (l + r) >> 1;
	if(p <= mid) sgtUpdate(x << 1, l, mid, p);
	else sgtUpdate(x << 1 | 1, mid + 1, r, p);
	tr[x] = merge(tr[x << 1], tr[x << 1 | 1]);
}
int sgtGetPos(int x, int l, int r, int v){
	if(l == r) return r;
	int mid = (l + r) >> 1;
	if(tr[x << 1].fi < v) return sgtGetPos(x << 1, l, mid, v);
	return sgtGetPos(x << 1 | 1, mid + 1, r, v);
}
pii sgtQuery(int x, int l, int r, int ql, int qr){
	if(ql > qr) return pii(INF, 0);
	if(l >= ql && r <= qr) return tr[x];
	int mid = (l + r) >> 1;
	if(qr <= mid) return sgtQuery(x << 1, l, mid, ql, qr);
	if(ql > mid) return sgtQuery(x << 1 | 1, mid + 1, r, ql, qr);
	return merge(sgtQuery(x << 1, l, mid, ql, qr), sgtQuery(x << 1 | 1, mid + 1, r, ql, qr));
}
int main(){
	int i, pos; pii tmp; LL ans = 0LL;
	scanf("%d%s", &n, str + 1);
	getSA();
	for(i = 1; i <= n; ++ i)
		pf[i] = pf[i - 1] + (str[i] == '(' ? 1 : -1);
	pf[n + 1] = - MAXN;
	sgtBuild(1, 1, n + 1);
	for(i = 1; i <= n; ++ i){
		pos = sgtGetPos(1, 1, n + 1, pf[i - 1]);
		tmp = sgtQuery(1, 1, n + 1, i + height[rank[i]], pos - 1);
		if(tmp.fi == pf[i - 1]) ans += tmp.se;
		sgtUpdate(1, 1, n + 1, i);
	}
	printf("%I64d\n", ans);
	return 0;
}