#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int n, m, k;
const int maxN = 12;
int a[maxN][maxN];
int bad = 0;
int ans = 0;
int already[maxN][maxN];
int real_color[maxN];
bool hs[maxN];
bool can[maxN];
void process() {
    memset(real_color, -1, sizeof real_color);
    memset(hs, 0, sizeof hs);
    memset(can, 0, sizeof can);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            hs[a[i][j]] = true;
            if (already[i][j]) {
                can[already[i][j]] = true;
                if (real_color[a[i][j]] != -1 && real_color[a[i][j]] != already[i][j]) return ;
                real_color[a[i][j]] = already[i][j];
            }
        }
    }
    for (int i = 1; i <= k; i++) {
        for (int j = i + 1; j <= k; j++) {
            if (real_color[i] == real_color[j] && real_color[i] != -1) return ;
        }
    }
    int val = 1;
    int cnt = 0;
    int total = k;
    for (int i = 1; i <= k; i++) {
        if (hs[i] && real_color[i] == -1) cnt++;
        if (can[i]) total--;
    }
    for (int i = 1; i <= cnt; i++) {
        val = (1LL * val * (total - i + 1)) % mod;
    }
    ans += val;
    ans %= mod;
}
void go(int x, int y, int clr) {
    if (x == n + 1) {
        process();
        return;
    }
    int nxtx = x; int nxty = y + 1;
    if (nxty == m + 1) {
        nxtx++;
        nxty = 1;
    }
    for (int i = 1; i <= min(clr + 1, k); i++) {
        bool ok = true;
        for (int j = 1; j <= x; j++) {
            for (int p = 1; p <= y; p++) {
                if (a[j][p] == i) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            a[x][y] = i;
            go(nxtx, nxty, clr + (i == clr + 1));
            a[x][y] = 0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    if (n + m - 1 > k) {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> already[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int u = i; u <= n; u++) {
                for (int p = j; p <= m; p++) {
                    if (i == u && j == p) continue;
                    if (already[i][j] == already[u][p] && already[i][j] > 0) {
                        cout << 0;
                        return 0;
                    }
                }
            }
        }
    }
    go(1, 1, 0);
    cout << ans;
    return 0;
}