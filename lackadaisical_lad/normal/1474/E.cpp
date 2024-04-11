#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int mod = 1e9 + 7;
 
ll binpow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << "1\n2 1\n1\n2 1\n";
        return;
    }
    if (n == 3) {
        cout << "5\n2 3 1\n2\n1 3\n3 2\n";
        return;
    }
    if (n % 2 == 0) {
        vector<int> p(n);
        p[0] = n - 2;
        p[n - 1] = 1;
        for (int i = 1; i + 1 < n / 2; i++) {
            p[i] = i + 1;
        }
        p[n / 2 - 1] = 0;
        p[n / 2] = n - 1;
        for (int i = n / 2 + 1; i + 1 < n; i++) {
            p[i] = i - 1;
        }
        ll ans = 1LL * (n - 1) * (n - 1);
        for (int i = n / 2; i > 1; i--) {
            ans += 2LL * (n - i) * (n - i);
        }
        cout << ans << '\n';
        for (int i = 0; i < n; i++) {
            cout << p[i] + 1 << " \n"[i + 1 == n];
        }
        cout << n - 1 << '\n';
        for (int i = n - 2; i >= n / 2; i--) {
            cout << i + 1 << " 1\n";
        }
        for (int i = 1; i < n / 2; i++) {
            cout << i + 1 << ' ' << n << '\n';
        }
        cout << "1 " << n << '\n';
    } else {
        vector<int> p(n);
        p[0] = n - 2;
        p[n - 1] = 1;
        for (int i = 1; i < n / 2; i++) {
            p[i] = i + 1;
        }
        p[n / 2] = 0;
        p[n / 2 + 1] = n - 1;
        for (int i = n / 2 + 2; i + 1 < n; i++) {
            p[i] = i - 1;
        }
        ll ans = 1LL * (n - 1) * (n - 1);
        ans += 1LL * (n - n / 2 - 1) * (n - n / 2 - 1);
        for (int i = n / 2; i > 1; i--) {
            ans += 2LL * (n - i) * (n - i);
        }
        cout << ans << '\n';
        for (int i = 0; i < n; i++) {
            cout << p[i] + 1 << " \n"[i + 1 == n];
        }
        cout << n - 1 << '\n';
        for (int i = n - 2; i > n / 2; i--) {
            cout << i + 1 << " 1\n";
        }
        for (int i = 1; i <= n / 2; i++) {
            cout << i + 1 << ' ' << n << '\n';
        }
        cout << "1 " << n << '\n';
    }
    
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}