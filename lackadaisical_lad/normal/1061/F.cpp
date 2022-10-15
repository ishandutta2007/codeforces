#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
    a %= mod;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int n, k;
    cin >> n >> k;
    mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
    int h = 0;
    int m = 1;
    int t = 1;
    while (m < n) {
        t *= k;
        ++h;
        m += t;
    }
    string res;
    while (1) {
        int a = rng() % n + 1;
        int b = rng() % n + 1;
        if (a == b) {
            continue;
        }
        vector<int> col = { a , b };
        for (int i = 1; i <= n; ++i) {
            if (i != a && i != b) {
                cout << "? " << a << ' ' << i << ' ' << b << endl;
                cin >> res;
                if (res == "Yes") {
                    col.push_back(i);
                }
            }
        }
        if (col.size() == h * 2 + 1) {
            for (int j : col) {
                int tmp = 0;
                for (int i : col) {
                    cout << "? " << a << ' ' << i << ' ' << j << endl;
                    cin >> res;
                    if (res == "Yes") {
                        ++tmp;
                    }
                }
                if (tmp == h + 1) {
                    cout << "! " << j << endl;
                    return;
                }
            }
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";  
        solve();
    }
    return 0;
}