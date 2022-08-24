#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxQ = 2e5 + 10;
const int maxN = 1002;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
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
int n, q;
const int maxP = (1 << 17) + 2;
int dp[maxN][maxN];
int cnt[maxN][maxN];
int que_inside[maxN][maxN];
int ans[18][maxP];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    string s;
    cin >> s;
    int tot_q = 0;
    for (char& c : s) {
        if (c == '?') tot_q++;
    }
    for (int l = s.size() - 1; l >= 0; l--) {
        for (int r = l; r < s.size(); r++) {
            int need = 0;
            int tot = 0;
            if (l != r) {
                if (s[l] == '?' && s[r] != '?') {
                    need |= (1 << (s[r] - 'a'));
                }
                else if (s[l] != '?' && s[r] == '?') {
                    need |= (1 << (s[l] - 'a'));
                }
                else if (s[l] != '?' && s[r] != '?' && s[l] != s[r]) {
                    need |= (1 << 17);
                }
            }
            if ((s[l] == '?' || s[r] == '?') && l != r) {
                tot++;
            }
            if (l + 1 <= r - 1) {
                need |= dp[l + 1][r - 1];
                tot += cnt[l + 1][r - 1];
            }
            dp[l][r] = need;
            cnt[l][r] = tot;
            if (!(need & (1 << 17))) {
                for (int z = 1; z <= 17; z++) {
                    ans[z][dp[l][r]] = sum(ans[z][dp[l][r]], pw(z, tot_q - cnt[l][r]));
                }
            }
        }
    }
    for (int z = 1; z <= 17; z++) {
        for (int bit = 0; bit < 17; bit++) {
            for (int mask = 0; mask < (1 << 17); mask++) {
                if (mask & (1 << bit)) {
                    ans[z][mask] = sum(ans[z][mask], ans[z][mask ^ (1 << bit)]);
                }
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;
        int mask = 0;
        for (char& c : t) {
            mask |= (1 << (c - 'a'));
        }
        cout << ans[t.size()][mask] << '\n';
    }
    return 0;
}