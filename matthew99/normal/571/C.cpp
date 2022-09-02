#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int oo = 0x3f3f3f3f;

template<typename T> T &Read(T &x)
{
	static char c;
	while (!isdigit(c = getchar()));
	x = c - '0';
	while (isdigit(c = getchar())) (x *= 10) += c - '0';
	return x;
}

const int max0 = 1000000;

struct edge
{
	int id, nxt;

	edge() { }
	edge(const int &_id, const int &_nxt): id(_id), nxt(_nxt) { }

};

int en = 0;
edge e[max0 + 5];
int st[max0 + 5];

inline void add_edge(const int &x, const int &y)
{
	e[en] = edge(y, st[x]), st[x] = en++;
}

int n, m;

int p[max0 + 5][2];

int ans[max0 + 5];

bool ok[max0 + 5];

inline void init()
{
	memset(p, -1, sizeof p);
	memset(st, -1, sizeof st), en = 0;
	scanf("%d%d", &m, &n);
	REP(i, 0, m)
	{
		int x;
		scanf("%d", &x);
		REP(j, 0, x)
		{
			int y;
			scanf("%d", &y);
			int &tmp = p[abs(y) - 1][y > 0];
			if (tmp == -1) tmp = i;
			else ok[tmp] = ok[i] = 1, ans[abs(y) - 1] = y > 0;
		}
	}
	REP(i, 0, n) 
		if (p[i][0] != -1 && p[i][1] != -1) add_edge(p[i][1], p[i][0]), add_edge(p[i][0], p[i][1]);
		else 
		{
			REP(j, 0, 2) if (p[i][j] != -1) ok[p[i][j]] = 1, ans[i] = j;
			add_edge(m, m), add_edge(m, m);
		}
}

int vis[max0 + 5];

int dfs(const int &x, const int &fa = -1)
{
	vis[x] = 1;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{ 
		if (i >> 1 == fa) continue;
		const int &y = e[i].id;
		if (vis[y]) return y;
		if (ok[y]) return y;
		int tmp = dfs(y, i >> 1);
		if (tmp != -1) return tmp;
	}
	return -1;
}

int rt;

void dfs0(const int &x, const int &fa = -1)
{
	vis[x] = 2;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		if (i >> 1 == fa) continue;
		const int &y = e[i].id;
		if (y == rt) ans[i >> 1] = i & 1;
		if (vis[y] == 2) continue;
		ans[i >> 1] = i & 1;
		dfs0(y, i >> 1);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	REP(i, 0, m) 
		if (!ok[i] && !vis[i])
		{
			int x = dfs(i);
			if (x == -1) EXIT("NO\n");
			else
			{
				rt = x;
				dfs0(x);
			}
		}
	printf("YES\n");
	REP(i, 0, n) printf("%d", ans[i]);
	return 0;
}