#include <bits/stdc++.h>

using namespace std;

const int maxn = 100100;

int n, m;
vector<int> adj[maxn];
int indeg[maxn];
int ar[maxn];
bool in[maxn];

int ans[maxn], anscnt;

void dfs(int v, int a = -1) {
    if (in[v]) a = v;
    if (ar[v] != a) {
        cout << "-1\n";
        exit(0);
    }

    for (int i : adj[v])
        dfs(i, a);

    if (in[v]) ans[anscnt++] = v;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }

    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        in[ar[i]] = 1;
    }

    for (int i = 1; i <= n; i++)
        if (!indeg[i])
            dfs(i);

   cout << anscnt << '\n';
    for (int i = 0; i < anscnt; i++)
        cout << ans[i] << '\n';
}