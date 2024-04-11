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

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int maxn = 2500, max0 = 6;

int n, m, K;
char g[maxn + 5][maxn + 5];

int sum[2][maxn + 5][maxn + 5];

LL ans = 0;

void work(int x0, int y0, int x1, int y1, int ty)
{
	if (y1 - y0 > x1 - x0) swap(x0, y0), swap(x1, y1), ty ^= 1;
	if (x1 - x0 <= 1)
	{
		ans += sum[ty][x0][y0 + 1] - sum[ty][x0][y0] == K;
		return;
	}
	int mid = (x0 + x1) >> 1;
	work(x0, y0, mid, y1, ty);
	work(mid, y0, x1, y1, ty);
	REP(i, y0, y1)
	{
		static int pl[max0 + 1], cntl[max0 + 1];
		static int pr[max0 + 1], cntr[max0 + 1];
		REP(j, 0, K + 1) pl[j] = x0, cntl[j] = 0;
		REP(j, 0, K + 1) pr[j] = x1, cntr[j] = 0;
		REP(j, i + 1, y1 + 1)
		{
			REP(k, 0, K + 1)
			{
				cntl[k] += sum[ty ^ 1][j - 1][mid] - sum[ty ^ 1][j - 1][pl[k]];
				while (cntl[k] > k)
				{
					cntl[k] -= sum[ty][pl[k]][j] - sum[ty][pl[k]][i];
					++pl[k];
				}
			}
			REP(k, 0, K + 1)
			{
				cntr[k] += sum[ty ^ 1][j - 1][pr[k]] - sum[ty ^ 1][j - 1][mid];
				while (cntr[k] > k)
				{
					--pr[k];
					cntr[k] -= sum[ty][pr[k]][j] - sum[ty][pr[k]][i];
				}
			}
			REP(k, 0, K + 1)
				if (cntl[k] == k && cntr[K - k] == K - k) 
					ans += ((!k ? mid : pl[k - 1]) - pl[k]) * (pr[K - k] - (!(K - k) ? mid : pr[K - k -1]));
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &K);
	REP(i, 0, n) scanf("%s", g[i]);
	REP(i, 0, n)
	{
		sum[0][i][0] = 0;
		REP(j, 0, m) sum[0][i][j + 1] = sum[0][i][j] + (g[i][j] - '0');
	}
	REP(i, 0, m)
	{
		sum[1][i][0] = 0;
		REP(j, 0, n) sum[1][i][j + 1] = sum[1][i][j] + (g[j][i] - '0');
	}
	work(0, 0, n, m, 0);
	printf("%I64d\n", ans);
	return 0;
}