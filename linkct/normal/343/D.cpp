#include <cstdio>
#include <cstring>
const int MAXN = 500005;

struct edge{
	int n, p;
	void var(int _n, int _p){
		n = _n, p = _p;
	}
}edges[MAXN << 1];
int g[MAXN], edgeSize, n, q, sum[MAXN << 2], sgn[MAXN << 2], tid[MAXN];
int border[MAXN], dfsClock, fa[MAXN];

void addEdge(int u, int v){
	edges[++ edgeSize].var(v, g[u]);
	g[u] = edgeSize;
}
void dfs(int x){
	tid[x] = border[x] = ++ dfsClock;
	for(int p = g[x]; p; p = edges[p].p)
		if(edges[p].n != fa[x]){
			fa[edges[p].n] = x;
			dfs(edges[p].n);
			border[x] = dfsClock;
		}
}
void setVal(int x, int l, int r, int v){
	sgn[x] = v, sum[x] = v * (r - l + 1);
}
void pushDown(int x, int l, int r){
	if(sgn[x] != -1){
		int mid = (l + r) >> 1;
		setVal(x << 1, l, mid, sgn[x]);
		setVal(x << 1 | 1, mid + 1, r, sgn[x]);
		sgn[x] = -1;
	}
}
int sgtQuery(int x, int l, int r, int ql, int qr){
	if(l >= ql && r <= qr) return sum[x];
	pushDown(x, l, r);
	int mid = (l + r) >> 1, ret = 0;
	if(ql <= mid) ret += sgtQuery(x << 1, l, mid, ql, qr);
	if(qr > mid) ret += sgtQuery(x << 1 | 1, mid + 1, r, ql, qr);
	return ret;
}
void sgtUpdate(int x, int l, int r, int ql, int qr, int qv){
	if(l >= ql && r <= qr){
		setVal(x, l, r, qv);
		return;
	}
	pushDown(x, l, r);
	int mid = (l + r) >> 1;
	if(ql <= mid) sgtUpdate(x << 1, l, mid, ql, qr, qv);
	if(qr > mid) sgtUpdate(x << 1 | 1, mid + 1, r, ql, qr, qv);
	sum[x] = sum[x << 1] + sum[x << 1 | 1];
}
int main(){
	int i, u, v;
	scanf("%d", &n);
	for(i = 1; i < n; ++ i){
		scanf("%d%d", &u, &v);
		addEdge(u, v);
		addEdge(v, u);
	}
	memset(sgn, -1, sizeof(sgn));
	dfs(1);
	scanf("%d", &q);
	for(i = 1; i <= q; ++ i){
		scanf("%d%d", &u, &v);
		if(u == 1){
			if(sgtQuery(1, 1, n, tid[v], border[v]) != border[v] - tid[v] + 1 && v != 1) sgtUpdate(1, 1, n, tid[fa[v]], tid[fa[v]], 0);
			sgtUpdate(1, 1, n, tid[v], border[v], 1);
		}else if(u == 2) sgtUpdate(1, 1, n, tid[v], tid[v], 0);
		else printf("%d\n", sgtQuery(1, 1, n, tid[v], border[v]) == border[v] - tid[v] + 1);
	}
	return 0;
}