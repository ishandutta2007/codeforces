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

const int maxn = 500100;

int n;
int a[maxn + 5], b[maxn + 5];

int posb[maxn + 5];

bool vis[maxn + 5];

int now;
int ans[maxn + 5];

vector<pair<int, int> > fen[maxn + 5];

void dfs(int x)
{
	if (vis[x]) return;
	vis[x] = 1;
	if (b[x] < n) dfs(b[x]);
	for (int i = a[x]; i; i -= i & -i)
	{
		while (!fen[i].empty() && fen[i].back().x > x)
		{
			int tmp = fen[i].back().y;
			fen[i].pop_back();
			dfs(tmp);
		}
	}
	ans[x] = now++;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	REP(i, 0, n) b[i] = n;
	REP(i, 0, n) 
	{
		if (~a[i]) --a[i], b[a[i]] = i;
		else a[i] = n;
	}
	memset(vis, 0, sizeof vis);
	REP(i, 0, n) posb[i] = i;
	sort(posb, posb + n, [&](int x, int y) { return b[x] < b[y]; });
	REP(i, 0, n)
		for (int j = posb[i] + 1; j <= n; j += j & -j) fen[j].pb(mp(b[posb[i]], posb[i]));
	now = 0;
	REP(i, 0, n) if (!vis[i]) dfs(i);
	REP(i, 0, n) printf("%d ", ans[i] + 1);
	return 0;
}