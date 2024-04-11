#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
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

const int maxn = 500;

int n, m;

bool f[maxn + 5][maxn + 5];

bool ac[maxn + 5];

bool vis[maxn + 5];

int col[maxn + 5];

void dfs(int x)
{
	if (vis[x]) return;
	vis[x] = 1;
	REP(y, 0, n) if (f[x][y] && ac[y]) dfs(y);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	memset(f, 0, sizeof f);
	REP(i, 0, m)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		f[u][v] = f[v][u] = 1;
	}
	REP(i, 0, n) 
	{
		ac[i] = 0;
		REP(j, 0, n)
			if (i != j && !f[i][j]) ac[i] = 1;
	}
	REP(i, 0, n)
		if (ac[i]) 
		{
			dfs(i);
			break;
		}
	REP(i, 0, n) col[i] = ac[i] ? vis[i] ? 2 : 0 : 1;
	REP(i, 0, n) REP(j, 0, i) if (i != j && f[i][j] != (abs(col[i] - col[j]) <= 1))
	{
		printf("No\n");
		exit(0);
	}
	printf("Yes\n");
	REP(i, 0, n) printf("%c", 'a' + col[i]);
	return 0;
}