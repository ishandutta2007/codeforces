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

const int maxq = 100000;
const int maxn = 1000, maxm = 1000;

int n, m, qn;
int N;
int fa[maxq + 5];
int cnt[maxq + 5];

int id[maxq + 5];

struct data
{
	int ty, x, y;
};

data a[maxq + 5];

int tot = 0;
bitset<maxm + 5> now[maxn + 5];
bitset<maxm + 5> full;

vector<int> chd[maxq + 5];

void dfs(int x)
{
	bool flag = 0;
	if (x)
	{
		tot -= now[a[x].x].count();
		if (a[x].ty == 1)
		{
			if (!now[a[x].x][a[x].y]) flag = 1;
		}
		else if (a[x].ty == 2)
		{
			if (now[a[x].x][a[x].y]) flag = 1;
		}
		if (a[x].ty != 3) now[a[x].x][a[x].y] = now[a[x].x][a[x].y] ^ flag;
		else now[a[x].x] ^= full;
		tot += now[a[x].x].count();
	}
	cnt[x] = tot;
	for (auto y : chd[x]) dfs(y);
	if (x)
	{
		tot -= now[a[x].x].count();
		if (a[x].ty != 3) now[a[x].x][a[x].y] = now[a[x].x][a[x].y] ^ flag;
		else now[a[x].x] ^= full;
		tot += now[a[x].x].count();
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &qn);
	REP(i, 0, m) full[i] = 1;
	fa[0] = -1;
	id[0] = 0;
	N = 1;
	int cur = 0;
	REP(i, 1, qn + 1)
	{
		int ty;
		scanf("%d", &ty);
		if (ty == 4)
		{
			int x;
			scanf("%d", &x);
			cur = id[i] = id[x];
		}
		else
		{
			a[N].ty = ty;
			scanf("%d", &a[N].x), --a[N].x;
			if (ty != 3) scanf("%d", &a[N].y), --a[N].y;
			id[i] = N;
			fa[N] = cur;
			cur = N++;
		}
	}
	REP(i, 1, N) chd[fa[i]].pb(i);
	dfs(0);
	REP(i, 1, qn + 1) printf("%d\n", cnt[id[i]]);
	return 0;
}