#include <bits/stdc++.h>

using namespace std;

const int N = (int)2e6;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

vector<int> g[N];
vector<int> gr[N];
string s[1111];
int dp[N];
int u[N];
bool cyc = false;
int n, m;

map<char, char> go;

void dfs(int v)
{
    u[v] = -1;
    for (int to : g[v])
    {
        if (u[to] == -1)
            cyc = true;
        if (!u[to])
            dfs(to);
    }
    u[v] = 1;
}

void dfs2(int v)
{
    u[v] = 1;
    dp[v] = s[v / m][v % m] == 'D' ? 1 : 0;
    for (int to : gr[v])
    {
        if (!u[to])
            dfs2(to);
        dp[v] = max(dp[v], dp[to] + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    go['D'] = 'I';
    go['I'] = 'M';
    go['M'] = 'A';
    go['A'] = 'D';
    bool any = false;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (s[i][j] == 'D')
                any = true;
    if (!any)
    {
        cout << "Poor Dima!";
        return 0;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int dir = 0; dir < 4; dir++)
            {
                int x = i + dx[dir];
                int y = j + dy[dir];
                if (x >= 0 && y >= 0 && x < n && y < m && go[s[i][j]] == s[x][y])
                {
                    g[i * m + j].push_back(x * m + y);
                    gr[x * m + y].push_back(i * m + j);
                }
            }
    fill(u, u + n * m, 0);
    int t = n * m;
    for (int i = 0; i < t; i++)
        if (!u[i])
            dfs(i);
    cerr << cyc << endl;
    if (cyc)
    {
        cout << "Poor Inna!";
        return 0;
    }
    fill(u, u + t, 0);
    for (int i = 0; i < t; i++)
        if (!u[i])
            dfs2(i);
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res = max(res, dp[i * m + j]);
    if (!(res / 4))
    {
        cout << "Poor Dima!";
        return 0;
    }
    cout << res / 4;

    return 0;
}