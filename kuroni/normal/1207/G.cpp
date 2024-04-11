#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 400005, Q = 400005, MX = 400005;

int n, t, u, q, cnt = 0, ans[Q];
int ch[MX][26], nxt[MX][26], kmp[MX], in[MX], out[MX], bit[MX];
string s;
char c;
vector<pair<int, int>> tri[N], que[N];
vector<int> adj[MX];

void update(int u, int v)
{
    for (; u <= cnt; u += u & -u)
        bit[u] += v;
}

int query(int u)
{
    int ret = 0;
    for (; u > 0; u -= u & -u)
        ret += bit[u];
    return ret;
}

int add(string s)
{
    int cur = 0;
    for (char &c : s)
    {
        if (ch[cur][c - 'a'] == 0)
            ch[cur][c - 'a'] = ++cnt;
        cur = ch[cur][c - 'a'];
    }
    return cur;
}

void BFS()
{
    queue<int> q;
    for (q.push(0); !q.empty(); q.pop())
    {
        int u = q.front();
        for (int i = 0; i < 26; i++)
        {
            nxt[u][i] = (ch[u][i] == 0 ? nxt[kmp[u]][i] : ch[u][i]);
            if (ch[u][i] > 0)
            {
                int v = ch[u][i];
                kmp[v] = nxt[u][i];
                if (kmp[v] == v)
                    kmp[v] = nxt[kmp[u]][i];
                if (kmp[v] == v)
                    kmp[v] = 0;
                adj[kmp[v]].push_back(v);
                q.push(v);
            }
        }
    }
}

void DFS_1(int u)
{
    in[u] = ++cnt;
    for (int &v : adj[u])
        DFS_1(v);
    out[u] = cnt;
}

void DFS_2(int u, int pos)
{
    update(in[pos], 1);
    for (pair<int, int> &v : que[u])
        ans[v.se] = query(out[v.fi]) - query(in[v.fi] - 1);
    for (pair<int, int> &v : tri[u])
        DFS_2(v.fi, nxt[pos][v.se]);
    update(in[pos], -1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        if (t == 1)
            u = 0;
        else
            cin >> u;
        cin >> c;
        tri[u].push_back({i, c - 'a'});
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> u >> s;
        que[u].push_back({add(s), i});
    }
    BFS();
    cnt = 0;
    DFS_1(0);
    DFS_2(0, 0);
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}