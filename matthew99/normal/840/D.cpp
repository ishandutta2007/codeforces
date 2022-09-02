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

const int maxn = 300100;
const int maxk = 5;

const int oo = 0x3f3f3f3f;

struct node;
 
node *newnode();

struct data
{
	pair<int, int> val[5][5];

	data() { REP(i, 0, 5) REP(j, 0, i) val[i][j] = mp(-1, 0); }

	friend data combine(const data &x, const data &y, int which = -1)
	{
		data ret;
		memcpy(ret.val, x.val, sizeof ret.val);
		int l = 1, r = maxk;
		if (~which) l = which, r = which + 1;
		REP(i, l, r)
		{
			REP(j, 0, i)
			{
				bool find = 0;
				REP(k, 0, i) if (ret.val[i][k].x == y.val[i][j].x)
				{
					ret.val[i][k].y += y.val[i][j].y;
					find = 1;
					break;
				}
				if (find) continue;
				int Min = y.val[i][j].y;
				REP(k, 0, i) chkmin(Min, ret.val[i][k].y);
				REP(k, 0, i)
				{
					if (!find && ret.val[i][k].y == Min) 
					{
						ret.val[i][k] = mp(y.val[i][j].x, y.val[i][j].y - Min);
						find = 1;
					}
					else ret.val[i][k].y -= Min;
				}
			}
		}
		return ret;
	}
};

struct node
{
	node *c[2];

	data sum;

	node() { memset(c, 0, sizeof c); }

	void update()
	{
		sum = combine(c[0]->sum, c[1]->sum);
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

int seg_x, seg_y, seg_k;

data seg_ret;

int n;
int a[maxn + 5];

vector<int> all[maxn + 5];

void build(node *&rt, int l, int r)
{
	rt = newnode();
	if (r - l <= 1)
	{
		REP(i, 1, maxk) rt->sum.val[i][0] = mp(a[l], 1);
		return;
	}
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
	rt->update();
}

void query(node *rt, int l, int r)
{
	if (seg_x <= l && r <= seg_y)
	{
		seg_ret = combine(seg_ret, rt->sum, seg_k);
		return;
	}
	int mid = (l + r) >> 1;
	if (seg_x < mid) query(rt->c[0], l, mid);
	if (seg_y > mid) query(rt->c[1], mid, r);
}

node *rt;
int m;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n) scanf("%d", a + i), all[a[i]].pb(i);
	rt = NULL;
	build(rt, 0, n);
	REP(i, 0, m)
	{
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k), --l;
		int lim = (r - l) / k;
		--k;
		seg_ret = data();
		seg_x = l, seg_y = r, seg_k = k;
		query(rt, 0, n);
		int Min = oo;
		REP(j, 0, k) if (~seg_ret.val[k][j].x) 
		{
			int tmp = seg_ret.val[k][j].x;
			if (lower_bound(ALL(all[tmp]), r) - lower_bound(ALL(all[tmp]), l) > lim) chkmin(Min, tmp);
		}
		if (Min == oo) Min = -1;
		printf("%d\n", Min);
	}
	return 0;
}