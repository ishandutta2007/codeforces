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

const int maxn = 5050, maxm = 5050;

int n, m;
vector<int> adj[maxn + 5];

inline void get_dis(int S, int *dis)
{
	static int q[maxn + 5];
	static bool vis[maxn + 5];
	memset(vis, 0, sizeof vis);
	REP(i, 0, n) dis[i] = oo;
	int head = 0, rear = 0;
	dis[S] = 0;
	vis[S] = 1;
	q[rear++] = S;
	while (head != rear)
	{
		int x = q[head++];
		for (auto y : adj[x])
		{
			if (vis[y]) continue;
			vis[y] = 1;
			q[rear++] = y;
			dis[y] = dis[x] + 1;
		}
	}
}

int dis[maxn + 5][maxn + 5];

bool in[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, m)
	{
		int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		adj[u].pb(v);
	}
	REP(i, 0, n) get_dis(i, dis[i]);
	int ans = n;
	REP(i, 0, n) if (!in[i])
	{
		vector<int> all;
		bool find = 0;
		int Min = oo;
		REP(j, 0, n) if (dis[i][j] < oo && dis[j][i] < oo)
		{
			all.pb(j);
			assert(!in[j]);
			if (!find)
			{
				for (auto k : adj[j]) 
					if (dis[i][k] >= oo || dis[k][i] >= oo) { find = 1; break; }
					else chkmin(Min, 1 + dis[k][j]);
			}
			in[j] = 1;
		}
		if (!find && SZ(all) > 1) ans += 998 * Min + 1;
	}
	printf("%d\n", ans);
	return 0;
}