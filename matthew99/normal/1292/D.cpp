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

const int maxabs = 5010;
const int maxn = 11010;

int n;
int w[maxn + 5];
int dep[maxn + 5];
int fa[maxn + 5];
vector<pair<int, int> > adj[maxn + 5];

int cnt[maxabs + 5];
int id[maxabs + 5];

inline int sum_cnt(int l, int r)
{
	int ret = 0;
	REP(i, l, r) ret += cnt[i];
	return ret;
}

LL sum;

void dfs(int x, int f = -1, int d = 0)
{
	sum += (LL)w[x] * d;
	for (auto y : adj[x]) if (y.x != f)
	{
		dfs(y.x, x, d + y.y);
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	n = 1;
	vector<int> stk;
	stk.pb(0);
	dep[0] = 0;
	id[1] = 0;
	REP(i, 2, maxabs + 1)
	{
		int x = i;
		int cur = 0;
		vector<int> to_add;
		for (int j = 2; j * j <= x; ++j)
			while (!(x % j))
			{
				chkmax(cur, j);
				to_add.pb(j);
				x /= j;
			}
		if (x > 1)
		{
			chkmax(cur, x);
			to_add.pb(x);
		}
		id[i] = n;
		dep[n + 1] = sum_cnt(cur, i + 1);
		for (auto u : to_add) ++cnt[u];
		dep[n] = sum_cnt(1, i + 1);
		int lst = -1;
		while (dep[stk.back()] > dep[n + 1]) lst = stk.back(), stk.pop_back();
		if (~lst) fa[lst] = n + 1;
		fa[n] = n + 1;
		fa[n + 1] = stk.back();
		stk.pb(n + 1);
		stk.pb(n);
		n += 2;
	}
	REP(i, 1, n)
	{
		adj[fa[i]].pb(mp(i, dep[i] - dep[fa[i]]));
		adj[i].pb(mp(fa[i], dep[i] - dep[fa[i]]));
	}
	int N, x;
	scanf("%d", &N);
	REP(i, 0, N)
	{
		scanf("%d", &x), ++w[id[x]];
	}
	LL ans = LLONG_MAX;
	REP(i, 0, n)
	{
		sum = 0;
		dfs(i);
		chkmin(ans, sum);
	}
	printf("%lld\n", ans);
	return 0;
}