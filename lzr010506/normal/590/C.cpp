#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 10;
const int INF = 0x3f3f3f3f;
char s[N][N];
bool vis[N][N];
int min_dis[3][N][N];
int dx[] = {0, 0, -1, +1};
int dy[] = {-1, +1, 0, 0};
int r, c;

void BFS(const char& ch) 
{
	memset(vis, 0, sizeof vis);
	deque<pair<int, int> > q;
	int i, j;
	for (i = 0; i < r; i ++)
		for (j = 0; j < c; j ++)
			if (s[i][j] == ch) 
			{
				q.push_back({i, j});
				min_dis[ch - '1'][i][j] = 0;
			}
	while (!q.empty()) {
		pair<int, int> now = q.front();
		int old_x = now.first;
		int old_y = now.second;
		q.pop_front();
		if (vis[old_x][old_y]) continue;
		vis[old_x][old_y] = true;
		for (i = 0; i < 4; ++i) {
			int new_x = old_x + dx[i];
			int new_y = old_y + dy[i];
			if (new_x < 0 || new_x >= r ||
					new_y < 0 || new_y >= c ||
					s[new_x][new_y] == '#') continue;

			int new_dis = min_dis[ch - '1'][old_x][old_y] + (s[new_x][new_y] == '.');
			if (min_dis[ch - '1'][new_x][new_y] > new_dis) 
			{
				min_dis[ch - '1'][new_x][new_y] = new_dis;
				if (s[new_x][new_y] == '.') q.push_back({new_x, new_y});
				else q.push_front({new_x, new_y});
			}
		}
	}
}

int main() 
{
	int i, j;
	while (~scanf("%d%d", &r, &c))
	{
		for (i = 0; i < r; ++i) scanf("%s", s[i]);
		memset(min_dis, 0x3F, sizeof min_dis);
		for (char c = '1'; c <= '3'; ++c) BFS(c);
		int ans = INF;
		for (i = 0; i < r; ++i)
			for (j = 0; j < c; ++j)
				if (s[i][j] != '#' && min_dis[0][i][j] != INF && min_dis[1][i][j] != INF && min_dis[2][i][j] != INF)
					ans = min(ans, min_dis[0][i][j] + min_dis[1][i][j] + min_dis[2][i][j] - 2*(s[i][j] == '.'));
		if (ans == INF) puts("-1");
		else printf("%d\n", ans);
	}
}