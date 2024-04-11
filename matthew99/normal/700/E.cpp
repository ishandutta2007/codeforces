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

const int maxn = 200000, maxlog = 18;

inline void sortx(int *a, int *b, int *c, const int &n, const int &m)
{
	static int sum[maxn + 5];
	memset(sum, 0, sizeof(int) * (m + 1));
	REP(i, 0, n) ++sum[b[i]];
	REP(i, 0, m) sum[i + 1] += sum[i];
	for (int i = n - 1; i >= 0; --i) a[--sum[b[c[i]]]] = c[i];
}

inline void make_sa(char *s, int *sa, int *rk, const int &n)
{
	static int x[maxn + 5], y[maxn + 5];
	REP(i, 0, n) x[i] = s[i], y[i] = i;
	sortx(sa, x, y, n, CHAR_MAX);
	rk[sa[0]] = 0;
	REP(i, 0, n - 1) rk[sa[i + 1]] = rk[sa[i]] + (s[sa[i]] != s[sa[i + 1]]);
	for (int i = 1; rk[sa[n - 1]] < n - 1; i <<= 1)
	{
		REP(j, 0, n) x[j] = j + i >= n ? 0 : rk[j + i] + 1;		
		sortx(y, x, sa, n, n);
		sortx(sa, rk, y, n, n); 
		memcpy(y, rk, sizeof(int) * n);
		rk[sa[0]] = 0;
		REP(j, 0, n - 1) rk[sa[j + 1]] = rk[sa[j]] + (y[sa[j]] != y[sa[j + 1]] || x[sa[j]] != x[sa[j + 1]]);
	}
}

inline void get_height(char *s, int *h, int *sa, int *rk, const int &n)
{
	int j = 0;
	REP(i, 0, n)
	{
		if (rk[i] + 1 >= n) continue;
		while (s[sa[rk[i]] + j] == s[sa[rk[i] + 1] + j]) ++j;
		h[rk[i]] = j;
		if (j) --j;
	}
}

int n;
char s[maxn + 5];

int sa[maxn + 5], rk[maxn + 5], h[maxn + 5];

int Log[maxn + 5];
int Min[maxlog][maxn + 5];

inline int query_Min(int x, int y)
{
	if (x > y) swap(x, y);
	assert(x < y);
	int tmp = Log[y - x];
	return min(Min[tmp][x], Min[tmp][y - (1 << tmp)]);
}

inline void build_ST()
{
	REP(i, 1, n)
	{
		Log[i] = -1;
		int u = i;
		while (u) u >>= 1, ++Log[i];
	} 
	REP(i, 0, n - 1) Min[0][i] = h[i];
	REP(i, 1, maxlog) REP(j, 0, n - 1) if (j + (1 << (i - 1)) >= n - 1) Min[i][j] = 0; else Min[i][j] = min(Min[i - 1][j], Min[i - 1][j + (1 << (i - 1))]);
}

struct node
{
	node *c[2];

	int Min;
 
	node(): Min(oo) { memset(c, 0, sizeof c); }
 
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
int seg_ret;

void build(node *&rt, int l, int r)
{
	if (!rt) rt = newnode();
	if (r - l <= 1) return;
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
}

void modify(node *rt, int l, int r)
{
	chkmin(rt->Min, seg_y);
	if (r - l <= 1) return;
	int mid = (l + r) >> 1;
	if (seg_x < mid) modify(rt->c[0], l, mid);
	else modify(rt->c[1], mid, r);
}
 
void query(node *rt, int l, int r)
{
	if (seg_x <= l && r <= seg_y)
	{
		chkmin(seg_ret, rt->Min);
		return;
	}
	int mid = (l + r) >> 1;
	if (seg_x < mid) query(rt->c[0], l, mid);
	if (seg_y > mid) query(rt->c[1], mid, r);
}
 
node *rt;

inline void seg_modify(int x, int y)
{
	seg_x = x, seg_y = y;
	modify(rt, 0, n);
	return;
}

inline int seg_query(int x, int y)
{
	seg_x = x, seg_y = y, seg_ret = oo;
	query(rt, 0, n);
	return seg_ret;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	scanf("%s", s);
	make_sa(s, sa, rk, n);
	get_height(s, h, sa, rk, n);
	build_ST();
	build(rt, 0, n);
	seg_modify(rk[n - 1], n - 1);
	int ans = 1;
	for (int i = n - 2; i >= 0; --i)
	{
		int cur = 1;
		int ret = 1;
		while (1)
		{
			int from = rk[i];
			for (int j = maxlog - 1; j >= 0; --j)
				if (from - (1 << j) >= 0 && Min[j][from - (1 << j)] >= cur) from -= 1 << j;
			int to = rk[i];
			for (int j = maxlog - 1; j >= 0; --j)
				if (to + (1 << j) < n && Min[j][to] >= cur) to += 1 << j;
			++to;
			int wh = seg_query(from, to);
			if (wh >= n) break;
			int real = query_Min(rk[i], rk[wh]);
			int num = (real - cur) / (wh - i) + 1;
			cur += (wh - i) * num;
			ret += num;
		}
		chkmax(ans, ret);
		seg_modify(rk[i], i);
	}
	printf("%d\n", ans);
	return 0;
}