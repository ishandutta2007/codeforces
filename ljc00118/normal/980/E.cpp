#include <bits/stdc++.h>
using namespace std;
vector<int> g[1000005];
int parent[1000005][32];
int depth[1000005];
bool intree[1000005];
void dfs(int u,int p){
	parent[u][0] = p;
	depth[u] = depth[p] + 1;
	for(int i = 1; i <= 20; i++){
		parent[u][i] = parent[parent[u][i-1]][i-1];
	}
	for(int v : g[u]){
		if(v == p) continue;
		dfs(v, u);
	}
}
int main()  {
	int n,k;
	scanf("%d%d",&n,&k);
	k = n - k - 1;
	int a,b;
	for(int i = 1; i < n; i++){
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(n,n);
	intree[n] = true;
	for(int i = n-1; i > 0; i--){
		int x = i;
		for(int j = 20; j >= 0; j--){
			if(!intree[parent[x][j]]){
				x = parent[x][j];
			}
		}
		if(depth[i] - depth[x] + 1 <= k){
			int y = i;
			while(!intree[y]){
				intree[y] = true;
				y = parent[y][0];
				k--;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(!intree[i]) printf("%d ",i);
	}
}