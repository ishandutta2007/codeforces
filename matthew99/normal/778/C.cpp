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

const int maxn = 300100;

int n;

vector<pair<int, int> > adj[maxn + 5];
int has[maxn + 5];

int dep[maxn + 5];

vector<int> v_d[maxn + 5];

void dfs0(int x)
{
	for (auto y : adj[x]) dep[y.x] = dep[x] + 1, dfs0(y.x);
}

int erased = 0;

int dfs1_cnt = 0;

void dfs1(vector<int> S)
{
	if (SZ(S) <= 1) return;
	++dfs1_cnt;
	erased += SZ(S) - 1;
	static vector<int> all_l[26];
	static int vis_cnt[26] = {0};
	vector<int> v_l;
	for (auto x : S)
	{
		for (auto y : adj[x])
		{
			if (vis_cnt[y.y] != dfs1_cnt) vis_cnt[y.y] = dfs1_cnt, all_l[y.y].clear(), v_l.pb(y.y);
			all_l[y.y].pb(y.x);
		}
	}
	vector<vector<int> > to_dfs;
	for (auto letter : v_l) to_dfs.pb(all_l[letter]);
	for (auto u : to_dfs) dfs1(u);
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n - 1)
	{
		int u, v;
		char s[3];
		scanf("%d%d%s", &u, &v, s), --u, --v;
		adj[u].pb(mp(v, s[0] - 'a'));
	}
	dep[0] = 0;
	dfs0(0);
	REP(i, 0, n) v_d[dep[i]].pb(i);
	int Max = -1, Maxp = -1;
	REP(i, 0, n)
	{
		erased = 0;
		for (auto ver : v_d[i])
		{
			vector<int> chd;
			for (auto ele : adj[ver]) chd.pb(ele.x);
			if (SZ(chd)) ++erased, dfs1(chd);
		}
		if (chkmax(Max, erased)) Maxp = i;
	}
	printf("%d\n", n - Max);
	printf("%d\n", Maxp + 1);
	return 0;
}