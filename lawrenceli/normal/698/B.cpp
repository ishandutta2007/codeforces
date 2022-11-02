#include <bits/stdc++.h>

using namespace std;

const int maxn = 200100;

int n, p[maxn], r, root;

int par[maxn];
vector<int> adj[maxn];

int getpar(int a) { return par[a] == a ? a : par[a] = getpar(par[a]); }
void merge(int a, int b) { 
    a = getpar(a), b = getpar(b);
    if (a == b) return;
    par[a] = b;
}

bool vis[maxn];

void dfs(int v, int p = -1) {
    if (root) return;
    if (vis[v]) {
        root = v;
        return;
    }
    vis[v] = 1;
    for (int i : adj[v]) {
        if (root) return;
        if (i == p) p = -1;
        else dfs(i, v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    iota(par, par + n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i] == i) r = i;
        else merge(i, p[i]);
        adj[i].push_back(p[i]);
        adj[p[i]].push_back(i);
    }

    int ans = 0;
    if (!r) {
        dfs(1);
        r = root;
        ans++;
        p[r] = r;
        memset(vis, 0, sizeof(vis));
        iota(par, par + n + 1, 0);
        for (int i = 1; i <= n; i++)
            merge(i, p[i]);
    }
/*
    cout << r << endl;
    for (int i = 1; i <= n; i++) cout << p[i] << ' '; cout << endl;
    for (int i = 1; i <= n; i++) cout << getpar(i) << ' '; cout << endl;
*/
    assert(r);

    vis[r] = 1;
    for (int i = 1; i <= n; i++) {
        int a = getpar(i);
        if (vis[a]) continue;
        if (p[a] == a) vis[a] = 1;
        else {
            root = 0;
            dfs(a);
            a = root;
        }
        ans++;
        p[a] = r;
    }

    cout << ans << '\n';
    for (int i = 1; i <= n; i++) cout << p[i] << ' ';
    cout << '\n';
}