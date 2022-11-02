#include <bits/stdc++.h>

using namespace std;

const int maxn = 300100;

int n, q;
vector<int> adj[maxn];
int sub[maxn];
int pc[maxn];

void dfs(int v) {
    sub[v] = 1;
    for (int i : adj[v]) {
        dfs(i);
        sub[v] += sub[i];
        if (pc[v] == 0 || sub[i] > sub[pc[v]])
            pc[v] = i;
    }
}

int h[maxn], ans[maxn];

void dfs2(int v, int c = 1) {
    while (1) {
        bool b = 0;
        if (pc[c] == 0) break;
        if (2 * sub[pc[c]] > sub[v]) {
            h[c] = pc[c];
            b = 1;
            c = pc[c];
        }
        if (!b) break;
    }

    ans[v] = c;

    for (int i : adj[v]) {
        if (i == h[v]) dfs2(i, c);
        else dfs2(i, i);
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        adj[p].push_back(i);
    }

    dfs(1);
    dfs2(1);

    for (int i = 0; i < q; i++) {
        int v; cin >> v;
        cout << ans[v] << '\n';
    }
}