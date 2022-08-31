#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool canGo[4][4] = 
{
	{1, 0, 1, 0}, // M
	{0, 1, 0, 1}, // MR
	{1, 0, 0, 1}, // WR
	{0, 1, 1, 0}, // W
};
int stX[4] = {0, 1, 1, 0};
int stY[4] = {0, 1, 0, 1};


const int maxn = 1000 + 5;
int dp[4][maxn][maxn];
int a[maxn][maxn];

bool used[maxn][maxn];
pair<int, int> qu[maxn * maxn];
int n, m;


void printDp(int dp[maxn][maxn] )
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			fprintf(stderr, "%4d ", dp[i][j] );
		fprintf(stderr, "\n");
	}
	fprintf(stderr, "\n\n");
}

bool inf(int x, int y)
{
	return x >= 0 && y >= 0 && x < n && y < m;
}

void getDp(bool canGo[4], int sx, int sy, int dp[maxn][maxn] )
{
	memset(used, false, sizeof used);
	int l = 0, r = 0;
	qu[r++] = make_pair(sx, sy);
	used[sx][sy] = true;
	dp[sx][sy] = a[sx][sy];
	while (r > l)
	{
		int x = qu[l].first;
		int y = qu[l].second;
		l++;
		int curd = dp[x][y];
		for (int d = 0; d < 4; d++)
		{
			if (!canGo[d] )
				continue;
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (!inf(nx, ny) )
				continue;
			int nd = curd + a[nx][ny];
			if (!used[nx][ny] )
			{
				used[nx][ny] = true;
				qu[r++] = make_pair(nx, ny);
				dp[nx][ny] = nd;
			}
			else
			{
				dp[nx][ny] = max(dp[nx][ny], nd);
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j] );
	for (int i = 0; i < 4; i++)
	{
		stX[i] *= n - 1;
		stY[i] *= m - 1;
	}
	for (int i = 0; i < 4; i++)
	{
		getDp(canGo[i], stX[i], stY[i], dp[i] );
		printDp(dp[i] );
	}
	int answer = 0;
	for (int i = 1; i < n - 1; i++)
		for (int j = 1; j < m - 1; j++)
		{
			int curans1 = dp[0][i - 1][j] + dp[1][i + 1][j] + dp[2][i][j - 1] + dp[3][i][j + 1];
			int curans2 = dp[0][i][j - 1] + dp[1][i][j + 1] + dp[2][i + 1][j] + dp[3][i - 1][j];
			answer = max(answer, curans1);
			answer = max(answer, curans2);
		}
	printf("%d\n", answer);


	return 0;
}