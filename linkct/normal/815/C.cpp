#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;

int n, c[MAXN], d[MAXN], fa[MAXN], f[MAXN][MAXN], sz[MAXN], tmp[MAXN], budget;
vector <int> g[MAXN], gd[MAXN], temp;

void dfs(int x){
	int i, j, k, v, sum;
	memset(f[x], 0x3f, sizeof(f[x]));
	sz[x] = 1, f[x][1] = d[x], gd[x].push_back(c[x]);
	for(i = 0; i < int(g[x].size()); ++ i)
		dfs(g[x][i]);
	for(i = 0; i < int(g[x].size()); ++ i){
		v = g[x][i];
		temp.resize(gd[x].size() + gd[v].size());
		merge(gd[x].begin(), gd[x].end(), gd[v].begin(), gd[v].end(), temp.begin());
		gd[x] = temp; temp.clear();
		memset(tmp, 0x3f, sizeof(int) * (sz[x] + sz[v] + 1));
		for(j = 0; j <= sz[x]; ++ j)
			for(k = 0; k <= sz[v]; ++ k)
				tmp[j + k] = min(tmp[j + k], f[x][j] + f[v][k]);
		for(j = 0, sz[x] += sz[v]; j <= sz[x]; ++ j)
			f[x][j] = tmp[j];
	} f[x][0] = 0;
	for(i = sum = 0; i < sz[x]; ++ i)
		if((sum += gd[x][i]) <= budget)
			f[x][i + 1] = min(f[x][i + 1], sum);
		else break;
}
int main(){
	int i;
	scanf("%d%d", &n, &budget);
	for(i = 1; i <= n; ++ i){
		scanf("%d%d", &c[i], &d[i]);
		d[i] = c[i] - d[i];
		if(i > 1){
			scanf("%d", &fa[i]);
			g[fa[i]].push_back(i);
		}
	} dfs(1);
	for(i = 0; i <= n; ++ i)
		if(f[1][i] > budget)
			break;
	printf("%d\n", i - 1);
	return 0;
}