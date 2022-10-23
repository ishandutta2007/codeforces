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
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = 1e5 + 10;
ll a[maxN];
ll pref[maxN];
int n;
int fact[maxN], invfact[maxN], inv[maxN];
int cnk(int n, int k) {
    if (n < k || k < 0) return 0;
    return mult(fact[n], mult(invfact[k], invfact[n - k]));
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    ll S = pref[n];
    map<ll,int> mp;
    for (int i = 1; i < n; i++) {
        mp[pref[i]]++;
    }
    vector<ll> vals;
    for (auto& it : mp) {
        vals.emplace_back(it.first);
    }

    int coef = 1;
    for (int i = 0; i < vals.size(); i++) {
        if (2 * vals[i] < S) {
            if (mp.count(S - vals[i])) {
                int d1 = mp[vals[i]];
                int d2 = mp[S - vals[i]];
                int f = 0;
                for (int cnt = 0; cnt <= min(d1, d2); cnt++) {
                    f = sum(f, mult(cnk(d1, cnt), cnk(d2, cnt)));
                }
                coef = mult(coef, f);
            }
        }
        else if (2 * vals[i] == S) {
            int tot = 1;
            int d = mp[vals[i]];
            for (int z = 0; z < d; z++) tot = mult(tot, 2);
            coef = mult(coef, tot);
        }
    }
    cout << coef << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
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