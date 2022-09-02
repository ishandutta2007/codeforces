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

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int Mod = 1e9 + 7;

const int oo = 0x3f3f3f3f;

const int maxn = 100000, max0 = 17;

struct edge
{
    int id, nxt;

    edge() { }
    edge(int _id, int _nxt): id(_id), nxt(_nxt) { }

};

edge e[(maxn << 1) + 5];
int st[maxn + 5], en = 0;

inline void add_edge(int x, int y)
{
    e[en] = edge(y, st[x]), st[x] = en++;
}

int n;

int fa[max0][maxn + 5];

int dep[maxn + 5];
int dfn[maxn + 5], End[maxn + 5], tot = 0;

void dfs(int x)
{
    dfn[x] = tot++;
    for (int i = st[x]; i != -1; i = e[i].nxt)
    {
        int y = e[i].id;
        if (y == fa[0][x]) continue;
        fa[0][y] = x;
        dep[y] = dep[x] + 1;
        dfs(y);
    }
    End[x] = tot;
}

int lca(int x, int y)
{
    if (dep[x] > dep[y]) swap(x, y);
    for (int i = 0; dep[x] != dep[y]; ++i) if ((dep[y] - dep[x]) >> i & 1) y = fa[i][y];
    assert(x >= 0);
    assert(y >= 0);
    int s = max0 - 1;
    while (x != y)
    {
        for ( ; s && fa[s][x] == fa[s][y]; --s);
        x = fa[s][x];
        y = fa[s][y];
    }
    assert(x >= 0);
    assert(y >= 0);
    return x;
}

inline bool cmp(int x, int y)
{
    return dfn[x] < dfn[y];
}

int dis[maxn + 5];

inline int climb(int x, int d)
{
    REP(i, 0, max0)
        if (d >> i & 1) x = fa[i][x];
    return x;
}

int dp[maxn + 5][2];
bool imp[maxn + 5];

void doit(int x)
{
    dp[x][0] = dp[x][1] = 0;
    int tmp0 = 0;
    for (int i = st[x]; i != -1; i = e[i].nxt)
    {
        const int &y = e[i].id;
        doit(y);
        static int tmp[2];
        tmp[0] = tmp[1] = oo;
        if (dep[y] - dep[x] > 1) chkmin(dp[y][0], dp[y][1] + 1);
        tmp0 += min(dp[y][0], dp[y][1]);
        REP(a, 0, 2) REP(b, 0, 2) if (a + b <= 1) chkmin(tmp[a + b], dp[x][a] + dp[y][b]);
        memcpy(dp[x], tmp, sizeof dp[x]);
    }
    if (imp[x]) dp[x][1] = dp[x][0], dp[x][0] = oo;
    else chkmin(dp[x][0], tmp0 + 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    memset(st, -1, sizeof st), en = 0;
    scanf("%d", &n);
    REP(i, 0, n - 1)
    {
        int x, y;
        scanf("%d%d", &x, &y), --x, --y;
        add_edge(x, y); 
        add_edge(y, x);
    }
    dep[0] = 0;
    fa[0][0] = -1;
    dfs(0);
    REP(i, 1, max0)
        REP(j, 0, n)
            if (fa[i - 1][j] == -1) fa[i][j] = fa[i - 1][j];
            else fa[i][j] = fa[i - 1][fa[i - 1][j]];
    int qn;
    scanf("%d", &qn);
    REP(i, 0, qn)
    {
        int m;
        scanf("%d", &m);
        vector<int> all;
        vector<int> v;
        all.resize(m);
        REP(i, 0, m) scanf("%d", &all[i]), --all[i], v.pb(all[i]);
        sort(ALL(v), cmp);
        REP(i, 0, m - 1) v.pb(lca(v[i], v[i + 1]));
        sort(ALL(v), cmp);
        v.resize(unique(ALL(v)) - v.begin());
        int N = SZ(v);
        REP(i, 0, N) st[v[i]] = -1, en = 0;
        REP(i, 0, N) imp[v[i]] = 0;
        for (auto x : all) imp[x] = 1;
        static int stk[maxn + 5];
        int tot = 0;
        REP(i, 0, N)
        {
            int x = v[i];
            while (tot && !(dfn[stk[tot - 1]] <= dfn[x] && dfn[x] < End[stk[tot - 1]])) --tot;
            if (tot) add_edge(stk[tot - 1], x);
            stk[tot++] = x;
        }
        doit(v[0]);
        int ans = min(dp[v[0]][0], dp[v[0]][1]);
        if (ans <= n) printf("%d\n", ans);
        else printf("-1\n");
    }
    return 0;
}