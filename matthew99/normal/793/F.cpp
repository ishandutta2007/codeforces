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

const int maxh = 100100, maxs = 100100, maxq = 100100;
const int maxlog = 17;

int height, sn;

pair<int, int> seg[maxs + 5];

int qn;
pair<int, int> q[maxq + 5];

int posq[maxq + 5];

int ans[maxq + 5];

struct node
{
	node *c[2];

	int Max, sMax;

	int label_from, label_to;

	node(): Max(0), sMax(-oo), label_from(-1) { memset(c, 0, sizeof c); }

	void update()
	{
		Max = 0, sMax = -oo;
		REP(i, 0, 2) if (c[i])
		{
			chkmax(Max, c[i]->Max);
			chkmax(sMax, c[i]->sMax);
			if (c[i]->Max < Max) chkmax(sMax, c[i]->Max);
		}
	}

	void flag_label(int _label_from, int _label_to)
	{
		if (_label_from < Max)
		{
			if (!~label_from) label_from = _label_from;
			label_to = _label_to;
			Max = _label_to;
		}
	}

	void push_down()
	{
		if (~label_from)
		{
			REP(i, 0, 2) if (c[i]) c[i]->flag_label(label_from, label_to);
			label_from = -1;
		}
	}

};

node nd[(maxh << 1) + 5];
int nd_cur = 0;

inline node *newnode() { return nd + (nd_cur++); }

int seg_x, seg_y, seg_z, seg_to, seg_ret;

void build(node *&rt, int l, int r)
{
	rt = newnode();
	if (r - l <= 1) 
	{
		rt->Max = l + 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
	rt->update();
}

void add(node *rt, int l, int r)
{
	if (rt->Max <= seg_z) return;
	if (seg_x <= l && r <= seg_y && rt->sMax <= seg_z)
	{
		rt->flag_label(seg_z, seg_to);
		return;
	}
	rt->push_down();
	int mid = (l + r) >> 1;
	if (seg_x < mid) add(rt->c[0], l, mid);
	if (seg_y > mid) add(rt->c[1], mid, r);
	rt->update();
}

void query(node *rt, int l, int r)
{
	if (r - l <= 1)
	{
		seg_ret = rt->Max;
		return;
	}
	rt->push_down();
	int mid = (l + r) >> 1;
	if (seg_x < mid) query(rt->c[0], l, mid);
	else query(rt->c[1], mid, r);
}

node *rt;

inline void add_seg(int id)
{
	seg_x = 0, seg_y = seg[id].x + 1, seg_z = seg[id].x, seg_to = seg[id].y;
	add(rt, 0, height);
}

inline int query(int x)
{
	seg_x = x;
	query(rt, 0, height);
	return seg_ret;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &height, &sn);
	REP(i, 0, sn) scanf("%d%d", &seg[i].x, &seg[i].y), --seg[i].x;
	sort(seg, seg + sn, [&](const pair<int, int> &x, const pair<int, int> &y) { return x.y < y.y; });
	scanf("%d", &qn);
	REP(i, 0, qn)
	{
		scanf("%d%d", &q[i].x, &q[i].y);
		--q[i].x;
		posq[i] = i;
	}
	sort(posq, posq + qn, [&](int x, int y) { return q[x].y < q[y].y; });
	build(rt, 0, height);
	int pt_s = 0;
	REP(i, 0, qn)
	{
		while (pt_s < sn && seg[pt_s].y <= q[posq[i]].y) add_seg(pt_s++);
		ans[posq[i]] = query(q[posq[i]].x);
	}
	REP(i, 0, qn) printf("%d\n", ans[i]);
	return 0;
}