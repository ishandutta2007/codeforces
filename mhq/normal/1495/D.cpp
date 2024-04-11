#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 405;
int f[maxN][maxN];
const int maxM = 605;
int a[maxM], b[maxM];
bool was[maxN];
vector<int> g[maxN];
const int mod = 998244353;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = n + 100;
        }
        f[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
        f[a[i]][b[i]] = 1;
        f[b[i]][a[i]] = 1;
        g[a[i]].emplace_back(b[i]);
        g[b[i]].emplace_back(a[i]);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            memset(was, 0, sizeof was);
            int D = f[x][y];
            bool ok = true;
            for (int p = 1; p <= n; p++) {
                if (f[x][p] + f[p][y] == D) {
                    if (was[f[x][p]]) {
                        ok = false;
                        break;
                    }
                    was[f[x][p]] = true;
                }
            }
            if (!ok) {
                cout << 0 << " ";
                continue;
            }
            int ways = 1;
            for (int p = 1; p <= n; p++) {
                if (f[x][p] + f[p][y] == D) continue;
                int cnt = 0;
                for (int u : g[p]) {
                    if (f[x][u] == f[x][p] - 1 && f[y][u] == f[y][p] - 1) cnt++;
                }
                ways = mult(ways, cnt);
            }
            cout << ways << " ";
        }
        cout << '\n';
    }
    return 0;
}