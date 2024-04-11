#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
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

const int maxn = 300000, maxm = 300000;

int n, m, K;

int fa[maxn + 5];

set<int> all;

vector<int> adj[maxn + 5];

int cnt[maxn + 5], sz[maxn + 5];

bool can[maxn + 5];

int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }

inline void Union(int x, int y)
{
	x = get(x), y = get(y);
	sz[x] += sz[y];
	can[x] |= can[y];
	fa[y] = x;
}

int deg[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &K);
	memset(can, 1, sizeof can);
	REP(i, 0, m)
	{
		int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		if (x && y) adj[x].pb(y), adj[y].pb(x);
		if (!x) can[y] = 0;
		if (!y) can[x] = 0;
		++deg[x], ++deg[y];
	}
	if (deg[0] + K > n - 1) EXIT("impossible\n");
	REP(i, 1, n) sz[i] = 1, fa[i] = i;
	REP(i, 1, n) all.insert(i);
	REP(i, 1, n)
	{
		map<int, int> sum;
		for (auto x : adj[i]) ++sum[get(x)];
		vector<int> to_del;
		int tmp = get(i);
		for (auto x : all)
		{
			assert(fa[x] == x);
			if (x != tmp)
			{
				if (sum[x] != sz[x]) 
				{
					Union(tmp, x);
					to_del.pb(x);
				}
			}
		}
		for (auto x : to_del) all.erase(x);
	}
	int cnt = 0;
	REP(i, 1, n) if (get(i) == i) 
	{
		if (!can[i]) EXIT("impossible\n");
		++cnt;
		if (cnt > K) EXIT("impossible\n");
	}
	printf("possible\n");
	return 0;
}