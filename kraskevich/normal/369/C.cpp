#include <bits/stdc++.h>

using namespace std;

const int N = (int)2e5;

vector<int> g[N];
vector<int> bad[N];
vector<bool> u(N, false);
vector<int> res;

bool dfs(int v, bool need)
{
    u[v] = true;
    bool up = false;
    for (int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if (!u[to])
            if (dfs(to, bad[v][i]))
                up = true;
    }
    if (up)
        need = false;
    if (need)
        up = true;
    if (need)
        res.push_back(v);
    return up;
}

int main()
{
    ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        --c;
        g[a].push_back(b);
        g[b].push_back(a);
        bad[a].push_back(c);
        bad[b].push_back(c);
    }
    dfs(0, false);
    cout << res.size() << "\n";
    for (auto x : res)
        cout << x + 1 << " ";

    return 0;
}