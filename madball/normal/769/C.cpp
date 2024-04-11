#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int LIM = 1010;
const int LIMK = 1000100;
const int INF = 1e+9 + 7;

int offset[4][2] = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
char code[4] = {'D', 'L', 'R', 'U'};

int n, m;
bool field[LIM][LIM];
int dist[LIM][LIM];
int reference[LIM][LIM];

bool is_free(int x, int y)
{
	return 0 <= x && x < m && 0 <= y && y < n && !field[x][y];
}

void bfs(int x, int y)
{
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			dist[i][j] = INF;
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	dist[x][y] = 0;
	while (!q.empty())
	{
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nextx = curx + offset[i][0];
			int nexty = cury + offset[i][1];
			if (is_free(nextx, nexty) && dist[nextx][nexty] > dist[curx][cury] + 1)
			{
				dist[nextx][nexty] = dist[curx][cury] + 1;
				reference[nextx][nexty] = i;
				q.push(make_pair(nextx, nexty));
			}
		}
	}
}

char ans[LIMK];

void solve()
{
	int k, x, y;
	scanf("%d %d %d", &n, &m, &k);
	if (k & 1)
	{
		printf("IMPOSSIBLE");
		return;
	}
	for (int j = 0; j < n; ++j)
	{
		for (int i = 0; i < m; ++i)
		{
			char c;
			scanf(" %c", &c);
			field[i][j] = c == '*';
			if (c == 'X')
			{
				x = i;
				y = j;
			}
		}
	}
	
	bfs(x, y);
	int curx = x;
	int cury = y;
	int steps = 0;
	while (dist[curx][cury] + steps < k)
	{
		for (int i = 0; i < 5; ++i)
		{
			if (i == 4)
			{
				printf("IMPOSSIBLE");
				return;
			}
			int nextx = curx + offset[i][0];
			int nexty = cury + offset[i][1];
			if (!is_free(nextx, nexty))
				continue;
			ans[steps++] = code[i];
			curx = nextx;
			cury = nexty;
			break;
		}
	}

	bfs(curx, cury);
	int steps2 = 0;
	while (x != curx || y != cury)
	{
		ans[k - (++steps2)] = code[reference[x][y]];
		int nextx = x - offset[reference[x][y]][0];
		int nexty = y - offset[reference[x][y]][1];
		x = nextx;
		y = nexty;
	}
	ans[k] = 0;
	printf("%s", ans);
}

int main()
{
	solve();
	return 0;
}