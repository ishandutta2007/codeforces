#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int dp[15][15][15];
int n, k;
const int maxN = 1e5 + 10;
vector<int> g[maxN];
int a[maxN];
int h[maxN];
const int maxK = 42;
int d[maxN][maxK];
void dfs(int v, int p) {
    d[v][0] = a[v];
    for (int to : g[v]) {
        if (to == p) continue;
        h[to] = h[v] + 1;
        dfs(to, v);
        for (int x = 0; x < 2 * k; x++) {
            d[v][(x + 1) % (2 * k)] ^= d[to][x];
        }
    }
}
int up[maxN][maxK];
void sec_dfs(int v, int p) {
    for (int to : g[v]) {
        if (to == p) continue;
        for (int r = 0; r < 2 * k; r++) {
            up[to][(r + 1) % (2 * k)] ^= up[v][r];
            up[to][(r + 1) % (2 * k)] ^= (d[v][r] ^ (d[to][(r + 2 * k - 1) % (2 * k)]));
        }
        sec_dfs(to, v);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    /*for (int k = 0; k < 15; k++) {
        for (int j = 0; j < 15; j++) {
            for (int i = 0; i + j + k < 15; i++) {
                set<int> s;
                for (int x = 1; x <= i; x++) {
                    s.insert(dp[i - x][j][k]);
                }
                for (int x = 1; x <= j; x++) {
                    s.insert(dp[i + x][j - x][k]);
                }
                for (int x = 1; x <= k; x++) {
                    s.insert(dp[i][j + x][k - x]);
                }
                int d = 0;
                while (s.count(d)) d++;
                dp[i][j][k] = d;
            }
        }
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            for (int k = 0; i + j + k < 15; k++) {
                if (k == 0) {
                    assert(dp[i][j][k] == i);
                }
                assert(dp[i][j][k] == (i ^ k));
            }
        }
    }*/
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    dfs(1, -1);
    sec_dfs(1, -1);
    for (int i = 1; i <= n; i++) {
        int s = 0;
        for (int r = k; r <= 2 * k - 1; r++) {
            s ^= up[i][r];
            s ^= d[i][r];
        }
        if (!s) {
            cout << 0 << " ";
        }
        else {
            cout << 1 << " ";
        }
    }
    return 0;
}