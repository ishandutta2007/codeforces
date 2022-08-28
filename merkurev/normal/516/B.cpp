#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

const int N = 2005;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m;
char mx[N][N];

queue<pair<int, int> > q;
bool used[N][N];

bool in_field(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

int get_cnt(int x, int y)
{
	int cnt = 0;	
	for (int dir = 0; dir < 4; dir++)
	{
		int new_x = x + dx[dir];
		int new_y = y + dy[dir];
		if (in_field(new_x, new_y) && mx[new_x][new_y] == '.')
			cnt++;
	}
	return cnt;
}

pair<int, int> get_near(int x, int y)
{
	for (int dir = 0; dir < 4; dir++)
	{
		int new_x = x + dx[dir];
		int new_y = y + dy[dir];
		if (in_field(new_x, new_y) && mx[new_x][new_y] == '.')
			return make_pair(new_x, new_y);
	}
	return make_pair(-1, -1);
}

void check(int x, int y)
{
	if (!in_field(x, y) || mx[x][y] != '.')
		return;

	if (get_cnt(x, y) == 1 && !used[x][y])
	{
		used[x][y] = true;
		q.push(make_pair(x, y));
	}
}

void check_near(int x, int y)
{
	for (int dir = 0; dir < 4; dir++)
		check(x + dx[dir], y + dy[dir]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d\n", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s\n", mx[i]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			check(i, j);

	while (!q.empty())
	{
		auto p = q.front();
		int x1 = p.first;
		int y1 = p.second;
		q.pop();
		if (mx[x1][y1] != '.')
			continue;
		
		p = get_near(x1, y1);
		int x2 = p.first;
		int y2 = p.second;
		
		if (x2 == -1)
		{
			printf("Not unique\n");
			return 0;
		}

		if (x1 == x2)
		{
			mx[x1][min(y1, y2)] = '<';
			mx[x1][max(y1, y2)] = '>';
		}
		else
		{
			mx[min(x1, x2)][y1] = '^';
			mx[max(x1, x2)][y2] = 'v';
		}

		check_near(x1, y1);
		check_near(x2, y2);
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (mx[i][j] == '.')
			{
				printf("Not unique\n");
				return 0;
			}

	for (int i = 0; i < n; i++)
		printf("%s\n", mx[i]);

	return 0;
}