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

const int Mod = 1e9 + 7;

const int maxn = 2000, maxm = 2000;

int n, m;
char a[maxn + 5], b[maxn + 5], c[maxn + 5];

int g[2][maxn + 5];
int w[maxn + 5];

bool ok_left[2][maxn + 5][maxm + 5];
bool ok_right[2][maxn + 5][maxm + 5];

int Max[2][maxn + 5][maxm + 5];

int dp[2][maxn + 5][maxn + 5];

int ans = 0;

inline void update(int i, int j, int k, int val)
{
	if (k == m || ok_right[i][j][k]) (ans += val) %= Mod;
}

inline void solve(bool ty)
{
	memset(ok_left, 0, sizeof ok_left);
	memset(ok_right, 0, sizeof ok_right);
	memset(Max, 0, sizeof Max);
	REP(i, 0, 2)
	{
		for (int j = n - 1; j >= 0; --j) for (int k = m - 1; k >= 0; --k)
			if (g[i][j] == w[k]) Max[i][j][k] = Max[i][j + 1][k + 1] + 1;
	}
	REP(i, 0, 2)
	{
		REP(j, 0, n)
		{
			int k = j;
			int cur = 0;
			while (k >= 0)
			{
				if (g[i][k] != w[cur++] || (cur << 1) > m) break;
				if (k != j) ok_left[!i][j + 1][cur << 1] = k + Max[!i][k][cur] > j;
				--k;
			}
		}
		for (int j = n - 1; j >= 0; --j)
		{
			int k = j;
			int cur = m;
			while (k < n)
			{
				if (g[i][k] != w[--cur] || (cur << 1) < m) break;
				if (j != k) ok_right[!i][j][(cur << 1) - m] = j + Max[!i][j][(cur << 1) - m] > k;
				++k;
			}
		}
	}
	memset(dp, 0, sizeof dp);
	REP(j, 0, n + 1)
	{
		REP(i, 0, 2)
			REP(k, 0, m + 1)
			{
				if (!k || ok_left[i][j][k]) (++dp[i][j][k]) %= Mod;
				if (ty && k && k < m) update(i, j, k, dp[i][j][k]);
				if (dp[i][j][k])
				{
					if (j < n)
					{
						if (k < m && g[i][j] == w[k]) 
						{
							(dp[i][j + 1][k + 1] += dp[i][j][k]) %= Mod;
							if (ty && k && k + 1 == m) update(i, j + 1, k + 1, dp[i][j][k]);
						}
						if (k + 1 < m && g[i][j] == w[k] && g[!i][j] == w[k + 1]) 
						{
							(dp[!i][j + 1][k + 2] += dp[i][j][k]) %= Mod;
							if (ty && k && k + 2 == m) update(!i, j + 1, k + 2, dp[i][j][k]);
						}
					}
					if (!ty) update(i, j, k, dp[i][j][k]);
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
	scanf("%s%s%s", a, b, c);
	n = strlen(a), m = strlen(c);
	REP(i, 0, n) g[0][i] = a[i] - 'a', g[1][i] = b[i] - 'a';
	REP(i, 0, m) w[i] = c[i] - 'a';
	ans = 0;
	solve(0);
	reverse(w, w + m);
	solve(1);
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}