#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
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

const int maxn = 100000;

int n, m, K;

vector<int> ret[maxn + 5];

const int walk[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool vis[5][5];
bool g[5][5];

void dfs(int x, int y)
{
	vis[x][y] = 1;
	REP(i, 0, 4)
	{
		int u = x + walk[i][0], v = y + walk[i][1];
		if (u < 0 || u >= n || v < 0 || v >= m) continue;
		if (g[u][v] && !vis[u][v]) dfs(u, v);
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &m, &K);
		if (n <= 4 && m <= 4)
		{
			bool find = 0;
			REP(i, 1, (1 << (n * m)))
			{
				REP(j, 0, n) REP(k, 0, m) g[j][k] = (i >> (j * m + k) & 1);
				int cnt = 0;
				memset(vis, 0, sizeof vis);
				REP(j, 0, n) REP(k, 0, m) if (g[j][k] && !vis[j][k]) dfs(j, k), ++cnt;
				if (cnt > 1) continue;
				int tot = 0;
				REP(j, 0, n - 1) REP(k, 0, m - 1)
				{
					int tmp = g[j][k] + g[j + 1][k] + g[j][k + 1] + g[j + 1][k + 1];
					if (tmp == 3) ++tot;
					else if (tmp == 4) tot += 4;
				}
				if (tot == K)
				{
					find = 1;
					REP(j, 0, n)
					{
						REP(k, 0, m)
						{
							if (g[j][k]) putchar('*');
							else putchar('.');
						}
						putchar('\n');
					}
					putchar('\n');
					break;
				}
			}
			if (!find) puts("-1\n");
			continue;
		}
		if (K > ((n - 1) * (m - 1) << 2))
		{
			puts("-1\n");
			continue;
		}
		else if (K == ((n - 1) * (m - 1) << 2))
		{
			REP(i, 0, n)
			{
				REP(j, 0, m) putchar('*');
				putchar('\n');
			}
			putchar('\n');
			continue;
		}
		else if (K == ((n - 1) * (m - 1) << 2) - 8)
		{
			if (n == 3)
			{
				REP(i, 0, n)
				{
					REP(j, 0, m) putchar(!j ? '.' : '*');
					putchar('\n');
				}
			}
			else if (m == 3)
			{
				REP(i, 0, n)
				{
					REP(j, 0, m) putchar(!i ? '.' : '*');
					putchar('\n');
				}
			}
			else puts("-1");
			putchar('\n');
			continue;
		}
		else if (!K)
		{
			REP(i, 0, n)
			{
				REP(j, 0, m) putchar((!i && !j ? '*' : '.'));
				putchar('\n');
			}
			putchar('\n');
			continue;
		}
		bool rev = 0;
		if (n > m) swap(n, m), rev = 1;
		REP(i, 0, n) ret[i] = vector<int>(m, 0);
		bool failed = 0;
		--K;
		REP(i, 0, m) ret[0][i] = 1;
		int px = 0, py = m - 1;
		REP(i, 1, n) REP(j, 1, m)
		{
			if (K < 4) break;
			px = i, py = j;
			ret[i][j] = 1;
			K -= 4;
		}
		if (py == m - 1) ++px, py = 0;
		REP(i, 0, px + 1) ret[i][0] = 1;
		if (K == 1)
		{
			if (px != n - 1) 
			{
				if (py >= 1) ret[px + 1][0] = 1;
				else ret[px][m - 1] = 1;
			}
			else if (py < m - 2) ret[n - 1][m - 1] = 1;
			else failed = 1;
		}
		else if (K == 2)
		{
			if (px != n - 1)
			{
				if (py >= 2) ret[px + 1][1] = 1;
				else ret[px][m - 2] = 1;
			}
			else if (py < m - 3) ret[px][m - 2] = 1;
			else failed = 1;
		}
		else if (K == 3)
		{
			if (px != n - 1)
			{
				if (py >= 3) ret[px + 1][0] = ret[px + 1][py - 1] = 1;
				else if (py == 2) ret[px + 1][1] = ret[px][m - 1] = 1;
				else if (py == 1) ret[px + 1][0] = ret[px][m - 2] = 1;
				else ret[px][m - 3] = ret[px][m - 1] = 1;
			}
			else if (py < m - 4) ret[px][m - 3] = ret[px][m - 1] = 1;
			else failed = 1;
		}
		if (rev) swap(n, m);
		if (failed)
		{
			puts("-1");
		}
		else
		{
			REP(i, 0, n)
			{
				REP(j, 0, m) putchar((rev ? ret[j][i] : ret[i][j]) ? '*' : '.');
				putchar('\n');
			}
		}
		putchar('\n');
	}
	return 0;
}