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

const int maxn = 100100;

struct node;
 
node *newnode();
 
struct node
{
	node *c[2];

	int sum;
 
	node(): sum(0) { memset(c, 0, sizeof c); }

	inline node* get_child(int kind) { return this ? c[kind] : 0; }
	inline int get_sum() { return this ? sum : 0; }
 
};

const int max0 = 100000;
 
node *nd_pool;
int nd_res = 0;
 
inline node *newnode()
{
	if (!nd_res) nd_pool = new node[max0], nd_res = max0;
	return nd_pool + (--nd_res);
}

inline node *copy(node *x)
{
	node *tmp = newnode();
	*tmp = *x;
	return tmp;
}
 
int seg_x;
 
void add(node *&rt, int l, int r)
{
	if (!rt) rt = newnode();
	else rt = copy(rt);
	++rt->sum;
	if (r - l <= 1) return;
	int mid = (l + r) >> 1;
	if (seg_x < mid) add(rt->c[0], l, mid);
	else add(rt->c[1], mid, r);
}

int seg_ret, seg_res;

inline void find_kth(node *rt, int l, int r)
{
	if (r - l <= 1)
	{
		seg_ret = l;
		return;
	}
	int mid = (l + r) >> 1;
	int tmp = rt->get_child(0)->get_sum();
	if (seg_res <= tmp) find_kth(rt->get_child(0), l, mid);
	else seg_res -= tmp, find_kth(rt->get_child(1), mid, r);
}
 
node *rt[maxn + 5];

int n;
int a[maxn + 5];

int lst[maxn + 5];

vector<int> pos_lst[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	map<int, int> map_lst;
	REP(i, 0, n) 
	{
		scanf("%d", a + i);
		if (map_lst.count(a[i])) lst[i] = map_lst[a[i]];
		else lst[i] = -1;
		map_lst[a[i]] = i;
		pos_lst[lst[i] + 1].pb(i);
	}
	rt[0] = NULL;
	REP(i, 0, n + 1)
	{
		for (auto u : pos_lst[i]) 
		{
			seg_x = u;
			add(rt[i], 0, n + 1);
		}
		rt[i + 1] = rt[i];
	}
	REP(i, 1, n + 1)
	{
		int cur = 0;
		int ret = 0;
		while (cur < n)
		{
			seg_res = cur + i + 1;
			find_kth(rt[cur], 0, n + 1);
			cur = seg_ret;
			++ret;
		}
		printf("%d ", ret);
	}
	return 0;
}