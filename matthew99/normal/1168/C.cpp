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

const int maxn = 300100, max0 = 19;

int n, qn;
int a[maxn + 5];

int reach[maxn + 5][max0];
int lst[maxn + 5][max0];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &qn);
	REP(i, 0, n) scanf("%d", a + i);
	static int cur_lst[max0];
	memset(cur_lst, -1, sizeof cur_lst);
	REP(i, 0, max0) REP(j, 0, n)
	{
		if (a[j] >> i & 1) lst[j][i] = cur_lst[i], cur_lst[i] = j;
	}
	memset(reach, -1, sizeof reach);
	REP(i, 0, n) REP(j, 0, max0)
		if (a[i] >> j & 1) reach[i][j] = i;
		else
		{
			REP(k, 0, max0) if ((a[i] >> k & 1) && (~lst[i][k])) chkmax(reach[i][j], reach[lst[i][k]][j]);
		}
	REP(i, 0, qn)
	{
		int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		bool yes = 0;
		REP(j, 0, max0) if (a[x] >> j & 1)
		{
			if (reach[y][j] >= x)
			{
				yes = 1;
				break;
			}
		}
		puts(yes ? "Shi" : "Fou");
	}
	return 0;
}