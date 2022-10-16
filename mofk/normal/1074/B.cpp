#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> adj[1005];
int dad[1005], h[1005];
int markA[1005], markB[1005];

void dfs(int u) {
    for (auto v: adj[u]) if (v != dad[u]) {
        dad[v] = u;
        h[v] = h[u] + 1;
        dfs(v);
    }
}

int ask(int u, int type) {
    if (type == 0)
        cout << 'A' << ' ' << u << endl;
    else cout << 'B' << ' ' << u << endl;
    int v; cin >> v; return v;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) adj[i].clear();
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        memset(dad, 0, sizeof dad);
        memset(h, 0, sizeof h);
        memset(markA, 0, sizeof markA);
        memset(markB, 0, sizeof markB);
        vector <int> A, B;
        int a, b;
        cin >> a;
        for (int i = 1; i <= a; ++i) {
            int u;
            cin >> u;
            markA[u] = 1;
            A.push_back(u);
        }
        cin >> b;
        for (int i = 1; i <= b; ++i) {
            int u;
            cin >> u;
            markB[u] = 1;
            B.push_back(u);
        }
        int id = ask(B[0], 1);
        if (markA[id]) {
            cout << 'C' << ' ' << id << endl;
            continue;
        }
        dfs(id);
        int op = A[0];
        for (auto u: A) if (h[u] < h[op]) op = u;
        int ans = ask(op, 0);
        if (markB[ans]) {
            cout << 'C' << ' ' << op << endl;
            continue;
        }
        cout << 'C' << ' ' << -1 << endl;
    }
    return 0;
}