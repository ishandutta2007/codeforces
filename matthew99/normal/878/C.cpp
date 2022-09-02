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

const int maxn = 50100, maxK = 11;

int n, K;

int a[maxK + 5][maxn + 5];

int pos[maxK + 5][maxn + 5];
int where[maxK + 5][maxn + 5];

int fa[maxn + 5], sz[maxn + 5];

int get(int x)
{
	return fa[x] == x ? x : fa[x] = get(fa[x]);
}

inline void add(int x, int y)
{
	x = where[0][x], y = where[0][y];
	while (1)
	{
		y = get(y);
		if (y <= x) return;
		fa[y] = y - 1; 
		sz[get(y - 1)] += sz[y];
		--y;
	}
}

set<int> all[maxK + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &K);
	REP(i, 0, n)
	{
		REP(j, 0, K) scanf("%d", a[j] + i);
	}
	REP(i, 0, K)
	{
		REP(j, 0, n) pos[i][j] = j;
		sort(pos[i], pos[i] + n, [&](int x, int y) { return a[i][x] < a[i][y]; });
		REP(j, 0, n) where[i][pos[i][j]] = j;
	}
	REP(i, 0, n) fa[i] = i;
	int Max = 0;
	REP(i, 0, n)
	{
		chkmax(Max, where[0][i]);
		REP(j, 1, K)
		{
			auto tmp = all[j].lower_bound(where[j][i]);
			if (tmp != all[j].end())
			{
				add(pos[j][*tmp], i); 
			}
			if (tmp != all[j].begin())
			{
				--tmp;
				add(i, pos[j][*tmp]); 
			}
			all[j].insert(where[j][i]);
		}
		++sz[get(where[0][i])];
		printf("%d\n", sz[get(Max)]);
	}
	return 0;
}