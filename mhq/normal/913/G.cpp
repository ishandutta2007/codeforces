#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxK = 19;
ll pw2[maxK], pw5[maxK], pw10[maxK];
ll sum(ll a, ll b, ll mod) {
    ll s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
ll mult(ll a, ll b, ll mod) {
    if (b == 0) return 0;
    if (b & 1) return sum(a, mult(a, b - 1, mod), mod);
    ll res = mult(a, b / 2, mod);
    return sum(res, res, mod);
}
ll pw(ll a, ll b, ll mod) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1, mod), mod);
    ll res = pw(a, b / 2, mod);
    return mult(res, res, mod);
}
ll get(ll res, ll cnt) {
    if (cnt == 1) {
        for (int i = 0; i <= 4; i++) {
            if (pw2[i] % 5 == res) return i;
        }
    }
    ll res_small = res % pw5[cnt - 1];
    ll md = get(res_small, cnt - 1);
    ll coef = pw(2, 4 * pw5[cnt - 2], pw5[cnt]);
    ll cur = pw(2, md, pw5[cnt]);
    ll now = md;
    for (int i = 0; i <= 4; i++) {
        if (cur == res) return now;
        cur = mult(cur, coef, pw5[cnt]);
        now += 4 * pw5[cnt - 2];
    }
    assert(0);
}
void solve() {
    ll x;
    cin >> x;
    ll q = pw2[12] - mult(x % pw2[12], pw5[6] % pw2[12], pw2[12]);
    ll num = x * pw10[6] + q * pw2[6];
    if (num % 5 == 0) {
        num += pw2[18];
    }
    ll s = (num / pw2[18]) % pw5[18];
    cout << get(s, 18) + 18 << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    pw2[0] = 1; pw5[0] = 1; pw10[0] = 1;
    for (int i = 1; i < maxK; i++) {
        pw2[i] = 2 * pw2[i - 1];
        pw5[i] = 5 * pw5[i - 1];
        pw10[i] = 10 * pw10[i - 1];
    }
    int tst;
    cin >> tst;
    for (int i = 1; i <= tst; i++) {
        solve();
    }
    return 0;
}