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

const int max0 = 17;
const int maxn = 100100;

int n, qn;

int fa[max0][maxn + 5];

int dep[maxn + 5], sum[maxn + 5];

int bel[maxn + 5];

int lca(int x, int y)
{
	if (dep[x] > dep[y]) swap(x, y);
	for (int i = 0; dep[x] != dep[y]; ++i) if ((dep[y] - dep[x]) >> i & 1) y = fa[i][y];
	assert(x >= 0);
	assert(y >= 0);
	int s = max0 - 1;
	while (x != y)
	{
		for ( ; s && fa[s][x] == fa[s][y]; --s);
		x = fa[s][x];
		y = fa[s][y];
	}
	assert(x >= 0);
	assert(y >= 0);
	return x;
}

bool work(int ty, int x, int y)
{
	if (x == y) return 0;
	if (bel[x] != bel[y]) return 0;
	int d = lca(x, y);
	if (ty == 1)
	{
		if (d != x) return 0;
		if (sum[y] != sum[x]) return 0;
		return 1;
	}
	if (y == d) return 0;
	if (sum[y] - sum[d] != dep[y] - dep[d]) return 0;
	if (sum[x] != sum[d]) return 0;
	return 1;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n)
	{
		int x;
		scanf("%d%d", fa[0] + i, &x);
		if (~fa[0][i])
		{ 
			--fa[0][i];
			bel[i] = bel[fa[0][i]];
			dep[i] = dep[fa[0][i]] + 1;
			sum[i] = sum[fa[0][i]] + x;
		}
		else bel[i] = i;
	}
	REP(i, 1, max0) REP(j, 0, n)
		if (fa[i - 1][j] == -1) fa[i][j] = fa[i - 1][j];
		else fa[i][j] = fa[i - 1][fa[i - 1][j]];
	scanf("%d", &qn);
	REP(i, 0, qn)
	{
		int ty, x, y;
		scanf("%d%d%d", &ty, &x, &y), --x, --y;
		puts(work(ty, x, y) ? "YES" : "NO");
	}
	return 0;
}