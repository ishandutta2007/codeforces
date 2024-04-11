#include <bits/stdc++.h>
using namespace std;

const int N = 1505;

int n, f[2 * N], iv[2 * N], rep[2 * N];
int len[2 * N][2 * N], minl[2 * N][2 * N], maxr[2 * N][2 * N], minL[2 * N][2 * N], maxR[2 * N][2 * N];
bool vis[2 * N];
vector<int> adj[2 * N];

void DFS(int u, int p = 0) {
    vis[u] = true; rep[u] = rep[p];
    for (int v : adj[u]) {
        if (v != p) {
            f[u] = v; iv[v] = u;
            if (!vis[v]) {
                DFS(v, u);
            }
            break;
        }
    }
}

int dist(int l, int r) {
    return r - l + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= 2 * n; i++) {
        if (!vis[i]) {
            rep[0] = i;
            DFS(i);
        }
    }
    for (int i = 1; i <= 2 * n; i++) {
        int cl = 0, ml = 2 * N, mr = 0, mL = 2 * N, mR = 0;
        int u = i;
        do {
            len[i][u] = ++cl;
            if (u <= n) {
                ml = min(ml, u);
                mr = max(mr, u);
            } else {
                mL = min(mL, u);
                mR = max(mR, u);
            }
            minl[i][u] = ml; maxr[i][u] = mr;
            minL[i][u] = mL; maxR[i][u] = mR;
            u = f[u];
        } while (u != i);
    }
    long long ans = 0;
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j <= 2 * n; j++) {
            if (len[i][j] >= 2) {
                int wl = 1, wr = n, wL = n + 1, wR = 2 * n;
                bool ok = true;
                bool mx = false;
                if (iv[i] != j) {
                    int ni = iv[i], nj = j;
                    if (minl[ni][nj] != minl[i][j]) {
                        wl = max(wl, minl[ni][nj] + 1);
                    } else if (maxr[ni][nj] != maxr[i][j]) {
                        wr = min(wr, maxr[ni][nj] - 1);
                    } else if (minL[ni][nj] != minL[i][j]) {
                        wL = max(wL, minL[ni][nj] + 1);
                    } else if (maxR[ni][nj] != maxR[i][j]) {
                        wR = min(wR, maxR[ni][nj] - 1);
                    } else {
                        ok = false;
                    }
                } else {
                    mx = true;
                }
                if (f[j] != i) {
                    int ni = i, nj = f[j];
                    if (minl[ni][nj] != minl[i][j]) {
                        wl = max(wl, minl[ni][nj] + 1);
                    } else if (maxr[ni][nj] != maxr[i][j]) {
                        wr = min(wr, maxr[ni][nj] - 1);
                    } else if (minL[ni][nj] != minL[i][j]) {
                        wL = max(wL, minL[ni][nj] + 1);
                    } else if (maxR[ni][nj] != maxR[i][j]) {
                        wR = min(wR, maxR[ni][nj] - 1);
                    } else {
                        ok = false;
                    }
                } else {
                    mx = true;
                }
                if (ok && (!mx || i == rep[i])) {
                    ans += 1LL * len[i][j] / 2 * dist(wl, minl[i][j]) * dist(maxr[i][j], wr) * dist(wL, minL[i][j]) * dist(maxR[i][j], wR);
                }
            }
        }
    }
    cout << ans;
}