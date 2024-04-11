#include <bits/stdc++.h>
using namespace std;

const int N = 45, MX = 1 << 20;

int n, m, u, v, col[N], dp[MX], ind[N];
bool chk[N];
long long ans[8];
vector<int> adj[N];
vector<int> le, ri, ve;

bool is_bipartite(int u, int cur = 1) {
    col[u] = cur;
    for (int v : adj[u]) {
        if (col[v] == cur) {
            return false;
        } else if (col[v] == 0 && !is_bipartite(v, 3 - cur)) {
            return false;
        }
    }
    return true;
}

void DFS(int u) {
    chk[u] = true;
    ve.push_back(u);
    for (int v : adj[u]) {
        if (!chk[v]) {
            DFS(v);
        }
    }
}

bool check(long long msk) {
    for (int u = 1; u <= n; u++) {
        if (msk >> u & 1) {
            for (int v : adj[u]) {
                if (msk >> v & 1) {
                    return false;
                }
            }
        }
    }
    return true;
}

void solve(int u) {
    ve.clear(); le.clear(); ri.clear();
    // nothing
    ans[0] = 0;
    // 0
    ans[1] *= 1;
    // 1
    ans[2] *= (is_bipartite(u) ? 2 : 0);
    // 2
    ans[4] *= 1;
    // 0/2
    ans[5] *= 2;
    // 0/1 and 1/2 --> independent sets
    long long se = 0;
    fill(dp, dp + MX, 0);
    DFS(u);
    int m = ve.size() / 2;
    for (int i = 0; i < m; i++) {
        le.push_back(ve[i]);
        ind[ve[i]] = -1;
    }
    for (int i = m; i < ve.size(); i++) {
        ri.push_back(ve[i]);
        ind[ve[i]] = i - m;
    }
    for (int msk = 0; msk < (1 << ri.size()); msk++) {
        long long cur = 0;
        for (int i = 0; i < ri.size(); i++) {
            if (msk >> i & 1) {
                cur ^= (1LL << ri[i]);
            }
        }
        if (check(cur)) {
            dp[msk]++;
        }
    }
    for (int i = 0; i < ri.size(); i++) {
        for (int msk = 0; msk < (1 << ri.size()); msk++) {
            if (msk >> i & 1) {
                dp[msk] += dp[msk ^ (1 << i)];
            }
        }
    }
    int mx = (1 << ri.size()) - 1;
    for (int msk = 0; msk < (1 << le.size()); msk++) {
        long long cur = 0;
        for (int i = 0; i < le.size(); i++) {
            if (msk >> i & 1) {
                cur ^= (1LL << le[i]);
            }
        }
        if (check(cur)) {
            int oth = mx;
            for (int l : le) {
                if (cur >> l & 1) {
                    for (int r : adj[l]) {
                        if (ind[r] >= 0) {
                            oth &= (mx ^ (1 << ind[r]));
                        }
                    }
                }
            }
            se += dp[oth];
        }
    }
    ans[3] *= se; ans[6] *= se;
    // 0-1-2
    ans[7] *= (1LL << ve.size());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    fill(ans, ans + 8, 1);
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!chk[i]) {
            if (!adj[i].empty()) {
                solve(i);
            } else {
                for (int j = 0; j < 8; j++) {
                    ans[j] *= 2;
                }
            }
        }
    }
    long long tot = 0;
    for (int i = 0; i < 8; i++) {
        tot += ((__builtin_popcount(i) & 1) ? 1 : -1) * ans[i];
    }
    cout << tot;
}