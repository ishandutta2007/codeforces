#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = 2e5 + 10;
int dp[maxN];
int n;
int a[maxN];
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
void solve() {
    cin >> n;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 0) cnt0++;
        else cnt1++;
    }
    if (!cnt0 || !cnt1) {
        cout << 0 << '\n';
        return;
    }
    int st = 0;
    for (int i = 1; i <= cnt0; i++) {
        if (a[i] == 0) st++;
    }
    const int inv2 = (mod + 1) / 2;
    int ans = 0;
    for (int i = cnt0 - 1; i >= st; i--) {

        int tot = mult(n, n - 1);
        tot = mult(tot, inv2);
        int good_prob = mult(pw(tot, mod - 2), mult(cnt0 - i, cnt0 - i));
//        cout << good_prob << " ? " << endl;
        ans = sum(ans, pw(good_prob, mod - 2));
        /*if (i == cnt0) {
            dp[i] = 0;
        }
        else {
            dp[i] =
        }*/
    }

    cout << ans << '\n';

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) solve();
    return 0;
}