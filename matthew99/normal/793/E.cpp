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

const int maxn = 5010;

bool leaf[maxn + 5];

int n, m;

int a[4];

int fa[maxn + 5];

bool dpa[4][maxn + 5];

int place[4];

int sz[maxn + 5];

bool has[maxn + 5];

inline void work(int id)
{
	static bool vis[maxn + 5];
	memset(vis, 0, sizeof vis);
	int u = a[id];
	while (u)
	{
		has[u] = 1;
		vis[u] = 1;
		if (fa[u] == 0) place[id] = u;
		u = fa[u];
	}
	memset(dpa[id], 0, sizeof dpa[id]);
	dpa[id][0] = 1;
	REP(i, 1, n) if (!vis[i] && vis[fa[i]])
		for (int j = maxn - sz[i]; j >= 0; --j) dpa[id][j + sz[i]] |= dpa[id][j];
}

bool dp[maxn + 5];

inline bool check(int from, int mid, int to)
{
	REP(i, 0, sz[place[from]] + 1) if (dpa[from][i]) REP(j, 0, sz[place[to]] + 1) if (dpa[from][j])
	{
		int resj = sz[place[to]] - j;
		if (i + resj + sz[place[mid]] <= (m >> 1) && dp[(m >> 1) - i - resj - sz[place[mid]]])
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, 4) scanf("%d", a + i), --a[i];
	fa[0] = -1;
	REP(i, 0, n) leaf[i] = 1;
	REP(i, 1, n) scanf("%d", fa + i), --fa[i], leaf[fa[i]] = 0;
	REP(i, 0, n) sz[i] += leaf[i];
	for (int i = n - 1; i >= 1; --i) sz[fa[i]] += sz[i];
	m = sz[0];
	if (m & 1) { puts("NO"); return 0; }
	REP(i, 0, 4) work(i);
	dp[0] = 1;
	REP(i, 1, n) if (!has[i] && fa[i] == 0)
		for (int j = m - sz[i]; j >= 0; --j) dp[j + sz[i]] |= dp[j];
	if (check(0, 2, 1) && check(1, 3, 0)) puts("YES");
	else if (check(0, 3, 1) && check(1, 2, 0)) puts("YES");
	else puts("NO");
	return 0;
}