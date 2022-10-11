#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

const int N = 1005;

int n, rt, cnt[N][N], map[N][N], con[N], pre[N];
vector<int> adj[N];
string s;

int read(string &s, int &pt)
{
    int ret = 0;
    for (++pt; pt < s.size() && '0' <= s[pt] && s[pt] <= '9'; pt++)
        (ret *= 10) += s[pt] - '0';
    return ret;
}

void rage(bool chk)
{
    if (chk)
        return;
    cout << -1;
    exit(0);
}

void DFS(int u, int p = 0)
{
    for (int &v : adj[u])
        if (v != p)
        {
            rage(u == rt || map[rt][u] == map[rt][v]);
            DFS(v, u);
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int pt = -1, cur = n - 1;
        cin >> s;
        while (cur > 0)
        {
            ++con[i];
            int tmp = read(s, pt);
            cur -= tmp;
            while (tmp--)
            {
                int u = read(s, pt);
                cnt[i][con[i]]++;
                map[i][u] = con[i];
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        int u = 0;
        for (int j = 1; j <= n; j++)
            if (pre[j] == 0 && con[j] == 1)
            {
                u = j;
                break;
            }
        rage(u > 0);
        for (int j = 1; j <= n; j++)
            if (pre[j] == 0 && --cnt[j][map[j][u]] == 0)
            {
                rage(pre[u] == 0);
                pre[u] = j;
                con[j]--;
            }
        rage(pre[u] > 0);
        adj[u].push_back(pre[u]);
        adj[pre[u]].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        rt = i;
        DFS(i);
    }
    cout << n - 1 << '\n';
    for (int i = 1; i < n; i++)
        if (pre[i] > 0)
            cout << i << " " << pre[i] << '\n';
}