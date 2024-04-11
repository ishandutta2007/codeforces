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

const int Mod = 1e9 + 7;

const int maxn = 100100;

int N = 2;

inline void mul(int a[2][2], int b[2][2])
{
	REP(i, 0, N) REP(j, 0, N) (a[i][j] += Mod) %= Mod, (b[i][j] += Mod) %= Mod;
	static LL ans[2][2];
	memset(ans, 0, sizeof ans);
	REP(i, 0, N) REP(j, 0, N) REP(k, 0, N)
		ans[i][k] += (ans[i][k] < 0 ? (LL)a[i][j] * b[j][k] : (LL)(a[i][j] - Mod) * b[j][k]);
	REP(i, 0, N) REP(j, 0, N) a[i][j] = ans[i][j] % Mod;
}

inline pair<int, int> calc(LL x)
{
	static int a[2][2];
	a[0][0] = 0;
	a[1][0] = a[0][1] = a[1][1] = 1;
	static int tmp[2][2];
	tmp[0][1] = tmp[1][0] = 0;
	tmp[0][0] = tmp[1][1] = 1;
	for ( ; x; x >>= 1, mul(a, a)) if (x & 1) mul(tmp, a);
	return mp(tmp[1][0], tmp[1][1]);
}

int n, m;
int a[maxn + 5];

struct node
{
	node *c[2];

	int sum0, sum1;
	int pre, now;
 
	node(): sum0(0), sum1(0), pre(-1), now(-1) { memset(c, 0, sizeof c); }
 
	void update()
	{
		sum0 = sum1 = 0;
		REP(i, 0, 2) 
			if (c[i])
			{
				(sum0 += c[i]->sum0) %= Mod;
				(sum1 += c[i]->sum1) %= Mod;
			}
	}

	void flag_label(int _pre, int _now)
	{
		int uu = ((LL)now * _now + (LL)pre * _pre) % Mod;
		int vv = ((LL)(pre + now) * _now + (LL)now * _pre) % Mod;
		int u = ((LL)sum1 * _now + (LL)sum0 * _pre) % Mod;
		int v = ((LL)sum1 * (_pre + _now) + (LL)sum0 * _now) % Mod;
		if (!~pre) pre = _pre, now = _now;
		else pre = uu, now = vv;
		sum0 = u, sum1 = v;
	}

	void push_down()
	{
		if (~pre)
		{
			REP(i, 0, 2) if (c[i]) c[i]->flag_label(pre, now);
			pre = now = -1;
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
 
int seg_x, seg_y, seg_pre, seg_now;

void build(node *&rt, int l, int r)
{
	rt = newnode();
	if (r - l <= 1) { auto tmp = calc(a[l]); rt->sum0 = tmp.x, rt->sum1 = tmp.y; return; }
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
	rt->update();
}
 
void add(node *&rt, int l, int r)
{
	if (seg_x <= l && r <= seg_y)
	{
		rt->flag_label(seg_pre, seg_now);
		return;
	}
	int mid = (l + r) >> 1;
	rt->push_down();
	if (seg_x < mid) add(rt->c[0], l, mid);
	if (seg_y > mid) add(rt->c[1], mid, r);
	rt->update();
}

int seg_ret;

void query(node *&rt, int l, int r)
{
	if (seg_x <= l && r <= seg_y)
	{
		(seg_ret += rt->sum0) %= Mod;
		return;
	}
	int mid = (l + r) >> 1;
	rt->push_down();
	if (seg_x < mid) query(rt->c[0], l, mid);
	if (seg_y > mid) query(rt->c[1], mid, r);
}
 
node *rt;

inline void seg_add(int x, int y, int z)
{
	seg_x = x, seg_y = y;
	auto tmp = calc(z - 1);
	seg_pre = tmp.x, seg_now = tmp.y;
	add(rt, 0, n);
}

inline int seg_query(int x, int y)
{
	seg_x = x, seg_y = y, seg_ret = 0;
	query(rt, 0, n);
	(seg_ret += Mod) %= Mod;
	return seg_ret;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n) scanf("%d", a + i);
	build(rt, 0, n);
	REP(i, 0, m)
	{
		int ty, l, r, x;
		scanf("%d%d%d", &ty, &l, &r), --l;
		if (ty == 1) scanf("%d", &x), seg_add(l, r, x);
		else printf("%d\n", seg_query(l, r));
	}
	return 0;
}