#include <bits/stdc++.h>
#define N 1010
#define eps 1e-8
using namespace std;
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};
char s[N][N];
int dis[3][N][N];
int main()
{
	int n, m;
   	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i ++)
		scanf("%s", s[i]);
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
			dis[0][i][j] = dis[1][i][j] = dis[2][i][j] = (int)1e8;
	queue<pair<int, int> > Q;
	for (int k = 0; k < 3; k ++)
	{
		while (!Q.empty())
			Q.pop();
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < m; j ++)
				if (s[i][j] == k + '1')
				{
					Q.push(make_pair(i, j));
					dis[k][i][j] = 0;
				}
		while (!Q.empty())
		{
			pair<int, int> now = Q.front();
			Q.pop();
			int x = now.first;
			int y = now.second;
			for (int i = 0; i < 4; i ++)
			{
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (!(xx >= 0 && xx < n))continue;
				if (!(yy >= 0 && yy < m))continue;
				if (s[xx][yy] == '#')continue;
				if (dis[k][xx][yy] > dis[k][x][y] + (s[x][y] == '.'))
				{
					dis[k][xx][yy] = dis[k][x][y] + (s[x][y] == '.');
					Q.push(make_pair(xx, yy));
				}
			}
		}
	}
	int ans = 1e9;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			ans = min(ans, dis[0][i][j] + dis[1][i][j] + dis[2][i][j] + (s[i][j]=='.'));
	if (ans >= 1e8)
		printf("-1");
	else
		printf("%d\n", ans);
   return 0;
}