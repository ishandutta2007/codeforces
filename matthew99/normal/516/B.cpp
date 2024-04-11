#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cctype>
#include <cassert>
#include <ctime>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

const int maxn = 2000;

int n, m;

char g[maxn + 5][maxn + 5];

int walk[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool vis[maxn + 5][maxn + 5];

bool able(const int &x, const int &y)
{
	return x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '.';
}

bool ok(const int &x, const int &y)
{
	if (!able(x, y)) return 0;
	int cnt = 0;
	REP(i, 0, 4) cnt += able(x + walk[i][0], y + walk[i][1]);
	if (!cnt) EXIT("Not unique\n");
	return cnt <= 1;
}

pair<int, int> q[maxn * maxn + 5];
int tot = 0;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n) scanf("%s", g[i]);
	REP(i, 0, n)
		REP(j, 0, m)
			if (ok(i, j)) q[tot++] = mp(i, j), vis[i][j] = 1;
	for (int i = 0; i < tot; ++i)
	{
		const pair<int, int> &x = q[i];
		if (!ok(x.x, x.y)) continue;
		REP(i, 0, 4) if (able(x.x + walk[i][0], x.y + walk[i][1]))
		{
			if (!walk[i][0])
			{
				int a = x.y, b = x.y + walk[i][1];
				if (a > b) swap(a, b);
				g[x.x][a] = '<';
				g[x.x][b] = '>';
			}
			else
			{
				int a = x.x, b = x.x + walk[i][0];
				if (a > b) swap(a, b);
				g[a][x.y] = '^';
				g[b][x.y] = 'v';
			}
			int u = x.x + walk[i][0], v = x.y + walk[i][1];
			REP(i, 0, 4)
				if (ok(u + walk[i][0], v + walk[i][1]) && !vis[u + walk[i][0]][v + walk[i][1]]) vis[u + walk[i][0]][v + walk[i][1]] = 1, q[tot++] = mp(u + walk[i][0], v + walk[i][1]);
		}
	}
	REP(i, 0, n)
		REP(j, 0, m)
			if (g[i][j] == '.') EXIT("Not unique\n");
	REP(i, 0, n)
	{
		REP(j, 0, m) printf("%c", g[i][j]);
		printf("\n");
	}
	return 0;
}