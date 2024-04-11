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
bool vis[maxn + 5][maxn + 5];

int ax, ay;
int bx, by;
int cx, cy;

void dfs(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= n) return;
	if (x == ax || y == ay || x + y == ax + ay || x - y == ax - ay) return;
	if (vis[x][y]) return;
	vis[x][y] = 1;
	REP(i, x - 1, x + 2) REP(j, y - 1, y + 2) dfs(i, j);
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	scanf("%d%d", &ax, &ay), --ax, --ay;
	scanf("%d%d", &bx, &by), --bx, --by;
	scanf("%d%d", &cx, &cy), --cx, --cy;
	dfs(bx, by);
	puts(vis[cx][cy] ? "YES" : "NO");
	return 0;
}