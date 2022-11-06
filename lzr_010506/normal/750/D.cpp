#include <bits/stdc++.h>
#define N 510
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int n, t[N];
bool vis[N][N], v[N][N][8][32];
//
void dfs(int x, int y, int d, int ceng)
{
	if (ceng == n) return;
	if (d < 0) d += 8;
	if (d > 7) d -= 8;
	if (v[x][y][d][ceng]) return;
	v[x][y][d][ceng] = 1;
	for (int i = 0; i < t[ceng]; i ++)
	{
		x += dx[d];
		y += dy[d];
		vis[x][y] = 1;
	}
	dfs(x, y, d + 1, ceng + 1);
	dfs(x, y, d - 1, ceng + 1);
}

int main()
{
	n = read();
	for(int i = 0; i < n; i ++) t[i] = read();
	dfs(250, 250, 0, 0);
	int ans = 0;
	for (int i = 0; i < N; i ++)
		for (int j = 0; j < N; j ++)
			ans += vis[i][j];
	cout << ans;
	return 0;
}