#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MAXB 20
#define INF 1234234234
#define MAXN 200000

vector<int> u, v, c, mst;
vector<pair<int,int> > elist;

int uf[MAXN];
int find(int a){
	if(uf[a] == a) return a;
	uf[a] = find(uf[a]);
	return uf[a];
}
void join(int a, int b){
	uf[find(a)] = find(b);
}

vector<int> edges[MAXN];
vector<int> len[MAXN];
int par[MAXN];
int parlen[MAXN];
int depth[MAXN];
int best[MAXN]; // best edge covering this edge
void dfs(int p, int a, int plen, int d){
	par[a] = p;
	parlen[a] = plen;
	depth[a] = d;
	for(int j = 0; j < edges[a].size(); j++){
		if(edges[a][j] == p) continue;
		dfs(a, edges[a][j], len[a][j], d+1);
	}
}
int jump[MAXB][MAXN];
int jumpmax[MAXB][MAXN];
int jumpupd[MAXB][MAXN]; // min updates
int ans[int(1.1e6)];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		int u1, v1, c1;
		scanf("%d%d%d", &u1, &v1, &c1);
		u1--; v1--; c1++;
		u.push_back(u1); v.push_back(v1); c.push_back(c1);
		elist.push_back(make_pair(c[i], i));
		mst.push_back(0);
	}
	for(int i = 0; i < n; i++){
		uf[i] = i;
		best[i] = INF;
	}

	sort(elist.begin(), elist.end());
	for(int i = 0; i < m; i++){
		int a = elist[i].second;
		if(find(u[a]) != find(v[a])){
			join(u[a], v[a]);
			edges[u[a]].push_back(v[a]);
			edges[v[a]].push_back(u[a]);
			mst[a] = 1;
			len[u[a]].push_back(c[a]);
			len[v[a]].push_back(c[a]);
		}
	}
	dfs(0,0,-INF,0);
	for(int j = 0; j < MAXB; j++){
		for(int i = 0; i < n; i++){
			jumpupd[j][i] = INF;
			if(j == 0){
				jump[j][i] = par[i];
				jumpmax[j][i] = parlen[i];
				continue;
			}
			jump[j][i] = jump[j-1][jump[j-1][i]];
			jumpmax[j][i] = max(jumpmax[j-1][i], jumpmax[j-1][jump[j-1][i]]);
		}
	}
	for(int i = 0; i < m; i++){
		int a = elist[i].second;
		if(mst[a]) continue;
		int x = u[a];
		int y = v[a];

		ans[a] = -INF;
		for(int j = MAXB-1; j >= 0; j--){
			if(depth[x] - depth[y] >= (1<<j)){
				ans[a] = max(ans[a], jumpmax[j][x]);
				jumpupd[j][x] = min(jumpupd[j][x], c[a]);
				x = jump[j][x];
			}
			if(depth[y] - depth[x] >= (1<<j)){
				ans[a] = max(ans[a], jumpmax[j][y]);
				jumpupd[j][y] = min(jumpupd[j][y], c[a]);
				y = jump[j][y];
			}
		}
		for(int j = MAXB-1; j >= 0; j--){
			if(jump[j][x] != jump[j][y]){
				ans[a] = max(ans[a], jumpmax[j][x]);
				ans[a] = max(ans[a], jumpmax[j][y]);
				jumpupd[j][x] = min(jumpupd[j][x], c[a]);
				jumpupd[j][y] = min(jumpupd[j][y], c[a]);
				x = jump[j][x];
				y = jump[j][y];
			}
		}
		if(x != y){
			ans[a] = max(ans[a], jumpmax[0][x]);
			ans[a] = max(ans[a], jumpmax[0][y]);
			jumpupd[0][x] = min(jumpupd[0][x], c[a]);
			jumpupd[0][y] = min(jumpupd[0][y], c[a]);
			x = jump[0][x];
			y = jump[0][y];
		}
	}
	for(int j = MAXB-1; j > 0; j--){
		for(int i = 0; i < n; i++){
			jumpupd[j-1][i] = min(jumpupd[j-1][i], jumpupd[j][i]);
			jumpupd[j-1][jump[j-1][i]] = min(jumpupd[j-1][jump[j-1][i]],jumpupd[j][i]);
		}
	}

	for(int a = 0; a < m; a++){
		if(!mst[a]) continue;
		if(depth[u[a]] > depth[v[a]]) swap(u[a], v[a]);
		ans[a] = jumpupd[0][v[a]];
	}
	for(int a = 0; a < m; a++){
		ans[a] = min(ans[a], int(1e9)+1);
		printf("%d\n", ans[a]-1);
		//printf("(%d) ", mst[a]);
	}
}