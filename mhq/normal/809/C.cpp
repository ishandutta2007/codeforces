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
int q;
const int BIT = 32;
int dp[BIT + 1][2][2][2];
int sm[BIT + 1][2][2][2];
void upd(int& x, int y) {
    x = sum(x, y);
}
int ways(ll a, ll b, ll k) {
    if (a < 0 || b < 0) return 0;
    memset(dp, 0, sizeof dp);
    memset(sm, 0, sizeof sm);
    dp[BIT][0][0][0] = 1;
    int tot = 0;
    for (int i = BIT; i >= 0; i--) {
        int bita = (a >> (i - 1)) & 1;
        int bitb = (b >> (i - 1)) & 1;
        int bitk = (k >> (i - 1)) & 1;
        for (int fla = 0; fla < 2; fla++) {
            for (int flb = 0; flb < 2; flb++) {
                for (int flk = 0; flk < 2; flk++) {
                    if (dp[i][fla][flb][flk] == 0) continue;
                    if (i == 0) {
                        upd(tot, dp[i][fla][flb][flk]);
                        upd(tot, sm[i][fla][flb][flk]);
                        continue;
                    }
                    for (int willa = 0; willa < 2; willa++) {
                        for (int willb = 0; willb < 2; willb++) {
                            if (willa > bita && !fla) continue;
                            if (willb > bitb && !flb) continue;
                            int willk = willa ^ willb;
                            if (willk > bitk && !flk) continue;
                            upd(dp[i - 1][fla || (willa < bita)][flb || (willb < bitb)][flk || (willk < bitk)], dp[i][fla][flb][flk]);
                            upd(sm[i - 1][fla || (willa < bita)][flb || (willb < bitb)][flk || (willk < bitk)], mult(2, sm[i][fla][flb][flk]));
                            if (willk) {
                                upd(sm[i - 1][fla || (willa < bita)][flb || (willb < bitb)][flk || (willk < bitk)], dp[i][fla][flb][flk]);
                            }
                        }
                    }
                }
            }
        }
    }
    return tot;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> q;
    while (q--) {
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        x1--; x2--; y1--; y2--; k--;
       // cout << x1 - 1 << " " << y1 - 1 << " " << k << " " << ways(x1 - 1, y1 - 1, k) << endl;
       // exit(0);
        int ans = sum(sub(ways(x2, y2, k), ways(x2, y1 - 1, k)), sub(ways(x1 - 1, y1 - 1, k), ways(x1 - 1, y2, k)));
        cout << ans << '\n';
    }
    return 0;
}