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

template<typename T> T &Read(T &x)
{
	static char c;
	while (!isdigit(c = getchar()));
	x = c - '0';
	while (isdigit(c = getchar())) (x *= 10) += c - '0';
	return x;
}

const int maxn = 1000;
const int maxm = 1000000;

struct edge
{
	int id, nxt;

	edge() { }
	edge(const int &_id, const int &_nxt): id(_id), nxt(_nxt) { }
};

edge e[maxm + 5];
int en = 0;
int st[(maxn << 1) + 5];

int lst[maxn + 5];
int lstp = -1;
int now[maxn + 5];
char ans[maxn + 5] = "";

char s[maxn + 5];
char ty[30];

int n, m;

int tmp[maxn + 5];

inline void add_edge(const int &x, const int &y)
{
	e[en] = edge(y, st[x]), st[x] = en++;
}

inline void del_edge(const int &x)
{
	st[x] = e[st[x]].nxt;
}

int dfn[maxn + 5], low[maxn + 5];
int belong[maxn + 5];
int stk[maxn + 5];
int tot = 0;
int cnt = 0;
int N = 0;

int l;

bool in[maxn + 5];

void dfs(const int &x)
{
	dfn[x] = low[x] = cnt++; 
	in[stk[tot++] = x] = 1;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		const int &y = e[i].id;
		if (dfn[y] == -1) dfs(y), low[x] = min(low[x], low[y]);
		else if (in[y]) low[x] = min(low[x], dfn[y]);
	}
	if (dfn[x] == low[x])
	{
		while (stk[tot - 1] != x) 
		{
			--tot;
			belong[stk[tot]] = N, in[stk[tot]] = 0;
		}
		--tot;
		belong[x] = N, in[x] = 0;
		++N;
	}
}

bool check()
{
	memset(dfn, -1, sizeof(int) * (n << 1));
	cnt = 0;
	N = 0;
	REP(i, 0, n << 1) if (dfn[i] == -1) dfs(i);
	REP(i, 0, n) if (belong[i << 1] == belong[i << 1 | 1]) return 0;
	return 1;
}

bool work(const int &x, const bool &ok = 0)
{
	if (x == n)
	{
		REP(i, 0, n) printf("%c", ans[i]);
		printf("\n");
		return 1;
	}
	if (clock() >= 1.9 * CLOCKS_PER_SEC) return 0;
	if (en >= maxm) return 0;
	int can[2];
	add_edge(x << 1 | 1, x << 1);
	can[0] = check();
	del_edge(x << 1 | 1);
	add_edge(x << 1, x << 1 | 1);
	can[1] = check();
	del_edge(x << 1);
	REP(j, ok ? 0 : (s[x] - 'a'), l)
	{
		int lyc = ty[j] == 'V';
		if (can[lyc])
		{
			ans[x] = 'a' + j;
			add_edge(x << 1 | (!lyc), x << 1 | lyc);
			if (work(x + 1, ok | (j > s[x] - 'a'))) return 1;
			if (en >= maxm) return 0;
			del_edge(x << 1 | (!lyc));
		}
	}
	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(st, -1, sizeof st), en = 0;
	scanf("%s", ty);
	l = strlen(ty);
	scanf("%d%d", &n, &m);
	memset(now, -1, sizeof now);
	REP(i, 0, m)
	{
		static int x, y;
		static char c0[3], c1[3];
		scanf("%d%s%d%s", &x, c0, &y, c1);
		--x, --y;
		int t0 = c0[0] == 'V';
		int t1 = c1[0] == 'V';
		add_edge(x << 1 | t0, y << 1 | t1);
		add_edge(y << 1 | (!t1), x << 1 | (!t0));
	}
	scanf("%s", s);
	if (!work(0)) EXIT("-1\n");
	return 0;
}