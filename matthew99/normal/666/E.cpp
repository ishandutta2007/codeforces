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

const int maxlen = 1000000;

const int maxm = 55000, maxllen = 55000, maxq = 500000;

const int block_sz = 75, block_cnt = 750;

int n, m;
char s[maxlen + 5];

int belong[maxlen + 5];

inline void init()
{
	scanf("%s", s);
	n = strlen(s);
}

int sa[maxlen + 5], rk[maxlen + 5], h[maxlen + 5];

inline void sortx(int *a, int *b, int *c, const int &n, const int &m)
{
	static int sum[maxlen + 5];
	memset(sum, 0, sizeof(int) * (m + 1));
	REP(i, 0, n) ++sum[b[i]];
	REP(i, 0, m) sum[i + 1] += sum[i];
	for (int i = n - 1; i >= 0; --i) a[--sum[b[c[i]]]] = c[i];
}

inline void make_sa(char *s, int *sa, int *rk, const int &n)
{
	static int x[maxlen + 5], y[maxlen + 5];
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

int precnt[maxlen + 5];

int N = 0;
int ty[maxllen + 5];

int block[maxllen + 5];

struct que
{
	int l, r, pl, pr, id;

	que() { }
	que(int _l, int _r, int _pl, int _pr, int _id): l(_l), r(_r), pl(_pl), pr(_pr), id(_id) { }

	friend bool operator<(const que &x, const que &y)
	{
		if (block[x.pl] == block[y.pl])
		{
			if (block[x.pl] & 1) return x.pr < y.pr;
			return x.pr > y.pr;
		}
		return x.pl < y.pl;
	}

};

int qn;
que q[maxq + 5];

int ans_Max[maxq + 5], ans_Maxp[maxq + 5];

vector<int> allq[maxlen + 5];
vector<int> allp[maxlen + 5];

int fal[maxlen + 5], far[maxlen + 5];

int getl(int x) { return fal[x] == x ? x : fal[x] = getl(fal[x]); }
int getr(int x) { return far[x] == x ? x : far[x] = getr(far[x]); }

inline void merge(int x)
{
	far[getr(x)] = getr(x + 1);
	fal[getl(x + 1)] = getl(x);
}

struct node
{
	node *c[2];
	int Max, Maxp;

	node(): Max(0), Maxp(-1) { memset(c, 0, sizeof c); }

	void update()
	{
		Max = -1, Maxp = -1;
		REP(i, 0, 2) if (c[i] && chkmax(Max, c[i]->Max)) Maxp = c[i]->Maxp;
	}

};

node *rt;

node nd[(maxm << 1) + 5];
int cur = 0;

inline node *newnode() { return nd + (cur++); }

int seg_x, seg_y, seg_Max, seg_Maxp;

void add(node *&rt, int l, int r)
{
	if (!rt) rt = newnode(), rt->Max = 0, rt->Maxp = l;
	if (r - l <= 1)
	{
		rt->Max += seg_y;
		return;
	}
	int mid = (l + r) >> 1;
	if (seg_x < mid) add(rt->c[0], l, mid);
	else add(rt->c[1], mid, r);
	rt->update();
}

void query(node *rt, int l, int r)
{
	if (!rt) return;
	if (seg_x <= l && r <= seg_y)
	{
		if (chkmax(seg_Max, rt->Max)) seg_Maxp = rt->Maxp;
		return;
	}
	int mid = (l + r) >> 1;
	if (seg_x < mid) query(rt->c[0], l, mid);
	if (seg_y > mid) query(rt->c[1], mid, r);
}

inline void add(int x, int y)
{
	seg_x = ty[x], seg_y = y;
	add(rt, 0, m);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", s);
	n = strlen(s);
	REP(i, 0, n) belong[i] = -1;
	scanf("%d", &m);
	REP(i, 0, m)
	{
		static char leaf[maxllen + 5];
		scanf("%s", leaf);
		int leafn = strlen(leaf);
		s[n] = '#';
		belong[n++] = -1;
		REP(j, 0, leafn)
		{
			s[n] = leaf[j];
			belong[n++] = i;
		}
	}
	scanf("%d", &qn);
	REP(i, 0, qn)
	{
		q[i].id = i;
		scanf("%d%d%d%d", &q[i].l, &q[i].r, &q[i].pl, &q[i].pr);
		--q[i].l, --q[i].pl;
		allq[q[i].pr - q[i].pl].pb(i);
	}
	make_sa(s, sa, rk, n);
	get_height(s, h, sa, rk, n);
	precnt[0] = 0;
	N = 0;
	REP(i, 0, n) 
	{
		precnt[i + 1] = precnt[i] + (belong[sa[i]] != -1);
		if (~belong[sa[i]]) ty[N++] = belong[sa[i]];
	}
	REP(i, 0, N) block[i] = i / block_sz;
	REP(i, 0, n - 1) allp[h[i]].pb(i);
	REP(i, 0, n) fal[i] = far[i] = i;
	for (int i = n; i >= 1; --i)
	{
		for (auto x : allp[i]) merge(x);
		for (auto x : allq[i])
		{
			int u = getl(rk[q[x].pl]), v = getr(rk[q[x].pl]) + 1;
			q[x].pl = precnt[u];
			q[x].pr = precnt[v];
		}
	}
	sort(q, q + qn);
	rt = NULL, cur = 0;
	int l = 0, r = 0;
	REP(i, 0, qn)
	{
		while (r < q[i].pr) add(r++, 1);
		while (l > q[i].pl) add(--l, 1);
		while (r > q[i].pr) add(--r, -1);
		while (l < q[i].pl) add(l++, -1);
		seg_x = q[i].l, seg_y = q[i].r, seg_Max = 0, seg_Maxp = q[i].l;
		query(rt, 0, m);
		ans_Max[q[i].id] = seg_Max;
		ans_Maxp[q[i].id] = seg_Maxp;
	}
	REP(i, 0, qn) printf("%d %d\n", ans_Maxp[i] + 1, ans_Max[i]);
	return 0;
}