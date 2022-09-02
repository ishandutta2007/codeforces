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

const int maxn = 100010;

const int Mod = 1e9 + 7;

struct node
{
	int sum[4][4];

	node *c[2];

	node() { memset(c, 0, sizeof c); }

	void update()
	{
		memset(sum, 0, sizeof sum);
		REP(i, 0, 4) REP(j, i, 4) REP(k, j, 4) (sum[i][k] += (LL)c[0]->sum[i][j] * c[1]->sum[j][k] % Mod) %= Mod;
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

int wl[maxn + 5], wr[maxn + 5];

void build(node *&rt, int l, int r)
{
	if (!rt) rt = newnode();
	if (r - l <= 1) 
	{
		REP(i, 0, 4) rt->sum[i][i] = 1;
		rt->sum[0][1] = wl[l];
		rt->sum[1][2] = 1;
		rt->sum[2][3] = wr[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
	rt->update();
}

int seg_x;
int sum0[4][4];

void modify(node *rt, int l, int r)
{
	if (r - l <= 1)
	{
		memcpy(rt->sum, sum0, sizeof rt->sum);
		return;
	}
	int mid = (l + r) >> 1;
	if (seg_x < mid) modify(rt->c[0], l, mid);
	else modify(rt->c[1], mid, r);
	rt->update();
}

int num[maxn + 5];
node *rt[maxn + 5];

int n, qn;
int a[maxn + 5];
int le[maxn + 5], ri[maxn + 5];

int id[maxn + 5];

vector<int> all[maxn + 5];

int fen[maxn + 5];

inline void add(int x)
{
	for (int i = x + 1; i <= n; i += i & -i) ++fen[i];
}

inline int query(int x)
{
	int ret = 0;
	for (int i = x + 1; i > 0; i -= i & -i) ret += fen[i];
	return ret;
}

inline void prepare()
{
	vector<int> v_a;
	REP(i, 0, n) v_a.pb(a[i]);
	sort(ALL(v_a));
	REP(i, 0, n) a[i] = lower_bound(ALL(v_a), a[i]) - v_a.begin();
	memset(fen, 0, sizeof fen);
	REP(i, 0, n)
	{
		le[i] = query(a[i]);
		add(a[i]);
	}
	memset(fen, 0, sizeof fen);
	for (int i = n - 1; i >= 0; --i)
	{
		ri[i] = query(a[i]);
		add(a[i]);
	}
}

int ans = 0;

inline void build_seg()
{
	REP(i, 0, n) all[a[i]].pb(i);
	REP(i, 0, n) if (SZ(all[i]))
	{
		REP(j, 0, SZ(all[i]))
		{
			id[all[i][j]] = j;
			wl[j] = le[all[i][j]], wr[j] = ri[all[i][j]];
		}
		build(rt[i], 0, SZ(all[i]));
		(ans += rt[i]->sum[0][3]) %= Mod;
	}
	debug("%d\n", ans);
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	prepare();
	build_seg();
	scanf("%d", &qn);
	REP(i, 0, qn)
	{
		int ty, x;
		scanf("%d%d", &ty, &x), --x;
		seg_x = id[x];
		memset(sum0, 0, sizeof sum0);
		REP(j, 0, 4) sum0[j][j] = 1;
		if (ty == 2)
		{
			sum0[0][1] = le[x];
			sum0[1][2] = 1;
			sum0[2][3] = ri[x];
		}
		(ans -= rt[a[x]]->sum[0][3]) %= Mod;
		modify(rt[a[x]], 0, SZ(all[a[x]]));
		(ans += rt[a[x]]->sum[0][3]) %= Mod;
		(ans += Mod) %= Mod;
		printf("%d\n", ans);
	}
	return 0;
}