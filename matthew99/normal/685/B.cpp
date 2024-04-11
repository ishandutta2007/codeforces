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

const int maxn = 300000;

int n;
int fa[maxn + 5];

vector<int> adj[maxn + 5];

int sz[maxn + 5], Max[maxn + 5];

inline bool cmp_sz(int x, int y) { return sz[x] > sz[y]; }

int pos[maxn + 5];

int tot = 0;
int dfn[maxn + 5], End[maxn + 5];
int what[maxn + 5];

void dfs(int x)
{
	what[dfn[x] = tot++] = x;
	sz[x] = 1;
	Max[x] = 0;
	for (auto y : adj[x]) dfs(y), sz[x] += sz[y], chkmax(Max[x], sz[y]);
	End[x] = tot;
}

struct node
{
	int Min;
	node *c[2];

	node(): Min(-1) { memset(c, 0, sizeof c); }

};

node nd[(maxn << 1) + 5];
int cur = 0;

int seg_x, seg_y, seg_z;

void insert(node *&rt, int l, int r)
{
	if (!rt) rt = nd + (cur++), *rt = node();
	if (!~rt->Min || Max[seg_y] < Max[rt->Min]) rt->Min = seg_y;
	if (r - l <= 1) return;
	int mid = (l + r) >> 1;
	if (seg_x < mid) insert(rt->c[0], l, mid);
	else insert(rt->c[1], mid, r);
}

void query(node *rt, int l, int r)
{
	if (!rt) return;
	if (seg_x <= l && r <= seg_y) { if (!~seg_z || Max[rt->Min] < Max[seg_z]) seg_z = rt->Min; return; }
	int mid = (l + r) >> 1;
	if (seg_x < mid) query(rt->c[0], l, mid);
	if (seg_y > mid) query(rt->c[1], mid, r);
}

node *rt;

int ans[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m;
	scanf("%d%d", &n, &m);
	REP(i, 1, n) scanf("%d", fa + i), --fa[i], adj[fa[i]].pb(i);
	fa[0] = -1;
	dfs(0);
	REP(i, 0, n) pos[i] = i;
	sort(pos, pos + n, cmp_sz);
	int j = 0;
	rt = NULL, cur = 0;
	REP(i, 0, n)
	{
		while (j < n && (sz[pos[j]] << 1) >= sz[pos[i]]) seg_x = dfn[pos[j]], seg_y = pos[j], insert(rt, 0, n), ++j;
		seg_x = dfn[pos[i]], seg_y = End[pos[i]], seg_z = -1;
		query(rt, 0, n);
		ans[pos[i]] = seg_z;
	}
	REP(i, 0, m)
	{
		int x;
		scanf("%d", &x), --x;
		printf("%d\n", ans[x] + 1);
	}
	return 0;
}