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

const int maxn = 2010;

int n;
int fa[maxn + 5], cnt[maxn + 5];
vector<int> chd[maxn + 5];

vector<int> all[maxn + 5];

int a[maxn + 5];

void dfs(int x)
{
	for (auto y : chd[x])
	{
		dfs(y);
		for (auto u : all[y]) all[x].pb(u);
	}
	sort(ALL(all[x]), [&](int u, int v) { return a[u] < a[v]; });
	if (cnt[x] > SZ(all[x]))
	{
		puts("NO");
		exit(0);
	}
	REP(i, 0, SZ(all[x])) a[all[x][i]] = i + (i >= cnt[x]);
	a[x] = cnt[x];
	all[x].pb(x);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	int rt = -1;
	REP(i, 0, n)
	{
		scanf("%d%d", fa + i, cnt + i), --fa[i];
		if (!~fa[i]) rt = i;
		else chd[fa[i]].pb(i);
	}

	dfs(rt);

	puts("YES");
	REP(i, 0, n) printf("%d ", a[i] + 1);
	printf("\n");

	return 0;
}