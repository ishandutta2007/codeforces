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

const int maxq = 500100;
const int maxabs = 1e9;
 
struct node
{
	node *c[2];

	LL sum;
 
	node(): sum(0) { memset(c, 0, sizeof c); }
 
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
 
void add(node *&rt, int l, int r)
{
	if (!rt) rt = newnode();
	rt->sum += seg_y;
	if (r - l <= 1) return;
	int mid = (l + r) >> 1;
	if (seg_x < mid) add(rt->c[0], l, mid);
	else add(rt->c[1], mid, r);
}
 
LL seg_ret = 0; 

void query(node *rt, int l, int r)
{
	if (!rt) return;
	if (seg_x <= l && r <= seg_y)
	{
		seg_ret += rt->sum;
		return;
	}
	int mid = (l + r) >> 1;
	if (seg_x < mid) query(rt->c[0], l, mid);
	if (seg_y > mid) query(rt->c[1], mid, r);
}

node *rt;

int qn;

multiset<int> S;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &qn);
	REP(i, 0, qn)
	{
		static char s[5];
		int x;
		scanf("%s%d", s, &x);
		if (s[0] == '+')
		{
			S.insert(x);
			seg_x = x, seg_y = x;
			add(rt, 0, maxabs);
		}
		else if (s[0] == '-')
		{
			S.erase(S.find(x));
			seg_x = x, seg_y = -x;
			add(rt, 0, maxabs);
		}
		if (SZ(S) == 0) printf("0\n");
		else
		{
			int ans = SZ(S) - 1;
			LL cur = *S.begin();
			int Max = *--S.end();
			while (2 * cur < Max)
			{
				seg_x = 0, seg_y = 2 * cur + 1;
				seg_ret = 0;
				query(rt, 0, maxabs);
				if (seg_ret == cur)
				{
					--ans;
					cur += *S.upper_bound(cur);
				}
				else cur = seg_ret;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}