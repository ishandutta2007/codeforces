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

int n, m;
vector<int> adj[maxn + 5];

int pre[maxn + 5];

bool draw = 0;
int win = -1;

int s;

bool in[maxn + 5];

void dfs(int x)
{
	if (!SZ(adj[x]) && (x & 1))
	{
		win = x;
		return;
	}
	in[x] = 1;
	for (auto y : adj[x])
	{
		if (in[y]) draw = 1;
		else 
		{
			if (!~pre[y])
			{
				pre[y] = x, dfs(y);
			}
		}
	}
	in[x] = 0;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n)
	{
		int num;
		scanf("%d", &num);
		REP(j, 0, num)
		{
			int x;
			scanf("%d", &x), --x;
			adj[i << 1].pb(x << 1 | 1);
			adj[i << 1 | 1].pb(x << 1);
		}
	}
	n <<= 1;
	scanf("%d", &s), --s;
	s <<= 1;
	memset(pre, -1, sizeof pre);
	pre[s] = s;
	dfs(s);
	if (~win)
	{
		puts("Win");
		vector<int> v;
		int u = win;
		while (u != s)
		{
			v.pb(u);
			u = pre[u];
		}
		v.pb(s);
		reverse(ALL(v));
		for (auto &x : v) x >>= 1;
		for (auto x : v) printf("%d ", x + 1);
		printf("\n");
	}
	else
	{
		if (draw) puts("Draw");
		else puts("Lose");
	}
	return 0;
}