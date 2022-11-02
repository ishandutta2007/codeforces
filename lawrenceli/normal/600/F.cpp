#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;
const int maxm = 100100;

int n[2], m;
int ea[maxm], eb[maxm];
int deg[2][maxn];
int adj[2][maxn][maxn], acol[2][maxn][maxn];
int c[2];

void go(int v, int k) {
    bool b = 0;
    while (1) {
        int nxt = adj[k][v][c[b]];
        swap(adj[k][v][c[b]], adj[k][v][c[!b]]);
        if (!nxt) break;
        v = nxt, k = !k, b = !b;
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n[0] >> n[1] >> m;
    for (int i = 0; i < m; i++) {
        cin >> ea[i] >> eb[i];
        deg[0][ea[i]]++;
        deg[1][eb[i]]++;
    }

    int maxd = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 1; j <= n[i]; j++)
            maxd = max(maxd, deg[i][j]);
    
    for (int i = 0; i < m; i++) {
        int col = 0, col2 = 0;
        for (int j = 1; j <= maxd; j++) {
            bool b1 = adj[0][ea[i]][j], b2 = adj[1][eb[i]][j];
            if (!b1 && !b2) {
                col = j;
                break;
            } else if (!b1 || !b2) col2 = j;
        }

        if (col) {
            adj[0][ea[i]][col] = eb[i];
            adj[1][eb[i]][col] = ea[i];
        } else {
            assert(col2);
            c[0] = col2;
            int v = (adj[0][ea[i]][col2] ? ea[i] : eb[i]);
            int k = (adj[0][ea[i]][col2] ? 0 : 1);
            for (int j = 1; j <= maxd; j++)
                if (!adj[k][v][j]) {
                    c[1] = j;
                    break;
                }
            go(v, k);

            assert(!adj[0][ea[i]][col2]);
            assert(!adj[1][eb[i]][col2]);

            adj[0][ea[i]][col2] = eb[i];
            adj[1][eb[i]][col2] = ea[i];
        }
    }

    for (int i = 0; i < 2; i++)
        for (int j = 1; j <= n[i]; j++)
            for (int k = 1; k <= maxd; k++)
                if (adj[i][j][k])
                    acol[i][j][adj[i][j][k]] = k;

    cout << maxd << '\n';
    for (int i = 0; i < m; i++)
        cout << acol[0][ea[i]][eb[i]] << ' ';
    cout << '\n';
}