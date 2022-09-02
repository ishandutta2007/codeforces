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

const int maxn = 50, maxm = 50;

int n, m;

char ban;

inline bool check(char a[maxn + 5][maxn + 5])
{
	REP(i, 0, n) REP(j, 0, m) if (a[i][j] == ban) return 0;
	return 1;
}

inline void work(char a[maxn + 5][maxn + 5], vector<pair<int, int> > &ans)
{
	while (1)
	{
		while (1)
		{
			bool find = 0;
			REP(i, 0, n - 1) REP(j, 0, m - 1) if (a[i][j] == 'L' && a[i + 1][j] == 'L')
			{
				ans.pb(mp(i, j));
				a[i][j] = 'U';
				a[i + 1][j] = 'D';
				a[i][j + 1] = 'U';
				a[i + 1][j + 1] = 'D';
				find = 1;
			}
			if (!find) break;
		}
		if (check(a)) break;
		while (1)
		{
			bool find = 0;
			REP(i, 0, n - 1) REP(j, 0, m - 1) if (a[i][j] == 'U' && a[i][j + 1] == 'U')
			{
				ans.pb(mp(i, j));
				a[i][j] = 'L';
				a[i][j + 1] = 'R';
				a[i + 1][j] = 'L';
				a[i + 1][j + 1] = 'R';
				find = 1;
			}
			if (!find) break;
		}
		if (check(a)) break;
	}
}

char a[maxn + 5][maxm + 5];
char b[maxn + 5][maxm + 5];

vector<pair<int, int> > a0, a1;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n) scanf("%s", a[i]);
	REP(i, 0, n) scanf("%s", b[i]);
	if (n & 1) ban = 'U';
	else ban = 'L';
	work(a, a0);
	work(b, a1);
	printf("%d\n", SZ(a0) + SZ(a1));
	REP(i, 0, SZ(a0)) printf("%d %d\n", a0[i].x + 1, a0[i].y + 1);
	reverse(ALL(a1));
	REP(i, 0, SZ(a1)) printf("%d %d\n", a1[i].x + 1, a1[i].y + 1);
	return 0;
}