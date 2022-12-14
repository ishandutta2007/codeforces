#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int LL;
const int MAXN = 200005;

int n, m, u[MAXN], v[MAXN], pre[MAXN][19], g[MAXN], to[MAXN << 1];
int nxt[MAXN << 1], edgeSize, dep[MAXN], f[MAXN], fa[MAXN];
vector <LL> tmp1, tmp2;
LL weight[MAXN << 1], up[MAXN];

int find(int x){return x == f[x] ? x : f[x] = find(f[x]);}
void addEdge(int u, int v, LL w){
	nxt[++ edgeSize] = g[u];
	g[u] = edgeSize;
	to[edgeSize] = v;
	weight[edgeSize] = w;
}
void dfsInit(int x){
	int p;
	for(p = 1; dep[x] > (1 << p); ++ p)
		pre[x][p] = pre[pre[x][p - 1]][p - 1];
	for(p = g[x]; p; p = nxt[p])
		if(to[p] != fa[x]){
			pre[to[p]][0] = fa[to[p]] = x;
			dep[to[p]] = dep[x] + 1;
			up[to[p]] = weight[p];
			if(weight[p] == 1) f[to[p]] = f[x];
			else f[to[p]] = to[p];
			dfsInit(to[p]);
		}
}
inline int getLCA(int u, int v){
	if(dep[u] < dep[v]) swap(u, v);
	int i;
	for(i = 17; i >= 0; -- i)
		if(dep[u] - (1 << i) >= dep[v])
			u = pre[u][i];
	if(u == v) return u;
	for(i = 17; i >= 0; -- i)
		if(pre[u][i] != pre[v][i])
			u = pre[u][i], v = pre[v][i];
	return fa[u];
}
int main(){
	int i, j, a, b, lca, id, op; LL val; double product;
	scanf("%d%d", &n, &m);
	for(i = 1; i < n; ++ i){
		scanf("%d%d%I64d", &u[i], &v[i], &val);
		addEdge(u[i], v[i], val);
		addEdge(v[i], u[i], val);
	} f[1] = dep[1] = 1;
	dfsInit(1);
	for(i = 1; i <= m; ++ i){
		scanf("%d", &op);
		if(op == 1){//query
			scanf("%d%d%I64d", &a, &b, &val);
			lca = getLCA(a, b);
			product = 1.0; tmp1.clear(); tmp2.clear();
			while(dep[a = find(a)] > dep[lca]){
				if(a == 1) break;
				product *= up[a];
				if(product > val) break;
				tmp1.push_back(up[a]);
				a = fa[a];
			}
			while(dep[b = find(b)] > dep[lca]){
				if(b == 1) break;
				product *= up[b];
				if(product > val) break;
				tmp2.push_back(up[b]);
				b = fa[b];
			}
			if(product > val) printf("0\n");
			else{
				reverse(tmp2.begin(), tmp2.end());
				for(j = 0; j < int(tmp1.size()); ++ j) val /= tmp1[j];
				for(j = 0; j < int(tmp2.size()); ++ j) val /= tmp2[j];
				printf("%I64d\n", val);
			}
		}else{//modify
			scanf("%d%I64d", &id, &val);
			if(dep[u[id]] > dep[v[id]]){
				up[u[id]] = val;
				if(val == 1) f[u[id]] = f[fa[u[id]]];
			}else{
				up[v[id]] = val;
				if(val == 1) f[v[id]] = f[fa[v[id]]];
			}
		}
	}
	return 0;
}