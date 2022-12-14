#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 100005;

struct data{
	int dis, pos;
	data(){dis = -0x3f3f3f3f, pos = 0;}
	data(int d, int p){dis = d, pos = p;}
}down[MAXN], up[MAXN];
int g[MAXN], nxt[MAXN << 1], to[MAXN << 1], val[MAXN << 1], add[MAXN], minus[MAXN], dfsClock;
int delta[MAXN << 3], n, m, dep[MAXN], pre[MAXN][21], edgeSize;
bool crucial[MAXN];

data merge(data a, data b, int &x){
	if(a.dis > b.dis) return a;
	else if(a.dis < b.dis) return b;
	return (data) {a.dis, x};
}
void addEdge(int u, int v, int w){
	edgeSize ++;
	nxt[edgeSize] = g[u];
	g[u] = edgeSize;
	to[edgeSize] = v;
	val[edgeSize] = w;
}
void calcData1(int x){
	add[x] = ++ dfsClock;
	int i;
	for(i = 1; dep[x] > (1 << i); ++ i)
		pre[x][i] = pre[pre[x][i - 1]][i - 1];
	for(i = g[x]; i; i = nxt[i])
		if(to[i] != pre[x][0]){
			pre[to[i]][0] = x;
			dep[to[i]] = dep[x] + 1;
			calcData1(to[i]);
			down[x] = merge(down[x], (data) {down[to[i]].dis + val[i], down[to[i]].pos}, x);
		}
	minus[x] = ++ dfsClock;
	if(down[x].dis < 0 && crucial[x]) down[x].dis = 0, down[x].pos = x;
}
void calcData2(int x){
	vector <data> pf, sf;
	int i, j = 0;
	for(i = g[x]; i; i = nxt[i])
		if(to[i] != pre[x][0]){
			pf.push_back((data) {down[to[i]].dis + val[i], down[to[i]].pos});
			sf.push_back((data) {down[to[i]].dis + val[i], down[to[i]].pos});
		}
	for(i = 1; i < int(pf.size()); ++ i) pf[i] = merge(pf[i], pf[i - 1], x);
	for(i = int(pf.size()) - 2; i >= 0; -- i) sf[i] = merge(sf[i], sf[i + 1], x);
	for(i = g[x]; i; i = nxt[i])
		if(to[i] != pre[x][0]){
			if(!j){
				if(int(pf.size()) == 1) up[to[i]] = up[x];
				else up[to[i]] = merge(up[x], sf[j + 1], x);
			}else if(j == int(pf.size()) - 1)
				up[to[i]] = merge(pf[j - 1], up[x], x);
			else{
				up[to[i]] = merge(pf[j - 1], sf[j + 1], x);
				up[to[i]] = merge(up[to[i]], up[x], x);
			}
			if(up[to[i]].dis < 0 && crucial[x])
				up[to[i]].dis = 0, up[to[i]].pos = x;
			up[to[i]].dis += val[i];
			++ j;
			calcData2(to[i]);
		}
}
int getLCA(int u, int v){
	int i;
	if(dep[u] < dep[v]) i = u, u = v, v = i;
	for(i = 20; i >= 0; -- i)
		if(dep[u] - (1 << i) >= dep[v])
			u = pre[u][i];
	if(u == v) return u;
	for(i = 20; i >= 0; -- i)
		if(pre[u][i] != pre[v][i])
			u = pre[u][i], v = pre[v][i];
	return pre[u][0];
}
void sgtUpdate(int x, int l, int r, int ql, int qr, int qv){
	if(l >= ql && r <= qr){
		delta[x] += qv;
		return;
	}
	delta[x << 1] += delta[x], delta[x << 1 | 1] += delta[x];
	delta[x] = 0;
	int mid = (l + r) >> 1;
	if(ql <= mid) sgtUpdate(x << 1, l, mid, ql, qr, qv);
	if(qr > mid) sgtUpdate(x << 1 | 1, mid + 1, r, ql, qr, qv);
}
int sgtQuery(int x, int l, int r, int qp){
	if(l == r) return delta[x];
	delta[x << 1] += delta[x], delta[x << 1 | 1] += delta[x];
	delta[x] = 0;
	int mid = (l + r) >> 1;
	if(qp <= mid) return sgtQuery(x << 1, l, mid, qp);
	return sgtQuery(x << 1 | 1, mid + 1, r, qp);
}
void routeUpdate(int u, int v){
	int lca = getLCA(u, v);
	sgtUpdate(1, 1, n << 1, 1, add[u], 1);
	sgtUpdate(1, 1, n << 1, 1, add[v], 1);
	sgtUpdate(1, 1, n << 1, 1, add[lca], -1);
	if(pre[lca][0]) sgtUpdate(1, 1, n << 1, 1, add[pre[lca][0]], -1);
}
int main(){
	int i, u, v, w, ans = -1, cnt, tmp;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= m; ++ i){
		scanf("%d", &w);
		crucial[w] = true;
	}
	for(i = 1; i < n; ++ i){
		scanf("%d%d%d", &u, &v, &w);
		addEdge(u, v, w);
		addEdge(v, u, w);
	}
	dep[1] = 1;
	calcData1(1);
	calcData2(1);
	for(i = 1; i <= n; ++ i){
		if(!crucial[i]) continue;
		down[i] = merge(down[i], up[i], i);
		routeUpdate(i, down[i].pos);
	}
	for(i = 1; i <= n; ++ i){
		if(crucial[i]) continue;
		tmp = sgtQuery(1, 1, n << 1, add[i]) - sgtQuery(1, 1, n << 1, minus[i]);
		if(tmp > ans) ans = tmp, cnt = 1;
		else if(tmp == ans) cnt ++;
	}
	printf("%d %d\n", ans, cnt);
	return 0;
}