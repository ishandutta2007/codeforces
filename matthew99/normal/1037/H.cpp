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

struct node
{
	node *c[2];

	int Min;
 
	node(): Min(oo) { memset(c, 0, sizeof c); }
 
	void update()
	{
		Min = oo;
		REP(i, 0, 2) chkmin(Min, c[i]->Min);
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

void build(node *&rt, int l, int r)
{
	rt = newnode();
	if (r - l <= 1) return;
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
}

int seg_x, seg_y, seg_z, seg_ret;
 
void add(node *rt, int l, int r)
{
	if (r - l <= 1)
	{
		chkmin(rt->Min, seg_z);
		return;
	}
	int mid = (l + r) >> 1;
	if (seg_x < mid) add(rt->c[0], l, mid);
	else add(rt->c[1], mid, r);
	rt->update();
}

void query(node *rt, int l, int r)
{
	if (rt->Min > seg_z) return;
	if (r - l <= 1)
	{
		seg_ret = l;
		return;
	}
	int mid = (l + r) >> 1;
	if (seg_x < mid) query(rt->c[0], l, mid);
	if (!~seg_ret && seg_y > mid) query(rt->c[1], mid, r);
}

node *rt;

const int maxn = 500500;
const int maxqn = 200200;

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

int sa[maxn + 5], rk[maxn + 5], h[maxn + 5];

struct que
{
	int id, l, r, pos, len;

	que() { }
	que(int _id, int _l, int _r, int _pos, int _len): id(_id), l(_l), r(_r), pos(_pos), len(_len) { }

};

int n, qn;
char s[maxn + 5];
vector<que> all[maxn + 5];

const int max0 = 20;

int Min[max0][maxn + 5];

pair<int, int> ans[maxqn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", s);
	n = strlen(s);
	int ori_n = n;
	s[n++] = '#';
	scanf("%d", &qn);
	REP(i, 0, qn)
	{
		int l, r;
		static char ss[maxn + 5];
		scanf("%d%d", &l, &r), --l;
		scanf("%ss", ss);
		int len = strlen(ss);
		all[l].pb(que(i, l, r, n, len));
		REP(j, 0, len) s[n++] = ss[j];
		s[n++] = '#';
	}
	s[n] = 0;

	make_sa(s, sa, rk, n);
	get_height(s, h, sa, rk, n);
	h[n - 1] = 0;

	REP(i, 0, n) Min[0][i] = h[i];
	REP(i, 1, max0) REP(j, 0, n)
		if (j + (1 << (i - 1)) >= n) Min[i][j] = Min[i - 1][j];
		else Min[i][j] = min(Min[i - 1][j], Min[i - 1][j + (1 << (i - 1))]);

	REP(i, 0, qn) ans[i] = mp(oo, oo);

	build(rt, 0, n);
	for (int i = ori_n - 1; i >= 0; --i)
	{
		seg_x = rk[i], seg_z = i;
		add(rt, 0, n);
		for (auto q : all[i])
		{
			REP(k, 0, q.len + 1)
			{
				int fir = rk[q.pos];
				for (int l = max0 - 1; l >= 0; --l)
					if (Min[l][fir] > k)
					{
						fir += 1 << l;
					}
				++fir;
				seg_ret = -1;
				seg_x = fir, seg_y = n, seg_z = q.r - k - 1;
				if (seg_x < seg_y) query(rt, 0, n);
				if (~seg_ret)
				{
					chkmin(ans[q.id], mp(seg_ret, k + 1)); 
				}
			}
		}
	}

	REP(i, 0, qn)
	{
		if (ans[i].x >= oo) printf("-1\n");
		else 
		{
			REP(j, sa[ans[i].x], sa[ans[i].x] + ans[i].y) printf("%c", s[j]);
			printf("\n");
		}
	}
	return 0;
}