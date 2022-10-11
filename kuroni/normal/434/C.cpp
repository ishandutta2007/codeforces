#include <bits/stdc++.h>
using namespace std;

const int N = 205, M = 20, L = 205, K = 505, MX = 205, MOD = 1E9 + 7;

int n, m, k, v, dp[MX][K][2][2][2];
int cnt = 0, ch[MX][M], nxt[MX][N], kmp[MX], sum[MX];

struct SNumber
{
    vector<int> ve;

    void read()
    {
        int n; cin >> n;
        ve = vector<int>(n, 0);
        for (int i = n - 1; i >= 0; i--)
            cin >> ve[i];
    }
} le, ri, num;

void add(SNumber &tmp, int v)
{
    int cur = 0;
    for (int &v : tmp.ve)
    {
        if (ch[cur][v] == 0)
            ch[cur][v] = ++cnt;
        cur = ch[cur][v];
    }
    sum[cur] = min(k + 1, sum[cur] + v);
}

void BFS()
{
    queue<int> q;
    for (q.push(0); !q.empty(); q.pop())
    {
        int u = q.front();
        for (int i = 0; i < m; i++)
        {
            nxt[u][i] = (ch[u][i] > 0 ? ch[u][i] : nxt[kmp[u]][i]);
            if (ch[u][i] > 0)
            {
                int v = ch[u][i];
                kmp[v] = nxt[u][i];
                if (kmp[v] == v)
                    kmp[v] = nxt[kmp[u]][i];
                if (kmp[v] == v)
                    kmp[v] = 0;
                sum[v] = min(k + 1, sum[v] + sum[kmp[v]]);
                q.push(v);
            }
        }
    }
}

int find_ans(SNumber &cur)
{
    int ans = 0;
    vector<int> &ve = cur.ve;
    for (int nod = 0; nod <= cnt; nod++)
        for (int val = 0; val <= k; val++)
            for (int le = 0; le < 2; le++)
                for (int ze = 0; ze < 2; ze++)
                    dp[nod][val][1][le][ze] = 0;
    dp[0][0][1][1][1] = 1;
    for (int i = 0; i < ve.size(); i++)
    {
        int cur = i & 1, pre = cur ^ 1, v = ve[i];
        for (int nod = 0; nod <= cnt; nod++)
            for (int val = 0; val <= k; val++)
                for (int le = 0; le < 2; le++)
                    for (int ze = 0; ze < 2; ze++)
                        dp[nod][val][cur][le][ze] = 0;
        for (int nod = 0; nod <= cnt; nod++)
            for (int val = 0; val <= k; val++)
                for (int le = 0; le < 2; le++)
                    for (int ze = 0; ze < 2; ze++)
                        for (int di = 0; di < m; di++)
                        {
                            int nw = nxt[nod][di];
                            int nv = val + sum[nw];
                            if (nv > k)
                                continue;
                            int nl = (le & (di <= v)) | (di < v);
                            int nz = (di == 0);
                            (dp[nw][nv][cur][nl][nz] += dp[nod][val][pre][le][ze]) %= MOD;
                        }
        for (int nod = 0; nod <= cnt; nod++)
            for (int val = 0; val <= k; val++)
                for (int le = (i + 1 == ve.size()); le < 2; le++)
                    (ans += dp[nod][val][cur][le][0]) %= MOD;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    le.read();
    for (int i = 0; i < le.ve.size(); i++)
        if (le.ve[i] > 0)
        {
            le.ve[i]--;
            break;
        }
        else
            le.ve[i] = m - 1;
    if (le.ve.back() == 0)
        le.ve.pop_back();
    ri.read();
    while (n--)
    {
        num.read();
        cin >> v;
        add(num, v);
    }
    BFS();
    cout << (find_ans(ri) - find_ans(le) + MOD) % MOD;
}