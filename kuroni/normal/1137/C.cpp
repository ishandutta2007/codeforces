#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100005, D = 50;

int n, m, d, u, v, cnt = 0, scc = 0, vis[N], num[N][D], low[N][D], col[N][D];
int val[N * D], dp[N * D];
vector<int> adj[N], com[N * D];
vector<pair<int, int>> st;
string s[N];

inline void DFS(int u, int t)
{
    num[u][t] = low[u][t] = ++cnt;
    st.push_back(make_pair(u, t));
    int nxt = (t + 1) % d;
    for (int &v : adj[u])
        if (col[v][nxt] == 0)
        {
            if (num[v][nxt] == 0)
            {
                DFS(v, nxt);
                low[u][t] = min(low[u][t], low[v][nxt]);
            }
            else
                low[u][t] = min(low[u][t], num[v][nxt]);
        }
    if (num[u][t] == low[u][t])
        for (++scc; col[u][t] == 0; st.pop_back())
        {
            pair<int, int> cur = st.back();
            if (s[cur.first][cur.second] == '1' && vis[cur.first] < scc)
            {
                val[scc]++;
                vis[cur.first] = scc;
            }
            col[cur.first][cur.second] = scc;
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> d;
    while (m--)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    DFS(1, 0);
    for (int i = 1; i <= n; i++)
        for (int t = 0; t < d; t++)
        {
            int nxt = (t + 1) % d;
            for (int &v : adj[i])
                if (col[i][t] != col[v][nxt])
                    com[col[i][t]].push_back(col[v][nxt]);
        }
    for (int i = 1; i <= scc; i++)
    {
        for (int &v : com[i])
            dp[i] = max(dp[i], dp[v]);
        dp[i] += val[i];
    }
    cout << dp[scc] << '\n';
    return 0;
}