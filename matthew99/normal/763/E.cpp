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

const int maxn = 100100;
const int maxm = 100100;
const int maxK = 5;

int n, m, qn;

vector<int> adj[maxn + 5];

pair<int, int> q[maxm + 5];

int ans[maxm + 5];

int pos[maxm + 5];

int fa[maxn + 5];

inline int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }

inline void work(int l0, int r0, int l1, int r1)
{
	if (l1 == r1) return;
	int mid = (l0 + r0 + 1) >> 1;
	static int val[maxn + 5][maxK], cnt[maxn + 5];
	static int id[maxn + 5];
	REP(i, l0, r0) fa[i] = i;
	REP(i, l0, mid) id[i] = mid - i - 1;
	int now = 0;
	for (int i = mid - 1; i >= l0; --i)
	{
		for (auto j : adj[i]) if (j > i && j < mid) 
		{
			int u = get(i), v = get(j);
			if (u != v) fa[u] = v, ++now;
		}
		cnt[i] = now;
		memset(val[i], -1, sizeof val[i]);
		for (int j = mid - 1; j >= l0 && id[j] < maxK; --j) val[i][id[j]] = get(j);
	}
	REP(i, mid, r0) id[i] = i - mid;
	now = 0;
	REP(i, mid, r0 + 1)
	{
		cnt[i] = now;
		memset(val[i], -1, sizeof val[i]);
		for (int j = mid; j < r0 && id[j] < maxK; ++j) val[i][id[j]] = get(j);
		if (i == r0) break;
		for (auto j : adj[i]) if (j < i && j >= mid) 
		{
			int u = get(i), v = get(j);
			if (u != v) fa[u] = v, ++now;
		}
	}
	int nowl = l1, nowr = r1;
	static int ppos[maxn + 5];
	REP(i, l1, r1)
	{
		int x = pos[i];
		if (q[x].x < mid && q[x].y >= mid)
		{
			int ret = cnt[q[x].x] + cnt[q[x].y];
			for (int j = mid - 1; j >= q[x].x && id[j] < maxK; --j) 
			{
				int tmp = val[q[x].x][id[j]];
				fa[j] = tmp, fa[tmp] = tmp;
			}
			for (int j = mid; j < q[x].y && id[j] < maxK; ++j)
			{
				int tmp = val[q[x].y][id[j]];
				fa[j] = tmp, fa[tmp] = tmp;
			}
			for (int j = mid; j < q[x].y && id[j] < maxK; ++j)
			{
				for (auto k : adj[j]) if (k < mid && k >= q[x].x)
				{
					int u = get(j), v = get(k);
					if (u != v) ++ret, fa[u] = v;
				}
			}
			ans[x] = q[x].y - q[x].x - ret;
		}
		else if (q[x].y < mid) ppos[nowl++] = pos[i];
		else ppos[--nowr] = pos[i];
	}
	REP(i, l1, r1) pos[i] = ppos[i];
	work(l0, mid, l1, nowl), work(mid, r0, nowr, r1);
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%*d", &n);
	scanf("%d", &m);
	REP(i, 0, m)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		adj[u].pb(v), adj[v].pb(u);
	}
	scanf("%d", &qn);
	REP(i, 0, qn) scanf("%d%d", &q[i].x, &q[i].y), --q[i].x, pos[i] = i;
	work(0, n, 0, qn);
	REP(i, 0, qn) printf("%d\n", ans[i]);
	return 0;
}