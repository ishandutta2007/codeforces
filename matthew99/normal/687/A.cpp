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

const int maxn = 100000, maxm = 100000;

int n, m;

vector<int> adj[maxn + 5];

int col[maxn + 5];

bool dfs(int x)
{
	for (auto y : adj[x])
	{
		if (~col[y] && col[y] == col[x]) return 0;
		if (!~col[y] && !(col[y] = !col[x], dfs(y))) return 0;
	}
	return 1;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, m)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		adj[u].pb(v), adj[v].pb(u);
	}
	memset(col, -1, sizeof col);
	REP(i, 0, n) if (!~col[i] && !(col[i] = 0, dfs(i))) { puts("-1"); return 0; }
	vector<int> A, B;
	REP(i, 0, n) if (col[i]) A.pb(i); else B.pb(i);
	printf("%d\n", SZ(A));
	for (auto u : A) printf("%d ", u + 1);
	printf("\n");
	printf("%d\n", SZ(B));
	for (auto u : B) printf("%d ", u + 1);
	printf("\n");
	return 0;
}