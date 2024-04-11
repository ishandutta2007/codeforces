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
const LL OO = 0x3f3f3f3f3f3f3f3fLL;

bool Q;

struct line 
{
	mutable LL k, b, p;

	line(const LL &_k, const LL &_b, const LL &_p): k(_k), b(_b), p(_p) { }

	bool operator<(const line& o) const 
	{
		return Q ? p < o.p : k < o.k;
	}

};

inline LL fdiv(const LL &a, const LL &b) { return a / b - ((a ^ b) < 0 && a % b); }

struct lset: multiset<line> //get maximum
{
	bool isect(const iterator &x, const iterator &y) 
	{
		if (y == end()) 
		{ 
			x->p = OO; 
			return false; 
		}
		if (x->k == y->k) x->p = x->b > y->b ? OO : -OO;
		else x->p = fdiv(y->b - x->b, x->k - y->k);
		return x->p >= y->p;
	}

	void add(const LL &k, const LL &b) 
	{
		auto z = insert(line(k, b, 0)), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}

	LL query(const LL &x) 
	{
		if (empty()) return OO;
		Q = 1; 
		auto l = *lower_bound(line(0, 0, x)); 
		Q = 0;
		return l.k * x + l.b;
	}
};

const int maxn = 100100;

int n;
LL a[maxn + 5], b[maxn + 5];

vector<int> adj[maxn + 5];

LL dp[maxn + 5];

int fa[maxn + 5];
vector<int> seq;

void dfs(int x, int f = -1)
{
	fa[x] = f;
	seq.pb(x);
	for (auto y : adj[x]) if (y != f)
	{
		dfs(y, x);
	}
}

lset all[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%" LLFORMAT "d", a + i), a[i] = -a[i];
	REP(i, 0, n) scanf("%" LLFORMAT "d", b + i);
	REP(i, 0, n - 1)
	{
		int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		adj[x].pb(y), adj[y].pb(x);
	}
	memset(dp, oo, sizeof dp);
	REP(i, 1, n) if (SZ(adj[i]) == 1) dp[i] = 0;
	seq.clear();
	dfs(0);
	for (int i = SZ(seq) - 1; i >= 0; --i)
	{
		int x = seq[i];
		chkmin(dp[x], all[x].query(a[x]));
		all[x].add(b[x], dp[x]);
		if (~fa[x])
		{
			if (SZ(all[fa[x]]) < SZ(all[x])) swap(all[x], all[fa[x]]);
			for (auto u : all[x])
				all[fa[x]].add(u.k, u.b);
			all[x].clear();
		}
	}
	REP(i, 0, n) dp[i] = -dp[i], printf("%" LLFORMAT "d ", dp[i]);
	return 0;
}