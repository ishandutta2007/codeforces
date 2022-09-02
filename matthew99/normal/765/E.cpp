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

const int maxn = 200100;

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

inline void add_biedge(int x, int y)
{
	add_edge(x, y), add_edge(y, x);
}

int ans;
int n;

int dep[maxn + 5];

bool is_leaf[maxn + 5];

int fa[maxn + 5];

int Max[maxn + 5], Min[maxn + 5];

void dfs(int x, int f = -1)
{
	fa[x] = f;
	is_leaf[x] = 1;
	Min[x] = oo, Max[x] = -oo;
	for (int i = st[x]; ~i; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == f) continue;
		is_leaf[x] = 0;
		dep[y] = dep[x] + 1;
		dfs(y, x);
		chkmax(Max[x], Max[y]);
		chkmin(Min[x], Min[y]);
	}
	if (is_leaf[x]) Max[x] = Min[x] = dep[x];
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(st, -1, sizeof st), en = 0;
	scanf("%d", &n);
	REP(i, 0, n - 1)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		add_biedge(u, v);
	}
	dep[0] = 0;
	dfs(0);
	int rt = 0;
	REP(i, 1, n) if (dep[i] > dep[rt]) rt = i;
	dep[rt] = 0;
	dfs(rt);
	rt = 0;
	REP(i, 1, n) if (dep[i] > dep[rt]) rt = i;
	REP(i, 0, dep[rt] >> 1) rt = fa[rt];
	dep[rt] = 0;
	dfs(rt);
	map<int, int> all;
	REP(i, 0, n) if (is_leaf[i]) ++all[dep[i]];
	if (SZ(all) <= 2) 
	{
		bool failed = 0;
		for (int i = st[rt]; ~i; i = e[i].nxt)
		{
			int x = e[i].id;
			if (Min[x] != Max[x])
			{
				ans = -1;
				failed = 1;
				break;
			}
		}
		if (!failed) 
		{
			ans = 0;
			for (auto u : all) ans += u.x;
			while (!(ans & 1)) ans >>= 1;
		}
	}
	else ans = -1;
	printf("%d\n", ans);
	return 0;
}