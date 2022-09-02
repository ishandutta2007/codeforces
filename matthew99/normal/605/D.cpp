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

const int maxn = 100000, max0 = 3000000, maxabs = 1e9 + 1;

int n;
pair<int, int> a[maxn + 5], b[maxn + 5];

bool vis[maxn + 5];

struct node
{
	node *c[2];

	set<pair<int, int> > all;

	node() { memset(c, 0, sizeof c); }

};

node nd[max0 + 5];
int nd_cur = 0;

node *rt = NULL;

int dis[maxn + 5];
int q[maxn + 5];
int pre[maxn + 5];
int head = 0, rear = 0;

inline void add(node *&rt, int x, int y, int id, int l, int r)
{
	if (!rt) rt = nd + (nd_cur++);
	rt->all.insert(mp(y, id));
	if (r - l <= 1) return;
	int mid = (l + r) >> 1;
	if (x < mid) add(rt->c[0], x, y, id, l, mid);
	else add(rt->c[1], x, y, id, mid, r);
}

inline void query(node *rt, int x, int y, int h, int d, int l, int r)
{
	if (!rt) return;
	if (!SZ(rt->all) || rt->all.begin()->x > h) return;
	if (x <= l && r <= y)
	{
		while (!rt->all.empty())
		{
			if (rt->all.begin()->x > h) break;
			int tmp = rt->all.begin()->y;
			rt->all.erase(rt->all.begin());
			if (!vis[tmp]) q[rear++] = tmp, vis[tmp] = 1, dis[tmp] = d == -1 ? 0 : dis[d] + 1, pre[tmp] = d;
		}
		return;
	}
	int mid = (l + r) >> 1;
	if (x < mid) query(rt->c[0], x, y, h, d, l, mid);
	if (y > mid) query(rt->c[1], x, y, h, d, mid, r);
}

inline void go(int x, int y, int z)
{
	query(rt, 0, x + 1, y, z, 0, maxabs);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d%d%d%d", &a[i].x, &a[i].y, &b[i].x, &b[i].y), add(rt, a[i].x, a[i].y, i, 0, maxabs);
	go(0, 0, -1);
	while (head != rear)
	{
		int x = q[head++];
		if (x == n - 1)
		{
			printf("%d\n", dis[x] + 1);
			vector<int> all;
			while (x != -1) all.pb(x), x = pre[x];
			reverse(ALL(all));
			for (auto it : all) printf("%d ", it + 1);
			return 0;
		}
		go(b[x].x, b[x].y, x);
	}
	printf("-1\n");
	return 0;
}