#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
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
const int maxN = 2e5 + 10;
int inv[maxN];
int d[maxN];
int pref[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    inv[1] = 1;
    for (int i = 2; i < maxN; i++) {
        inv[i] = mult(inv[mod % i], mod - mod / i);
    }
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    sort(d + 1, d + n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = sum(pref[i - 1], d[i] % mod);
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        int pos = lower_bound(d + 1, d + n + 1, b) - d;
        int cnt_bigger = n + 1 - pos;
        int ans = 0;
        if (a <= cnt_bigger - 1) {
            ans = sum(ans, mult(sub(pref[n], pref[pos - 1]), mult(cnt_bigger - a, inv[cnt_bigger])));
        }
        if (a <= cnt_bigger) {
            ans = sum(ans, mult(pref[pos - 1], mult(cnt_bigger + 1 - a, inv[cnt_bigger + 1])));
        }
        cout << ans << '\n';
    }
    return 0;
}