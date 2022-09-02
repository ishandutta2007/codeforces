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

const int max0 = 1000000, max1 = 10000000;

struct edge
{
	int id, g, nxt;

	edge() { }
	edge(int _id, int _g, int _nxt): id(_id), g(_g), nxt(_nxt) { }

};

int st[max0 + 5], en = 0;
edge e[max1 + 5];

inline void add_edge(int x, int y, int z)
{
	e[en] = edge(y, z, st[x]), st[x] = en++;
}

inline void add_biedge(int x, int y, int z) { add_edge(x, y, z), add_edge(y, x, 0); }

int S, T, N;

int dis[max0 + 5];

inline bool bfs()
{
	static int q[max0 + 5];
	static bool vis[max0 + 5];
	int head = 0, rear = 0;
	memset(dis, -1, sizeof(dis[0]) * N);
	memset(vis, 0, sizeof(vis[0]) * N);
	vis[q[rear++] = S] = 1;
	dis[S] = 0;
	while (head != rear)
	{
		int x = q[head++];
		for (int i = st[x]; i != -1; i = e[i].nxt)
		{
			if (!e[i].g) continue;
			int y = e[i].id;
			if (!vis[y])
			{
				dis[y] = dis[x] + 1;
				if (y == T) return 1;
				q[rear++] = y;
				vis[y] = 1;
			}
		}
	}
	return 0;
}

int cur[max0 + 5];

inline int dfs(int x, int flow)
{
	if (x == T) return flow;
	int res = flow;
	for (int &i = cur[x]; i != -1; i = e[i].nxt)
	{
		if (!e[i].g) continue;
		int y = e[i].id;
		if (dis[y] == dis[x] + 1)
		{
			int F = dfs(y, min(e[i].g, res));
			res -= F;
			e[i].g -= F;
			e[i ^ 1].g += F;
			if (res <= 0) return flow;
		}
	}
	dis[x] = -1;
	return flow - res;
}

int work()
{
	if (S == T) return oo;
	int ret = 0;
	for ( ; bfs(); )
	{
		REP(i, 0, N) cur[i] = st[i];
		ret += dfs(S, oo);
	}
	return ret;
}

const int maxn = 100100, maxm = 100100;

map<int, int> idx, idy;

bool ty[maxm + 5];
int lim[maxm + 5];
int cnt[maxm + 5];

int wh[maxn + 5];

int R, B;

int n, m;

pair<int, int> a[maxn + 5];

int cnts, cntt;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(st, -1, sizeof st), en = 0;
	N = 0;
	scanf("%d%d", &n, &m);
	scanf("%d%d", &R, &B);
	REP(i, 0, n) scanf("%d%d", &a[i].x, &a[i].y);
	REP(i, 0, m)
	{
		int t, x, d;
		scanf("%d%d%d", &t, &x, &d);
		if (t == 1)
		{
			if (!idx.count(x)) ty[N] = 0, lim[N] = d, idx[x] = N++;
			else chkmin(lim[idx[x]], d);
		}
		else
		{
			if (!idy.count(x)) ty[N] = 1, lim[N] = d, idy[x] = N++;
			else chkmin(lim[idy[x]], d);
		}
	}
	REP(i, 0, n)
	{
		int x = a[i].x, y = a[i].y;
		if (!idx.count(x)) x = N;
		else x = idx[x];
		if (!idy.count(y)) y = N + 1;
		else y = idy[y];
		++cnt[x], ++cnt[y];
		wh[i] = en ^ 1;
		add_biedge(x, y, 1);
	}
	int s = N + 2, t = N + 3;
	add_biedge(s, N, oo), add_biedge(N + 1, t, oo);
	S = N + 4, T = N + 5;
	cnts = cntt = 0;
	REP(i, 0, N)
	{
		int Min = (cnt[i] - lim[i] + 1) >> 1, Max = (cnt[i] + lim[i]) >> 1;
		chkmax(Min, 0), chkmin(Max, cnt[i]);
		if (Min > Max) { puts("-1"); return 0; }
		if (!ty[i])
		{
			cnts += Min;
			add_biedge(s, i, Max - Min);
			add_biedge(S, i, Min); 
		}
		else
		{
			cntt += Min;
			add_biedge(i, T, Min);
			add_biedge(i, t, Max - Min);
		}
	}
	add_biedge(s, T, cnts);
	add_biedge(S, t, cntt);
	add_biedge(t, s, oo);
	N += 6;
	if (work() != cnts + cntt) puts("-1");
	else
	{
		S = s, T = t;
		int ret = work();
		cout << (LL)min(R, B) * ret + (LL)max(R, B) * (n - ret) << endl;
		REP(i, 0, n) putchar((e[wh[i]].g ^ (B < R)) ? 'r' : 'b');
	}
	return 0;
}