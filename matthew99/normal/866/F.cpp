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

#define ctz __builtin_ctz
#define bcnt __builtin_popcount

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxN = 70;

const int maxn = 50;

const int lim = 22;

LL C[maxN + 5][maxN + 5];

inline void prepare()
{
	REP(i, 0, maxN)
	{
		C[i][0] = 1;
		REP(j, 1, i + 1)
		{
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
}

int n, m, N;

int mid;
int g[maxN + 5];

vector<pair<LL, int> > partb[maxn + 5][maxn + 5];

void dfs_partb(int x, int cnta, int cntb, LL sum = 0)
{
	if (x == mid) 
	{
		partb[cnta][cntb].pb(mp(sum, 1));
		return;
	}
	REP(i, 0, 2)
	{
		if (~g[x - 1] && i != g[x - 1]) continue;
		LL tmp = 0;
		if (i == 0)
		{
			if (cnta > 0)
			{
				REP(j, 0, n) tmp += C[cnta - 1][n - 1] * C[cntb][j] * C[N - x][n - j];
				dfs_partb(x - 1, cnta - 1, cntb, sum + tmp);
			}
		}
		else
		{
			if (cntb > 0)
			{
				REP(j, 0, n) tmp -= C[cntb - 1][n - 1] * C[cnta][j] * C[N - x][n - j];
				dfs_partb(x - 1, cnta, cntb - 1, sum + tmp);
			}
		}
	}
}

map<LL, LL> parta[maxn + 5][maxn + 5];

LL ans = LLONG_MAX, ans_cnt = 0;

inline void update(const LL &val, const LL &cnt)
{
	if (chkmin(ans, val)) ans_cnt = cnt;
	else if (val == ans) ans_cnt += cnt;
}

void bfs_parta()
{
	REP(i, 0, n + m + 1) REP(j, 0, n + m + 1) parta[i][j].clear();
	parta[0][0][0] = 1;
	REP(i, 0, n + m + 1) REP(j, 0, n + m + 1) 
		for (auto u : parta[i][j])
		{
			if (i + j == mid)
			{
				int p = lower_bound(ALL(partb[i][j]), mp(-u.x, -1)) - partb[i][j].begin();
				if (p < SZ(partb[i][j])) update(abs(u.x + partb[i][j][p].x), u.y * partb[i][j][p].y);
				if (p)
				{
					update(abs(u.x + partb[i][j][p - 1].x), u.y * partb[i][j][p - 1].y);
				}
			}
			else
			{
				int p = i + j;
				REP(k, 0, 2)
				{ 
					if (~g[p] && k != g[p]) continue;
					int cnta = i, cntb = j;
					if (k == 0) ++cnta;
					else ++cntb;
					if (cnta <= n + m && cntb <= n + m)
					{
						LL tmp = 0;
						if (k == 0)
						{
							REP(l, 0, n) tmp += C[cnta - 1][n - 1] * C[cntb][l] * C[N - p - 1][n - l];
						}
						else
						{
							REP(l, 0, n) tmp -= C[cntb - 1][n - 1] * C[cnta][l] * C[N - p - 1][n - l];
						}
						parta[cnta][cntb][u.x + tmp] += u.y;
					}
				}
			}
		}
}

inline void work()
{
	REP(i, 0, n + m + 1) REP(j, 0, n + m + 1) partb[i][j].clear();
	dfs_partb(N, n + m, n + m);
	REP(i, 0, n + m + 1) REP(j, 0, n + m + 1)
	{
		sort(ALL(partb[i][j]));
		vector<pair<LL, int> > tmp;
		int sz = SZ(partb[i][j]);
		for (int k = 0; k < sz; )
		{
			LL cur = partb[i][j][k].x;
			int cnt = 0;
			while (k < sz && partb[i][j][k].x == cur) cnt += partb[i][j][k].y, ++k;
			tmp.pb(mp(cur, cnt));
		}
		partb[i][j] = tmp;
	}
	bfs_parta();
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	static char s[maxN + 5];
	scanf("%d%d%s", &n, &m, s);
	N = (n + m) << 1;
	mid = max(0, N - lim);
	memset(g, -1, sizeof g);
	work();
	ans_cnt = 0;
	REP(i, 0, N) if (s[i] == 'A') g[i] = 0; else if (s[i] == 'B') g[i] = 1;
	work();
	cout << ans_cnt << endl;
	return 0;
}