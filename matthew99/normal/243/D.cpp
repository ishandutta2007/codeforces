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

const int maxabs = 1e8;

const int maxn = 1010;

int n, vx, vy;
int a[maxn * maxn + 5];

int val[maxn * maxn + 5];

int pos[maxn * maxn + 5];

inline bool cmp(int x, int y) { return val[x] < val[y];}

struct node;

inline node *newnode();

struct node
{
	int Min;
	int label;

	node *c[2];

	node(): Min(0), label(-1) { memset(c, 0, sizeof c); }

	void flag_label(int _label)
	{
		chkmax(Min, _label);
		chkmax(label, _label);
	}

	void push_down()
	{
		if (~label)
		{
			REP(i, 0, 2) 
			{
				if (!c[i]) c[i] = newnode();
				c[i]->flag_label(label);
			}
			label = -1;
		}
	}

	void update()
	{
		Min = oo;
		REP(i, 0, 2) 
			if (c[i]) chkmin(Min, c[i]->Min);
			else Min = 0;
	}

};

const int max0 = 1e5;

node *nd_pool;
int nd_res = 0;

inline node *newnode() 
{ 
	if (!nd_res) nd_res = max0, nd_pool = new node[max0];
	return nd_pool + (--nd_res); 
}

int seg_x, seg_y, seg_z, seg_ret;

void add(node *&rt, int l, int r)
{
	if (!rt) rt = newnode();
	if (seg_x <= l && r <= seg_y)
	{
		chkmin(seg_ret, rt->Min);
		rt->flag_label(seg_z);
		return;
	}
	int mid = (l + r) >> 1;
	rt->push_down();
	if (seg_x < mid) add(rt->c[0], l, mid);
	if (seg_y > mid) add(rt->c[1], mid, r);
	rt->update();
}

node *rt;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &vx, &vy);
	REP(i, 0, n) REP(j, 0, n) scanf("%d", a + i * n + j), val[i * n + j] = i * vx + j * vy;
	REP(i, 0, n * n) pos[i] = i;
	sort(pos, pos + n * n, cmp);
	LL ans = 0;
	REP(i, 0, n * n) if (a[pos[i]])
	{
		int x = pos[i] / n, y = pos[i] % n;
		int a0 = x * -vy + y * vx;
		int a1 = (x - 1) * -vy + y * vx;
		int a2 = x * -vy + (y - 1) * vx;
		int a3 = (x - 1) * -vy + (y - 1) * vx;
		seg_x = min(min(a0, a1), min(a2, a3));
		seg_y = max(max(a0, a1), max(a2, a3));
		seg_z = a[pos[i]];
		seg_ret = oo;
		add(rt, -maxabs, maxabs);
		ans += max(0, a[pos[i]] - seg_ret);
	}
	cout << ans << endl;
	return 0;
}