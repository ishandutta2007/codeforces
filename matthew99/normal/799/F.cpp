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

const int maxn = 200100;

int n, m;
pair<int, int> a[maxn + 5];

int posl[maxn + 5], posr[maxn + 5];

LL ans;

struct node
{
	node *c[2];

	LL sum;
	int cnt;
	bool label;
 
	node(): sum(0), cnt(0), label(0) { memset(c, 0, sizeof c); }
 
	void update()
	{
		sum = 0;
		cnt = 0;
		REP(i, 0, 2) 
			if (c[i]) sum += c[i]->sum, cnt += c[i]->cnt;
	}

	void flag_label()
	{
		label = 1;
		sum = 0;
		cnt = 0;
	}

	void push_down()
	{
		if (label)
		{
			REP(i, 0, 2) c[i]->flag_label();
			label = 0;
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
 
int seg_x, seg_y;

int seg_od;

void build(node *&rt, int l, int r)
{
	rt = newnode();
	if (r - l <= 1)
	{
		if ((l & 1) == seg_od) rt->sum = l, rt->cnt = 1;
		else rt->sum = 0, rt->cnt = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
	rt->update();
}
 
void add(node *rt, int l, int r)
{
	if (seg_x <= l && r <= seg_y)
	{
		rt->flag_label();
		return;
	}
	int mid = (l + r) >> 1;
	rt->push_down();
	if (seg_x < mid) add(rt->c[0], l, mid);
	if (seg_y > mid) add(rt->c[1], mid, r);
	rt->update();
}

LL seg_sum;
int seg_cnt;
 
void query(node *rt, int l, int r)
{
	if (seg_x <= l && r <= seg_y)
	{
		seg_sum += rt->sum, seg_cnt += rt->cnt;
		return;
	}
	int mid = (l + r) >> 1;
	rt->push_down();
	if (seg_x < mid) query(rt->c[0], l, mid);
	if (seg_y > mid) query(rt->c[1], mid, r);
}
 
node *rt;

inline void work(int odl, int odr)
{
	int ptrl = 0, ptrr = 0;
	multiset<int> limr, liml;
	limr.insert(0), liml.insert(m);
	rt = NULL;
	seg_od = odl;
	build(rt, 0, m);
	for (int i = odr; i < m; i += 2)
	{
		while (ptrl < n && a[posl[ptrl]].x <= i)
		{
			if (odl != odr) liml.insert(a[posl[ptrl]].x);
			if ((a[posl[ptrl]].x ^ odr) & 1)
			{
				limr.insert(a[posl[ptrl]].x);
			}
			++ptrl;
		}
		while (ptrr < n && a[posr[ptrr]].y <= i)
		{
			if (odl != odr) liml.erase(liml.find(a[posr[ptrr]].x));
			if ((a[posr[ptrr]].x ^ odr) & 1)
			{
				limr.erase(limr.find(a[posr[ptrr]].x));
			}
			if (!((a[posr[ptrr]].y ^ a[posr[ptrr]].x) & 1))
			{
				limr.insert(a[posr[ptrr]].x);
			}
			if (!((a[posr[ptrr]].y ^ odl) & 1))
			{
				seg_x = a[posr[ptrr]].x;
				seg_y = a[posr[ptrr]].y;
				add(rt, 0, m);
			}
			++ptrr;
		}
		seg_x = *--limr.end(), seg_y = *liml.begin();
		if (ptrl == ptrr)
		{
			if (!ptrr) chkmin(seg_y, 0);
			else chkmin(seg_y, a[posr[ptrr - 1]].y);
		}
		chkmin(seg_y, i + 1);
		if (seg_x < seg_y) 
		{
			seg_sum = 0;
			seg_cnt = 0;
			query(rt, 0, m);
			ans += (LL)seg_cnt * (i + 1) - seg_sum;
		}
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n) scanf("%d%d", &a[i].x, &a[i].y), --a[i].x, posl[i] = posr[i] = i;
	sort(posl, posl + n, [&](int x, int y) { return a[x].x < a[y].x; });
	sort(posr, posr + n, [&](int x, int y) { return a[x].y < a[y].y; });
	REP(odl, 0, 2) REP(odr, 0, 2)
	{
		work(odl, odr);
	}
	cout << ans << endl;
	return 0;
}