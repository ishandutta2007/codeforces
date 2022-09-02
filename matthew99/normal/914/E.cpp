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

#ifdef __WIN32
#define LLFORMAT "I64"
#define Rand() ((rand() << 15) | rand())
#else
#define LLFORMAT "ll"
#define Rand() (rand())
#endif

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 200000;
const int maxabs = 1 << 20;

struct edge
{
	int id, nxt;

	edge() { }
	edge(int _id, int _nxt): id(_id), nxt(_nxt) { }

};

edge e[(maxn << 1) + 5];
int st[maxn + 5], en = 0;

inline void add_edge(int x, int y)
{
	e[en] = edge(y, st[x]), st[x] = en++;
}

int n;

int sz[maxn + 5];
int Max[maxn + 5];
int dfs_seq[maxn + 5], dfs_tot = 0;

void pre_dfs(int x, int f = -1)
{
	dfs_seq[dfs_tot++] = x;
	sz[x] = 1;
	Max[x] = 0;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == f) continue;
		pre_dfs(y, x);
		sz[x] += sz[y];
		chkmax(Max[x], sz[y]);
	}
}

bool del_edge(int x, int y)
{
	for (int *i = st + x; *i != -1; i = &e[*i].nxt)
		if (e[*i].id == y)
		{
			*i = e[*i].nxt;
			return 1;
		}
	return 0;
}

int a[maxn + 5];
int val[maxn + 5];

int fa[maxn + 5];

void dfs(int x, int f = -1)
{
	dfs_seq[dfs_tot++] = x;
	val[x] ^= a[x];
	fa[x] = f;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == f) continue;
		val[y] = val[x];
		dfs(y, x);
	}
}

LL ans[maxn + 5];

void work(int rt, int d = 0)
{
	dfs_tot = 0;
	pre_dfs(rt);
	static LL sum[maxn + 5];
	int x = -1;
	REP(i, 0, dfs_tot)
	{
		int y = dfs_seq[i];
		sum[y] = 0;
		chkmax(Max[y], sz[rt] - sz[y]);
		if (x == -1 || Max[y] < Max[x]) x = y;
	}
	static int cnt[maxabs + 5];
	static int add[maxabs + 5];
	static int lst[maxabs + 5];
	static int cur = 0;
	if (!cur) memset(lst, -1, sizeof lst);
	++cur;
	lst[0] = cur;
	add[0] = 0;
	cnt[0] = 1;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		int y = e[i].id;
		dfs_tot = 0;
		val[y] = 0;
		dfs(y, x);
		REP(j, 0, dfs_tot)
		{
			int u = dfs_seq[j];
			if (lst[val[u] ^ a[x]] != cur)
			{
				lst[val[u] ^ a[x]] = cur;
				cnt[val[u] ^ a[x]] = 0;
				add[val[u] ^ a[x]] = 0;
			}
			sum[u] += cnt[val[u] ^ a[x]];
			++add[val[u] ^ a[x]];
			REP(k, 0, 20)
			{
				if (lst[val[u] ^ a[x] ^ (1 << k)] != cur)
				{
					lst[val[u] ^ a[x] ^ (1 << k)] = cur;
					cnt[val[u] ^ a[x] ^ (1 << k)] = 0;
					add[val[u] ^ a[x] ^ (1 << k)] = 0;
				}
				sum[u] += cnt[val[u] ^ a[x] ^ (1 << k)];
				++add[val[u] ^ a[x] ^ (1 << k)];
			}
		}
		REP(j, 0, dfs_tot)
		{
			int u = dfs_seq[j];
			if (lst[val[u]] != cur)
			{
				lst[val[u]] = cur;
				cnt[val[u]] = 0;
				add[val[u]] = 0;
			}
			sum[u] -= add[val[u]];
			++cnt[val[u]];
		}
	}
	dfs_tot = 0;
	val[x] = 0;
	dfs(x);
	for (int i = dfs_tot - 1; i >= 0; --i)
	{
		int y = dfs_seq[i];
		sum[y] += add[val[y] ^ a[x]];
		if (~fa[y]) sum[fa[y]] += sum[y];
	}
	assert(!(sum[x] & 1));
	sum[x] >>= 1;
	++sum[x];
	for (int i = dfs_tot - 1; i >= 0; --i)
	{
		int y = dfs_seq[i];
		ans[y] += sum[y];
	}

	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		assert(del_edge(e[i].id, x));
		work(e[i].id, d + 1);
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	memset(st, -1, sizeof st), en = 0;
	REP(i, 0, n - 1)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		add_edge(u, v);
		add_edge(v, u);
	}
	static char s[maxn + 5];
	scanf("%s", s);
	REP(i, 0, n) a[i] = 1 << (s[i] - 'a');
	work(0);
	REP(i, 0, n)
	{
		printf("%" LLFORMAT "d ", ans[i]);
	}
	return 0;
}