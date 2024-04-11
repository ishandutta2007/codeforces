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

const int maxn = 100100, max0 = 11;

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

int ex_gcd(const int &a, const int &b, int &x, int &y)
{
	if (!b)
	{
		x = 1, y = 0;
		return a;
	}
	int d = ex_gcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

int n, Mod;
int a[maxn + 5], bare[maxn + 5];

inline int get_inv(int x)
{
	int u, v;
	assert(ex_gcd(x, Mod, u, v));
	return u % Mod;
}

int pn;
vector<int> pr; 

int pw[maxn + 5][max0];

inline void get_pr()
{
	int u = Mod;
	for (int i = 2; i * i <= u; ++i)
		if (!(u % i))
		{
			pr.pb(i);
			while (!(u % i)) u /= i;
		}
	if (u > 1) pr.pb(u);
	pn = SZ(pr);
}

inline int strip(int x, int *ret)
{
	REP(i, 0, pn)
	{
		while (!(x % pr[i]))
		{
			++ret[i];
			x /= pr[i];
		}
	}
	return x;
}

struct node
{
	node *c[2];

	int sum;
	int label_mul;
	int label_mul_bare;
	int label_add[max0];
 
	node(): sum(0), label_mul(1), label_mul_bare(1) { memset(label_add, 0, sizeof label_add); }
 
	void update()
	{
		sum = 0;
		REP(i, 0, 2) 
			(sum += c[i]->sum) %= Mod;
	}

	void flag_label(int mul, int mul_bare, int *add)
	{
		sum = (LL)sum * mul % Mod;
		label_mul = (LL)label_mul * mul % Mod;
		label_mul_bare = (LL)label_mul_bare * mul_bare % Mod;
		REP(i, 0, pn) label_add[i] += add[i];
	}

	void push_down()
	{
		REP(i, 0, 2) 
		{
			c[i]->flag_label(label_mul, label_mul_bare, label_add);
		}
		label_mul = 1;
		label_mul_bare = 1;
		memset(label_add, 0, sizeof label_add);
	}

};

const int max1 = 100000;

node *nd_pool;
int nd_res = 0;

inline node *newnode()
{
	if (!nd_res) nd_pool = new node[max1], nd_res = max1;
	return nd_pool + (--nd_res);
}

int seg_x, seg_y, seg_mul, seg_mul_bare, seg_ret;
int seg_add[max0];

void build(node *&rt, int l, int r)
{
	rt = newnode();
	if (r - l <= 1) 
	{
		rt->sum = a[l];
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
		rt->flag_label(seg_mul, seg_mul_bare, seg_add);
		return;
	}
	int mid = (l + r) >> 1;
	rt->push_down();
	if (seg_x < mid) add(rt->c[0], l, mid);
	if (seg_y > mid) add(rt->c[1], mid, r);
	rt->update();
}

void modify(node *rt, int l, int r)
{
	if (r - l <= 1)
	{
		bare[l] = (LL)bare[l] * rt->label_mul_bare % Mod;
		bare[l] = (LL)bare[l] * seg_mul_bare % Mod;
		REP(i, 0, pn)
		{
			pw[l][i] += rt->label_add[i];
			pw[l][i] += seg_add[i];
		}

		rt->sum = bare[l];
		REP(i, 0, pn) rt->sum = (LL)rt->sum * fpm(pr[i], pw[l][i], Mod) % Mod;

		rt->label_mul = 1;
		rt->label_mul_bare = 1;
		memset(rt->label_add, 0, sizeof rt->label_add);
		return;
	}
	int mid = (l + r) >> 1;
	rt->push_down();
	if (seg_x < mid) modify(rt->c[0], l, mid);
	else modify(rt->c[1], mid, r);
	rt->update();
}

void query(node *rt, int l, int r)
{
	if (seg_x <= l && r <= seg_y)
	{
		(seg_ret += rt->sum) %= Mod;
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
	scanf("%d%d", &n, &Mod);
	get_pr();
	REP(i, 0, n)
	{
		scanf("%d", a + i);
		bare[i] = strip(a[i], pw[i]);
	}

	build(rt, 0, n);
	int qn;
	scanf("%d", &qn);
	REP(i, 0, qn)
	{
		int ty;
		scanf("%d", &ty);
		if (ty == 1)
		{
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x), --l;
			seg_x = l, seg_y = r;
			seg_mul = x;
			memset(seg_add, 0, sizeof seg_add);
			seg_mul_bare = strip(x, seg_add);
			add(rt, 0, n);
		}
		else if (ty == 2)
		{
			int p, x;
			scanf("%d%d", &p, &x), --p;
			seg_x = p;
			memset(seg_add, 0, sizeof seg_add);
			seg_mul_bare = strip(x, seg_add);
			seg_mul_bare = get_inv(seg_mul_bare);
			REP(j, 0, pn) seg_add[j] = -seg_add[j];
			modify(rt, 0, n);
		}
		else if (ty == 3)
		{
			int l, r;
			scanf("%d%d", &l, &r), --l;
			seg_x = l, seg_y = r;
			seg_ret = 0;
			query(rt, 0, n);
			(seg_ret += Mod) %= Mod;
			printf("%d\n", seg_ret);
		}
	}
	return 0;
}