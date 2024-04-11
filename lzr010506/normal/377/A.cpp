#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 510
using namespace std;
char a[N][N];
int vis[N][N];
int n, m, k;
void dfs(int x, int y)
{
	if(x < 0 || x >= n || y < 0 || y >= m) return;
	if(a[x][y] != '.') return;
	if(vis[x][y]) return;
	vis[x][y] = 1;
	dfs(x + 1, y);
	dfs(x - 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);
	if(k) a[x][y] = 'X', k --;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 0; i < n; i ++)
		scanf("%s", a[i]);
	for(int i = 0; i < n && k; i ++)
		for(int j = 0; j < m && k; j ++)
			dfs(i, j);
	for(int i = 0; i < n; i ++)
		puts(a[i]);
	return 0;
}