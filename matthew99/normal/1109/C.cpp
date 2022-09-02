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

const int maxabs = 1.01e9;

int qn;
set<pair<int, int> > all;

struct node
{
	node *c[2];

	int sz;
	LL val;
	LL Min;
	int label;
 
	node(): val(0), Min(0), label(oo) { memset(c, 0, sizeof c); }
 
	void update()
	{
		Min = 0;
		val = 0;
		if (c[0]) val = c[0]->val, Min = c[0]->Min;
		if (c[1]) chkmin(Min, val + c[1]->Min), val += c[1]->val;
	}

	void flag_label(int _label)
	{
		label = _label;
		val = (LL)sz * _label;
		Min = min(0LL, val);
	}

	void push_down()
	{
		if (label != oo)
		{
			REP(i, 0, 2) c[i]->flag_label(label);
			label = oo;
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
 
int seg_x, seg_y, seg_z, seg_ret;
LL seg_goal;
 
void change(node *&rt, int l, int r)
{
	if (!rt) rt = newnode(), rt->sz = r - l;
	if (seg_x <= l && r <= seg_y)
	{
		rt->flag_label(seg_z);
		return;
	}
	int mid = (l + r) >> 1;
	if (!rt->c[0]) rt->c[0] = newnode(), rt->c[0]->sz = mid - l;
	if (!rt->c[1]) rt->c[1] = newnode(), rt->c[1]->sz = r - mid;
	rt->push_down();
	if (seg_x < mid) change(rt->c[0], l, mid);
	if (seg_y > mid) change(rt->c[1], mid, r);
	rt->update();
}
 
void query(node *&rt, int l, int r)
{
	if (!rt) rt = newnode(), rt->sz = r - l;
	if (seg_x <= l && r <= seg_y && rt->Min > seg_goal)
	{
		seg_goal -= rt->val;
		return;
	}
	if (r - l <= 1)
	{
		seg_ret = l;
		return;
	}
	int mid = (l + r) >> 1;
	if (!rt->c[0]) rt->c[0] = newnode(), rt->c[0]->sz = mid - l;
	if (!rt->c[1]) rt->c[1] = newnode(), rt->c[1]->sz = r - mid;
	rt->push_down();
	if (seg_x < mid) query(rt->c[0], l, mid);
	if (!~seg_ret && seg_y > mid) query(rt->c[1], mid, r);
}
 
node *rt;

inline void add(int t, int s)
{
	all.insert(mp(t, s));
	auto tmp = all.upper_bound(mp(t, oo));
	seg_x = t, seg_y = tmp->x, seg_z = s;
	change(rt, 0, maxabs);
}

inline void del(int t)
{
	auto tmp = all.lower_bound(mp(t, -oo));
	auto pre = tmp; --pre;
	auto nxt = tmp; ++nxt;
	seg_x = t, seg_y = nxt->x, seg_z = pre->y;
	change(rt, 0, maxabs);
	all.erase(tmp);
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &qn);
	all.insert(mp(0, 0));
	all.insert(mp(maxabs, 0));
	REP(i, 0, qn)
	{
		int ty;
		scanf("%d", &ty);
		if (ty == 1)
		{
			int t, s;
			scanf("%d%d", &t, &s);
			add(t, s);
		}
		else if (ty == 2)
		{
			int t;
			scanf("%d", &t);
			del(t);
		}
		else if (ty == 3)
		{
			int l, r, v;
			scanf("%d%d%d", &l, &r, &v);
			if (!v) printf("%d\n", l);
			else if (l == r)
			{
				printf("-1\n");
			}
			else
			{
				bool has = 0;
				if (all.lower_bound(mp(l, -oo))->x == l) has = 1;
				if (!has) add(l, 0);

				seg_x = l, seg_y = r, seg_goal = -v, seg_ret = -1;
				query(rt, 0, maxabs);
				if (~seg_ret)
				{
					double ret = seg_ret + (double)seg_goal / (--all.upper_bound(mp(seg_ret, oo)))->y;
					printf("%.10f\n", ret);
				}
				else printf("-1\n");

				if (!has) del(l);
			}
		}
	}
	return 0;
}