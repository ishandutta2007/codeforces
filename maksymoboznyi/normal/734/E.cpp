#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int N = 2e5 + 5;

int ans,n, dep[N], c[N], numw[N], numb[N], cw, cb, mdep[N];
vector<int> g[N];

void dfs(int v, int dist, int p = 0) {
    int m1 = 0, m2 = 0;
    dep[v] = dist;
    int pp = v, pp1 = v;
    for (int i = 0; i < g[v].size(); i++)
        if (g[v][i] != p) {
            dfs(g[v][i], dist + (c[g[v][i]] != c[v]), v);
            if (mdep[g[v][i]] > m1 || (mdep[g[v][i]] == m1 && c[g[v][i]] != c[v])) {
                if (m1 > m2 || (m1 == m2 && c[pp] != c[v]))
                    pp1 = pp, m2 = m1;
                m1 = mdep[g[v][i]], pp = g[v][i];
            }
            else
                if (mdep[g[v][i]] > m2 || (mdep[g[v][i]] == m2 && c[g[v][i]] != c[v]))
                    m2 = mdep[g[v][i]], pp1 = g[v][i];;
        }
  //  cout << v << ' ' << m1 << ' ' << m2 << ' ' << pp << endl;
    ans = max(ans, m1 + m2);
    mdep[v] = m1 + (c[v] != c[p]);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1, 0, 0);
    cout << (ans + 1) / 2;
    return 0;
}