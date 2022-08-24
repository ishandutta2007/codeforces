#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int tst;
int n, x, y, z;
const int BUBEN = 1000;
int dp[BUBEN][3];
int val[3];
bool ok[5];
int calc() {
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < BUBEN; i++) {
        for (int j = 0; j < 3; j++) {
            memset(ok, 0, sizeof ok);
            if (i == 0) {
                dp[i][j] = 0;
                continue;
            }
            for (int p = 0; p < 3; p++) {
                if (j == p && j != 0) continue;
                int ni = max(0, i - val[p]);
                ok[dp[ni][p]] = true;
            }
            while (ok[dp[i][j]]) dp[i][j]++;
        }
    }
    for (int per = 1; 2 * per < BUBEN; per++) {
        bool ok  = true;
        for (int i = 100; i + per  < BUBEN; i++) {
            if (!ok) break;
            for (int j = 0; j < 3; j++) {
                if (dp[i][j] != dp[i + per][j]) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) return per;
    }
    return -1;
}
const int maxN = 3 * (int)1e5 + 10;
ll a[maxN];
void solve() {
    cin >> n >> x >> y >> z;
    val[0] = x; val[1] = y; val[2] = z;
    int xr = 0;
    int per = calc();
    assert(per != -1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] >= 1000) {
            a[i] = a[i] % per + per * ((100 + per - 1) / per);
        }
        xr ^= dp[a[i]][0];
    }
    if (xr == 0) {
        cout << 0 << '\n';
    }
    else {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                if ((xr ^ dp[a[i]][0]) == dp[max(0LL, a[i] - val[j])][j]) cnt++;
            }
        }
        assert(cnt);
        cout << cnt << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> tst;
    while (tst--) solve();
    return 0;
}