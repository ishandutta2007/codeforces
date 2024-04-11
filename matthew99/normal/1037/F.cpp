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

const int Mod = 1e9 + 7;

struct node
{
	node *c[2];

	int Max;
	int Min;
	int sum;
	int label;
	int sz;
 
	node(): label(-1) { memset(c, 0, sizeof c); }
 
	void update()
	{
		sum = 0;
		Max = 0;
		Min = oo;
		REP(i, 0, 2) 
		{
			(sum += c[i]->sum) %= Mod;
			chkmax(Max, c[i]->Max);
			chkmin(Min, c[i]->Min);
		}
	}

	void flag_label(int _label)
	{
		Min = Max = label = _label;
		sum = (LL)_label * sz % Mod;
	}

	void push_down()
	{
		if (~label)
		{
			REP(i, 0, 2) c[i]->flag_label(label);
			label = -1;
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

void build(node *&rt, int l, int r)
{
	rt = newnode();
	rt->sz = r - l;
	if (r - l <= 1) 
	{
		rt->Max = rt->Min = rt->sum = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
	rt->update();
}

int seg_x, seg_y, seg_z, seg_ret;
 
void add(node *rt, int l, int r)
{
	if (rt->Min >= seg_z) return;
	if (seg_x <= l && r <= seg_y && rt->Max <= seg_z)
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

void query(node *rt, int l, int r)
{
	if (seg_x <= l && r <= seg_y)
	{
		(seg_ret += rt->sum) %= Mod;
		return;
	}
	int mid = (l + r) >> 1;
	rt->push_down();
	if (seg_x < mid) query(rt->c[0], l, mid);
	if (seg_y > mid) query(rt->c[1], mid, r);
}

node *rt;

const int maxn = 1000100;

int n, K;

int a[maxn + 5];
int Max[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &K);
	REP(i, 0, n) scanf("%d", a + i);
	deque<int> q;
	for (int i = n - 1; i >= 0; --i)
	{
		while (!q.empty() && a[q.back()] < a[i]) q.pop_back();
		q.pb(i);
		while (q.front() - i >= K) q.pop_front();
		Max[i] = a[q.front()];
	}
	int ans = 0;
	REP(i, 0, K - 1)
	{
		rt = NULL;
		int N = n / (K - 1) + 1;
		build(rt, 0, N);
		for (int j = i; j + K <= n; j += K - 1)
		{
			seg_x = 0, seg_y = j / (K - 1) + 1, seg_z = Max[j];
			add(rt, 0, N);
			seg_x = 0, seg_y = j / (K - 1) + 1, seg_ret = 0;
			query(rt, 0, N);
			(ans += seg_ret) %= Mod;
		}
	}
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}