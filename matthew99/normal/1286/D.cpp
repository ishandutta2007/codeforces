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

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

const int Mod = 998244353;

const int maxn = 100100;

int n;
int a[maxn + 5], _v[maxn + 5], p[maxn + 5], q[maxn + 5], alll[maxn + 5], allr[maxn + 5];

struct fraction
{
	int x, y;

	fraction() { }
	fraction(int _x, int _y): x(_x), y(_y) { }

	int eval() { return (LL)x * fpm(y, Mod - 2, Mod) % Mod; }
	double to_double() { return (double)x / y; }

	friend bool operator < (const fraction &x, const fraction &y)
	{
		return (LL)x.x * y.y < (LL)x.y * y.x; 
	}

};

vector<pair<fraction, int> > all;

struct matrix
{
	int a[2][2];

	matrix() { memset(a, 0, sizeof a); }
};

matrix multiply(const matrix &x, const matrix &y)
{
	matrix ret;
	REP(k, 0, 2) REP(i, 0, 2) REP(j, 0, 2)
		(ret.a[i][j] += (LL)x.a[i][k] * y.a[k][j] % Mod) %= Mod;
	return ret;
}

struct node;
 
node *newnode();
 
struct node
{
	node *c[2];

	matrix sum;
 
	node() { memset(c, 0, sizeof c); }
 
	void update()
	{
		sum = multiply(c[0]->sum, c[1]->sum);
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
	if (!rt) rt = newnode();
	if (r - l <= 1)
	{
		rt->sum = matrix();
		rt->sum.a[0][0] = rt->sum.a[1][0] = p[l];
		rt->sum.a[0][1] = rt->sum.a[1][1] = q[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
	rt->update();
} 

void ban(node *rt, int l, int r)
{
	if (r - l <= 1)
	{
		rt->sum.a[seg_y][seg_z] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	if (seg_x < mid) ban(rt->c[0], l, mid);
	else ban(rt->c[1], mid, r);
	rt->update();
}
 
node *rt;

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n)
	{
		scanf("%d%d%d", a + i, _v + i, p + i);
		p[i] = (LL)p[i] * fpm(100, Mod - 2, Mod) % Mod;
		q[i] = (1 - p[i]) % Mod;
		allr[i] = p[i];
		alll[i] = q[i];
	}
	REP(i, 0, n - 1)
	{
		all.pb(mp(fraction(a[i + 1] - a[i], _v[i] + _v[i + 1]), i * 3));
	}
	REP(i, 0, n - 1)
		if (_v[i + 1] < _v[i])
		{
			all.pb(mp(fraction(a[i + 1] - a[i], _v[i] - _v[i + 1]), i * 3 + 1));
		}
	REP(i, 0, n - 1)
		if (_v[i + 1] > _v[i])
		{
			all.pb(mp(fraction(a[i + 1] - a[i], _v[i + 1] - _v[i]), i * 3 + 2));
		}
	sort(ALL(all));
	int ans = 0;
	int lst = 0;
	build(rt, 0, n);
	REP(i, 0, SZ(all))
	{
		int tmp = all[i].x.eval();
		(tmp -= lst) %= Mod;
		(lst += tmp) %= Mod;
		int cur = (rt->sum.a[0][0] + rt->sum.a[0][1]) % Mod;
		(ans += (LL)cur * tmp % Mod) %= Mod;
		int u = all[i].y;
		if (u % 3 == 0)
		{
			u /= 3;
			seg_x = u + 1, seg_y = 0, seg_z = 1;
			ban(rt, 0, n);
		}
		else if (u % 3 == 1)
		{
			u /= 3;
			seg_x = u + 1, seg_y = 0, seg_z = 0;
			ban(rt, 0, n);
		}
		else
		{
			u /= 3;
			seg_x = u + 1, seg_y = 1, seg_z = 1;
			ban(rt, 0, n);
		}
	}
	int cur = (rt->sum.a[0][0] + rt->sum.a[0][1]) % Mod;
	(ans -= (LL)lst * cur % Mod) %= Mod;
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}