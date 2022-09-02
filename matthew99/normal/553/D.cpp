#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

const int Mod = 1e9 + 7;
const int maxn = 100000, maxm = 100000;

struct edge
{
	int id, nxt;

	edge() { }
	edge(const int &_id, const int &_nxt): id(_id), nxt(_nxt) { }
};

int st[maxn + 5];
edge e[(maxm << 1) + 5];
int en = 0;

inline void add_edge(const int &x, const int &y)
{
	e[en] = edge(y, st[x]), st[x] = en++;
}

int n, m;

int deg[maxn + 5];

vector<int> ans;

pair<int, int> seq[maxn * 3 + 5];
int seqn = 0;
bool fort[maxn + 5];

inline bool cmp(const pair<int, int> &x, const pair<int, int> &y)
{
	return (LL)x.x * y.y < (LL)x.y * y.x;
}

inline void init()
{
	memset(st, -1, sizeof st), en = 0;
	int k;
	scanf("%d%d%d", &n, &m, &k);
	REP(i, 0, k)
	{
		static int x;
		scanf("%d", &x), --x;
		fort[x] = 1;
	}
	REP(i, 0, m)
	{
		static int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		add_edge(x, y);
		add_edge(y, x);
		++deg[x], ++deg[y];
	}
	REP(i, 0, n)
	{
		REP(j, 0, deg[i] + 1)
			seq[seqn++] = mp(j, deg[i]);
	}
	sort(seq, seq + seqn, cmp);
	seqn = unique(seq, seq + seqn) - seq;
}

int can[maxn + 5];
int curdeg[maxn + 5];

int q[maxn + 5];
int head = 0, rear = 0;
bool vis[maxn + 5];

bool check(const int &x)
{
	REP(i, 1, n + 1) can[i] = i;
	REP(j, x, seqn) can[seq[j].y] = min(can[seq[j].y], seq[j].x);
	head = rear = 0;
	memset(vis, 0, sizeof vis);
	REP(i, 0, n)
	{
		curdeg[i] = deg[i];
		if (fort[i]) vis[q[rear++] = i] = 1;
	}
	while (head != rear)
	{
		const int &x = q[head++];
		for (int i = st[x]; i != -1; i = e[i].nxt)
		{
			const int &y = e[i].id;
			if (!vis[y])
			{
				if (--curdeg[y] < can[deg[y]]) vis[q[rear++] = y] = 1;
				if (rear == n) return 0;
			}
		}
	}
	return rear != n;
}

inline void solve()
{
	int l = 0, r = seqn - 1;
	while (l != r)
	{
		int mid = (l + r + 1) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	assert(check(l));
	REP(i, 0, n) if (!vis[i]) ans.pb(i);
}

inline void output()
{
	printf("%d\n", SZ(ans));
	REP(i, 0, SZ(ans)) printf("%d ", ans[i] + 1);
	printf("\n");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	solve();
	output();
	return 0;
}