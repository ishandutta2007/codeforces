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

const int max0 = 18;
const int maxn = 200100;

struct node;
 
node *newnode();
 
struct node
{
	node *c[2];

	int Min, label;
 
	node(): Min(0), label(-1) { memset(c, 0, sizeof c); }
 
	void update()
	{
		Min = oo;
		REP(i, 0, 2) if (c[i]) chkmin(Min, c[i]->Min);
	}

	void flag_label(int _label)
	{
		label = _label;
		Min = _label;
	}

	void push_down()
	{
		if (~label)
		{
			REP(i, 0, 2) if (c[i]) c[i]->flag_label(label);
			label = -1;
		}
	}
 
};

const int _max0 = 100000;
 
node *nd_pool;
int nd_res = 0;
 
inline node *newnode()
{
	if (!nd_res) nd_pool = new node[_max0], nd_res = _max0;
	return nd_pool + (--nd_res);
}
 
int seg_x, seg_y, seg_z, seg_ret;

inline int get_Min(int, int);
 
void add(node *&rt, int l, int r)
{
	if (!rt) rt = newnode(), rt->Min = get_Min(l, r);
	if (seg_x <= l && r <= seg_y)
	{
		rt->flag_label(seg_z);
		return;
	}
	int mid = (l + r) >> 1;
	if (!rt->c[0]) rt->c[0] = newnode(), rt->c[0]->Min = get_Min(l, mid);
	if (!rt->c[1]) rt->c[1] = newnode(), rt->c[1]->Min = get_Min(mid, r);
	rt->push_down();
	if (seg_x < mid) add(rt->c[0], l, mid);
	if (seg_y > mid) add(rt->c[1], mid, r);
	rt->update();
} 

void query(node *&rt, int l, int r)
{
	if (!rt) rt = newnode(), rt->Min = get_Min(l, r);
	if (seg_x <= l && r <= seg_y)
	{
		chkmin(seg_ret, rt->Min);
		return;
	}
	int mid = (l + r) >> 1;
	if (!rt->c[0]) rt->c[0] = newnode(), rt->c[0]->Min = get_Min(l, mid);
	if (!rt->c[1]) rt->c[1] = newnode(), rt->c[1]->Min = get_Min(mid, r);
	rt->push_down();
	if (seg_x < mid) query(rt->c[0], l, mid);
	if (seg_y > mid) query(rt->c[1], mid, r);
}

int n, K;
int a[maxn + 5];

int Min[max0][maxn + 5];
int Log[maxn + 5];

inline void get_ST()
{
	REP(i, 0, n << 1) Min[0][i] = a[i];
	REP(i, 1, max0) REP(j, 0, n << 1)
		if (j + (1 << (i - 1)) < (n << 1)) Min[i][j] = min(Min[i - 1][j], Min[i - 1][j + (1 << (i - 1))]);
		else Min[i][j] = Min[i - 1][j];
}

inline int rmq(int l, int r)
{
	int tmp = Log[r - l];
	return min(Min[tmp][l], Min[tmp][r - (1 << tmp)]);
}

inline int get_Min(int l, int r)
{
	int to_shift = (l / n) * n;
	l -= to_shift;
	r -= to_shift;
	chkmin(r, n << 1);
	return rmq(l, r);
}
 
node *rt;

int qn;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	for (int i = 1; i <= maxn; ++i)
	{
		int u = i;
		Log[i] = -1;
		while (u) ++Log[i], u >>= 1;
	}
	scanf("%d%d", &n, &K);
	REP(i, 0, n) scanf("%d", a + i), a[n + i] = a[i];
	get_ST();
	rt = newnode();
	rt->Min = get_Min(0, n * K);
	scanf("%d", &qn);
	REP(i, 0, qn)
	{
		int ty, l, r;
		scanf("%d%d%d", &ty, &l, &r), --l;
		if (ty == 1)
		{
			int x;
			scanf("%d", &x);
			seg_x = l, seg_y = r, seg_z = x;
			add(rt, 0, n * K);
		}
		else if (ty == 2)
		{
			seg_x = l, seg_y = r, seg_ret = oo;
			query(rt, 0, n * K);
			printf("%d\n", seg_ret);
		}
	}
	return 0;
}