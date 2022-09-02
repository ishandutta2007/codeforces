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

const int maxn = 100100;

const int len = 10;

int n;
char s[maxn + 5];

int qn;

int sum[4][len + 1][len][maxn + 5];

inline int get_id(const char &c)
{
	if (c == 'A') return 0;
	if (c == 'T') return 1;
	if (c == 'G') return 2;
	if (c == 'C') return 3;
	assert(0);
	return -1;
}

inline void add(int x, int y)
{
	int tmp = get_id(s[x]);
	REP(i, 1, len + 1)
	{
		int j = x % i;
		for (int k = x + 1; k <= n; k += k & -k) sum[tmp][i][j][k] += y;
	}
}

inline int get_sum(int *fen, int x)
{
	int ret = 0;
	for (int i = x; i > 0; i -= i & -i) ret += fen[i];
	return ret;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", s);
	n = strlen(s);
	REP(i, 0, n) add(i, 1);
	scanf("%d", &qn);
	REP(i, 0, qn)
	{
		int ty, x;
		static char c[20];
		scanf("%d", &ty);
		if (ty == 1)
		{
			scanf("%d%s", &x, c), --x;
			add(x, -1);
			s[x] = c[0];
			add(x, 1);
		}
		else
		{
			int l, r;
			scanf("%d%d", &l, &r), --l;
			scanf("%s", c);
			int m = strlen(c);
			int ans = 0;
			REP(j, 0, m)
			{
				ans += get_sum(sum[get_id(c[j])][m][(l + j) % m], r) - get_sum(sum[get_id(c[j])][m][(l + j) % m], l);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}