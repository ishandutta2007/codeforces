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

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 12, maxnum = 10;

int n, m;
pair<int, int> a[maxn + 5], b[maxn + 5];

int has[maxnum + 5];
int hasa[maxn + 5][maxnum + 5], hasb[maxn + 5][maxnum + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
	}
	REP(i, 0, m)
	{
		scanf("%d%d", &b[i].x, &b[i].y);
	}
	REP(i, 0, n) REP(j, 0, m)
		if ((a[i].x == b[j].x) + (a[i].x == b[j].y) + (a[i].y == b[j].x) + (a[i].y == b[j].y) == 1)
		{
			REP(k, 1, 10) if (k == a[i].x || k == a[i].y)
				if (k == b[j].x || k == b[j].y)
				{
					has[k] = 1;
					hasa[i][k] = 1;
					hasb[j][k] = 1;
				}
		}
	int cnt = 0;
	REP(i, 1, 10) if (has[i]) ++cnt;
	if (cnt == 1)
	{
		REP(i, 1, 10) if (has[i]) printf("%d\n", i);
	}
	else
	{
		assert(cnt > 1);
		REP(i, 0, n)
		{
			int cnta = 0;
			REP(j, 1, 10) if (hasa[i][j]) ++cnta;
			if (cnta > 1)
			{
				printf("-1\n");
				exit(0);
			}
		}
		REP(i, 0, m)
		{
			int cntb = 0;
			REP(j, 1, 10) if (hasb[i][j]) ++cntb;
			if (cntb > 1)
			{
				printf("-1\n");
				exit(0);
			}
		}
		printf("0\n");
	}
	return 0;
}