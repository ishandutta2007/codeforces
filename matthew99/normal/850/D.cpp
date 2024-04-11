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

const int max0 = 70;
const int max1 = 500;
const int maxn = 50;

int n;
int a[maxn + 5];

int pre[maxn + 5][max0 + 5][max1 + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	sort(a, a + n);
	memset(pre, -1, sizeof pre);
	pre[0][0][0] = 0;
	REP(i, 0, n) REP(j, 0, max0) REP(k, 0, max1) if (~pre[i][j][k])
	{
		if (k + a[i] - j >= 0) pre[i][j + 1][k + a[i] - j] = i, pre[i + 1][j + 1][k + a[i] - j] = i;
	}
	REP(i, 0, max0) if (~pre[n][i][0])
	{
		int p = n, u = i, v = 0;
		vector<int> ret;
		while (u)
		{
			p = pre[p][u][v];
			ret.pb(a[p]);
			--u;
			v += u - a[p];
		}
		reverse(ALL(ret));
		printf("%d\n", SZ(ret));
		static bool f[max0 + 5][max1 + 5];
		memset(f, 0, sizeof f);
		REP(j, 0, SZ(ret))
		{
			static int pos[max0 + 5];
			int posn = 0;
			REP(k, j + 1, SZ(ret)) pos[posn++] = k;
			sort(pos, pos + posn, [&](int x, int y) { return ret[x] < ret[y]; });
			REP(k, 0, posn)
				if (ret[j])
				{
					--ret[j];
					f[j][pos[k]] = 1;
				}
				else f[pos[k]][j] = 1, --ret[pos[k]];
		}
		REP(j, 0, SZ(ret))
		{
			REP(k, 0, SZ(ret)) printf("%d", f[j][k]);
			printf("\n");
		}
		return 0;
	}
	puts("=(");
	return 0;
}