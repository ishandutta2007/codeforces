#include <bits/stdc++.h>
using namespace std;

const int N = 5, MX = 4 * N, LG = 31, MOD = 998244353;

int n, m, x[N], y[N];
int px[1 << N], nx[1 << N], py[1 << N], ny[1 << N];
int dp[LG][MX][MX][MX][MX][2][2];

void add(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int msk = 0; msk < (1 << n); msk++) {
        for (int i = 0; i < n; i++) {
            if (msk >> i & 1) {
                (x[i] < 0 ? nx : px)[msk] += abs(x[i]);
                (y[i] < 0 ? ny : py)[msk] += abs(y[i]);
            }
        }
    }
    int mpx = max(1, px[(1 << n) - 1]);
    int mpy = max(1, py[(1 << n) - 1]);
    int mnx = max(1, nx[(1 << n) - 1]);
    int mny = max(1, ny[(1 << n) - 1]);
    dp[0][0][0][0][0][0][0] = 1;
    for (int lg = 0; (1 << lg) <= m; lg++) {
        for (int cpx = 0; cpx < mpx; cpx++) {
            for (int cpy = 0; cpy < mpy; cpy++) {
                for (int cnx = 0; cnx < mnx; cnx++) {
                    for (int cny = 0; cny < mny; cny++) {
                        for (int sx = 0; sx < 2; sx++) {
                            for (int sy = 0; sy < 2; sy++) {
                                for (int msk = 0; msk < (1 << n); msk++) {
                                    int spx = cpx + px[msk];
                                    int spy = cpy + py[msk];
                                    int snx = cnx + nx[msk];
                                    int sny = cny + ny[msk];
                                    if (((spx ^ snx) & 1) || ((spy ^ sny) & 1)) {
                                        continue;
                                    }
                                    int bx = spx & 1, by = spy & 1;
                                    int nsx = (bx < (m >> lg & 1) ? 0 : bx > (m >> lg & 1) ? 1 : sx);
                                    int nsy = (by < (m >> lg & 1) ? 0 : by > (m >> lg & 1) ? 1 : sy);
                                    add(dp[lg + 1][spx / 2][spy / 2][snx / 2][sny / 2][nsx][nsy], dp[lg][cpx][cpy][cnx][cny][sx][sy]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << (dp[__lg(m) + 1][0][0][0][0][0][0] + MOD - 1) % MOD << '\n';
}