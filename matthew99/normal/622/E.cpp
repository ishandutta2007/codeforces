#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
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

const int Mod = 1e9 + 7;

const int maxn = 500000;

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

int dep[maxn + 5];

vector<int> all;

int ans = 0;

void dfs(int x, int f = -1)
{
	int cnt = 0;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == f) continue;
		++cnt;
		dep[y] = dep[x] + 1;
		dfs(y, x);
	}
	if (!cnt) all.pb(dep[x]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(st, -1, sizeof st), en = 0;
	scanf("%d", &n);
	REP(i, 0, n - 1)
	{
		int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		add_edge(x, y), add_edge(y, x);
	}
	for (int i = st[0]; i != -1; i = e[i].nxt) 
	{
		int u = e[i].id;
		all.clear();
		dep[u] = 1;
		dfs(u, 0);
		sort(ALL(all), greater<int>());
		REP(i, 0, SZ(all)) chkmax(ans, i + all[i]);
	}
	printf("%d\n", ans);
	return 0;
}