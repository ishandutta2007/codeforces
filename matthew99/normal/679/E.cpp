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

const int maxn = 100000, maxlog = 12;

LL pw[maxlog];

int n, qn;
LL a[maxn + 5];

struct lab_type
{
	bool ty;
	LL val;

	lab_type(): ty(0), val(0) { }
	lab_type(int _ty, const LL &_val): ty(_ty), val(_val) { }

	bool empty() { return !ty && !val; }

	friend lab_type &operator+=(lab_type &x, const lab_type &y)
	{
		if (y.ty) return x = y;
		if (!x.ty || x.val) x.val += y.val;
		return x;
	}

	friend LL &operator+=(LL &x, const lab_type &y)
	{
		if (y.ty) return x = y.val;
		if (!x) return x;
		return x += y.val;
	}

};
 
struct node
{
	node *c[2];

	LL Max;
	lab_type label;
 
	node(): Max(0) { memset(c, 0, sizeof c); }
 
	void update()
	{
		Max = 0;
		REP(i, 0, 2) 
			if (c[i]) chkmax(Max, c[i]->Max);
	}

	void flag_label(const lab_type &_label)
	{
		label += _label;
		Max += _label;
	}

	void push_down()
	{
		if (!label.empty())
		{
			REP(i, 0, 2) if (c[i]) c[i]->flag_label(label);
			label = lab_type();
		}
	}
 
};

const int max0 = 100000;
 
node *nd_pool;
int nd_res = 0;
 
node *newnode()
{
	if (!nd_res) nd_pool = new node[max0], nd_res = max0;
	return nd_pool + (--nd_res);
}
 
node *rt[maxlog];
 
int seg_x, seg_y;
lab_type seg_z;
LL seg_ret;
int seg_id;
 
void add(node *&rt, int l, int r)
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

void doit(node *rt, int l, int r)
{
	if (!rt) return;
	if (rt->Max <= pw[seg_id]) return;
	if (r - l <= 1)
	{
		rt->Max = 0;
		return;
	}
	if (rt->label.ty)
	{
		rt->flag_label(lab_type(1, 0));
		return;
	}
	rt->push_down();
	int mid = (l + r) >> 1;
	doit(rt->c[0], l, mid);
	doit(rt->c[1], mid, r);
	rt->update();
}

void query(node *rt, int l, int r)
{
	if (!rt) return;
	if (seg_x <= l && r <= seg_y) 
	{
		chkmax(seg_ret, rt->Max);
		return;
	}
	rt->push_down();
	int mid = (l + r) >> 1;
	if (seg_x < mid) query(rt->c[0], l, mid);
	if (seg_y > mid) query(rt->c[1], mid, r);
	rt->update();
}

void build(node *&rt, int l, int r)
{
	if (!rt) rt = newnode();
	if (r - l <= 1)
	{
		if (a[l] <= pw[seg_id]) rt->Max = a[l];
		else rt->Max = 0;
		return;
	}
	rt->push_down();
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
	rt->update();
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	pw[0] = 1;
	REP(i, 1, maxlog) pw[i] = pw[i - 1] * 42;
	scanf("%d%d", &n, &qn);
	REP(i, 0, n) scanf("%I64d", a + i);
	REP(i, 0, maxlog)
	{
		seg_id = i;
		build(rt[i], 0, n);
	}
	REP(i, 0, qn)
	{
		int ty, l, r, x;
		scanf("%d", &ty);
		if (ty == 1)
		{
			scanf("%d", &x), --x;
			seg_x = x, seg_y = x + 1, seg_ret = 0;
			query(rt[maxlog - 1], 0, n);
			printf("%I64d\n", seg_ret);
		}
		else
		{
			scanf("%d%d%d", &l, &r, &x), --l;
			seg_x = l, seg_y = r;
			if (ty == 2)
			{
				seg_z = lab_type(1, x);
				for (int i = maxlog - 1; i >= 0; --i)
				{
					if (x > pw[i]) seg_z.val = 0;
					add(rt[i], 0, n);
				}
			}
			else
			{
				static LL Max[maxlog];
				static LL cnt[maxlog];
				REP(i, 0, maxlog)
				{
					seg_ret = 0;
					query(rt[i], 0, n);
					Max[i] = seg_ret;
					cnt[i] = 0;
				}
				while (1)
				{
					bool ok = 1;
					REP(i, 0, maxlog)
					{
						cnt[i] += x;
						if (Max[i] && Max[i] + cnt[i] > pw[i]) 
						{
							seg_z = lab_type(0, cnt[i]);
							add(rt[i], 0, n);
							cnt[i] = 0;
							seg_id = i;
							doit(rt[i], 0, n);
							seg_ret = 0;
							query(rt[i], 0, n);
							Max[i] = seg_ret;
						}
						if (Max[i] && Max[i] + cnt[i] == pw[i]) ok = 0;
					}
					if (ok) break;
				}
				REP(i, 0, maxlog) if (cnt[i]) 
				{
					seg_z = lab_type(0, cnt[i]), add(rt[i], 0, n), cnt[i] = 0;
					assert(rt[i]->Max != pw[i]);
				}
			}
		}
	}
	return 0;
}