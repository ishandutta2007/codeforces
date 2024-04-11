#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
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
int n;
const int maxN = 305;
vector<int> g[maxN];
int R = 0;
int TOT = 0;
int dpG[maxN][maxN];
int dpB[maxN][maxN];
int sz[maxN];
int dp_G[maxN];
int dp_B[maxN];
void dfs(int v, int p) {
    sz[v] = 1;
    dpG[v][0] = 1;
    if (R != 0) {
        dpB[v][0] = 1;
    }
    for (int to : g[v]) {
        if (to == p) continue;
        dfs(to, v);
        memset(dp_G, 0, sizeof dp_G);
        memset(dp_B, 0, sizeof dp_B);
        for (int a = 0; a <= sz[v]; a++) {
            for (int b = 0; b <= sz[to]; b++) {
                int nb = b + 1;
                if (min(a, nb) <= R) {
                    dp_G[min(a, nb)] = sum(dp_G[min(a, nb)], mult(dpG[v][a], dpG[to][b]));
                }
                if (a + nb > R) {
                    dp_B[nb] = sum(dp_B[nb], mult(dpG[v][a], dpB[to][b]));
                    dp_B[a] = sum(dp_B[a], mult(dpB[v][a], dpG[to][b]));
                }
                else {
                    dp_G[a] = sum(dp_G[a], mult(dpG[v][a], dpB[to][b]));
                    dp_G[nb] = sum(dp_G[nb], mult(dpB[v][a], dpG[to][b]));
                }
                dp_B[max(a, nb)] = sum(dp_B[max(a, nb)], mult(dpB[v][a], dpB[to][b]));
            }
        }
        sz[v] += sz[to];
        for (int u = 0; u <= sz[v]; u++) {
            dpG[v][u] = 0;
            dpB[v][u] = 0;
            if (u <= R) {
                dpG[v][u] = dp_G[u];
                dpB[v][u] = dp_B[u];
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    TOT = 1;
    for (int i = 1; i <= n; i++) TOT = mult(TOT, 2);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    int ans = 0;
    for (int z = 0; z <= n; z++) {
        R = z;
        memset(dpG, 0, sizeof dpG);
        memset(dpB, 0, sizeof dpB);
        dfs(1, -1);
        int f = 0;
        for (int p = 0; p <= R; p++) {
            f = sum(f, dpG[1][p]);
        }
        ans = sum(ans, sub(TOT, f));
    }
    int inv2 = (mod + 1) / 2;
    for (int i = 0; i < n; i++) ans = mult(ans, inv2);
    ans = sub(ans, 1);
    cout << ans;
    return 0;
}