#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int N = 2e5 + 5;

int n, d[N], p[N];
vector<int> g[N];

void dfs(int v, int par, int dep = 0) {
    p[v] = par;
    d[v] = dep;
    for (int i = 0; i < g[v].size(); i++)
        if (g[v][i] != par)
            dfs(g[v][i], v, dep + 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1, -1);
    int p1 = 1;
    for (int i = 1; i <= n; i++)
        if (d[i] > d[p1])
            p1 = i;
    dfs(p1, -1);
    int p2 = 1;
    for (int i = 1; i <= n; i++)
        if (d[i] > d[p2])
            p2 = i;
    for (int i = 1; i <= n; i++)
        d[i] = -1;
    queue<int> q;
    int a = p1, b = p2, c = -1;
    while (p2 != p1) {
        q.push(p2);
        d[p2] = 0;
        p2 = p[p2];
    }
    q.push(p1);
    int res = q.size() - 1;
    while (!q.empty()) {
        int v = q.front();
        if (v != a && v != b)
            c = v;
        q.pop();
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            if (d[to] == -1)
                d[to] = d[v] + 1, q.push(to);
        }
    }
    //cout << res << endl;
    cout << res + d[c] << "\n";
    cout << a << ' ' << b << ' ' << c;
    return 0;
}