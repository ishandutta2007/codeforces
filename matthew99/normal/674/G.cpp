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

const int maxn = 150100;

int n, m, p;
int a[maxn + 5];

int lim;

struct data
{
	vector<pair<int, int> > all;

	data() { }

	data &operator+=(const data &x)
	{
		for (auto &u : x.all)
		{
			bool find = 0;
			for (auto &v : all)
				if (v.x == u.x)
				{
					find = 1;
					v.y += u.y;
					break;
				}
			if (!find)
			{
				if (SZ(all) < lim)
				{
					all.pb(u);
					continue;
				}
				int Min = oo;
				for (auto &v : all) chkmin(Min, v.y);
				if (Min >= u.y) for (auto &v : all) v.y -= u.y;
				else
				{
					for (auto &v : all) v.y -= Min;
					for (auto &v : all) if (!v.y) { v.x = u.x, v.y = u.y - Min; break; }
				}
			}
		}
		return *this;
	}

};

struct node
{
	node *c[2];

	int label;
	int sz;
	data sum;

	node(): label(-1) { memset(c, 0, sizeof c); }

	void flag_label(int _label)
	{
		label = _label;
		sum.all.clear();
		sum.all.pb(mp(_label, sz));
	}

	void push_down()
	{
		if (~label)
		{
			REP(i, 0, 2) if (c[i]) c[i]->flag_label(label);
			label = -1;
		}
	}

	void update()
	{
		sum = data();
		REP(i, 0, 2) if (c[i]) sum += c[i]->sum;
	}

};

node *rt;

node nd[(maxn << 1) + 5];
int cur = 0;

node *newnode() { return nd + (cur++); }

void build(node *&rt, int l, int r)
{
	if (!rt) rt = newnode(), rt->sz = r - l;
	if (r - l <= 1)
	{
		rt->sum.all.clear();
		rt->sum.all.pb(mp(a[l], 1));
		return;
	}
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
	rt->update();
}

int seg_x, seg_y, seg_z;

data seg_ret;

void assign(node *rt, int l, int r)
{
	if (!rt) return;
	if (seg_x <= l && r <= seg_y) { rt->flag_label(seg_z); return; }
	int mid = (l + r) >> 1;
	rt->push_down();
	if (seg_x < mid) assign(rt->c[0], l, mid);
	if (seg_y > mid) assign(rt->c[1], mid, r);
	rt->update();
}

void query(node *rt, int l, int r)
{
	if (!rt) return;
	if (seg_x <= l && r <= seg_y) { seg_ret += rt->sum; return; }
	int mid = (l + r) >> 1;
	rt->push_down();
	if (seg_x < mid) query(rt->c[0], l, mid);
	if (seg_y > mid) query(rt->c[1], mid, r);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &p);
	lim = 100 / p;
	REP(i, 0, n) scanf("%d", a + i), --a[i];
	build(rt, 0, n);
	REP(i, 0, m)
	{
		int ty;
		scanf("%d%d%d", &ty, &seg_x, &seg_y), --seg_x;
		if (ty == 1)
		{
			scanf("%d", &seg_z), --seg_z;
			assign(rt, 0, n);
		}
		else
		{
			seg_ret = data();
			query(rt, 0, n);
			printf("%d", SZ(seg_ret.all));
			for (auto &x : seg_ret.all) printf(" %d", x.x + 1);
			printf("\n");
		}
	}
	return 0;
}