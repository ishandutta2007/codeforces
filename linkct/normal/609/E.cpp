#include <iostream>
#include <algorithm>
typedef long long int LL;
using namespace std;
const int MAXN = 200005;

struct Edge{
	int u, v, id, w;
	bool operator < (const Edge &rhs) const{
		return w < rhs.w;
	}
}e[MAXN];
int n, m, dep[MAXN], g[MAXN], nxt[MAXN << 1], to[MAXN << 1], edgeSize;
int pre[MAXN][20], val[MAXN][20], f[MAXN], weight[MAXN << 1];
bool inside[MAXN];
LL ans[MAXN];

int find(int x){return f[x] ? f[x] = find(f[x]) : x;}
void merge(int u, int v){f[find(u)] = find(v);}
void dfsBuild(int x, int fa){
	int p;
	for(p = 1; (1 << p) < dep[x]; ++ p){
		pre[x][p] = pre[pre[x][p - 1]][p - 1];
		val[x][p] = max(val[x][p - 1], val[pre[x][p - 1]][p - 1]);
	}
	for(p = g[x]; p; p = nxt[p])
		if(to[p] != fa){
			pre[to[p]][0] = x;
			val[to[p]][0] = weight[p];
			dep[to[p]] = dep[x] + 1;
			dfsBuild(to[p], x);
		}
}
void addEdge(int u, int v, int w){
	nxt[++ edgeSize] = g[u];
	g[u] = edgeSize;
	to[edgeSize] = v;
	weight[edgeSize] = w;
}
int query(int u, int v){
	if(dep[u] < dep[v]) swap(u, v);
	int p, res = -1;
	for(p = 19; p >= 0; -- p)
		if(dep[u] - (1 << p) >= dep[v]){
			res = max(res, val[u][p]);
			u = pre[u][p];
		}
	if(u == v) return res;
	for(p = 19; p >= 0; -- p)
		if(pre[u][p] != pre[v][p]){
			res = max(res, max(val[u][p], val[v][p]));
			u = pre[u][p];
			v = pre[v][p];
		}
	return max(res, max(val[u][0], val[v][0]));
}
int main(){
	int i; LL sum = 0LL;
	cin >> n >> m;
	for(i = 1; i <= m; ++ i){
		cin >> e[i].u >> e[i].v >> e[i].w;
		e[i].id = i;
	}
	sort(e + 1, e + 1 + m);
	for(i = 1; i <= m; ++ i)
		if(find(e[i].u) != find(e[i].v)){
			inside[i] = true;
			merge(e[i].u, e[i].v);
			addEdge(e[i].u, e[i].v, e[i].w);
			addEdge(e[i].v, e[i].u, e[i].w);
			sum += e[i].w;
		}
	dep[1] = 1;
	dfsBuild(1, -1);
	for(i = 1; i <= m; ++ i)
		if(inside[i]) ans[e[i].id] = sum;
		else ans[e[i].id] = sum + e[i].w - query(e[i].u, e[i].v);
	for(i = 1; i <= m; ++ i) cout << ans[i] << endl;
	return 0;
}