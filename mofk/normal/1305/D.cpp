#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> adj[1005];
int dad[1005];
int leaf[1005];
bitset <1005> good, save;

int ask(int u, int v) {
    cout << "? " << u << ' ' << v << endl;
    int r;
    cin >> r;
    return r;
}

int dfs(int u, int cnt) {
    int ret = u;
    for (auto v: adj[u]) {
        if (!good.test(v) || v == dad[u]) continue;
        dad[v] = u;
        ret = dfs(v, 1);
        ++cnt;
    }
    if (cnt == 1) leaf[u] = 1;
    return ret;
}

void dfs2(int u, int p) {
    save.set(u);
    for (auto v: adj[u]) {
        if (!good.test(v) || v == p) continue;
        dfs2(v, u);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) good.set(i);
    while (true) {
        if (good.count() == 1) {
            cout << "! " << good._Find_first() << endl;
            return 0;
        }
        if (good.count() == 2) {
            int u = good._Find_first();
            int v = good._Find_next(u);
            int r = ask(u, v);
            cout << "! " << r << endl;
            return 0;
        }
        if (good.count() == 3) {
            int u = good._Find_first();
            int v = good._Find_next(u);
            int t = good._Find_next(v);
            int r;
            if (find(adj[u].begin(), adj[u].end(), v) == adj[u].end())
                r = ask(u, v);
            else if (find(adj[u].begin(), adj[u].end(), t) == adj[u].end())
                r = ask(u, t);
            else r = ask(v, t);
            cout << "! " << r << endl;
            return 0;
        }
        int r = good._Find_first();
        memset(dad, 0, sizeof dad);
        memset(leaf, 0, sizeof leaf);
        int w = dfs(r, 0);
        int u = dad[w];
        int v = -1;
        for (auto x: adj[u]) if (good.test(x) && !leaf[x]) v = x;
        if (v == -1) {
            vector <int> k;
            for (auto x: adj[u]) if (good.test(x)) k.push_back(x);
            while (k.size() >= 2) {
                int x = k.back(); k.pop_back();
                int y = k.back(); k.pop_back();
                int p = ask(x, y);
                if (p != u) {
                    cout << "! " << p << endl;
                    return 0;
                }
            }
            if (k.empty()) {
                cout << "! " << u << endl;
                return 0;
            }
            else {
                int p = ask(u, k[0]);
                cout << "! " << p << endl;
                return 0;
            }
        }
        int t = ask(u, v);
        save = 0;
        if (t == u) dfs2(u, v);
        else dfs2(v, u);
        good &= save;
    }
    return 0;
}