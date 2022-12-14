#include <stdio.h>
#include <queue>
#include <string.h>
#define MAXN 105
using namespace std;

const int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
char g[MAXN][MAXN];
int n, m;

inline bool inmap(int x, int y){return x >= 1 && x <= n && y >= 1 && y <= m;}
void bfs(int r, int c)
{
	queue < pair<int, int> > q;
	int nx, ny, i;
	g[r][c] = 'W';
	q.push(pair<int, int>(r, c));
	while(!q.empty())
	{
		nx = q.front().first;
		ny = q.front().second;
		q.pop();
		for(i = 0; i < 4; i ++)
		{
			if(inmap(nx + dx[i], ny + dy[i]) && g[nx + dx[i]][ny + dy[i]] == '.')
			{
				g[nx + dx[i]][ny + dy[i]] = g[nx][ny] == 'W' ? 'B' : 'W';
				q.push(pair<int, int>(nx + dx[i], ny + dy[i]));
			}
		}
	}
	return;
}
int init()
{
	int i, j;
	char str[MAXN];
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; i ++)
	{
		scanf("%s", str);
		int len = strlen(str);
		for(j = 0; j < len; j ++)
			g[i][j + 1] = str[j];
	}
	return 0;
}
int solve()
{
	int i, j;
	for(i = 1; i <= n; i ++)
		for(j = 1; j <= m; j ++)
			if(g[i][j] == '.')
				bfs(i, j);
	for(i = 1; i <= n; i ++)
	{
		for(j = 1; j <= m; j ++)
			printf("%c", g[i][j]);
		printf("\n");
	}
	return 0;
}
int main()
{
	init();
	solve();
	return 0;
}