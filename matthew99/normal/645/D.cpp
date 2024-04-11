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

const int maxn = 100000, maxm = 100000;

int n, m;

int rk[maxn + 5];

vector<int> v[maxn + 5];

pair<int, int> ed[maxm + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	static int deg[maxn + 5];
	memset(deg, 0, sizeof deg);
	REP(i, 0, m) scanf("%d%d", &ed[i].x, &ed[i].y), --ed[i].x, --ed[i].y, v[ed[i].x].pb(ed[i].y), ++deg[ed[i].y];
	static int q[maxn + 5];
	int head = 0, rear = 0;
	REP(i, 0, n) if (!deg[i]) q[rear++] = i;
	while (head != rear)
	{
		int x = q[head];
		rk[x] = head++;
		for (auto y : v[x]) if (!--deg[y]) q[rear++] = y;
	}
	int cnt = 0;
	REP(i, 0, m) if (rk[ed[i].x] + 1 == rk[ed[i].y])
	{
		++cnt;
		if (cnt == n - 1) { printf("%d\n", i + 1); return 0; }
	}
	printf("-1\n");
	return 0;
}