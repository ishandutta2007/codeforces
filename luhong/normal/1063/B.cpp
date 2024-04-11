#include <cstdio>
#include <cstring>

int q[8010000][2], h = 4000001, t = 4000000;
bool mp[2010][2010]; int step[2010][2010];
char s[2010]; int n, m;
int _x[4] = {1, 0, -1, 0}, _y[4] = {0, -1, 0, 1}; 

void bfs(int x, int y)
{
	memset(step, -1, sizeof(step));
	step[x][y] = 0;
	q[++t][0] = x; q[t][1] = y;
	while(h <= t)
	{
		x = q[h][0]; y = q[h][1]; h++;
		for(int i = 0; i <= 3; i++)
		{
			int X = x + _x[i], Y = y + _y[i];
			if(X <= 0 || X > n || Y <= 0 || Y > m || mp[X][Y] || step[X][Y] != -1) continue;
			step[X][Y] = step[x][y];
			if(i == 3 || i == 1)
			{
				if(i == 3) step[X][Y]++;
				q[++t][0] = X, q[t][1] = Y;
			}
			else q[--h][0] = X, q[h][1] = Y;
		}
	}
}

int main()
{
	int r, c, x, y;
	scanf("%d%d%d%d%d%d", &n, &m, &r, &c, &x, &y);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", s + 1);
		for(int j = 1; j <= m; j++) mp[i][j] = (s[j] == '*');
	}
	bfs(r, c);
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			if(step[i][j] == -1) continue;
			int R = step[i][j], L = R - (j - c);
			if(L <= x && R <= y) ans++;
		}
	printf("%d\n", ans);
	return 0;
}