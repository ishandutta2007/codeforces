#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int walk[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

const int maxn = 510, maxm = 510;

int n, K;

int N;
int bel[maxn + 5][maxm + 5];
int sz[maxn * maxm + 5];
char g[maxn + 5][maxm + 5];

bool vis[maxn + 5][maxm + 5];

void dfs(int x, int y, int col)
{
	vis[x][y] = 1;
	bel[x][y] = col;
	++sz[col];
	REP(i, 0, 4)
	{
		int u = x + walk[i][0], v = y + walk[i][1];
		if (u < 0 || u >= n || v < 0 || v >= n || g[u][v] != '.') continue;
		if (vis[u][v]) continue;
		dfs(u, v, col);
	}
}

int now = 0;
int cnt[maxn * maxm + 5];

int in[maxn + 5][maxn + 5];

inline void add_lat(int x, int y, int ty)
{
	if (x < 0 || x >= n || y < 0 || y >= n) return;
	in[x][y] += ty;
	if (g[x][y] == '.') 
	{
		int tmp = bel[x][y];
		if (cnt[tmp]) now -= sz[tmp];
		cnt[tmp] += ty;
		if (cnt[tmp]) now += sz[tmp];
	}
}

inline void add_col(int u, int l, int r, int ty)
{
	if (u < 0 || u >= n) return;
	REP(i, l, r) if (i >= 0 && i < n) add_lat(u, i, ty);
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &K);
	REP(i, 0, n) scanf("%s", g[i]);
	REP(i, 0, n) REP(j, 0, n) if (g[i][j] == '.' && !vis[i][j]) dfs(i, j, N++);
	int ans = 0;
	REP(i, 0, n - K + 1)
	{
		now = 0;
		memset(in, 0, sizeof in);
		memset(cnt, 0, sizeof cnt);
		REP(j, 0, K) 
		{
			add_col(j, i - 1, i + K + 1, 1);
			REP(k, i, i + K) if (g[j][k] != '.') ++now;
		}
		REP(j, 0, n - K + 1)
		{
			add_col(j + K, i - 1, i + K + 1, 1);
			add_col(j - 2, i - 1, i + K + 1, -1);
			add_lat(j - 1, i - 1, -1);
			add_lat(j - 1, i + K, -1);
			add_lat(j + K, i - 1, -1);
			add_lat(j + K, i + K, -1);
			chkmax(ans, now);
			if (j + K < n) 
			{
				REP(k, i, i + K) if (g[j + K][k] != '.') ++now;
				REP(k, i, i + K) if (g[j][k] != '.') --now;
			}
			add_lat(j - 1, i - 1, 1);
			add_lat(j - 1, i + K, 1);
			add_lat(j + K, i - 1, 1);
			add_lat(j + K, i + K, 1);
		}
	}
	printf("%d\n", ans);
	return 0;
}