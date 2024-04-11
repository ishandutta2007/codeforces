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

const int maxn = 200000;

struct edge
{
	int id, g, nxt;
	
	edge() { }
	edge(const int &_id, const int &_g, const int &_nxt): id(_id), g(_g), nxt(_nxt) { }

};

edge e[(maxn << 1) + 5];
int en = 0;
int st[maxn + 5];

inline void add_edge(const int &x, const int &y, const int &z)
{
	e[en] = edge(y, z, st[x]), st[x] = en++;
}

inline void del_edge(const int &x, const int &y)
{
	for (int *i = st + x; *i != -1; i = &e[*i].nxt)
		if (e[*i].id == y)
		{
			*i = e[*i].nxt;
			break;
		}
}

int n;
int w[maxn + 5];

int ans;

double ansval;

int sz[maxn + 5];
int Max[maxn + 5];

int all[maxn + 5], alln = 0;

bool vis[maxn + 5];

void pre_dfs(const int &x, const int &f = -1)
{
	all[alln++] = x;
	sz[x] = 1;
	Max[x] = 0;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		const int &y = e[i].id;
		if (y == f) continue;
		if (vis[y]) continue;
		pre_dfs(y, x);
		sz[x] += sz[y];
		Max[x] = max(Max[x], sz[y]);
	}
}

double sum = 0;
int dep[maxn + 5];

int rt;

void dfs(const int &x, const int &f = -1)
{
	sum += (double)w[x] * sqrt((double)dep[x]);
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		const int &y = e[i].id;
		if (y == f) continue;
		dep[y] = dep[x] + e[i].g;
		dfs(y, x);
	}
}

void calc(const int &x, const int &f = -1, const int &dep = 0)
{
	sum += (double)w[x] * dep * sqrt((double)dep);
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		const int &y = e[i].id;
		if (y == f) continue;
		calc(y, x, dep + e[i].g);
	}
}

void update(const int &x)
{
	sum = 0;
	calc(x);
	if (ans == -1 || sum < ansval) ans = x, ansval = sum;
}

void work(const int &rt)
{
	::rt = rt;
	alln = 0;
	pre_dfs(rt);

	int x = -1;
	REP(i, 0, alln)
	{
		const int &y = all[i];
		Max[y] = max(Max[y], alln - sz[y]);
		if (x == -1 || Max[y] < Max[x]) x = y;
	}
	update(x);
	if (alln == 1) return;
	
	int Max = -1;
	double Maxval;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		const int &y = e[i].id;
		if (vis[y]) continue;
		dep[y] = e[i].g;
		sum = 0;
		dfs(y, x);
		if (Max == -1 || sum > Maxval) Max = y, Maxval = sum;
	}

	vis[x] = 1;
	work(Max);

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	memset(st, -1, sizeof st), en = 0;
	REP(i, 0, n) scanf("%d", w + i);
	REP(i, 0, n - 1)
	{
		static int x, y, z;
		scanf("%d%d%d", &x, &y, &z), --x, --y;
		add_edge(x, y, z), add_edge(y, x, z);
	}
	ans = -1;
	work(0);
	printf("%d ", ans + 1);
	printf("%.16f\n", ansval);
	return 0;
}