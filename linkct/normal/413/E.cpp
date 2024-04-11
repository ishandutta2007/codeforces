#include <cstdio>
const int MAXN = 200005, INF = 0x3f3f3f3f;

struct treeNode{
	int u, d, m, s, l, r;
}t[MAXN << 2];
int n, m;
char s[2][MAXN];

inline int min(int a, int b){return a > b ? b : a;}
treeNode merge(treeNode l, treeNode r){
	treeNode ret;
	ret.u = min(min(l.u + r.u, l.m + r.s) + 1, INF);
	ret.d = min(min(l.d + r.d, l.s + r.m) + 1, INF);
	ret.l = min(l.l, l.u + r.l + l.d + 2);
	ret.r = min(r.r, r.u + l.r + r.d + 2);
	ret.m = min(min(l.u + 1 + r.m, l.m + 1 + r.d), INF);
	ret.s = min(min(l.s + 1 + r.u, l.d + 1 + r.s), INF);
	return ret;
}
void sgtBuild(int x, int l, int r){
	if(l == r){
		if(s[0][l] == '.' && s[1][l] == '.'){
			t[x].l = t[x].r = t[x].m = t[x].s = 1;
			t[x].u = t[x].d = 0;
		}else if(s[0][l] == '.'){
			t[x].u = 0;
			t[x].l = t[x].r = t[x].m = t[x].s = t[x].d = INF;
		}else if(s[1][l] == '.'){
			t[x].d = 0;
			t[x].l = t[x].r = t[x].m = t[x].s = t[x].u = INF;
		}else t[x].u = t[x].l = t[x].r = t[x].m = t[x].s = t[x].d = INF;
		return;
	}
	int mid = (l + r) >> 1;
	sgtBuild(x << 1, l, mid);
	sgtBuild(x << 1 | 1, mid + 1, r);
	t[x] = merge(t[x << 1], t[x << 1 | 1]);
}
treeNode sgtQuery(int x, int l, int r, int ql, int qr){
	if(l >= ql && r <= qr) return t[x];
	int mid = (l + r) >> 1;
	if(qr <= mid) return sgtQuery(x << 1, l, mid, ql, qr);
	if(ql > mid) return sgtQuery(x << 1 | 1, mid + 1, r, ql, qr);
	return merge(sgtQuery(x << 1, l, mid, ql, qr), sgtQuery(x << 1 | 1, mid + 1, r, ql, qr));
}
inline int f(int x){return x == INF	? -1 : x;}
int main(){
	int i, u, v;
	scanf("%d%d%s%s", &n, &m, s[0] + 1, s[1] + 1);
	sgtBuild(1, 1, n);
	for(i = 1; i <= m; ++ i){
		scanf("%d%d", &u, &v);
		if(u > v) u ^= v ^= u ^= v;
		if(u > n && v > n) printf("%d\n", f(sgtQuery(1, 1, n, u - n, v - n).d));
		else if(v > n){
			if(u <= v - n) printf("%d\n", f(sgtQuery(1, 1, n, u, v - n).m));
			else printf("%d\n", f(sgtQuery(1, 1, n, v - n, u).s));
		}else printf("%d\n", f(sgtQuery(1, 1, n, u, v).u));
	}
	return 0;
}