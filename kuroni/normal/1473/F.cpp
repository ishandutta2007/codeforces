#include <bits/stdc++.h>
using namespace std;

const int N = 3005, MX = 105, M = N * 4, INF = 1E9 + 7;

int n, a[N], c[N];
bool chk[MX];

struct dinic {
    vector<pair<int, int>> adj[N];
    vector<int> cap;
    int n, lv[N], ptr[N];

    void add_edge(int u, int v, int c) {
        adj[u].emplace_back(v, cap.size()); cap.push_back(c);
        adj[v].emplace_back(u, cap.size()); cap.push_back(0);
    }

    bool BFS(int s, int t, int lim) {
        fill(lv, lv + n + 1, -1);
        queue<int> q;
        for (q.push(s), lv[s] = 0; !q.empty(); q.pop()) {
            int u = q.front();
            for (auto [v, ind] : adj[u]) {
                if (lv[v] == -1 && cap[ind] >= lim) {
                    q.push(v);
                    lv[v] = lv[u] + 1;
                }
            }
        }
        return lv[t] != -1;
    }

    int DFS(int u, int t, int psh) {
        if (u == t || psh == 0) {
            return psh;
        }
        for (; ptr[u] < adj[u].size(); ptr[u]++) {
            auto [v, ind] = adj[u][ptr[u]];
            if (lv[v] != lv[u] + 1) {
                continue;
            }
            if (int np = DFS(v, t, min(cap[ind], psh))) {
                cap[ind] -= np;
                cap[ind ^ 1] += np;
                return np;
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int ans = 0;
        for (int sc = (1 << 30); sc > 0; sc /= 2) {
            while (BFS(s, t, sc)) {
                fill(ptr, ptr + n + 1, 0);
                while (int f = DFS(s, t, INF)) {
                    ans += f;
                }
            }
        }
        return ans;
    }
} fl;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n; fl.n = n + 1;
    int s = 0, t = n + 1, tot = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        fill(chk, chk + MX, false);
        for (int j = i - 1; j >= 1; j--) {
            if (a[i] % a[j] == 0 && !chk[a[j]]) {
                fl.add_edge(i, j, INF);
                chk[a[j]] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        if (c[i] < 0) {
            fl.add_edge(i, t, -c[i]);
        } else {
            fl.add_edge(s, i, c[i]);
            tot += c[i];
        }
    }
    cout << tot - fl.max_flow(s, t);
}