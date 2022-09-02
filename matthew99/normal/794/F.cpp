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

#ifdef __WIN32
#define LLFORMAT "I64"
#define Rand() ((rand() << 15) | rand())
#else
#define LLFORMAT "ll"
#define Rand() (rand())
#endif

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 100100;

inline void combine(int *a, int *b)
{
	static int ret[10];
	REP(i, 0, 10) ret[i] = b[a[i]];
	memcpy(a, ret, sizeof(a[0]) * 10);
}

struct node
{
	node *c[2];

	int p[10];
	int label[10];
	LL cnt[10];
 
	node() { memset(c, 0, sizeof c); REP(i, 0, 10) p[i] = label[i] = i; memset(cnt, 0, sizeof cnt); }
 
	void update()
	{
		memset(cnt, 0, sizeof cnt);
		REP(i, 0, 2) 
			if (c[i])
			{
				REP(j, 0, 10) cnt[j] += c[i]->cnt[j];
			}
	}

	void flag_label(int *_label)
	{
		combine(label, _label);
		combine(p, _label);
		static LL tmp[10];
		memset(tmp, 0, sizeof tmp);
		REP(i, 0, 10) tmp[_label[i]] += cnt[i];
		memcpy(cnt, tmp, sizeof tmp);
	}

	void push_down()
	{
		REP(j, 0, 10) if (label[j] != j)
		{
			REP(i, 0, 2) c[i]->flag_label(label);
			REP(i, 0, 10) label[i] = i;
			break;
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

int seg_trans[10];

int n, qn;
int a[maxn + 5];

void build(node *&rt, int l, int r)
{
	rt = newnode();
	if (r - l <= 1) 
	{
		int x = a[l];
		LL now = 1;
		while (x) rt->cnt[x % 10] += now, x /= 10, now *= 10;
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
		rt->flag_label(seg_trans);
		return;
	}
	int mid = (l + r) >> 1;
	rt->push_down();
	if (seg_x < mid) add(rt->c[0], l, mid);
	if (seg_y > mid) add(rt->c[1], mid, r);
	rt->update();
}

LL sum[10];
 
void query(node *rt, int l, int r)
{
	if (seg_x <= l && r <= seg_y)
	{
		REP(i, 0, 10) sum[i] += rt->cnt[i];
		return;
	}
	int mid = (l + r) >> 1;
	rt->push_down();
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
	scanf("%d%d", &n, &qn);
	REP(i, 0, n) scanf("%d", a + i);
	build(rt, 0, n);
	REP(i, 0, qn)
	{
		int ty, l, r, x, y;
		scanf("%d%d%d", &ty, &l, &r);
		if (ty == 1) scanf("%d%d", &x, &y);
		--l;
		seg_x = l, seg_y = r;
		if (ty == 1)
		{
			REP(j, 0, 10) seg_trans[j] = j;
			seg_trans[x] = y;
			add(rt, 0, n);
		}
		else
		{
			memset(sum, 0, sizeof sum);
			query(rt, 0, n);
			LL ret = 0;
			REP(j, 0, 10) ret += sum[j] * j;
			printf("%" LLFORMAT "d\n", ret);
		}
	}
	return 0;
}