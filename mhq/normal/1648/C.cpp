#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
const int maxN = 2e5 + 10;
int inv[maxN], fact[maxN], invfact[maxN];
int n, m;
int cnt[maxN];
int t[maxN];
int fenw[maxN];
int get(int r) {
    int ans = 0;
    while (r > 0) {
        ans = sum(ans, fenw[r]);
        r &= (r - 1);
    }
    return ans;
}
void upd(int v, int by) {
    while (v < maxN) {
        fenw[v] = sum(fenw[v], by);
        v = (v | (v - 1)) + 1;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    fact[0] = invfact[0] = fact[1] = invfact[1] = inv[1] = 1;
    for (int i = 2; i < maxN; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int s;
        cin >> s;
        cnt[s]++;
    }
    for (int i = 1; i <= m; i++) {
        cin >> t[i];
    }
    int ans = 0;
    int coef = 1;
    for (int i = 1; i < maxN; i++) {
        coef = mult(coef, invfact[cnt[i]]);
        upd(i, cnt[i]);
    }
    for (int pref = 0; pref <= min(n, m); pref++) {
        if (pref == m) break;
        if (pref == n) {
            assert(coef == 1);
            ans = sum(ans, 1);
            break;
        }
        int D = get(t[pref + 1] - 1);
        ans = sum(ans, mult(coef, mult(fact[n - pref - 1], D)));
        if (!cnt[t[pref + 1]]) break;
        upd(t[pref + 1], sub(0, 1));
        coef = mult(coef, cnt[t[pref + 1]]);
        cnt[t[pref + 1]]--;
    }
    cout << ans << '\n';
    return 0;
}