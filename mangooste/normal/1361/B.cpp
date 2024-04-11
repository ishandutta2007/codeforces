#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
 
using namespace std;
using ll = long long;
 
#define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fun function
 
void solve();
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}

#define ll __int128

istream& operator >> (istream &in, __int128 &val) {
    int64_t tmp;
    in >> tmp;
    val = tmp;
    return in;
}
 
const ll BUBEN = 2000000ll;
const ll MOD = 1000000007ll;
 
ll bin_pow(ll a, ll b) {
    if (b == 0) {
        return 1ll;
    } else if (b % 2 == 1) {
        return bin_pow(a, b - 1) * a % MOD;
    } else {
        return bin_pow(a * a % MOD, b / 2);
    }
}
 
ll bin_powll(ll a, ll b, bool &flag) {
    if (b == 0) {
        return 1ll;
    } else if (b % 2 == 1) {
        flag |= (a >= BUBEN);
        ll cur = bin_powll(a, b - 1, flag) * a;
        flag |= (cur >= BUBEN);
        return cur;
    } else {
        flag |= (a >= BUBEN);
        ll cur = bin_powll(a, b / 2, flag);
        flag |= (cur >= BUBEN);
        cur *= cur;
        flag |= (cur >= BUBEN);
        return cur;
    }
}
 
void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> k(n);
    for (auto &el : k) {
        cin >> el;
    }
    if (p == 1) {
        cout << n % 2 << '\n';
        return;
    }
    sort(all(k));
    reverse(all(k));
    ll a = bin_pow(p, k[0]), b = 0;
    ll K = 1;
    bool always = false;
    for (int i = 1; i < n; i++) {
        if (K >= BUBEN) {
            always = true;
        }
        if (always) {
            b += bin_pow(p, k[i]);
            while (b >= MOD) {
                b -= MOD;
            }
            continue;
        }
        ll delta = k[i - 1] - k[i];
        bool chk = false;
        ll md = bin_powll(p, delta, chk);
        if (K != 0 && (chk || (K * md >= BUBEN))) {
            always = true;
        }
        if (always) {
            b += bin_pow(p, k[i]);
            while (b >= MOD) {
                b -= MOD;
            }
            continue;
        }
        K *= md;
        if (K <= 0) {
            a += bin_pow(p, k[i]);
            while (a >= MOD) {
                a -= MOD;
            }
            K = 1;
        } else {
            K--;
            b += bin_pow(p, k[i]);
            while (b >= MOD) {
                b -= MOD;
            }
        }
    }
    ll ans = (a - b + MOD) % MOD;
    cout << (int64_t)ans << '\n';
}