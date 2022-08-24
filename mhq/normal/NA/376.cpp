#include <bits/stdc++.h>
using namespace std;
const int maxN = 2 * (int)1e5 + 10;
typedef long long ll;
ll gcd(ll a, ll b) {
    while (a > 0 && b > 0) {
        if (a < b) swap(a, b);
        a %= b;
    }
    return a + b;
}
int n;
ll x, y;
vector < ll > a, b;
int vala[maxN], valb[maxN];
int maska[1 << 22], maskb[1 << 22];
vector < ll > all;
void upd() {
    int k = all.size() - 1;
    ll p  = all.back();
    for (int i = 0; i < a.size(); i++) {
        if (a[i] % p == 0) {
            vala[i] |= (1 << k);
            while (a[i] % p == 0) {
                a[i] /= p;
            }
        }
    }
    for (int i = 0; i < b.size(); i++) {
        if (b[i] % p == 0) {
            valb[i] |= (1 << k);
            while (b[i] % p == 0) {
                b[i] /= p;
            }
        }
    }
}
void factorize(ll p) {
    vector < int > cur;
    for (int i = 2; i <= (int)1e6 + 3; i++) {
        if (1LL * i * i > p) break;
        if (p % i == 0) {
            all.push_back(i);
            upd();
            while (p % i == 0) {
                p /= i;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
   // freopen("input.txt", "r", stdin);
    cin >> n >> x >> y;
    if (y % x != 0) {
        cout << 0;
        return 0;
    }
    ll d = y / x;
    for (int i = 1; i <= n; i++) {
        ll t;
        cin >> t;
        if (t % x == 0) a.push_back(gcd(d, t / x));
        if (y % t == 0) b.push_back(gcd(d, y / t));
    }
    /*int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (gcd(a[i], b[j]) == 1) ans++;
        }
    }*/
    factorize(d);
    ll vals1 = 1;
    ll vals2 = 1;
    for (int i = 0; i < a.size(); i++) {
        if (vals2 != 1) break;
        if (a[i] != 1) {
            if ((vals1 != 1) && (a[i] != vals1)) vals2 = a[i];
            else vals1 = a[i];
        }
    }
    for (int i = 0; i < b.size(); i++) {
        if (vals2 != 1) break;
        if (b[i] != 1) {
            if ((vals1 != 1) && (b[i] != vals1)) vals2 = b[i];
            else vals1 = b[i];
        }
    }
    if (vals1 != 1) {
        if (vals2 == 1) {
            all.push_back(vals1);
            upd();
        }
        else {
            if (vals1 > vals2) swap(vals1, vals2);
            if (vals2 % vals1 != 0) {
                all.push_back(vals1);
                upd();
                all.push_back(vals2);
                upd();
            }
            else {
                all.push_back(vals1);
                upd();
                if (vals1 != (vals2 / vals1)) {
                    all.push_back(vals2 / vals1);
                    upd();
                }
            }
        }
    }
    int n = all.size();
    assert(n <= 22);
    for (int i = 0; i < a.size(); i++) maska[vala[i]]++;
    for (int i = 0; i < b.size(); i++) maskb[valb[i]]++;
    int big = (1 << n) - 1;
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (mask & (1 << i)) maskb[mask] += maskb[mask ^ (1 << i)];
        }
    }
    ll ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) ans += 1LL * maska[mask] * maskb[mask ^ big];
    cout << ans;
    return 0;
}