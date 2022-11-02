#include <cstdio>
#include <memory.h>

using namespace std;

const int N = 1000 * 1000 + 10;
const int S = 50 * 1000 + 10;

int go[N][37];
long long dp[N][11];
int l[11], r[11];
int suf[N], len[N];
int sz = 1, p = 0;
char s[S], u[N];
long long res = 0;
int n;

void init()
{
    for (int i = 0; i < N; i++)
    {
        u[i] = 0;
        for (int j = 0; j < 11; j++)
            dp[i][j] = 0;
        for (int j = 0; j < 37; j++)
            go[i][j] = -1;
    }
    suf[0] = -1;
    len[0] = 0;
}

void add(int c)
{
    int v = sz++;
    len[v] = len[p] + 1;
    for (; p >= 0 && go[p][c] == -1; p = suf[p])
        go[p][c] = v;
    if (p == -1)
    {
        suf[p] = 0;
    }
    else
    {
        int to = go[p][c];
        if (len[to] == len[p] + 1)
        {
            suf[v] = to;
        }
        else
        {
            int cl = sz++;
            memcpy(go[cl], go[to], 37 * sizeof(int));
            len[cl] = len[p] + 1;
            suf[cl] = suf[to];
            for (; p >= 0 && go[p][c] == to; p = suf[p])
                go[p][c] = cl;
            suf[v] = suf[to] = cl;
        }
    }
    p = v;
}

void dfs(int v)
{
    u[v] = 1;
    for (int i = 0; i <= n; i++)
        if (go[v][i] >= 0)
            dp[v][i] = 1;
    for (int i = n + 1; i < 37; i++)
        if (go[v][i] >= 0)
        {
            if (!u[go[v][i]])
                dfs(go[v][i]);
            for (int j = 0; j <= n; j++)
                dp[v][j] += dp[go[v][i]][j];
        }
    if (v && dp[v][0])
    {
        bool ok = true;
        for (int i = 1; i <= n && ok; i++)
            if (dp[v][i] < l[i] || dp[v][i] > r[i])
                ok = false;
        if (ok)
            res += len[v] - len[suf[v]];
    }
}

int main()
{
    init();
    scanf("%s", s);
    int len = strlen(s);
    scanf("%d", &n);
    for (int i = 0; i < len; i++)
        add(s[i] - 'a' + n + 1);
    add(0);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s%d%d", s, &l[i], &r[i]);
        len = strlen(s);
        for (int j = 0; j < len; j++)
            add(s[j] - 'a' + n + 1);
        add(i);
    }
    dfs(0);
    printf("%I64d", res);
    return 0;
}