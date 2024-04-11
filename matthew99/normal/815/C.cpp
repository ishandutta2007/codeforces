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
const LL OO = 0x3f3f3f3f3f3f3f3fLL;

const int maxn = 5010;

int n, K;

LL cou[maxn + 5][maxn + 5];
LL ncou[maxn + 5][maxn + 5];

int fa[maxn + 5];

int sz[maxn + 5];

int a[maxn + 5], b[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &K);
	REP(i, 0, n)
	{
		scanf("%d%d", a + i, b + i);
		b[i] = a[i] - b[i];
		if (i > 0) scanf("%d", fa + i), --fa[i];
		else fa[i] = -1;
	}
	memset(cou, oo, sizeof cou);
	memset(ncou, oo, sizeof ncou);
	REP(i, 0, n) 
	{
		ncou[i][0] = 0;
		ncou[i][1] = a[i];
		cou[i][1] = b[i];
		sz[i] = 1;
	}
	for (int i = n - 1; i >= 0; --i)
	{
		if (~fa[i])
		{
			for (int j = sz[fa[i]]; j >= 0; --j)
				REP(k, 0, sz[i] + 1)
				{
					chkmin(cou[fa[i]][j + k], cou[fa[i]][j] + min(ncou[i][k], cou[i][k]));
					chkmin(ncou[fa[i]][j + k], ncou[fa[i]][j] + ncou[i][k]);
				}
			sz[fa[i]] += sz[i];
		}
	}
	int ans = n;
	while (min(cou[0][ans], ncou[0][ans]) > K) --ans;
	printf("%d\n", ans);
	return 0;
}