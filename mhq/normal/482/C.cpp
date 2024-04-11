#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 55;
const int maxK = 20;
ll f[(1 << maxK) + 2];
ll bt[(1 << maxK) + 2];
string s[maxN];
ll val[maxK];
ld num[maxK];
bool bad[(1 << maxK) + 2];
int bits[(1 << maxK) + 2];
ld dp[(1 << maxK) + 2];
int main() {
   // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i < (1 << (20)); i++) {
        for (int j = 0; j < 20; j++) {
            if (i & (1 << j)) {
                bt[i] = j;
                bits[i] = bits[i ^ (1 << j)] + 1;
                break;
            }
        }
    }
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int m = s[0].size();
    num[0] = 1;
    for (int i = 1; i <= m; i++) {
        num[i] = (num[i - 1]) * ((1.0 * i) / (m - i + 1));
    }
    ld all = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            val[j] = 0;
            for (int k = 0; k < n; k++) {
                if (k == i) continue;
                if (s[i][j] == s[k][j]) {
                    val[j] |= (1LL << k);
                }
            }
        }
        f[0] = (1LL << n) -  1;
        ld ans = 0;
        dp[0] = 1;
        for (int mask = 1; mask < (1 << m); mask++) {
            f[mask] = f[mask ^ (1 << bt[mask])] & val[bt[mask]];
            if (f[mask] != 0) {
                ans += num[bits[mask]];
                //cout << mask << " " << dp[mask] << endl;
            }
        }
        //cout << "----" << endl;
        //cout << ans << " " << i << endl;
        all += (ans + 1) / n;
    }
    cout << fixed << setprecision(10) << all;
    return 0;
}