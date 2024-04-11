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

const int maxn = 100100;

const int walk[6][2] = {-1, -1, -1, 0, -1, 1, 1, -1, 1, 0, 1, 1};

int a[2][maxn + 5];
int cnt;
int n, qn;

inline void calc(int x, int y, int z)
{
	REP(i, 0, 6)
	{
		int u = x + walk[i][0], v = y + walk[i][1];
		if (u < 2 && u >= 0 && v >= 0 && v < n)
		{
			if (a[u][v]) cnt += z;
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &qn);
	REP(i, 0, qn)
	{
		int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		a[x][y] ^= 1;
		calc(x, y, a[x][y] * 2 - 1);
		puts(cnt == 0 ? "Yes" : "No");
	}
	return 0;
}