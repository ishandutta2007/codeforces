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

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;
const LL OO = 0x3f3f3f3f3f3f3f3fLL;

const int maxn = 500100, maxm = 500100;

int n;
vector<int> adj[maxn + 5];

int fa[maxn + 5];
int w[maxn + 5];

int End[maxn + 5];

LL dis[maxn + 5];

int qn;

LL ans[maxm + 5];

bool isleaf[maxn + 5];

struct info
{
	int l, r, where, id;

	info() { }
	info(int _l, int _r, int _where, int _id): l(_l), r(_r), where(_where), id(_id) { }

};

vector<info> alll[maxn + 5], allr[maxn + 5];

struct node
{
	node *c[2];

	LL Min;

	LL label;
 
	node(): Min(OO), label(0) { memset(c, 0, sizeof c); }
 
	void update()
	{
		Min = OO;
		REP(i, 0, 2) 
			if (c[i]) chkmin(Min, c[i]->Min);
	}

	void flag_label(const LL &_label)
	{
		Min += _label;
		chkmin(Min, OO);
		label += _label;
	}

	void push_down()
	{
		if (label)
		{
			REP(i, 0, 2) 
				if (c[i]) c[i]->flag_label(label);
			label = 0;
		}
	}
 
};

const int max0 = 100000;
 
node *nd_pool;
int nd_res = 0;
 
inline node *newnode()
{
	if (!nd_res) nd_pool = new node[max0], nd_res = max0;
	return nd_pool + (--nd_res);
}

inline void build(node *&rt, int l, int r)
{
	if (!rt) rt = newnode();
	if (r - l <= 1)
	{
		if (isleaf[l]) rt->Min = -dis[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
	rt->update();
}

int seg_x, seg_y;
LL seg_z;
LL seg_ret;

inline void add(node *rt, int l, int r)
{
	if (seg_x <= l && r <= seg_y)
	{
		rt->flag_label(seg_z);
		return;
	}
	int mid = (l + r) >> 1;
	rt->push_down();
	if (seg_x < mid) add(rt->c[0], l, mid);
	if (seg_y > mid) add(rt->c[1], mid, r);
	rt->update();
}

inline void query(node *rt, int l, int r)
{
	if (seg_x <= l && r <= seg_y)
	{
		chkmin(seg_ret, rt->Min);
		return;
	}
	int mid = (l + r) >> 1;
	rt->push_down();
	if (seg_x < mid) query(rt->c[0], l, mid);
	if (seg_y > mid) query(rt->c[1], mid, r);
}

node *rt;

inline bool anc(int x, int y) { return x <= y && y < End[x]; }

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &qn);
	fa[0] = -1;
	REP(i, 1, n)
	{
		isleaf[i] = 1;
		scanf("%d%d", fa + i, w + i), --fa[i];
		isleaf[fa[i]] = 0;
		dis[i] = dis[fa[i]] + w[i];
	}

	for (int i = n - 1; i >= 0; --i)
	{
		chkmax(End[i], i + 1);
		if (~fa[i]) chkmax(End[fa[i]], End[i]);
	}

	REP(i, 0, qn)
	{
		ans[i] = OO;
		int x, l, r;
		scanf("%d%d%d", &x, &l, &r), --x, --l;
		if (l < x) alll[x].pb(info(l, min(r, x), x, i));
		if (r > x) allr[x].pb(info(max(l, x), r, x, i));
	}

	{
		rt = NULL;
		build(rt, 0, n);
		stack<int> stk;
		REP(i, 0, n)
		{
			while (!stk.empty() && !anc(stk.top(), i)) 
			{
				int x = stk.top();
				seg_x = x, seg_y = End[x], seg_z = 2 * w[x];
				add(rt, 0, n);
				stk.pop();
			}

			int goal = stk.empty() ? -1 : stk.top();
			vector<int> to_push;
			int cur = i;
			while (cur != goal) to_push.pb(cur), cur = fa[cur];
			while (!to_push.empty()) stk.push(to_push.back()), to_push.pop_back();

			for (auto u : alll[i])
			{
				seg_ret = OO;
				seg_x = u.l, seg_y = u.r;
				query(rt, 0, n);
				chkmin(ans[u.id], seg_ret + dis[u.where]);
			}

		}
	}

	{
		rt = NULL;
		build(rt, 0, n);
		stack<int> stk;
		for (int i = n - 1; i >= 0; --i)
		{
			while (!stk.empty() && !anc(stk.top(), i)) 
			{
				int x = stk.top();
				seg_x = x, seg_y = End[x], seg_z = 2 * w[x];
				add(rt, 0, n);
				stk.pop();
			}

			int goal = stk.empty() ? -1 : stk.top();
			vector<int> to_push;
			int cur = i;
			while (cur != goal) to_push.pb(cur), cur = fa[cur];
			while (!to_push.empty()) stk.push(to_push.back()), to_push.pop_back();

			for (auto u : allr[i])
			{
				seg_ret = OO;
				seg_x = u.l, seg_y = u.r;
				query(rt, 0, n);
				chkmin(ans[u.id], seg_ret + dis[u.where]);
			}

		}
	}

	REP(i, 0, qn)
	{
		printf("%lld\n", ans[i]);
	}

	return 0;
}