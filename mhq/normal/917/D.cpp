#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
const int maxN = 105;
int c[maxN][maxN];
void init() {
    c[0][0] = 1;
    for (int i = 1; i < maxN; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = sum(c[i - 1][j], c[i - 1][j - 1]);
        }
    }
}
int dp[maxN][maxN][maxN];
int n;
vector < int > g[maxN];
int sz[maxN];
int f[maxN];
int dp_now[maxN][maxN];
void dfs(int v, int p) {
    sz[v] = 1;
    dp[v][0][1] = 1;
    for (int to : g[v]) {
        if (to == p) continue;
        dfs(to, v);
        memset(dp_now, 0, sizeof dp_now);
        for (int edges_take = 0; edges_take < sz[v]; edges_take++) {
            for (int sz_now = 0; sz_now <= sz[v]; sz_now++) {
                if (!dp[v][edges_take][sz_now]) continue;
                for (int his_take = 0; his_take < sz[to]; his_take++) {
                    for (int his_sz = 0; his_sz <= sz[to]; his_sz++) {
                        if (!dp[to][his_take][his_sz]) continue;
                        // not take edge
                        dp_now[edges_take + his_take][sz_now] = sum(dp_now[edges_take + his_take][sz_now], mult(
                            dp[v][edges_take][sz_now], mult(dp[to][his_take][his_sz], his_sz))
                            );
                        // take edge
                        dp_now[edges_take + his_take + 1][sz_now + his_sz] = sum(dp_now[edges_take + his_take + 1][sz_now + his_sz],
                            mult(dp[v][edges_take][sz_now], dp[to][his_take][his_sz]));
                    }
                }
            }
        }
        sz[v] += sz[to];
        for (int edges_take = 0; edges_take < sz[v]; edges_take++) {
            for (int sz_now = 0; sz_now <= sz[v]; sz_now++) {
                dp[v][edges_take][sz_now] = dp_now[edges_take][sz_now];
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    init();
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, -1);
    for (int edges = 0; edges < sz[1]; edges++) {
        int val = 0;
        for (int sz_now = 0; sz_now <= sz[1]; sz_now++) {
            val = sum(val, mult(dp[1][edges][sz_now], sz_now));
        }
        // k - edges, n - k components
        if (edges == n - 1) {
            f[edges] = 1;
        }
        else {
            f[edges] = mult(val, pw(n, n - edges - 2));
        }
    }
    for (int edges = 0; edges < n; edges++) {
        int cur = 0;
        for (int add = 0; add + edges < n; add++) {
            int coef = mult(c[edges + add][add], f[edges + add]);
            if (add & 1) cur = sub(cur, coef);
            else cur = sum(cur, coef);
        }
        cout << cur << " ";
    }
    return 0;
}