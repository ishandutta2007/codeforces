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
 
struct node
{
	node *c[2];

	int sz;
	LL sum;

	int Max;
	int Min;

	int label;
 
	node(): sum(0), Max(0), Min(0), label(-1) { memset(c, 0, sizeof c); }
 
	void update()
	{
		Min = oo;
		sum = 0;
		REP(i, 0, 2) 
		{
			chkmin(Min, c[i]->Min);
			chkmax(Max, c[i]->Max);
			sum += c[i]->sum;
		}
	}

	void flag_label(int _label)
	{
		Min = Max = _label;
		sum = (LL)_label * sz;
		label = _label;
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
 
int seg_x, seg_y, seg_z;

void build(node *&rt, int l, int r)
{
	rt = newnode();
	rt->sz = r - l;
	if (r - l <= 1) return;
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
}
 
void add(node *rt, int l, int r)
{
	if (rt->Min >= seg_z) return;
	if (seg_x <= l && r <= seg_y)
	{
		if (rt->Max <= seg_z)
		{
			rt->flag_label(seg_z);
			return;
		}
	}
	int mid = (l + r) >> 1;
	rt->push_down();
	if (seg_x < mid) add(rt->c[0], l, mid);
	if (seg_y > mid) add(rt->c[1], mid, r);
	rt->update();
}

const int maxabs = 500100;
 
node *rt;

vector<pair<int, int> > all[maxabs + 5];

int n, p, q, r;

LL ans;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d%d", &n, &p, &q, &r);
	ans = (LL)p * q * r;
	build(rt, 0, q);
	REP(i, 0, n)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a, --b, --c;
		all[a].pb(mp(b, c));
		seg_x = 0, seg_y = b + 1, seg_z = c + 1;
		add(rt, 0, q);
	}
	for (int i = p - 1; i >= 0; --i)
	{
		for (auto u : all[i])
		{
			seg_x = 0, seg_y = u.x + 1, seg_z = r;
//			debug("	%d %d %d\n", seg_x, seg_y, seg_z);
			add(rt, 0, q);
			seg_x = u.x + 1, seg_y = q, seg_z = u.y + 1;
//			debug("%d %d %d\n", seg_x, seg_y, seg_z);
			add(rt, 0, q);
		}
//		debug("%d: %I64d\n", i + 1, rt->sum);
		ans -= rt->sum;
	}
	cout << ans << endl;
	return 0;
}