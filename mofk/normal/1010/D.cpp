#include <bits/stdc++.h>

using namespace std;

int n;
string op[1000006];
int dad[1000006][20];
vector <int> child[1000006];
int h[1000006];
bool val[1000006];
bool f[1000006][20][2];

void dfs(int u) {
    for (auto v: child[u]) {
        h[v] = h[u] + 1;
        dfs(v);
    }
    if (op[u] == "IN") return;
    else if (op[u] == "NOT") {
        int v = child[u][0];
        val[u] = !val[v];
        f[v][0][0] = 1;
        f[v][0][1] = 0;
        return;
    }
    int v = child[u][0], w = child[u][1];
    if (op[u] == "AND") {
        val[u] = val[v] & val[w];
        f[v][0][0] = f[w][0][0] = 0;
        f[v][0][1] = val[w];
        f[w][0][1] = val[v];
    }
    else if (op[u] == "OR") {
        val[u] = val[v] | val[w];
        f[v][0][1] = f[w][0][1] = 1;
        f[v][0][0] = val[w];
        f[w][0][0] = val[v];
    }
    else if (op[u] == "XOR") {
        val[u] = val[v] ^ val[w];
        f[v][0][0] = val[w];
        f[w][0][0] = val[v];
        f[v][0][1] = !val[w];
        f[w][0][1] = !val[v];
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> op[i];
        if (op[i] == "IN") cin >> val[i];
        else {
            int sz;
            if (op[i] == "NOT") sz = 1;
            else sz = 2;
            for (int j = 0; j < sz; ++j) {
                int u;
                cin >> u;
                child[i].push_back(u);
                dad[u][0] = i;
            }
        }
    }
    dfs(1);
    for (int j = 1; j < 20; ++j) {
        for (int i = 1; i <= n; ++i) {
            dad[i][j] = dad[dad[i][j-1]][j-1];
            if (dad[i][j] == 0) continue;
            for (int t = 0; t < 2; ++t) f[i][j][t] = f[dad[i][j-1]][j-1][f[i][j-1][t]];
        }
    }
    for (int i = 1; i <= n; ++i) if (op[i] == "IN") {
        int u = i;
        int t = !val[i];
        for (int j = 19; j >= 0; --j) if (dad[u][j]) {
            t = f[u][j][t];
            u = dad[u][j];
        }
        cout << t;
    }
    cout << endl;
    return 0;
}