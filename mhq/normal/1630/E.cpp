#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 1e6 + 10;
int a[maxN];
int cnt[maxN];
int T[maxN];
int fact[maxN], invfact[maxN], inv[maxN];
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
int pw(int a, int b) {
    if (b== 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b  / 2);
    return mult(res, res);
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    bool eq = true;
    int gc = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        if (i > 1) eq &= (a[i] == a[i - 1]);
    }
    vector<int> not_z;
    for (int j = 1; j <= n; j++) {
        if (cnt[j] != 0) {
            not_z.emplace_back(cnt[j]);
            if (gc == 0) gc = cnt[j];
            else gc = __gcd(gc, cnt[j]);
        }
    }
    if (eq) {
        cout << 1 << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        T[i] = 0;
    }
    for (int shift = 1; shift <= n; shift++) {
        T[__gcd(shift, n)]++;
    }
    int ans = 0;
    int all = 0;
    for (int i = 1; i <= n; i++) {
        if (T[i] > 0) {
            assert(n % i == 0);
            int t = n / i;
            if (gc % t != 0) continue;
            vector<int> nv;
            int cnt_per = fact[i];
            for (int v : not_z) {
                nv.emplace_back(v / t);
                cnt_per = mult(cnt_per, invfact[v / t]);
            }
//            cout << cnt_per << endl;
            ans = sum(ans, mult(mult(T[i], n), cnt_per));
            all = sum(all, mult(T[i], cnt_per));
            for (int v : nv) {
                if (v >= 2) {
                    int new_per = mult(cnt_per, inv[i]);
                    new_per = mult(new_per, inv[i - 1]);
                    new_per = mult(new_per, v);
                    new_per = mult(new_per, v - 1);
                    ans = sub(ans, mult(mult(T[i], new_per), n));
                }
            }
        }
    }
    ans = mult(ans, inv[n]);
    all = mult(all, inv[n]);
    cout << mult(ans, pw(all, mod - 2)) << '\n';
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
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}