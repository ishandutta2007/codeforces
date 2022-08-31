#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
int n, q;
const int LOG = 17;
const int maxK = 31;
const int maxN = 20 * 1000 + 10;
int dp[LOG][maxK][maxN];
int lg[maxN];
int a[maxN];
int sparse[maxK][LOG][maxN];

int getMax(int l, int r, int id_k) {
    int k = lg[r - l + 1];
    return max(sparse[id_k][k][l], sparse[id_k][k][r - (1 << k) + 1]);
}

int cur_dp[maxN][maxK];
int ans[maxN];
int l[maxN], r[maxN], k[maxN];
int new_dp[maxK];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    lg[1] = 0;
    cin >> n >> q;
    for (int i = 2; i < maxN; i++) {
        lg[i] = lg[i - 1];
        if (!(i & (i - 1))) lg[i]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //build
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < maxK; j++) {
            dp[0][j][i] = min(i + a[i] + j, n - 1);
        }
    }
    for (int i = 0; i + 1 < LOG; i++) {
        //build sparse
        for (int x = 0; x < maxK; x++) {
            for (int y = 0; y < n; y++) {
                sparse[x][0][y] = dp[i][x][y];
            }
            for (int z = 0; z + 1 < LOG; z++) {
                for (int y = 0; y + (1 << (z + 1)) <= n; y++) {
                    sparse[x][z + 1][y] = max(sparse[x][z][y], sparse[x][z][y + (1 << z)]);
                }
            }
        }
        //calc
        for (int k1 = 0; k1 < maxK; k1++) {
            for (int k2 = 0; k2 + k1 < maxK; k2++) {
                for (int x = 0; x < n; x++) {
                    dp[i + 1][k1 + k2][x] = max(dp[i + 1][k1 + k2][x], getMax(x, dp[i][k1][x], k2));
                }
            }
        }
    }
    for (int i = 0; i < q; i++) {
        cin >> l[i] >> r[i] >> k[i];
        l[i]--;
        r[i]--;
        if (l[i] == r[i]) {
            ans[i] = -1;
            continue;
        }
        for (int z = 0; z <= k[i]; z++) {
            cur_dp[i][z] = l[i];
        }
    }
    for (int i = LOG - 1; i >= 0; i--) {
        //build sparse
        for (int x = 0; x < maxK; x++) {
            for (int y = 0; y < n; y++) {
                sparse[x][0][y] = dp[i][x][y];
            }
            for (int z = 0; z + 1 < LOG; z++) {
                for (int y = 0; y + (1 << (z + 1)) <= n; y++) {
                    sparse[x][z + 1][y] = max(sparse[x][z][y], sparse[x][z][y + (1 << z)]);
                }
            }
        }
        //process
        for (int id = 0; id < q; id++) {
            if (ans[id] == -1) continue;
            memset(new_dp, 0, sizeof new_dp);
            for (int was = 0; was <= k[id]; was++) {
                for (int will = 0; will + was <= k[id]; will++) {
                    new_dp[was + will] = max(new_dp[was + will], getMax(l[id], cur_dp[id][was], will));
                }
            }
            if (new_dp[k[id]] < r[id]) {
                ans[id] += (1 << i);
                memcpy(cur_dp[id], new_dp, sizeof(new_dp));
            }
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] + 1 << '\n';
    }

    return 0;
}