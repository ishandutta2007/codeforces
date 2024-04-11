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

const int maxn = 100100, maxK = 12, maxm = 100100;

typedef bitset<(1 << maxK) + 5> bset;

int n, K, qn;

int a[maxK + 5][maxn + 5];

bset b[maxm + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &K, &qn);
	REP(i, 0, K) REP(j, 0, n)
		scanf("%d", a[i] + j);
	REP(i, 0, K) REP(j, 0, 1 << K) b[i][j] = j >> i & 1;
	int cur = K;
	REP(qid, 0, qn)
	{
		int ty;
		int x, y;
		scanf("%d", &ty);
		if (ty == 1)
		{
			scanf("%d%d", &x, &y), --x, --y;
			b[cur++] = b[x] | b[y];
		}
		else if (ty == 2)
		{
			scanf("%d%d", &x, &y), --x, --y;
			b[cur++] = b[x] & b[y];
		}
		else if (ty == 3)
		{
			scanf("%d%d", &x, &y), --x, --y;
			int ans = 0;
			REP(i, 0, K)
			{
				int tmp = 0;
				REP(j, 0, K) if (a[j][y] >= a[i][y]) tmp |= 1 << j;
				if (b[x][tmp]) chkmax(ans, a[i][y]);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}