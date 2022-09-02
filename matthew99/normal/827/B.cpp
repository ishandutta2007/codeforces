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

const int maxn = 200100;

int n, K;

vector<int> adj[maxn + 5];

int dep[maxn + 5];

void dfs(int x, int f = -1) { for (auto y : adj[x]) if (y != f) dep[y] = dep[x] + 1, dfs(y, x); }

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &K);
	REP(i, 0, n - 1) adj[i].pb(min(n - 1, i + K)), adj[min(n - 1, i + K)].pb(i);
	dfs(0);
	int x = max_element(dep, dep + n) - dep;
	dep[x] = 0;
	dfs(x);
	printf("%d\n", *max_element(dep, dep + n));
	REP(i, 0, n - 1) printf("%d %d\n", i + 1, min(n, i + K + 1));
	return 0;
}