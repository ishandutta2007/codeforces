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
const int maxw = 100100;

const int Mod = 1e9 + 7;

struct data
{
	int u, l, r, s;

	friend bool operator<(const data &x, const data &y) { return x.u < y.u; }

};

int h, w, n;
data a[maxn + 5];

int rec[maxn + 5];
bool picked[(maxn << 1) + maxw + 5];

struct node
{
	vector<int> stk;

	node *c[2];

	node() { memset(c, 0, sizeof c); }

};

const int max0 = 100000;
 
node *nd_pool;
int nd_res = 0;
 
inline node *newnode()
{
	if (!nd_res) nd_pool = new node[max0], nd_res = max0;
	return nd_pool + (--nd_res);
}

int seg_x, seg_y, seg_num, seg_h;
int seg_ret;

void build(node *&rt, int l, int r)
{
	if (!rt) rt = newnode();
	REP(i, l, r) rt->stk.pb((n << 1) + i);
	if (r - l <= 1) return;
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
}
 
void add(node *&rt, int l, int r)
{
	rt->stk.pb(seg_num);
	if (r - l <= 1) return;
	int mid = (l + r) >> 1;
	if (seg_x < mid) add(rt->c[0], l, mid);
	else add(rt->c[1], mid, r);
}

void query(node *rt, int l, int r)
{
	if (seg_x <= l && r <= seg_y)
	{
		while (!rt->stk.empty())
		{
			int x = rt->stk.back();
			if (picked[x]) 
			{
				rt->stk.pop_back();
				continue;
			}
			if (x < (n << 1))
			{
				if (a[x >> 1].u <= seg_h)
				{
					picked[x] = 1;
					(seg_ret += rec[x >> 1]) %= Mod;
					rt->stk.pop_back();
				}
				else break;
			}
			else 
			{
				if (seg_h >= h + 1)
				{
					picked[x] = 1;
					(++seg_ret) %= Mod;
					rt->stk.pop_back();
				}
				else break;
			}
		}
		return;
	}
	int mid = (l + r) >> 1;
	if (seg_x < mid) query(rt->c[0], l, mid);
	if (seg_y > mid) query(rt->c[1], mid, r);
}

node *rt;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &h, &w, &n);
	REP(i, 0, n) scanf("%d%d%d%d", &a[i].u, &a[i].l, &a[i].r, &a[i].s), --a[i].l;
	build(rt, 0, w);
	sort(a, a + n);
	int ans = w;
	for (int i = n - 1; i >= 0; --i)
	{
		seg_ret = 0;
		seg_x = a[i].l, seg_y = a[i].r;
		seg_h = a[i].u + a[i].s;
		query(rt, 0, w);
		(ans += seg_ret) %= Mod;
		rec[i] = seg_ret;
		seg_num = i << 1;
		if (!a[i].l) seg_x = a[i].r;
		else seg_x = a[i].l - 1;
		seg_y = seg_x + 1;
		add(rt, 0, w);
		seg_num = i << 1 | 1;
		if (a[i].r == w) seg_x = a[i].l - 1;
		else seg_x = a[i].r;
		seg_y = seg_x + 1;
		add(rt, 0, w);
	}
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}