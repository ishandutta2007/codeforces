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

const int maxn = 1010;

int n;
vector<int> adj[maxn + 5];

bool in[maxn + 5];

int an, bn;
int a[maxn + 5], b[maxn + 5];

int fa[maxn + 5];

void dfs(int x, int f = -1)
{
	fa[x] = f;
	for (auto y : adj[x]) if (y != f)
	{
		dfs(y, x);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		REP(i, 0, n) adj[i].clear();
		REP(i, 0, n - 1)
		{
			int u, v;
			scanf("%d%d", &u, &v), --u, --v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		memset(in, 0, sizeof in);
		scanf("%d", &an);
		REP(i, 0, an) scanf("%d", a + i), --a[i], in[a[i]] = 1;
		scanf("%d", &bn);
		REP(i, 0, bn) scanf("%d", b + i), --b[i];
		dfs(a[0]);
		printf("B %d\n", b[0] + 1);
		fflush(stdout);
		int id;
		scanf("%d", &id), --id;
		while (!in[id]) id = fa[id];
		printf("A %d\n", id + 1);
		fflush(stdout);
		int b_id;
		scanf("%d", &b_id), --b_id;
		bool found = 0;
		REP(i, 0, bn) if (b[i] == b_id) found = 1;
		if (found) printf("C %d\n", id + 1);
		else printf("C %d\n", -1);
		fflush(stdout);
	}
	return 0;
}