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

#ifdef __WIN32
#define LLFORMAT "I64"
#define Rand() ((rand() << 15) | rand())
#else
#define LLFORMAT "ll"
#define Rand() (rand())
#endif

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 400100;

const int Mod0 = 1e9 + 7, Mod1 = 1e9 + 9;
const int magic = 113;

struct hd
{
	int a0, a1;

	hd(int _val = 0): a0(_val), a1(_val) { }
	hd(int _a0, int _a1): a0(_a0), a1(_a1) { }

	friend hd operator+(const hd &x, const hd &y)
	{
		return hd((x.a0 + y.a0) % Mod0, (x.a1 + y.a1) % Mod1);
	}

	friend hd operator-(const hd &x, const hd &y)
	{
		return hd((x.a0 - y.a0 + Mod0) % Mod0, (x.a1 - y.a1 + Mod1) % Mod1);
	}

	friend hd operator*(const hd &x, const hd &y)
	{
		return hd((LL)x.a0 * y.a0 % Mod0, (LL)x.a1 * y.a1 % Mod1);
	}
	
	friend bool operator<(const hd &x, const hd &y)
	{
		if (x.a0 == y.a0) return x.a1 < y.a1;
		return x.a0 < y.a0;
	}


};

LL ans;

int n;
int n0, n1;
char s[maxn + 5];

hd hpw[maxn + 5];
hd hpre[maxn + 5];

pair<int, int> pre;

struct node
{
	int p, Min, len, where;
	bool in0, in1;
	int go[26];

	node(): p(0), Min(oo), len(0), where(-1), in0(0), in1(0) { memset(go, 0, sizeof go); }
}nd[maxn + 5];
int nd_cur;
int nd_cnt = 0;

int place[maxn + 5];

inline void extend(int m)
{
	int w = s[m] - 'a';
	int u = nd_cur;
	while (m + nd[u].len + 1 >= n || s[m] != s[m + nd[u].len + 1]) u = nd[u].p;
	if (!nd[u].go[w])
	{
		int v = nd[u].p;
		while (m + nd[v].len + 1 >= n || s[m] != s[m + nd[v].len + 1]) v = nd[v].p;
		nd[nd_cnt] = node();
		nd[nd_cnt].p = nd[v].go[w];
		nd[u].go[w] = nd_cnt;
		nd[nd_cnt].len = nd[u].len + 2;
		++nd_cnt;
	}
	nd_cur = nd[u].go[w];

	nd[nd_cur].where = m;
	if (m < n0) nd[nd_cur].in0 = 1;
	else if (m > n0) nd[nd_cur].in1 = 1;
}

inline void get_hash()
{
	hpw[0] = 1;
	REP(i, 0, n) hpw[i + 1] = hpw[i] * magic;
	hpre[0] = 0;
	REP(i, 0, n) 
	{
		hpre[i + 1] = hpre[i] * magic + s[i] - 'a' + 1;
	}
}

set<hd> pal0, pal1;

map<hd, int> num0, num1;

inline hd hcalc(int l, int r)
{
	return hpre[r] - hpre[l] * hpw[r - l];
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	static char s0[maxn + 5], s1[maxn + 5];
	scanf("%s%s", s0, s1);
	n0 = strlen(s0), n1 = strlen(s1);
	n = n0 + 1 + n1;
	REP(i, 0, n0) s[i] = s0[i];
	s[n0] = '#';
	REP(i, 0, n1) s[n0 + 1 + i] = s1[i];

	nd[0] = nd[1] = node();
	nd_cur = 0;
	nd_cnt = 2, nd[1].len = -1, nd[0].p = 1;

	place[n] = nd_cur;
	for (int i = n - 1; i >= 0; --i)
	{
		if (i == n0) nd_cur = 0;
		else extend(i);
		place[i] = nd_cur;
	}

	get_hash();

	int cnt0 = 0, cnt1 = 0;
	REP(i, 2, nd_cnt)
	{
		if (nd[i].in0) ++cnt0, pal0.insert(hcalc(nd[i].where, nd[i].where + nd[i].len));
		if (nd[i].in1) ++cnt1, pal1.insert(hcalc(nd[i].where, nd[i].where + nd[i].len));
	}

	ans = (LL)cnt0 * cnt1;

	REP(i, 2, nd_cnt)
	{
		if (nd[i].p > 1)
		{
			int seg = nd[i].len - nd[nd[i].p].len;
			int cnt = (nd[i].len - 1) / seg;
			int res = seg - nd[i].len % seg;
			hd head = hcalc(nd[i].where, nd[i].where + seg);
			hd tail = hcalc(nd[i].where + nd[i].len - seg, nd[i].where + nd[i].len);
			if (nd[i].in0)
			{
				chkmax(num0[head], cnt); 
				if (pal1.count(tail * hpw[res] + hcalc(nd[i].where + nd[i].len - seg, nd[i].where + nd[i].len - seg + res)))
					chkmax(num1[head], 1);
			}
			if (nd[i].in1)
			{
				chkmax(num1[tail], cnt); 
				if (pal0.count(tail * hpw[res] + hcalc(nd[i].where + nd[i].len - seg, nd[i].where + nd[i].len - seg + res)))
					chkmax(num0[tail], 1);
			}
		}
	}

	for (auto u : num0)
	{
		int tmp0 = u.y, tmp1 = num1[u.x];
		if (tmp0 && tmp1)
		{
			ans -= LL(tmp0 + 1) * (tmp1 + 1);
			ans += tmp0 + tmp1 + 1;
		}
	}

	printf("%" LLFORMAT "d\n", ans);
	return 0;
}