#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int N = 505;
char f[N][N];
int color[N][N];
int sz[N * N];
int inc[N * N];
int sum = 0;

int n;

int DX[4] = {-1, 1, 0, 0};
int DY[4] = {0, 0, -1, 1};

void dfs(int x, int y, int c)
{
	color[x][y] = c;
	sz[c]++;
	for (int d = 0; d < 4; d++)
	{
		int nx = x + DX[d];
		int ny = y + DY[d];
		if (f[nx][ny] != '.' || color[nx][ny] != 0) continue;
		dfs(nx, ny, c);
	}
}

void remove(int c)
{
	if (c != 0)
	{
		inc[c]--;
		if (inc[c] == 0)
			sum -= sz[c];
	}
}

void add(int c)
{
	if (c != 0)
	{
		if (inc[c] == 0)
			sum += sz[c];
		inc[c]++;
	}
}

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%s", f[i + 1] + 1);
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= n + 1; j++)
			if (i == 0 || i == n + 1 || j == 0 || j == n + 1)
				f[i][j] = 'X';

	int id = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (f[i][j] == '.' && color[i][j] == 0)
			{
				dfs(i, j, id);
				id++;
			}

	int ans = 0;
	for (int r = 0; r + k <= n; r++)
	{
		sum = 0;
		memset(inc, 0, sizeof inc);
		int cntIn = 0;
		for (int i = 0; i <= k + 1; i++)
			for (int j = 0; j <= k + 1; j++)
				if (!(i == 0 || i == k + 1) || !(j == 0 || j == k + 1) )
					add(color[j][i + r] );
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= k; j++)
				if (color[j][i + r] != 0)
					cntIn++;
		for (int c = 0; c + k <= n; c++)
		{
			int cur = sum + k * k - cntIn;
//			printf("%d\n", cur);
			ans = max(ans, cur);

			for (int i = 1; i <= k; i++)
				add(color[k + 2 + c][i + r] );
			add(color[k + 1 + c][r] );
			add(color[k + 1 + c][r + k + 1] );

			for (int i = 1; i <= k; i++)
				remove(color[c][i + r] );
			remove(color[c + 1][r] );
			remove(color[c + 1][r + k + 1] );
		
			for (int i = 1; i <= k; i++)
				if (color[c + 1][i + r] != 0)
					cntIn--;
			for (int i = 1; i <= k; i++)
				if (color[c + k + 1][i + r] != 0)
					cntIn++;
		}
	}
	printf("%d\n", ans);

	return 0;
}