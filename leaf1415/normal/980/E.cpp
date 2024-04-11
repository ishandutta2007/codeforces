#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int k, n;
int cnt;
vector<int> G[1000005];
int parent[21][1000005];
int depth[1000005];
bool used[1000005];

void pardfs(int v, int prev, int dep)
{
	parent[0][v] = prev;
	depth[v] = dep;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == prev) continue;
		pardfs(G[v][i], v, dep+1);
	}
}

void add(int v)
{
	int p = v;
	while(!used[p]){
		used[p] = true;
		cnt++;
		p = parent[0][p];
	}
}

int getAncestor(int v)
{
	int p = v;
	for(int i = 20; i >= 0; i--){
		if(parent[i][p] != 0 && !used[parent[i][p]]) p = parent[i][p];
	}
	return parent[0][p];
}

int main(void)
{
	//scanf("%d %d", &n, &k);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	int a, b;
	for(int i = 0; i < n-1; i++){
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	pardfs(n, 0, 0);
	for(int j = 1; j <= 20; j++){
		for(int i = 1; i <= n; i++){
			parent[j][i] = parent[j-1][parent[j-1][i]];
		}
	}
	
	cnt = 1;
	used[n] = true;
	
	for(int i = n-1; i >= 1; i--){
		if(used[i]) continue;
		if(cnt + depth[i] - depth[getAncestor(i)] <= n-k) add(i);
	}
	
	for(int i = 1; i <= n; i++) if(!used[i]) /*printf("%d ", i);*/ cout << i << " "; cout << endl;
	return 0;
}