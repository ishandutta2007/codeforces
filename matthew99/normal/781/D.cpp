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

const int maxn = 500, maxm = 1000000;
const int max0 = 60;

typedef bitset<maxn + 5> bset;

bset go[max0 + 5][2][maxn + 5];

int n, m;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, m)
	{
		int u, v, t;
		scanf("%d%d%d", &u, &v, &t), --u, --v;
		go[0][t][u][v] = 1;
	}
	REP(i, 1, max0) REP(ty, 0, 2)
		REP(j, 0, n) REP(k, 0, n) if (go[i - 1][ty][j][k]) go[i][ty][j] |= go[i - 1][!ty][k];
	LL ans = 0;
	bset now;
	REP(i, 0, n) now[i] = 1;
	REP(i, 0, 1)
	{
		LL len = 0;
		int ty = i;
		for (int j = max0 - 1; j >= 0; --j)
		{
			bset nxt;
			REP(k, 0, n) if (now[k]) nxt |= go[j][ty][k];
			if (nxt.any())
			{
				len += (1LL << j);
				ty = !ty;
				now = nxt;
			}
		}
		chkmax(ans, len);
	}
	if (ans > 1000000000000000000LL) puts("-1");
	else cout << ans << endl;
	return 0;
}