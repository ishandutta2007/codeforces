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

const int maxn = 100000;

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

int w[maxn + 5];
LL val[maxn + 5];
LL sum = 0;

int deg[maxn + 5];

void dfs(int x, int f = -1)
{
	val[x] = 1;
	deg[x] = 0;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == f) continue;
		++deg[x];
		dfs(y, x);
		if (__gcd(val[x], val[y])) val[x] = (LL)val[x]  / __gcd(val[x], val[y]) * val[y];
	}
	if (deg[x]) val[x] *= deg[x];
}

LL lyc[maxn + 5];

bool doit(int x, LL now, int f = -1)
{
	if (!deg[x]) lyc[x] = now;
	else
	{
		if (now % deg[x]) return 0;
		now /= deg[x];
		for (int i = st[x]; i != -1; i = e[i].nxt)
		{
			int y = e[i].id;
			if (y == f) continue;
			if (!doit(y, now, x)) return 0;
		}
	}
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(st, -1, sizeof st), en = 0;
	scanf("%d", &n);
	sum = 0;
	REP(i, 0, n) scanf("%d", w + i), sum += w[i];
	REP(i, 0, n - 1)
	{
		int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		add_edge(x, y), add_edge(y, x);
	}
	dfs(0);
	LL ans = sum;
	if (val[0] > 0 && val[0] <= sum && doit(0, val[0]))
	{
		int Min = oo;
		REP(i, 0, n) if (!deg[i]) chkmin(Min, (int)(w[i] / lyc[i]));
		ans = 0;
		REP(i, 0, n) if (!deg[i]) ans += w[i] - lyc[i] * Min;
	}
	printf("%I64d\n", ans);
	return 0;
}