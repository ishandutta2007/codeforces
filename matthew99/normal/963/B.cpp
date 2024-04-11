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

const int maxn = 200100;

int n;
int p[maxn + 5];

vector<int> adj[maxn + 5];

int sz[maxn + 5];

void dfs0(int x, int f = -1)
{
	sz[x] = 1;
	for (auto y : adj[x]) if (y != f)
	{
		dfs0(y, x);
		sz[x] += sz[y];
	}
}

void dfs1(int x, int f = -1)
{
	for (auto y : adj[x]) if (y != f)
	{
		if (!(sz[y] & 1)) dfs1(y, x);
	}
	printf("%d\n", x + 1);
	for (auto y : adj[x]) if (y != f)
	{
		if (sz[y] & 1) dfs1(y, x);
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) 
	{
		scanf("%d", p + i), --p[i];
		if (~p[i])
		{
			adj[p[i]].pb(i), adj[i].pb(p[i]);
		}
	}
	if (!(n & 1))
	{
		puts("NO");
	}
	else
	{
		puts("YES");
		dfs0(0);
		dfs1(0);
	}
	return 0;
}