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

const int Mod = 1e9 + 7;

const int maxn = 200000, maxq = 40000, max0 = 40;

void doit(int *a, int &n)
{
	REP(i, 0, n)
	{
		REP(j, 0, i)
		{
			if ((a[i] ^ a[j]) < a[i]) a[i] ^= a[j];
			if (a[i] > a[j])
			{
				int tmp = a[i];
				for (int k = i; k > j; --k) a[k] = a[k - 1];
				a[j] = tmp;
				break;
			}
		}
	}
	REP(i, 0, n) 
		if (!a[i])
		{
			n = i;
			break;
		}
}

struct data
{
	int all[max0];
	int alln;

	data(): alln(0) { memset(all, 0, sizeof all); }
	data(const int &val) { memset(all, 0, sizeof all), all[0] = val, alln = 1; }

	int cnt() { return 1 << (alln - (alln && all[alln - 1] == 1)); }

	void flag_label(const int &k)
	{
		REP(i, 0, alln) if (all[i] & 1) all[i] ^= k << 1;
		doit(all, alln);
	}

	friend data combine(const data &x, const data &y)
	{
		static int tmp[max0 << 1];
		int tmpn = 0;
		REP(i, 0, x.alln) tmp[tmpn++] = x.all[i];
		REP(i, 0, y.alln) tmp[tmpn++] = y.all[i];
		doit(tmp, tmpn);
		data ret;
		ret.alln = tmpn;
		memcpy(ret.all, tmp, sizeof(int) * tmpn);
		return ret;
	}

};

struct node
{
	data sum;

	int label;

	node *c[2];

	node() { memset(c, 0, sizeof c); }

	void flag_label(const int &_label)
	{
		label ^= _label;
		sum.flag_label(_label);
	}

	void push_down()
	{
		if (label)
		{
			REP(i, 0, 2) if (c[i]) c[i]->flag_label(label);
			label = 0;
		}
	}

	void update()
	{
		sum = data();
		REP(i, 0, 2) if (c[i]) sum = combine(sum, c[i]->sum);
	}

};

int nd_cur = 0;
node nd[(maxn << 1) + 5];

node *rt = NULL;

int a[maxn + 5], n, m;

void build(node *&rt, const int &l, const int &r)
{
	if (!rt) rt = nd + (nd_cur++);
	if (r - l <= 1)
	{
		rt->sum = data(a[l] << 1 | 1);
		return;
	}
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
	rt->update();
}

data ret;
int x, y, z;

void add(node *rt, const int &l, const int &r)
{
	if (!rt) return;
	if (x <= l && r <= y)
	{
		rt->flag_label(z);
		return;
	}
	rt->push_down();
	int mid = (l + r) >>1;
	if (x < mid) add(rt->c[0], l, mid);
	if (y > mid) add(rt->c[1], mid, r);
	rt->update();
}

void query(node *rt, const int &l, const int &r)
{
	if (!rt) return;
	if (x <= l && r <= y)
	{
		ret = combine(ret, rt->sum);
		return;
	}
	rt->push_down();
	int mid = (l + r) >>1;
	if (x < mid) query(rt->c[0], l, mid);
	if (y > mid) query(rt->c[1], mid, r);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n) scanf("%d", a + i);
	build(rt, 0, n);
	REP(i, 0, m)
	{
		int ty;
		scanf("%d%d%d", &ty, &x, &y), --x;
		if (ty == 1) scanf("%d", &z), add(rt, 0, n);
		else 
		{
			ret = data(), query(rt, 0, n);
			printf("%d\n", ret.cnt());
		}
	}
	return 0;
}