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

const int __buffsize = 100000;
char __buff[__buffsize];
char *__buffs, *__buffe;

#define getc() (__buffs == __buffe ? fread(__buff, 1, __buffsize, stdin), __buffe = __buff + __buffsize, *((__buffs = __buff)++) : *(__buffs++))

template<typename T> inline T &Read(T &x)
{
	static char c;
	while (1) 
	{ 
		c = getc(); 
		if (c == '-' || (c >= '0' && c <= '9')) break; 
	}
	bool flag = c == '-';
	x = flag ? 0 : c - '0';
	while (1)
	{
		c = getc();
		if (c < '0' || c > '9') break;
		(x *= 10) += c - '0';
	}
	if (flag) x = -x;
	return x;
}

#undef getc

const int oo = 0x3f3f3f3f;

const int maxn = 100100;

const int maxm = 300100;

int n;
int a[maxn + 5];

struct node
{
	node *c[2];
	int Min;
	vector<pair<int, int> > all;

	node(): Min(oo) { memset(c, 0, sizeof c); }

};

node nd[(maxn << 1) + 5];
int nd_cur = 0;

inline node *newnode() { return nd + (nd_cur++); }

void build(node *&rt, int l, int r)
{
	rt = newnode();
	if (r - l <= 1)
	{
		rt->all.pb(mp(a[l], 0));
		rt->all.pb(mp(oo, 0));
		return;
	}
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
	int u = 0, v = 0;
	int cur = 0;
	REP(i, 0, SZ(rt->c[0]->all) + SZ(rt->c[1]->all) - 2)
	{
		if (rt->c[1]->all[v].x < rt->c[0]->all[u].x) rt->all.pb(mp(rt->c[1]->all[v++].x, cur));
		else rt->all.pb(mp(rt->c[0]->all[u++].x, cur++));
	}
	rt->all.pb(mp(oo, cur));
}

int seg_x, seg_y, seg_z, seg_ret;

void add(node *rt, int l, int r, int p)
{
	if (r <= seg_x + 1) return;
	if (r - l <= 1)
	{
		chkmin(rt->Min, abs(a[l] - a[seg_x]));
		chkmin(seg_z, rt->Min);
		return;
	}
	if (seg_z < oo)
	{
		int tmp = oo;
		if (p < SZ(rt->all) - 1) chkmin(tmp, rt->all[p].x - a[seg_x]);
		if (p) chkmin(tmp, a[seg_x] - rt->all[p - 1].x);
		if (tmp >= seg_z)
		{
			chkmin(seg_z, rt->Min);
			return;
		}
	}
	int mid = (l + r) >> 1;
	add(rt->c[0], l, mid, rt->all[p].y);
	add(rt->c[1], mid, r, p - rt->all[p].y);
	rt->Min = seg_z;
}

void query(node *rt, int l, int r)
{
	if (seg_x <= l && r <= seg_y)
	{
		chkmin(seg_ret, rt->Min);
		return;
	}
	int mid = (l + r) >> 1;
	if (seg_x < mid) query(rt->c[0], l, mid);
	if (seg_y > mid) query(rt->c[1], mid, r);
}

node *rt;

int qn;
int pos[maxm + 5];
pair<int, int> q[maxm + 5];

int ans[maxm + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Read(n);
	REP(i, 0, n) Read(a[i]);
	build(rt, 0, n);
	Read(qn);
	REP(i, 0, qn)
	{
		pos[i] = i;
		Read(q[i].x), Read(q[i].y), --q[i].x;
	}
	sort(pos, pos + qn, [&](int x, int y) { return q[x] > q[y]; });
	int j = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		seg_x = i;
		seg_z = oo;
		add(rt, 0, n, lower_bound(ALL(rt->all), mp(a[i], 0)) - rt->all.begin());
		seg_x = i + 1;
		while (j < qn && q[pos[j]].x == i) 
		{
			seg_y = q[pos[j]].y;
			seg_ret = oo;
			query(rt, 0, n);
			ans[pos[j]] = seg_ret;
			++j;
		}
	}
	REP(i, 0, qn) printf("%d\n", ans[i]);
	return 0;
}