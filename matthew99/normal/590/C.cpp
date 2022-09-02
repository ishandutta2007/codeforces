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

const int max0 = 10000000;

const int maxn = 1000, maxm = 1000, maxk = 3;

int n, m;

char s[maxn + 5][maxm + 5];

int ans = oo;
int dp[maxn + 5][maxn + 1][1 << maxk];

struct data
{
	int sta, dis;

	friend bool operator<(const data &x, const data &y)
	{
		return x.dis > y.dis;
	}

	data() { }
	data(int _sta, int _dis): sta(_sta), dis(_dis) { }

};

int walk[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n)
		scanf("%s", s[i]);
	memset(dp, oo, sizeof dp);
	REP(i, 0, n)
		REP(j, 0, m)
		{
			if (s[i][j] == '#') continue;
			dp[i][j][0] = s[i][j] == '.';
			if (isdigit(s[i][j])) dp[i][j][1 << (s[i][j] - '1')] = 0;
		}
	REP(mask, 0, 1 << maxk)
	{
		REP(i, 0, n)
			REP(j, 0, m)
				for (int k = mask; ; k = (k - 1) & mask)
				{
					chkmin(dp[i][j][mask], dp[i][j][k] + dp[i][j][mask ^ k] - (s[i][j] == '.'));
					if (!k) break;
				}
		static data q[max0 + 5];
		static bool vis[maxn * maxm + 5];
		memset(vis, 0, sizeof vis);
		int tot = 0;
		REP(i, 0, n)
			REP(j, 0, m)
				if (dp[i][j][mask] < oo) q[tot++] = data(i * m + j, dp[i][j][mask]);
		make_heap(q, q + tot);
		while (tot)
		{
			data x = q[0];
			pop_heap(q, q + (tot--));
			if (vis[x.sta]) continue;
			int u = x.sta / m, v = x.sta % m;
			REP(i, 0, 4)
			{
				int u0 = u + walk[i][0], v0 = v + walk[i][1];
				if (u0 < 0 || u0 >= n || v0 < 0 || v0 >= m) continue;
				if (s[u0][v0] == '#') continue;
				if (chkmin(dp[u0][v0][mask], dp[u][v][mask] + (s[u0][v0] == '.'))) q[tot++] = data(u0 * m + v0, dp[u0][v0][mask]);
			}
		}
	}
	REP(i, 0, n) REP(j, 0, m) chkmin(ans, dp[i][j][(1 << maxk) - 1]);
	if (ans == oo) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}