#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
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

const int maxn = 100000;

struct edge
{
	int id, nxt;

	edge() { }
	edge(const int &_id, const int &_nxt): id(_id), nxt(_nxt) { }

};

int st[maxn + 5], en;
edge e[(maxn << 1) + 5];

int n;

inline void add_edge(const int &x, const int &y) { e[en] = edge(y, st[x]), st[x] = en++; }

inline void init()
{
	memset(st, -1, sizeof st), en = 0;
	scanf("%d", &n);
	REP(i, 0, n - 1)
	{
		static int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		add_edge(x, y);
		add_edge(y, x);
	}
}

int dp[maxn + 5], fa[maxn + 5];
int deg[maxn + 5];

bool flag = 0;

void dfs(const int &x, int limit)
{
	int tot = 0;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		const int &y = e[i].id;
		if (y == fa[x]) continue;
		++tot;
		fa[y] = x;
		dfs(y, 1);
		if ((limit -= dp[y]) < 0) flag = 1;
		dp[x] |= dp[y] || deg[y] >= 2;
	}
	deg[x] = tot;
	dp[x] |= tot > 2;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	srand(time(NULL));
	init();
	while (clock() < 0.9 * CLOCKS_PER_SEC)
	{
		int tmp = rand() % n;
		memset(dp, 0, sizeof dp);
		fa[tmp] = -1;
		flag = 0;
		dfs(tmp, 2);
		if (!flag)
		{
			EXIT("Yes\n");
		}
	}
	printf("No\n");
	return 0;
}