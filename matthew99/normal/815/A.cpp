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

const int maxn = 110;

int n, m;
int a[maxn + 5][maxn + 5];

vector<pair<int, int> > ans;

inline void work_row(int x)
{
	int Min = oo;
	REP(i, 0, m) chkmin(Min, a[x][i]);
	REP(i, 0, Min) ans.pb(mp(0, x));
	REP(i, 0, m) a[x][i] -= Min;
}

inline void work_col(int x)
{
	int Min = oo;
	REP(i, 0, n) chkmin(Min, a[i][x]);
	REP(i, 0, Min) ans.pb(mp(1, x));
	REP(i, 0, n) a[i][x] -= Min;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n) REP(j, 0, m) scanf("%d", a[i] + j);
	if (n < m)
	{
		REP(i, 0, n) work_row(i);
		REP(i, 0, m) work_col(i);
	}
	else
	{
		REP(i, 0, m) work_col(i);
		REP(i, 0, n) work_row(i);
	}
	REP(i, 0, n)
	{
		REP(j, 0, m) if (a[i][j])
		{
			puts("-1");
			return 0;
		}
	}
	printf("%d\n", SZ(ans));
	for (auto u : ans)
	{
		if (u.x == 0) printf("row ");
		else printf("col ");
		printf("%d\n", u.y + 1);
	}
	return 0;
}