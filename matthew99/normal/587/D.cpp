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

const int maxn = 1000000, maxm = 10000000;

int n, m;

map<int, vector<int> > all_ed[maxn + 5];

int N = 0;
 
int to[maxn + 5], val[maxn + 5];

vector<int> go[maxn + 5], from[maxn + 5];

bool in[maxn + 5];

inline void add_edge(const int &x, const int &y, const int &c, const int &t)
{
	to[N] = y;
	val[N] = t;
	auto &v = all_ed[x][c];
	v.pb(N);
	if (SZ(v) > 2) EXIT("No\n");
	if (SZ(v) == 2)
	{
		if (SZ(go[x])) EXIT("No\n");
		go[x] = v;
		for (auto it : v) from[to[it]].pb(it), in[it >> 1] = 1;
	}
	++N;
}

struct edge
{
	int id, nxt;

	edge() { }
	edge(const int &_id, const int &_nxt): id(_id), nxt(_nxt) { }

};

int st[maxn + 5], en = 0;
edge e[maxm + 5];

inline void add_edge(const int &x, const int &y)
{
	e[en] = edge(y, st[x]), st[x] = en++;
}

int belong[maxn + 5];

int dfn[maxn + 5], low[maxn + 5];
int tot = 0;

int vis[maxn + 5];

int stk[maxn + 5];
int stkn = 0;

int SCC_cnt = 0;

void dfs(const int &x)
{
	stk[stkn++] = x;
	dfn[x] = low[x] = tot++;
	vis[x] = 1;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		const int &y = e[i].id;
		if (dfn[y] == -1) dfs(y), chkmin(low[x], low[y]);
		else if (vis[y] == 1) chkmin(low[x], dfn[y]);
	}
	if (dfn[x] == low[x])
	{
		while (stk[--stkn] != x) vis[stk[stkn]] = 2, belong[stk[stkn]] = SCC_cnt;
		belong[x] = SCC_cnt;
		vis[x] = 2;
		++SCC_cnt;
	}
}

vector<int> ans;

bool result[maxn + 5];
vector<int> all[maxn + 5];

vector<int> _e[maxn + 5], __e[maxn + 5];

void print(const int &x)
{
	if (result[x]) return;
	result[x] = 1;
	for (auto y : __e[x]) print(y);
}

void get_ans()
{
	static int deg[maxn + 5];
	REP(i, 0, N << 1) deg[i] = 0, _e[i].clear(), __e[i].clear(), all[belong[i]].pb(i);
	memset(result, 0, sizeof result);
	REP(i, 0, N << 1)
	{
		for (int j = st[i]; j != -1; j = e[j].nxt)
		{
			const int &x = e[j].id;
			if (belong[i] != belong[x]) _e[belong[i]].pb(belong[x]), __e[belong[x]].pb(belong[i]), ++deg[belong[x]];
		}
	}
	static int q[maxn + 5];
	int head = 0, rear = 0;
	REP(i, 0, SCC_cnt) if (!deg[i]) q[rear++] = i;
	while (head != rear)
	{
		const int &x = q[head++];
		for (auto y : _e[x])
			if (!--deg[y]) q[rear++] = y;
	}
	for (int i = rear - 1; i >= 0; --i)
	{
		const int &x = q[i];
		if (!result[x])
		{
			for (auto it : all[x])
			{
				if ((it & 1) && it < (m << 1) && in[it >> 1]) ans.pb(it >> 1);
				print(belong[it ^ 1]);
			}
		}
	}
}

bool work(const int &w, const bool &ty = 0)
{
	static int tmp[maxn + 5], tmp_en = -1;
	tmp_en = en;
	memcpy(tmp, st, sizeof tmp);
	REP(i, 0, m) if (val[i << 1] > w) add_edge(i << 1 | 1, i << 1);
	memset(dfn, -1, sizeof dfn);
	SCC_cnt = 0;
	tot = 0;
	REP(i, 0, N << 1) if (dfn[i] == -1) dfs(i);
	bool flag = 1;
	REP(i, 0, N) if (belong[i << 1] == belong[i << 1 | 1]) { flag = 0; break; }
	if (ty) get_ans();
	en = tmp_en;
	memcpy(st, tmp, sizeof st);
	return flag;
}

inline void add_res(const int &x, const bool &ty0, const int &y, const bool &ty1)
{
	add_edge(x << 1 | ty0, y << 1 | ty1);
	add_edge(y << 1 | (!ty1), x << 1 | (!ty0));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, m)
	{
		static int u, v, c, t;
		scanf("%d%d%d%d", &u, &v, &c, &t), --u, --v;
		add_edge(u, v, c, t);
		add_edge(v, u, c, t);
	}
	N >>= 1;
	memset(st, -1, sizeof st);
	REP(i, 0, n)
	{
		vector<int> tmp;
		for (auto &it : go[i]) it >>= 1;
		for (auto &it : from[i]) 
		{
			it >>= 1;
			if (!SZ(go[i]) || (it != go[i][0] && it != go[i][1])) tmp.pb(it);
		}
		for (auto it : go[i]) tmp.pb(it);
		from[i] = tmp;
		static int pre[maxn + 5];
		REP(j, 0, SZ(from[i]))
		{
			pre[j] = N++;
			add_res(from[i][j], 1, pre[j], 0);
			if (j) add_res(pre[j - 1], 0, from[i][j], 0);
			if (j) add_res(pre[j - 1], 0, pre[j], 0);
		}
		if (SZ(go[i]))
		{
			add_res(go[i][0], 1, go[i][1], 0);
			add_res(go[i][0], 0, go[i][1], 1);
		}
	}
	int l = 0, r = 1e9 + 1;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (work(mid)) r = mid;
		else l = mid + 1;
	}
	if (l > 1e9) EXIT("No\n");
	work(l, 1);
	printf("Yes\n");
	printf("%d %d\n", l, SZ(ans));
	for (auto it : ans) printf("%d ", it + 1);
	return 0;
}