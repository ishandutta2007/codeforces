#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

struct Region{
	vector <int> v;
	int id;
	bool operator < (const Region &rhs) const{
		int i, j;
		for(i = int(v.size()) - 1, j = int(rhs.v.size()) - 1; i >= 0 && j >= 0; -- i, -- j)
			if(v[i] != rhs.v[j]) return v[i] < rhs.v[j];
		return j >= 0;
	}
}reg[MAXN];
int n, m, cnt, vis[MAXN], G[MAXN], nxt[MAXN << 1], to[MAXN << 1], edgeSize;
int size[MAXN], maxadj[MAXN], rt, fullSize; vector <int> g[MAXN], id[MAXN];

void getRoot(int x, int f){
	size[x] = 1, maxadj[x] = 0;
	for(int p = G[x]; p; p = nxt[p]){
		if(vis[to[p]] || to[p] == f) continue;
		getRoot(to[p], x);
		size[x] += size[to[p]];
		if(maxadj[x] < size[to[p]])
			maxadj[x] = size[to[p]];
	}
	if(maxadj[x] < fullSize - size[x])
		maxadj[x] = fullSize - size[x];
	if(maxadj[x] < maxadj[rt]) rt = x;
}
void getSize(int x, int f){
	size[x] = 1;
	for(int p = G[x]; p; p = nxt[p]){
		if(vis[to[p]] || to[p] == f) continue;
		getSize(to[p], x);
		size[x] += size[to[p]];
	}
}
void dfs(int x, int dep){
	int p;
	rt = 0; getRoot(x, -1);
	//printf("solve %d, rt = %d, fs = %d\n", x, rt, fullSize);
	vis[x = rt] = dep;
	getSize(x, -1);
	for(p = G[x]; p; p = nxt[p]){
		if(vis[to[p]]) continue;
		fullSize = size[to[p]];
		dfs(to[p], dep + 1);
	}
}
void addEdge(int u, int v){
	//printf("%d -> %d\n", u, v);
	nxt[++ edgeSize] = G[u];
	to[G[u] = edgeSize] = v;
}
int main(){
	maxadj[0] = MAXN;
	int i, j, u, v, to, fr, nxt;
	scanf("%d%d", &n, &m);
	if(m == 0){
		printf("1\n");
		return 0;
	}
	for(i = 1; i <= m; ++ i){
		scanf("%d%d", &u, &v);
		-- u, -- v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(i = 0; i < n; ++ i){
		g[i].push_back((i - 1 + n) % n);
		g[i].push_back((i + 1) % n);
		sort(g[i].begin(), g[i].end());
		//for(j = 0; j < int(g[i].size()); ++ j)
		//	printf("%d -> %d\n", i, g[i][j]);
		id[i].resize(g[i].size());
	}
	for(i = 0; i < n; ++ i)
		for(j = 0; j < int(g[i].size()); ++ j){
			if(id[i][j]) continue;
			if(g[i][j] == ((i - 1 + n) % n) || g[i][j] == ((i + 1) % n)) continue;
			id[i][j] = ++ cnt; reg[cnt].v.push_back(i);
			reg[cnt].id = cnt;
			//printf("new region created %d ", i);
			for(to = g[i][j], fr = i; to != i; ){
				reg[cnt].v.push_back(to);
				//printf("%d ", to);
				nxt = ((lower_bound(g[to].begin(), g[to].end(), fr) - g[to].begin()) - 1 + g[to].size()) % g[to].size();
				id[to][nxt] = cnt, fr = to, to = g[to][nxt];
			} sort(reg[cnt].v.begin(), reg[cnt].v.end());
			//printf("\n");
		}
	sort(reg + 1, reg + 1 + cnt);
	for(i = 0; i < n; ++ i)
		for(j = 0; j < int(g[i].size()); ++ j){
			if(g[i][j] == ((i - 1 + n) % n) || g[i][j] == ((i + 1) % n)) continue;
			//process i -> g[i][j]
			addEdge(id[i][j], id[i][(j - 1 + id[i].size()) % id[i].size()]);
		}
	fullSize = cnt, dfs(1, 1);
	for(i = 1; i <= cnt; ++ i)
		printf("%d ", vis[reg[i].id]);
	return 0;
}