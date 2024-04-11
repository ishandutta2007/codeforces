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

const int maxn = 150100;

int n, qn;
int fa[maxn + 5];
char w[maxn + 5];

vector<int> adj[maxn + 5];

int dep[maxn + 5];

int cnt[maxn + 5][27];
int Min[maxn + 5][27];

int up[maxn + 5];

int leaf_depth = -1;

bool uneven = 0;

void dfs(int x)
{
	if (SZ(adj[x]) == 0)
	{
		if (!~leaf_depth) leaf_depth = dep[x];
		else if (leaf_depth != dep[x]) uneven = 1;
	}
	for (auto y : adj[x]) 
	{
		if (SZ(adj[x]) == 1) up[y] = up[x]; 
		else up[y] = y;
		dep[y] = dep[x] + 1;
		dfs(y);
	}
}

int sum_Min[maxn + 5];

int bad_cnt = 0;
bool bad[maxn + 5];

inline void update(int x, int l, int d)
{
	x = up[x];
	cnt[x][l] += d;
	Min[x][l] += d;
	while (1)
	{
		x = fa[x];
		if (!~x) break;
		sum_Min[up[x]] -= Min[up[x]][l] - cnt[up[x]][l];
		Min[up[x]][l] = 0;
		for (auto y : adj[x])
		{
			chkmax(Min[up[x]][l], Min[y][l]);
		}
		if (bad[up[x]]) --bad_cnt;
		sum_Min[up[x]] += Min[up[x]][l];
		bad[up[x]] = sum_Min[up[x]] > leaf_depth - dep[x];
		if (bad[up[x]]) ++bad_cnt;
		Min[up[x]][l] += cnt[up[x]][l];
		x = up[x];
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	static char ss[5];
	scanf("%d%d", &n, &qn);
	REP(i, 0, n) adj[i].clear();
	fa[0] = -1;
	REP(i, 1, n)
	{
		scanf("%d%s", fa + i, ss), --fa[i];
		w[i] = ss[0];
		adj[fa[i]].pb(i);
	}
	up[0] = 0;
	dfs(0);
	if (uneven)
	{
		REP(i, 0, qn) puts("Fou");
		return 0;
	}
	memset(Min, 0, sizeof Min);
	memset(sum_Min, 0, sizeof sum_Min);
	memset(cnt, 0, sizeof cnt);
	REP(i, 1, n) if (w[i] != '?') update(i, w[i] - 'a', 1);
	REP(i, 0, qn)
	{
		int x;
		scanf("%d%s", &x, ss), --x;
		if (w[x] != '?') update(x, w[x] - 'a', -1);
		w[x] = ss[0];
		if (w[x] != '?') update(x, w[x] - 'a', 1);
		int sum = 0;
		REP(j, 0, 26) sum += Min[0][j];
		if (bad_cnt) puts("Fou");
		else
		{
			int ans = 0;
			REP(j, 0, 26) ans += (j + 1) * (Min[0][j] + leaf_depth - sum);
			printf("Shi %d\n", ans);
		}
	}
	return 0;
}