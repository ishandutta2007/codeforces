#include <cstdio>
#define MAX 2005

const int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
int n, m, maxDep[3];
char graph[MAX][MAX];
bool out[MAX][MAX], vis[MAX][MAX];

inline int max(int a, int b){return a > b ? a : b;}
inline int getDir(char x){
	switch(x){
		case '^':
			return 0;
		case '<':
			return 1;
		case '>':
			return 2;
		case 'v':
			return 3;
	}
	return -1;
}
int dfs(int x, int y, int depth){
	vis[x][y] = true;
	int i, dir, retval = depth;
	for(i = 0; i < 4; ++ i)
		if(graph[x + dx[i]][y + dy[i]] != '#'){
			dir = getDir(graph[x + dx[i]][y + dy[i]]);
			if(i + dir == 3)
				retval = max(dfs(x + dx[i], y + dy[i], depth + 1), retval);
		}
	return retval;
}
int main(){
	int i, j, tempD;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; ++ i)
		scanf("%s", graph[i] + 1);
	for(i = 1; i <= n; ++ i)
		for(j = 1; j <= m; ++ j)
			if(graph[i][j] != '#' && graph[i + dx[getDir(graph[i][j])]][j + dy[getDir(graph[i][j])]] != '#')
				out[i][j] = true;
	for(i = 1; i <= n; ++ i)
		for(j = 1; j <= m; ++ j)
			if(graph[i][j] != '#' && !out[i][j]){
				tempD = dfs(i, j, 1);
				if(tempD > maxDep[1]){
					maxDep[2] = maxDep[1];
					maxDep[1] = tempD;
				}else if(tempD > maxDep[2])
					maxDep[2] = tempD;
			}
	for(i = 1; i <= n; ++ i)
		for(j = 1; j <= m; ++ j)
			if(graph[i][j] != '#' && !vis[i][j]){
				printf("-1\n");
				return 0;
			}
	if(!maxDep[1] && !maxDep[2])
		printf("0\n");
	else if(!maxDep[2])
		printf("%d\n", (maxDep[1] << 1) - 1);
	else printf("%d\n", maxDep[1] + max(maxDep[1] - 1, maxDep[2]));
	return 0;
}