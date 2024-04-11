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

int n;

vector<int> adj[maxn + 5];

int col[maxn + 5];

void dfs(int x, int f = -1)
{
	int now = 0;
	for (auto y : adj[x]) if (y != f)
	{
		while (1)
		{
			if (now != col[x] && (!~f || now != col[f])) break;
			++now;
		}
		col[y] = now++;
		dfs(y, x);
	}
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
		int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	int tmp = 0;
	REP(i, 0, n) chkmax(tmp, SZ(adj[i]));
	col[0] = 0;
	dfs(0);
	printf("%d\n", tmp + 1);
	REP(i, 0, n) printf("%d ", col[i] + 1);
	return 0;
}