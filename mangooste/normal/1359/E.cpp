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
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fun function

const ll MOD = 998244353ll;

ll bin_pow(ll a, ll b) {
    if (b == 0) {
        return 1ll;
    } else if (b % 2) {
        return bin_pow(a, b - 1) * a % MOD;
    } else {
        return bin_pow(a * a % MOD, b / 2);
    }
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> fact(n + 1), rfact(n + 1);
    fact[0] = 1ll;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    rfact[n] = bin_pow(fact[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) {
        rfact[i] = rfact[i + 1] * (i + 1) % MOD;
    }
    Fun<ll(ll, ll)> C = [&](ll N, ll K) {
        return fact[N] * rfact[K] % MOD * rfact[N - K] % MOD;
    };
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int can = n / i - 1;
        if (can >= k - 1) {
            ans += C(can, k - 1);
            if (ans >= MOD) {
                ans -= MOD;
            }
        }
    }
    cout << ans << '\n';
}