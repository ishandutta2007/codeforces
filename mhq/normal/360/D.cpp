#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int mod;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
int n, m;
const int maxN = (int)1e5 + 100;
int a[maxN], b[maxN];
vector < int > all_divs(int p) {
    vector < int > s;
    for (int i = 1; 1LL * i * i <= p; i++) {
        if (p % i == 0) {
            s.push_back(i);
            if (i != p / i) s.push_back(p / i);
        }
    }
    return s;
}
vector < int > only_primes(int p) {
    vector < int > s;
    for (int i = 2; 1LL * i * i <= p; i++) {
        if (p % i == 0) {
            while (p % i == 0) p /= i;
            s.push_back(i);
        }
    }
    if (p > 1) s.push_back(p);
    return s;
}
map < int, int > mp;
vector < int > pr;
int get_phi(int x) {
    int ans = x;
    for (int p : pr) {
        if (x % p == 0) {
            ans /= p;
            ans *= (p - 1);
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> mod;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    int d = mod - 1;
    for (int i = 1; i <= m; i++) {
        d = __gcd(d, b[i]);
    }
    vector < int > all = all_divs(mod - 1);
    sort(all.begin(), all.end());
    for (int i = 0; i < all.size(); i++) mp[all[i]] = i;
    reverse(all.begin(), all.end());
    int tot = all.size();
    vector < bool > hs(tot, false);
    for (int i = 1; i <= n; i++) {
        a[i] = pw(a[i], d);
        for (int v : all) {
            if (pw(a[i], (mod - 1) / v) == 1) {
                hs[mp[v]] = true;
                break;
            }
        }
    }
    pr = only_primes(mod - 1);
    reverse(all.begin(), all.end());
    for (int i = 0; i < all.size(); i++) {
        if (!hs[i]) continue;
        for (int t : pr) {
            if (((mod - 1) / all[i]) % t == 0) {
                //cout << mp[all[i] * t] << " TTT " << all[mp[all[i] * t]] << endl;
                hs[mp[all[i] * t]] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < all.size(); i++) {
        if (hs[i]) {
            //cout << all[i] << " uuu" << endl;
            ans += get_phi((mod - 1) / all[i]);
        }
    }
    cout << ans;
    return 0;
}