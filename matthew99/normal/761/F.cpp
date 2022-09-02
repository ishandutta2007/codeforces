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

const int maxn = 1010, maxk = 300100;

int n, m, K;
int a[maxn + 5][maxn + 5];
int sum[maxn + 5][maxn + 5][26];

pair<pair<int, int>, pair<int, int> > q[maxk + 5];
int ch[maxk + 5];

LL tot = 0, dta[maxn + 5][maxn + 5][26];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &K);
	REP(i, 0, n)
	{
		static char s[maxn + 5];
		scanf("%s", s);
		REP(j, 0, m) a[i][j] = s[j] - 'a';
	}
	REP(i, 0, K)
	{
		int u, v, x, y;
		char w[5];
		scanf("%d%d%d%d%s", &u, &v, &x, &y, w), --u, --v;
		q[i] = mp(mp(u, v), mp(x, y));
		ch[i] = w[0] - 'a';
		++sum[u][v][ch[i]];
		--sum[u][y][ch[i]];
		--sum[x][v][ch[i]];
		++sum[x][y][ch[i]];
	}
	REP(i, 0, n) REP(j, 0, m)
	{
		int res = K;
		int tmp = 0;
		REP(c, 0, 26)
		{
			if (i) sum[i][j][c] += sum[i - 1][j][c];
			if (j) sum[i][j][c] += sum[i][j - 1][c];
			if (i && j) sum[i][j][c] -= sum[i - 1][j - 1][c];
			tmp += sum[i][j][c] * abs(a[i][j] - c);
			res -= sum[i][j][c];
		}
		tot += tmp;
		REP(c, 0, 26) dta[i + 1][j + 1][c] = -tmp + res * abs(a[i][j] - c);
		int presum = 0, precnt = 0;
		REP(c, 0, 26)
		{
			dta[i + 1][j + 1][c] += precnt * c - presum;
			presum += sum[i][j][c] * c, precnt += sum[i][j][c];
		}
		presum = precnt = 0;
		for (int c = 25; c >= 0; --c)
		{
			dta[i + 1][j + 1][c] += presum - precnt * c;
			presum += sum[i][j][c] * c, precnt += sum[i][j][c];
		}
	}
	REP(i, 0, n + 1) REP(j, 0, m + 1)
	{
		REP(c, 0, 26)
		{
			dta[i + 1][j][c] += dta[i][j][c];
			dta[i][j + 1][c] += dta[i][j][c];
			dta[i + 1][j + 1][c] -= dta[i][j][c];
		}
	}
	LL ans = LLONG_MAX;
	REP(i, 0, K) chkmin(ans, tot + dta[q[i].x.x][q[i].x.y][ch[i]] - dta[q[i].y.x][q[i].x.y][ch[i]] - dta[q[i].x.x][q[i].y.y][ch[i]] + dta[q[i].y.x][q[i].y.y][ch[i]]);
	cout << ans << endl;
	return 0;
}