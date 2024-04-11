#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;

const int root = 646;

const int root_1 = 208611436;

const int root_pw = 1<<20;

int mult(int a, int b) {
    return (1LL * a * b) % mod;
}

int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}

int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}

int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int n, k, m;
const int maxN = 5e5 + 10;
int l[maxN], r[maxN], x[maxN];
int tp[maxN];
int dp[maxN][2];
int pref[maxN][2];
vector < int > f[maxN];
int delta[maxN];
int val[maxN];
int solve() {
    dp[0][0] = 1;
    pref[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i][1] = 0;
        f[i].clear();
        delta[i] = 0;
        pref[i][0] = pref[i][1] = 0;
    }
    for (int i = 1; i <= m; i++) {
        if (tp[i] == 1) {
            delta[l[i]]++;
            delta[r[i] + 1]--;
        }
        else {
            f[r[i]].emplace_back(l[i]);
        }
    }
    int gg = -1;
    for (int i = 1; i <= n; i++) {
        delta[i] += delta[i - 1];
        bool is_one = (delta[i] > 0);
        for (int p : f[i]) {
            gg = max(gg, p);
        }
        for (int r = 0; r < 2; r++) {
            if (r == 0 && is_one) continue;
            if (r == 0 || gg == -1) {
                dp[i][r] = sum(dp[i - 1][0], dp[i - 1][1]);
            }
            else {
                dp[i][r] = sub(pref[i - 1][0], pref[gg - 1][0]);
            }
        }
        for (int r = 0; r < 2; r++) {
            pref[i][r] = sum(pref[i - 1][r], dp[i][r]);
        }
    }
    return sum(dp[n][0], dp[n][1]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i] >> x[i];
    }
    int ans = 1;
    for (int i = 0; i < k; i++) {
        for (int j = 1; j <= m; j++) {
            if (x[j] & (1 << i)) {
                tp[j] = 1;
            }
            else {
                tp[j] = 0;
            }
        }
        ans = mult(ans, solve());
    }
    cout << ans;
    return 0;
}