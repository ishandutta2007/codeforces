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

const int maxn = 22;
const int maxN = 1 << maxn;

int n, m, N, full;
int a[maxN + 5];
int id[maxN + 5];

bool has[maxN + 5];

int fa[maxN + 5];

int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }

inline void Union(int x, int y)
{
	x = get(x), y = get(y);
	fa[x] = y;
}

bool vis[maxN + 5];

void dfs(int x, int y)
{
	if (!has[x]) return;
	if (vis[x])
	{
		Union(id[x], y);
		return;
	}
	if (~id[x]) Union(id[x], y);
	id[x] = y;
	vis[x] = 1;
	REP(i, 0, n) if ((x >> i) & 1)
	{
		dfs(x ^ (1 << i), y);
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m), N = 1 << n;
	full = (1 << n) - 1;
	memset(id, -1, sizeof id);
	REP(i, 0, m)
	{
		scanf("%d", a + i);
		id[a[i]] = i;
		has[a[i]] = 1;
	}
	REP(i, 0, n) REP(j, 0, N) if (j >> i & 1) 
	{
		if (has[j ^ (1 << i)]) has[j] = 1;
	}
	REP(i, 0, m) fa[i] = i;
	REP(i, 0, m)
	{
		dfs(full ^ a[i], i);
	}
	set<int> all;
	REP(i, 0, m) all.insert(get(i));
	printf("%d\n", SZ(all));
	return 0;
}