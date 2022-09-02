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

const int maxn = 1000, maxm = 200000;

int n, m, qn;
pair<int, int> ed[maxm + 5];

struct data
{
	int id, s, t, r;

	data() { }
	data(int _id, int _s, int _t, int _r): id(_id), s(_s), t(_t), r(_r) { }

};

vector<data> all[maxm + 5];
bool ans[maxm + 5];

int dp[maxn + 5][maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &qn);
	REP(i, 0, m) scanf("%d%d", &ed[i].x, &ed[i].y), --ed[i].x, --ed[i].y;
	REP(i, 0, qn)
	{
		int s, t, l, r;
		scanf("%d%d%d%d", &l, &r, &s, &t), --s, --t, --l;
		all[l].pb(data(i, s, t, r));
	}
	memset(dp, oo, sizeof dp);
	REP(i, 0, n) dp[i][i] = 0;
	for (int i = m - 1; i >= 0; --i)
	{
		int u = ed[i].x, v = ed[i].y;
		dp[u][v] = dp[v][u] = i;
//		REP(j, 0, n) if (j != v) chkmin(dp[u][j], dp[v][j]);
		int *p0 = dp[u], *p1 = dp[v];
		REP(j, 0, n)
		{
			if (j != v) chkmin(*p0, *p1);
			if (j != u) chkmin(*p1, *p0);
			++p0, ++p1;
		}
		for (auto j : all[i])
		{
			ans[j.id] = dp[j.s][j.t] < j.r;
		}
	}
	REP(i, 0, qn) puts(ans[i] ? "Yes" : "No");
	return 0;
}